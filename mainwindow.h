#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetWork>
#include "contact.h"
#include "readmail.h"
#include "sendmail.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createDockWidget();
    void createMenu();
    void createContacts();
    void sendMailProtocolInit();
    void recvMailProtocolInit();
    void mailCmdInit();

public slots:
    void openContact();
    void sendMailSlot();
    //send
    void readFromSendServSlot();
    void sendToSendServSlot();
    void disSendConnectHost();
    
    //recv
    void readFromRecvServSlot();
    void sendToRecvServSlot();
    void disRecvConnectHost();

    //from sendMail widget
    void readDataFromSendMail(QByteArray,QByteArray,QByteArray,QByteArray);

signals:
    void sendOver();

private:
    Ui::MainWindow *ui;
    QMenu *file;
    QMenu *edit;
    QMenu *tools;
    QAction *toolContact;
    QAction *newMailAct;

    /*  other class  */
    Contact *contactWidget;
    Sendmail *sendMailWidget;

    /*  mail address container   */
    QMap<QString,QString> mailAddr;

    /*  connect send mail server  */
    QTcpSocket *sendServer;
    QString sendServName;
    qint64 sendPort;

    /*  send mail cmd define  */
    QByteArray helloCmd;
    QByteArray authCmd;
    QByteArray userNameCmd;
    QByteArray passwordCmd;
    QByteArray mailCmd;
    QByteArray rcptCmd;
    QByteArray dataCmd;
    QByteArray mailHeader;
    QByteArray mailBody;

    bool sendMailFlag;
    bool sendRcptFlag;
    bool sendUserFlag;
    bool sendPasswdFlag;
    bool sendDataFlag;
    bool sendMailOverFlag;
    bool sendMailContensFlag;

    /*  connetc recv mail server  */
    QTcpSocket *recvServer;
    QString recvServName;
    qint64 recvPort;
};

#endif // MAINWINDOW_H
