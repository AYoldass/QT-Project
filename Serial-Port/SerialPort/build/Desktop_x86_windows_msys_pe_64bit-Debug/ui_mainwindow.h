/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnPortsInfo;
    QComboBox *cmbPorts;
    QPushButton *btnOpenPort;
    QPushButton *btnSend;
    QLineEdit *lnMessage;
    QListWidget *lstMessages;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnChangeSpeed;
    QSpinBox *spnSpeed;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnPortsInfo = new QPushButton(centralwidget);
        btnPortsInfo->setObjectName("btnPortsInfo");
        btnPortsInfo->setGeometry(QRect(70, 60, 75, 24));
        cmbPorts = new QComboBox(centralwidget);
        cmbPorts->setObjectName("cmbPorts");
        cmbPorts->setGeometry(QRect(160, 60, 171, 22));
        btnOpenPort = new QPushButton(centralwidget);
        btnOpenPort->setObjectName("btnOpenPort");
        btnOpenPort->setGeometry(QRect(350, 60, 75, 24));
        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName("btnSend");
        btnSend->setGeometry(QRect(350, 110, 75, 24));
        lnMessage = new QLineEdit(centralwidget);
        lnMessage->setObjectName("lnMessage");
        lnMessage->setGeometry(QRect(70, 110, 261, 22));
        lstMessages = new QListWidget(centralwidget);
        lstMessages->setObjectName("lstMessages");
        lstMessages->setGeometry(QRect(440, 60, 331, 291));
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName("btnStart");
        btnStart->setGeometry(QRect(140, 150, 141, 24));
        btnStop = new QPushButton(centralwidget);
        btnStop->setObjectName("btnStop");
        btnStop->setGeometry(QRect(140, 190, 141, 24));
        btnChangeSpeed = new QPushButton(centralwidget);
        btnChangeSpeed->setObjectName("btnChangeSpeed");
        btnChangeSpeed->setGeometry(QRect(140, 230, 141, 24));
        spnSpeed = new QSpinBox(centralwidget);
        spnSpeed->setObjectName("spnSpeed");
        spnSpeed->setGeometry(QRect(300, 230, 91, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnPortsInfo->setText(QCoreApplication::translate("MainWindow", "PORTS", nullptr));
        btnOpenPort->setText(QCoreApplication::translate("MainWindow", "OPEN", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        btnChangeSpeed->setText(QCoreApplication::translate("MainWindow", "CHANGE SPEED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
