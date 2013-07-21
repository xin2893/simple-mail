#ifndef CONTACT_H
#define CONTACT_H

#include <QtWidgets>
#include "ui_contact.h"

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = 0);

    void dataContactInit();
    void listWidgetInit();
    void tableWidgetInit();
    void uiContactTableInit();
    ~Contact();

signals:
    
public slots:
    void litem0Slot();
    void tableProc();
    void addContactSlot();
private:
    Ui::ContacTable *ui;

    QTableWidget *table;
    QListWidget *list;
    QTreeWidget *tree;

    /* item */
    QListWidgetItem *litem0;
    QListWidgetItem *litem1;
    QListWidgetItem *litem2;
    QListWidgetItem *litem3;
    QListWidgetItem *litem4;

    QList<QTableWidgetItem *> itemList;

    /* layout */
    QHBoxLayout *hlayout;
    QGridLayout *glayout;
};

#endif // CONTACT_H
