/********************************************************************************
** Form generated from reading UI file 'DeviveDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVIVEDIALOG_H
#define UI_DEVIVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviveDialog
{
public:
    QListWidget *lstMessages;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSend;
    QPushButton *btnConnect;
    QLineEdit *lnMessage;

    void setupUi(QDialog *DeviveDialog)
    {
        if (DeviveDialog->objectName().isEmpty())
            DeviveDialog->setObjectName("DeviveDialog");
        DeviveDialog->resize(544, 326);
        lstMessages = new QListWidget(DeviveDialog);
        lstMessages->setObjectName("lstMessages");
        lstMessages->setGeometry(QRect(60, 10, 256, 192));
        widget = new QWidget(DeviveDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(380, 10, 135, 84));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnSend = new QPushButton(widget);
        btnSend->setObjectName("btnSend");

        verticalLayout->addWidget(btnSend);

        btnConnect = new QPushButton(widget);
        btnConnect->setObjectName("btnConnect");

        verticalLayout->addWidget(btnConnect);

        lnMessage = new QLineEdit(widget);
        lnMessage->setObjectName("lnMessage");

        verticalLayout->addWidget(lnMessage);


        retranslateUi(DeviveDialog);

        QMetaObject::connectSlotsByName(DeviveDialog);
    } // setupUi

    void retranslateUi(QDialog *DeviveDialog)
    {
        DeviveDialog->setWindowTitle(QCoreApplication::translate("DeviveDialog", "Dialog", nullptr));
        btnSend->setText(QCoreApplication::translate("DeviveDialog", "SEND", nullptr));
        btnConnect->setText(QCoreApplication::translate("DeviveDialog", "CONNECT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviveDialog: public Ui_DeviveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVIVEDIALOG_H
