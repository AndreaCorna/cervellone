#include "cervellone.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cervellone w;
    w.show();
    
    return a.exec();
}
