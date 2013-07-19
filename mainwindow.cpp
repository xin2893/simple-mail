#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QDockWidget>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1000,600);
    createMenu();
    createContacts();

    //send mail init
    //sendMailProtocolInit();

    //mail init
    mailCmdInit();
    sendMailFlag = FALSE;
    sendRcptFlag = FALSE;
    sendUserFlag = FALSE;
    sendPasswdFlag = FALSE;
    sendDataFlag = FALSE;
    sendMailOverFlag = FALSE;
    sendMailContensFlag = FALSE;

    sendMailWidget = new Sendmail(mailAddr);
    connect(sendMailWidget, SIGNAL(sendClick(QByteArray,QByteArray,QByteArray,QByteArray))
            , this, SLOT(readDataFromSendMail(QByteArray,QByteArray,QByteArray,QByteArray)));

    connect(this, SIGNAL(sendOver()),sendMailWidget, SLOT(recvSendOverSlots()));
}

void MainWindow::mailCmdInit()
{
    /*  send mail cmd define*/
    helloCmd = "EHLO stephen\n";;
    authCmd = "AUTH LOGIN\n";
    userNameCmd = "dGVzdHN0ZXBoZW4=\n"; //teststephen ,for base64
    passwordCmd = "eGluNjUwNDA3\n";     //xin650407
    mailCmd = "MAIL From:<teststephen@163.com>\n";
    rcptCmd = "RCPT To:<289379297@qq.com>\n";
    dataCmd = "DATA\n";
    mailHeader = "From:teststephen@163.com \nTo:289379297@qq.com\nSubject:testing\n\n";
    mailBody = "test test test set set set \n.\n";
}

void MainWindow::sendMailProtocolInit()
{
    sendServer = new QTcpSocket(this);
    sendServName = "smtp.163.com";
    sendPort = 25;
    sendServer->connectToHost(sendServName,sendPort);

    connect(sendServer, SIGNAL(readyRead()), this, SLOT(readFromSendServSlot()));
    connect(sendServer, SIGNAL(connected()), this, SLOT(sendToSendServSlot()));
    connect(sendServer, SIGNAL(disconnected()), this, SLOT(disSendConnectHost()));
}

void MainWindow::recvMailProtocolInit()
{
    recvServer = new QTcpSocket(this);
    recvServName = "imap.163.com";
    recvPort = 143;
    recvServer->connectToHost(recvServName,recvPort);

    connect(recvServer, SIGNAL(readyRead()), this, SLOT(readFromRecvServSlot()));
    connect(recvServer, SIGNAL(connected()), this, SLOT(sendToRecvServSlot()));
    connect(recvServer, SIGNAL(disconnected()), this, SLOT(disRecvConnectHost()));
}

//send slot
void MainWindow::readFromSendServSlot()
{
    qDebug() << "readFromSendServSlot!";
    QString recvDate = sendServer->readAll();
    qDebug() << recvDate;
    QStringList slist = recvDate.split(QRegExp("\\W+"), QString::SkipEmptyParts);

    QString recv = slist[0];
    if(recv == "220"){
        sendServer->write(helloCmd);
    }else if(recv == "250"){
        if(sendMailFlag){
            sendServer->write(rcptCmd);
            sendMailFlag = FALSE;
            sendRcptFlag = TRUE;
        }else if(sendRcptFlag){
            sendServer->write(dataCmd);
            sendRcptFlag = FALSE;
        }else if(sendMailOverFlag){
            qDebug() << "send mail over";
            emit sendOver();
        }else{
            sendServer->write(authCmd);
            sendUserFlag = TRUE;
        }
    }else if(recv == "334"){
        if(sendUserFlag){
            sendServer->write(userNameCmd);
            sendUserFlag = FALSE;
            sendPasswdFlag = TRUE;
        }else if(sendPasswdFlag){
            sendServer->write(passwordCmd);
            sendPasswdFlag = FALSE;
        }else{
            qDebug() << "334 other";
        }
    }else if(recv == "235"){
        qDebug() << "OK ,go ahead for send mail";
        if(sendMailContensFlag){
            sendServer->write(mailCmd);
            sendMailFlag = TRUE;
        }
    }else if(recv == "354"){
        sendServer->write(mailHeader + mailBody);
        sendMailOverFlag = TRUE;
    }
}

void MainWindow::sendToSendServSlot()
{
    qDebug() << "sendToSendServSlot!";
}

void MainWindow::disSendConnectHost()
{
    qDebug() << "disconnected signal!";
}

//recv slot
void MainWindow::readFromRecvServSlot()
{
    qDebug() << "readFromRecvServSlot!";
}

void MainWindow::sendToRecvServSlot()
{
    qDebug() << "sendToRecvServSlot!";
}

void MainWindow::disRecvConnectHost()
{
    qDebug() << "disconnected signal!";
}

void MainWindow::createContacts()
{
    mailAddr.insert(QString("stephen"), QString("teststephen@163.com"));
}

void MainWindow::createMenu()
{
    file = ui->menuBar->addMenu(QString("file"));
    newMailAct = file->addAction("newMail");
    file->addAction("open");
    file->addSeparator();
    file->addAction("close");
    ui->menuBar->addMenu(QString("edit"));

    tools = ui->menuBar->addMenu(QString("tools"));
    toolContact = tools->addAction("contact");

    connect(toolContact, SIGNAL(triggered()), this, SLOT(openContact()));
    connect(newMailAct, SIGNAL(triggered()),this, SLOT(sendMailSlot()));
}

void MainWindow::createDockWidget()
{
    ReadMail *rm = new ReadMail(this);
    QDockWidget *dockWidget = new QDockWidget(tr("Dock Widget"),this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
                                Qt::RightDockWidgetArea);
    dockWidget->setWidget(rm);
    dockWidget->setFeatures(QDockWidget::DockWidgetVerticalTitleBar |
                            QDockWidget::DockWidgetClosable |
                            QDockWidget::DockWidgetMovable |
                            QDockWidget::DockWidgetFloatable);

    QDockWidget *dockWidget1 = new QDockWidget(tr("Dock1 Widget"), this);
    dockWidget1->setAllowedAreas(Qt::AllDockWidgetAreas);
    dockWidget1->setWidget(rm);

    addDockWidget(Qt::RightDockWidgetArea, dockWidget);
    addDockWidget(Qt::RightDockWidgetArea, dockWidget1);
}

/*  slot implementation  */
void MainWindow::openContact()
{
    contactWidget = new Contact();
    contactWidget->setWindowTitle(QString("Contact"));
    contactWidget->show();
}

/*  slot send mail */
void MainWindow::sendMailSlot()
{
    sendMailWidget->show();

}

void MainWindow::readDataFromSendMail(QByteArray fromAddr
                                      ,QByteArray toAddr
                                      ,QByteArray subject
                                      ,QByteArray content)
{
    qDebug() << fromAddr << toAddr << subject << content; //"test";
    //emit sendOver();
    sendMailContensFlag = TRUE;
    mailHeader = "From:teststephen@163.com \nTo:" + toAddr + "\nSubject:" + subject + "\n\n";
    mailBody = content + "\n.\n";

    //sendMailProtocolInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
