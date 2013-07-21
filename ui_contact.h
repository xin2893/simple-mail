/********************************************************************************
** Form generated from reading UI file 'Contact.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACT_H
#define UI_CONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContacTable
{
public:
    QTableWidget *table;
    QPushButton *addBtn;
    QPushButton *deleteBtn;

    void setupUi(QWidget *ContacTable)
    {
        if (ContacTable->objectName().isEmpty())
            ContacTable->setObjectName(QStringLiteral("ContacTable"));
        ContacTable->resize(400, 300);
        table = new QTableWidget(ContacTable);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(20, 30, 256, 192));
        addBtn = new QPushButton(ContacTable);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(290, 30, 75, 23));
        deleteBtn = new QPushButton(ContacTable);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setGeometry(QRect(290, 70, 75, 23));

        retranslateUi(ContacTable);

        QMetaObject::connectSlotsByName(ContacTable);
    } // setupUi

    void retranslateUi(QWidget *ContacTable)
    {
        ContacTable->setWindowTitle(QApplication::translate("ContacTable", "Contact", 0));
        addBtn->setText(QApplication::translate("ContacTable", "add", 0));
        deleteBtn->setText(QApplication::translate("ContacTable", "delete", 0));
    } // retranslateUi

};

namespace Ui {
    class ContacTable: public Ui_ContacTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACT_H
