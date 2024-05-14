#ifndef SERIALPORTMENAGER_H
#define SERIALPORTMENAGER_H

#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QQueue>
#include <QMutex>
#include <QString>

class SerialPortManager : public QThread
{
    Q_OBJECT
public:
    explicit SerialPortManager(QObject *parent = nullptr);
    ~SerialPortManager();

    void run() override; // QThread'in ana işlevi

    void connectPort(const QString &portName, int baudRate, QSerialPort::DataBits dataBits,
                     QSerialPort::StopBits stopBits, QSerialPort::Parity parity,
                     QSerialPort::FlowControl flowControl);

    void disconnectPort();

    //void sendMessage(const QString &message);

    void sendMessage(const QString &message);


signals:
    void messageReceived(const QString &message);

    void errorOccurred(const QString &error);

    void connected();

    void disconnected();

   // void processOutgoingMessages();

private:
    QSerialPort *serialPort;
    bool stopThread = false;
    QQueue<QString> outgoingMessages;  // Mesaj kuyruğu
    QMutex mutex;  // Eş zamanlı erişim için mutex

    void processOutgoingMessages();
};

#endif // SERIALPORTMANAGER_H
