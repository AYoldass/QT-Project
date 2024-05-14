#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SerialPortMenager.h>>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnConnect_clicked();

    void on_btnDisconnect_clicked();

    void on_btnRefreshPorts_clicked();

    void on_btnSend_clicked();

    void on_btnClear_clicked();

    void receiveMessage(const QString &message); // Gelen mesajları işlemek için güncellenmiş slot

    void handleError(const QString &error); // Hata mesajlarını işlemek için yeni slot

    void updateStatusConnected(); // Bağlandı durumunu güncellemek için yeni slot

    void updateStatusDisconnected(); // Bağlantı kesildi durumunu güncellemek için yeni slot

private:
    Ui::MainWindow *ui;
    SerialPortManager *serialManager; // QSerialPort nesnesinin yerine SerialPortManager kullanılıyor
    QSerialPort serialPort;
    QSerialPortInfo info;
    QString buffer;
    QString code;
    int codeSize;

     void refreshSerialPortInfo();
};
#endif // MAINWINDOW_H


/*
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnConnect_clicked();

    void on_btnDisconnect_clicked();

    void on_btnRefreshPorts_clicked();

    void on_btnSend_clicked();

    void on_btnClear_clicked();

    void receiveMessage();

private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;
    QSerialPortInfo info;
    QString buffer;
    QString code;
    int codeSize;
};
#endif // MAINWINDOW_H
*/
