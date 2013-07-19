#include "mainwindow.h"
#include "contact.h"
#include <QApplication>


//MainWindow
#define M_W 1

//contact
//#define C_W  1

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if M_W
    MainWindow w;
    w.show();
#endif


#if C_W
    Contact w;
    w.show();
#endif

    return a.exec();
}
