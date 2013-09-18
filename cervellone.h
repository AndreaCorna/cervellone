#ifndef CERVELLONE_H
#define CERVELLONE_H

#include <QMainWindow>
#include <QUrl>
#include <QString>
#include "database_controller.h"

namespace Ui {
class Cervellone;
}

class Cervellone : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Cervellone(QWidget *parent = 0);
    ~Cervellone();

public slots:
    void start_video();
    void stop_video();
    void next_question();
    void prev_question();
    void show_answer();
    
private:
    void show_question(question *curr_quest);
    void setup_controllers();
    void setup_database();
    void load_video();
    void load_question();
    Ui::Cervellone *ui;
    QUrl video_path;
    QString *video_name;
    database_controller* db;
};

#endif // CERVELLONE_H
