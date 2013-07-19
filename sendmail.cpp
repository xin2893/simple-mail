#include "sendmail.h"
#include "ui_sendmail.h"

Sendmail::Sendmail(QMap<QString,QString> &addresslist,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sendmail)
{
    ui->setupUi(this);
    setWindowTitle("Send Mail");

    //s_mailAddr["test"] = "tests";
    s_mailAddr = addresslist;
    signalAndSlots();
}

void Sendmail::signalAndSlots()
{
    connect(ui->sendBtn,SIGNAL(clicked()),this,SLOT(sendMailSlots()));
    connect(ui->addBtn, SIGNAL(clicked()),this,SLOT(addFromAddrSlots()));
    connect(ui->addBtn_2, SIGNAL(clicked()),this,SLOT(addToAddrSlots()));
}

/* recv from mainwindow */
void Sendmail::recvSendOverSlots()
{
    qDebug() << "test";
    ui->sendBtn->setEnabled(TRUE);
}

void Sendmail::sendMailSlots()
{
    QByteArray test("stephen");

    fromAddr = ui->mailFromAddrEdit->text().toUtf8();
    toAddr = ui->mailToAddrEdit->text().toUtf8();
    subject = ui->mailSubjectEdit->text().toUtf8();
    content = ui->contentsEdit->toPlainText().toUtf8();

    qDebug() << fromAddr << toAddr << subject << content;

    ui->sendBtn->setEnabled(FALSE);
    emit sendClick(fromAddr,toAddr,subject,content);
}

void Sendmail::addFromAddrSlots()
{
    //QString test = s_mailAddr["stephen"];
    ui->mailFromAddrEdit->insert("teststephen@163.com");
}

void Sendmail::addToAddrSlots()
{
    //QString test = s_mailAddr["stephen"];
    ui->mailToAddrEdit->insert("289379297@qq.com");
}

Sendmail::~Sendmail()
{
    delete ui;
}
