#ifndef CERVELLONE_H
#define CERVELLONE_H

#include <QMainWindow>
#include <QUrl>
#include <QString>

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
    
private:
    void setup_controllers();
    void load_video();
    void load_question();
    Ui::Cervellone *ui;
    QUrl video_path;
    QString *video_name;
};

#endif // CERVELLONE_H
