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
    QString rules;
    QFile rule_file("./rules.txt");
    if (rule_file.open(QIODevice::ReadOnly))
    {
        QTextStream data_stream(&rule_file);
        while ( !data_stream.atEnd() )
        {
            QString line = data_stream.readLine();
            rules.append("\n"+line);
        }
        QFont font("Times",16);
        QMessageBox box_rules;
        box_rules.setText(rules);
        box_rules.setFont(font);
        box_rules.exec();
        }else{
         QMessageBox::information(0, "error", rule_file.errorString());
    }

    rule_file.close();

}
