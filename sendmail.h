#ifndef SENDMAIL_H
#define SENDMAIL_H

#include <QtWidgets>

namespace Ui {
class Sendmail;
}

class Sendmail : public QWidget
{
    Q_OBJECT
    
public:
    explicit Sendmail(QMap<QString,QString> &addresslist,QWidget *parent = 0);
    ~Sendmail();
    void signalAndSlots();

private slots:
    void sendMailSlots();
    void addFromAddrSlots();
    void addToAddrSlots();
    void recvSendOverSlots();

signals:
    void sendClick(QByteArray,QByteArray,QByteArray,QByteArray);
    
private:
    Ui::Sendmail *ui;
    QMap<QString,QString> s_mailAddr;

    /* mail contents */
    QByteArray fromAddr;
    QByteArray toAddr;
    QByteArray subject;
    QByteArray content;
};

#endif // SENDMAIL_H
