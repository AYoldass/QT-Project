#include "SerialPortMenager.h"

SerialPortManager::SerialPortManager(QObject *parent) : QThread(parent), serialPort(new QSerialPort(this))
{
}

SerialPortManager::~SerialPortManager()
{
    disconnectPort();
    delete serialPort;
}

void SerialPortManager::run() {
    while (!stopThread) {
        if (serialPort->isOpen() && serialPort->waitForReadyRead(100)) {
            QByteArray data = serialPort->readAll();
            if (!data.isEmpty()) {
                emit messageReceived(QString::fromUtf8(data));
            }
        }
         processOutgoingMessages(); // Kuyruktaki mesajları düzenli olarak işle
    }
}

void SerialPortManager::connectPort(const QString &portName, int baudRate, QSerialPort::DataBits dataBits,
                                    QSerialPort::StopBits stopBits, QSerialPort::Parity parity,
                                    QSerialPort::FlowControl flowControl)
{
    if (serialPort->isOpen())
        disconnectPort();

    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(parity);
    serialPort->setFlowControl(flowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        emit connected();
        start(); // İş parçacığını başlat
    } else {
        emit errorOccurred(serialPort->errorString());
    }
}

void SerialPortManager::disconnectPort()
{
    if (serialPort->isOpen()) {
        stopThread = true;
        wait(); // İş parçacığının bitmesini bekle
        serialPort->close();
        emit disconnected();
    }
}

/*void SerialPortManager::sendMessage(const QString &message) {
    if (serialPort->isOpen() && serialPort->isWritable()) {
        qint64 bytesWritten = serialPort->write(message.toUtf8());
        if (bytesWritten == -1) {
            emit errorOccurred("Failed to write the data");
        } else if (bytesWritten != message.toUtf8().size()) {
            emit errorOccurred("Not all data was written to the port");
        } else {
            serialPort->flush(); // Verinin hemen gönderilmesini sağlamak için
        }
    } else {
        emit errorOccurred("Port is not open or not writable");
    }
}

void SerialPortManager::processOutgoingMessages() {
    while (!outgoingMessages.isEmpty()) {
        QString message = outgoingMessages.dequeue();
        serialPort->write(message.toUtf8());
    }*/

void SerialPortManager::sendMessage(const QString &message) {
    QMutexLocker locker(&mutex); // Mutex ile kuyruğa erişimi kilitle
    outgoingMessages.enqueue(message); // Mesajı kuyruğa ekle
}

void SerialPortManager::processOutgoingMessages() {
    QMutexLocker locker(&mutex); // Kuyrukta işlem yaparken mutex ile kilitle
    while (!outgoingMessages.isEmpty()) {
        QString message = outgoingMessages.dequeue(); // Kuyruktan mesaj çıkar
        serialPort->write(message.toUtf8()); // Mesajı seri porta yaz
        serialPort->flush(); // Portun hemen yazmasını sağla
    }
}


