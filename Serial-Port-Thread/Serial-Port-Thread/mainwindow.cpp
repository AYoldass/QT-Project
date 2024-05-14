#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serialManager(new SerialPortManager(this)) // SerialPortManager nesnesi yaratılıyor
{
    ui->setupUi(this);
    setFixedSize(width(), height());
    QWidget::setWindowTitle("Serial Port Example");

    connect(serialManager, &SerialPortManager::messageReceived, this, &MainWindow::receiveMessage);
    connect(serialManager, &SerialPortManager::connected, this, &MainWindow::updateStatusConnected);
    connect(serialManager, &SerialPortManager::disconnected, this, &MainWindow::updateStatusDisconnected);
    connect(serialManager, &SerialPortManager::errorOccurred, this, &MainWindow::handleError);

    refreshSerialPortInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete serialManager; // Nesneyi silmek için eklenen kod
}

void MainWindow::on_btnConnect_clicked()
{
    QString portName = ui->cmbPort->currentText();
    int baudRate = ui->cmbBaudRate->currentText().toInt();
    QSerialPort::DataBits dataBits = static_cast<QSerialPort::DataBits>(ui->cmbData->currentText().toInt());
    QSerialPort::StopBits stopBits = ui->cmbStop->currentText() == "1 Bit" ? QSerialPort::OneStop : QSerialPort::TwoStop;
    QSerialPort::Parity parity = ui->cmbParity->currentText() == "No Parity" ? QSerialPort::NoParity : QSerialPort::EvenParity; // Simplified for brevity
    QSerialPort::FlowControl flowControl = ui->cmbFlow->currentText() == "No Flow Control" ? QSerialPort::NoFlowControl : QSerialPort::HardwareControl;

    serialManager->connectPort(portName, baudRate, dataBits, stopBits, parity, flowControl);
}

void MainWindow::on_btnDisconnect_clicked()
{
    serialManager->disconnectPort();
}

void MainWindow::on_btnRefreshPorts_clicked()
{
    refreshSerialPortInfo();
}

void MainWindow::on_btnSend_clicked() {
    QString message = ui->lnMessage->text();
    if (!message.isEmpty()) {
        serialManager->sendMessage(message);
        ui->textBrowser->setTextColor(Qt::darkGreen);
        ui->textBrowser->append("Sent: " + message);
    }
}

void MainWindow::on_btnClear_clicked()
{
    ui->textBrowser->clear();
}

void MainWindow::receiveMessage(const QString &message)
{
    ui->textBrowser->setTextColor(Qt::blue);
    ui->textBrowser->append(message);
}

void MainWindow::updateStatusConnected()
{
    ui->textBrowser->setTextColor(Qt::darkGreen);
    ui->textBrowser->append("Connected");
}

void MainWindow::updateStatusDisconnected()
{
    ui->textBrowser->setTextColor(Qt::red);
    ui->textBrowser->append("Disconnected");
}


void MainWindow::handleError(const QString &error) {
    ui->textBrowser->setTextColor(Qt::red);
    ui->textBrowser->append("Error: " + error);
}

void MainWindow::refreshSerialPortInfo()
{
    ui->cmbPort->clear();
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {
        ui->cmbPort->addItem(port.portName());
    }

    ui->cmbBaudRate->clear(); // Baud rate listesini temizle
    QList<qint32> baudRates = QSerialPortInfo::standardBaudRates();
    for (int rate : baudRates) {
        ui->cmbBaudRate->addItem(QString::number(rate));
    }
}

























/*
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable maximizing
    setFixedSize(width(), height());

    // Adding title for widget
    QWidget::setWindowTitle("Serial Port Example");

    // Ports
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->cmbPort->addItems(stringPorts);

    // Baud Rate Ratios
    QList<qint32> baudRates = info.standardBaudRates(); // What baudrates does my computer support ?
    QList<QString> stringBaudRates;
    for(int i = 0 ; i < baudRates.size() ; i++){
        stringBaudRates.append(QString::number(baudRates.at(i)));
    }
    ui->cmbBaudRate->addItems(stringBaudRates);

    // Data Bits
    ui->cmbData->addItem("5");
    ui->cmbData->addItem("6");
    ui->cmbData->addItem("7");
    ui->cmbData->addItem("8");

    // Stop Bits
    ui->cmbStop->addItem("1 Bit");
    ui->cmbStop->addItem("2 Bits");

    // Parities
    ui->cmbParity->addItem("No Parity");
    ui->cmbParity->addItem("Even Parity");
    ui->cmbParity->addItem("Odd Parity");
    ui->cmbParity->addItem("Mark Parity");
    ui->cmbParity->addItem("Space Parity");

    //Flow Controls
    ui->cmbFlow->addItem("No Flow Control");
    ui->cmbFlow->addItem("Hardware Flow Control");
    ui->cmbFlow->addItem("Software Flow Control");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnConnect_clicked()
{
    QString portName = ui->cmbPort->currentText();
    serialPort.setPortName(portName);

    serialPort.open(QIODevice::ReadWrite);

    if (!serialPort.isOpen()) {
        ui->textBrowser->setTextColor(Qt::red);
        ui->textBrowser->append("Incorrect port entry!!");
    }
    else {
        // If the port opens successfully, display "Connected".
        ui->textBrowser->setTextColor(Qt::darkGreen);
        ui->textBrowser->append("Connected");

        QString stringbaudRate = ui->cmbBaudRate->currentText();
        int intbaudRate = stringbaudRate.toInt();
        serialPort.setBaudRate(intbaudRate);

        QString dataBits = ui->cmbData->currentText();
        if(dataBits == "5 Bits") {
            serialPort.setDataBits(QSerialPort::Data5);
        }
        else if((dataBits == "6 Bits")) {
            serialPort.setDataBits(QSerialPort::Data6);
        }
        else if(dataBits == "7 Bits") {
            serialPort.setDataBits(QSerialPort::Data7);
        }
        else if(dataBits == "8 Bits"){
            serialPort.setDataBits(QSerialPort::Data8);
        }

        QString stopBits = ui->cmbStop->currentText();
        if(stopBits == "1 Bit") {
            serialPort.setStopBits(QSerialPort::OneStop);
        }
        else if(stopBits == "1,5 Bits") {
            serialPort.setStopBits(QSerialPort::OneAndHalfStop);
        }
        else if(stopBits == "2 Bits") {
            serialPort.setStopBits(QSerialPort::TwoStop);
        }

        QString parity = ui->cmbParity->currentText();
        if(parity == "No Parity"){
            serialPort.setParity(QSerialPort::NoParity);
        }
        else if(parity == "Even Parity"){
            serialPort.setParity(QSerialPort::EvenParity);
        }
        else if(parity == "Odd Parity"){
            serialPort.setParity(QSerialPort::OddParity);
        }
        else if(parity == "Mark Parity"){
            serialPort.setParity(QSerialPort::MarkParity);
        }
        else if(parity == "Space Parity") {
            serialPort.setParity(QSerialPort::SpaceParity);
        }

        QString flowControl = ui->cmbFlow->currentText();
        if(flowControl == "No Flow Control") {
            serialPort.setFlowControl(QSerialPort::NoFlowControl);
        }
        else if(flowControl == "Hardware Flow Control") {
            serialPort.setFlowControl(QSerialPort::HardwareControl);
        }
        else if(flowControl == "Software Flow Control") {
            serialPort.setFlowControl(QSerialPort::SoftwareControl);
        }

        connect(&serialPort,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
    }
}


void MainWindow::on_btnDisconnect_clicked()
{
    serialPort.close();
}


void MainWindow::on_btnRefreshPorts_clicked()
{
    ui->cmbPort->clear();
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->cmbPort->addItems(stringPorts);
}


void MainWindow::on_btnSend_clicked()
{
    QString message = ui->lnMessage->text();
    ui->textBrowser->setTextColor(Qt::darkGreen); // Color of message to send is green.
    ui->textBrowser->append(message);
    serialPort.write(message.toUtf8());
}


void MainWindow::on_btnClear_clicked()
{
    ui->textBrowser->clear();
}

void MainWindow::receiveMessage()
{
    QByteArray dataBA = serialPort.readAll();
    QString data(dataBA);
    buffer.append(data);
    int index = buffer.indexOf(code);
    if(index != -1){
        QString message = buffer.mid(0,index);
        ui->textBrowser->setTextColor(Qt::blue); // Receieved message's color is blue.
        ui->textBrowser->append(message);
        buffer.remove(0,index+codeSize);
    }
}
*/
