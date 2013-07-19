/********************************************************************************
** Form generated from reading UI file 'sendmail.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDMAIL_H
#define UI_SENDMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sendmail
{
public:
    QLineEdit *mailFromAddrEdit;
    QLabel *address;
    QPushButton *addBtn;
    QTextEdit *contentsEdit;
    QLabel *label;
    QPushButton *sendBtn;
    QLabel *address_2;
    QLineEdit *mailToAddrEdit;
    QPushButton *addBtn_2;
    QLabel *address_3;
    QLineEdit *mailSubjectEdit;

    void setupUi(QWidget *Sendmail)
    {
        if (Sendmail->objectName().isEmpty())
            Sendmail->setObjectName(QStringLiteral("Sendmail"));
        Sendmail->resize(700, 500);
        mailFromAddrEdit = new QLineEdit(Sendmail);
        mailFromAddrEdit->setObjectName(QStringLiteral("mailFromAddrEdit"));
        mailFromAddrEdit->setGeometry(QRect(110, 40, 321, 20));
        address = new QLabel(Sendmail);
        address->setObjectName(QStringLiteral("address"));
        address->setGeometry(QRect(50, 40, 31, 21));
        addBtn = new QPushButton(Sendmail);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(460, 40, 75, 23));
        contentsEdit = new QTextEdit(Sendmail);
        contentsEdit->setObjectName(QStringLiteral("contentsEdit"));
        contentsEdit->setGeometry(QRect(110, 130, 521, 311));
        label = new QLabel(Sendmail);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 130, 54, 16));
        sendBtn = new QPushButton(Sendmail);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(510, 452, 75, 31));
        address_2 = new QLabel(Sendmail);
        address_2->setObjectName(QStringLiteral("address_2"));
        address_2->setGeometry(QRect(50, 70, 31, 21));
        mailToAddrEdit = new QLineEdit(Sendmail);
        mailToAddrEdit->setObjectName(QStringLiteral("mailToAddrEdit"));
        mailToAddrEdit->setGeometry(QRect(110, 70, 321, 20));
        addBtn_2 = new QPushButton(Sendmail);
        addBtn_2->setObjectName(QStringLiteral("addBtn_2"));
        addBtn_2->setGeometry(QRect(460, 70, 75, 23));
        address_3 = new QLabel(Sendmail);
        address_3->setObjectName(QStringLiteral("address_3"));
        address_3->setGeometry(QRect(50, 100, 51, 21));
        mailSubjectEdit = new QLineEdit(Sendmail);
        mailSubjectEdit->setObjectName(QStringLiteral("mailSubjectEdit"));
        mailSubjectEdit->setGeometry(QRect(110, 100, 321, 20));

        retranslateUi(Sendmail);

        QMetaObject::connectSlotsByName(Sendmail);
    } // setupUi

    void retranslateUi(QWidget *Sendmail)
    {
        Sendmail->setWindowTitle(QApplication::translate("Sendmail", "Form", 0));
        mailFromAddrEdit->setText(QApplication::translate("Sendmail", "teststephen@163.com", 0));
        address->setText(QApplication::translate("Sendmail", "From", 0));
        addBtn->setText(QApplication::translate("Sendmail", "add", 0));
        label->setText(QApplication::translate("Sendmail", "contents", 0));
        sendBtn->setText(QApplication::translate("Sendmail", "send", 0));
        address_2->setText(QApplication::translate("Sendmail", "To", 0));
        mailToAddrEdit->setText(QString());
        addBtn_2->setText(QApplication::translate("Sendmail", "add", 0));
        address_3->setText(QApplication::translate("Sendmail", "Subject", 0));
        mailSubjectEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Sendmail: public Ui_Sendmail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDMAIL_H
