#include "cervellone.h"
#include "ui_cervellone.h"

Cervellone::Cervellone(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cervellone)
{
    ui->setupUi(this);

}

Cervellone::~Cervellone()
{
    delete ui;
}
