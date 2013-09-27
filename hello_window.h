#ifndef HELLO_WINDOW_H
#define HELLO_WINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

namespace Ui {
class hello_window;
}

class hello_window : public QDialog
{
    Q_OBJECT

public:
    explicit hello_window(QWidget *parent = 0);
    ~hello_window();

public slots:
    void info();
    void rules();

private:
    Ui::hello_window *ui;
};

#endif // HELLO_WINDOW_H
