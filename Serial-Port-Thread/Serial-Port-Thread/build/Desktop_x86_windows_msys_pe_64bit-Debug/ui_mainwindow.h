/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lnMessage;
    QPushButton *btnSend;
    QPushButton *btnClear;
    QPushButton *btnConnect;
    QPushButton *btnDisconnect;
    QPushButton *btnRefreshPorts;
    QTextBrowser *textBrowser;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *lblPoert;
    QComboBox *cmbPort;
    QLabel *lblBaudRate;
    QComboBox *cmbBaudRate;
    QLabel *lblData;
    QComboBox *cmbData;
    QLabel *lblStop;
    QComboBox *cmbStop;
    QLabel *lblParity;
    QComboBox *cmbParity;
    QLabel *lblFlow;
    QComboBox *cmbFlow;
    QLabel *lblCode;
    QLineEdit *lnCode;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(717, 441);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lnMessage = new QLineEdit(centralwidget);
        lnMessage->setObjectName(QString::fromUtf8("lnMessage"));
        lnMessage->setGeometry(QRect(260, 340, 301, 31));
        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(580, 340, 111, 31));
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(580, 10, 111, 31));
        btnConnect = new QPushButton(centralwidget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(20, 310, 101, 31));
        btnDisconnect = new QPushButton(centralwidget);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));
        btnDisconnect->setGeometry(QRect(130, 310, 101, 31));
        btnRefreshPorts = new QPushButton(centralwidget);
        btnRefreshPorts->setObjectName(QString::fromUtf8("btnRefreshPorts"));
        btnRefreshPorts->setGeometry(QRect(70, 350, 111, 31));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(260, 50, 431, 271));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(8, 50, 241, 241));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lblPoert = new QLabel(widget);
        lblPoert->setObjectName(QString::fromUtf8("lblPoert"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblPoert);

        cmbPort = new QComboBox(widget);
        cmbPort->setObjectName(QString::fromUtf8("cmbPort"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cmbPort);

        lblBaudRate = new QLabel(widget);
        lblBaudRate->setObjectName(QString::fromUtf8("lblBaudRate"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblBaudRate);

        cmbBaudRate = new QComboBox(widget);
        cmbBaudRate->setObjectName(QString::fromUtf8("cmbBaudRate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cmbBaudRate);

        lblData = new QLabel(widget);
        lblData->setObjectName(QString::fromUtf8("lblData"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblData);

        cmbData = new QComboBox(widget);
        cmbData->setObjectName(QString::fromUtf8("cmbData"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cmbData);

        lblStop = new QLabel(widget);
        lblStop->setObjectName(QString::fromUtf8("lblStop"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblStop);

        cmbStop = new QComboBox(widget);
        cmbStop->setObjectName(QString::fromUtf8("cmbStop"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cmbStop);

        lblParity = new QLabel(widget);
        lblParity->setObjectName(QString::fromUtf8("lblParity"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lblParity);

        cmbParity = new QComboBox(widget);
        cmbParity->setObjectName(QString::fromUtf8("cmbParity"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cmbParity);

        lblFlow = new QLabel(widget);
        lblFlow->setObjectName(QString::fromUtf8("lblFlow"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lblFlow);

        cmbFlow = new QComboBox(widget);
        cmbFlow->setObjectName(QString::fromUtf8("cmbFlow"));

        formLayout->setWidget(5, QFormLayout::FieldRole, cmbFlow);

        lblCode = new QLabel(widget);
        lblCode->setObjectName(QString::fromUtf8("lblCode"));

        formLayout->setWidget(6, QFormLayout::LabelRole, lblCode);

        lnCode = new QLineEdit(widget);
        lnCode->setObjectName(QString::fromUtf8("lnCode"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lnCode);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(7, QFormLayout::FieldRole, verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 717, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        btnConnect->setText(QCoreApplication::translate("MainWindow", "CONNECT", nullptr));
        btnDisconnect->setText(QCoreApplication::translate("MainWindow", "DISCONNECT", nullptr));
        btnRefreshPorts->setText(QCoreApplication::translate("MainWindow", "REFRESH PORT", nullptr));
        lblPoert->setText(QCoreApplication::translate("MainWindow", "Port : ", nullptr));
        lblBaudRate->setText(QCoreApplication::translate("MainWindow", "Baud Rate : ", nullptr));
        lblData->setText(QCoreApplication::translate("MainWindow", "Data Bits :", nullptr));
        lblStop->setText(QCoreApplication::translate("MainWindow", "Stop Bits : ", nullptr));
        lblParity->setText(QCoreApplication::translate("MainWindow", "Parity :", nullptr));
        lblFlow->setText(QCoreApplication::translate("MainWindow", "Flow Ctrl :", nullptr));
        lblCode->setText(QCoreApplication::translate("MainWindow", "Code : ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
