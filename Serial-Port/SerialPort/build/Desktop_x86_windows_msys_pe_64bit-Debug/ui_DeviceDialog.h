/********************************************************************************
** Form generated from reading UI file 'DeviceDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEDIALOG_H
#define UI_DEVICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceDialog
{
public:
    QListWidget *lstMessages;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnConnect;
    QLineEdit *lnMessage;
    QPushButton *btnSend;
    QLabel *lblState;
    QLabel *label_2;
    QLabel *lblSpeed;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DeviceDialog)
    {
        if (DeviceDialog->objectName().isEmpty())
            DeviceDialog->setObjectName("DeviceDialog");
        DeviceDialog->resize(509, 372);
        lstMessages = new QListWidget(DeviceDialog);
        lstMessages->setObjectName("lstMessages");
        lstMessages->setGeometry(QRect(10, 10, 281, 341));
        widget = new QWidget(DeviceDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(300, 10, 201, 341));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnConnect = new QPushButton(widget);
        btnConnect->setObjectName("btnConnect");

        verticalLayout->addWidget(btnConnect);

        lnMessage = new QLineEdit(widget);
        lnMessage->setObjectName("lnMessage");

        verticalLayout->addWidget(lnMessage);

        btnSend = new QPushButton(widget);
        btnSend->setObjectName("btnSend");

        verticalLayout->addWidget(btnSend);

        lblState = new QLabel(widget);
        lblState->setObjectName("lblState");

        verticalLayout->addWidget(lblState);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lblSpeed = new QLabel(widget);
        lblSpeed->setObjectName("lblSpeed");

        verticalLayout->addWidget(lblSpeed);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(DeviceDialog);

        QMetaObject::connectSlotsByName(DeviceDialog);
    } // setupUi

    void retranslateUi(QDialog *DeviceDialog)
    {
        DeviceDialog->setWindowTitle(QCoreApplication::translate("DeviceDialog", "Dialog", nullptr));
        btnConnect->setText(QCoreApplication::translate("DeviceDialog", "CONNECT", nullptr));
        btnSend->setText(QCoreApplication::translate("DeviceDialog", "SEND", nullptr));
        lblState->setText(QCoreApplication::translate("DeviceDialog", "Device State: ", nullptr));
        label_2->setText(QCoreApplication::translate("DeviceDialog", "------------", nullptr));
        lblSpeed->setText(QCoreApplication::translate("DeviceDialog", "Device Speed:", nullptr));
        label_4->setText(QCoreApplication::translate("DeviceDialog", "------------", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceDialog: public Ui_DeviceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEDIALOG_H
