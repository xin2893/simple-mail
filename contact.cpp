#include "contact.h"

#include <QDebug>


Contact::Contact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContacTable)
{
    ui->setupUi(this);
    //listWidgetInit();
    //tableWidgetInit();
    uiContactTableInit();
    dataContactInit();
}

void Contact::dataContactInit()
{
    //read data from contact file
}

void Contact::uiContactTableInit()
{
    //table = new QTableWidget(this);

    ui->table->setColumnCount(2);
    ui->table->setRowCount(2);
    ui->table->setShowGrid(FALSE);
    //设置选择行为时每次选择一行
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置垂直头不可见
    ui->table->verticalHeader()->setVisible(false);
    //设置header自适应treeWidget
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //table->setFocus();
    ui->table->setFocusPolicy(Qt::NoFocus);

    QStringList headers;
    headers << "Mail" << "Name";
    ui->table->setHorizontalHeaderLabels(headers);

    QTableWidgetItem *item0 = new QTableWidgetItem("test");
    item0->setSelected(false);

    QTableWidgetItem *item1 = new QTableWidgetItem("aaaa");
    QTableWidgetItem *item2 = new QTableWidgetItem("test");
    QTableWidgetItem *item3 = new QTableWidgetItem("aaaa");
    ui->table->setItem(0,0,item0);
    ui->table->setItem(1,0,item1);
    ui->table->setItem(0,1,item2);
    ui->table->setItem(1,1,item3);

    //table->show();

    connect(ui->table, SIGNAL(cellClicked(int,int)),this,SLOT(tableProc()));
    connect(ui->addBtn, SIGNAL(clicked()),this,SLOT(addContactSlot()));
}

void Contact::addContactSlot()
{
    QTableWidgetItem *item1 = new QTableWidgetItem("email");
    QTableWidgetItem *item2 = new QTableWidgetItem("name");
    itemList.insert(0,item1);
    itemList.insert(0,item2);
    int row = ui->table->rowCount();
    ui->table->insertRow(row);
    //ui->table->setSelection();
    ui->table->setItem(row,0,item1);
    ui->table->setItem(row,1,item2);

}

void Contact::tableWidgetInit()
{
    glayout = new QGridLayout(this);
    table = new QTableWidget(this);

    table->setColumnCount(2);
    table->setRowCount(5);
    table->setShowGrid(FALSE);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行为时每次选择一行
    table->verticalHeader()->setVisible(false); //设置垂直头不可见
    //table->setFocus();
    table->setFocusPolicy(Qt::NoFocus);

    QStringList headers;
    headers << "Mail" << "Name";
    table->setHorizontalHeaderLabels(headers);

    table->setItem(0,0,new QTableWidgetItem("test"));
    table->setItem(1,0,new QTableWidgetItem("aaaa"));
    table->setItem(0,1,new QTableWidgetItem("test"));
    table->setItem(1,1,new QTableWidgetItem("aaaa"));

    //table->show();

    connect(table, SIGNAL(cellClicked(int,int)),this,SLOT(tableProc()));
}

void Contact::listWidgetInit()
{
    hlayout = new QHBoxLayout(this);
    //table = new QTableWidget(this);
    list = new QListWidget(this);

    litem0 = new QListWidgetItem("test0");
    litem1 = new QListWidgetItem("test1");
    litem2 = new QListWidgetItem("test2");
    litem3 = new QListWidgetItem("test3");
    litem4 = new QListWidgetItem("test4");

    list->insertItem(1, litem0);
    list->insertItem(2, litem1);
    list->insertItem(3, litem2);
    list->insertItem(4, litem3);
    list->insertItem(5, litem4);
    list->addItem("aaa");

    list->setViewMode(QListView::IconMode);
    list->setSelectionMode(QAbstractItemView::MultiSelection);

    hlayout->addWidget(list);

    setLayout(hlayout);

    connect(list, SIGNAL(clicked(QModelIndex)),this,SLOT(litem0Slot()));
}

void Contact::tableProc()
{
    QList<QTableWidgetItem*> litem = ui->table->selectedItems();
    if(!litem.isEmpty()){
        qDebug() << litem[0]->text();// << litem[1]->text();
    }
}

void Contact::litem0Slot()
{
    qDebug() << list->currentItem()->text();
}

Contact::~Contact()
{
    //save contact to contact file
}

