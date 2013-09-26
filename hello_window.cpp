#include "hello_window.h"
#include "ui_hello_window.h"

hello_window::hello_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hello_window)
{
    ui->setupUi(this);
    QPixmap image("image/intro.jpg");
    ui->label_2->setPixmap(image);
    ui->label_2->setVisible(true);
}

hello_window::~hello_window()
{
    delete ui;
}

void hello_window::info(){
    QMessageBox::information(NULL,"Cervellone","Created by docs Fontana & Corna");
}

void hello_window::rules(){
    QMessageBox::information(NULL,"Regolamento","Created by docs Fontana & Corna");
}
