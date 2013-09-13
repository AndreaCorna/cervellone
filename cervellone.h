#ifndef CERVELLONE_H
#define CERVELLONE_H

#include <QMainWindow>

namespace Ui {
class Cervellone;
}

class Cervellone : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Cervellone(QWidget *parent = 0);
    ~Cervellone();
    
private:
    Ui::Cervellone *ui;
};

#endif // CERVELLONE_H
