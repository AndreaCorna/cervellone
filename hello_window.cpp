#include "hello_window.h"
#include "ui_hello_window.h"

hello_window::hello_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hello_window)
{
    ui->setupUi(this);
}

hello_window::~hello_window()
{
    delete ui;
}
