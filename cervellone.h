#ifndef CERVELLONE_H
#define CERVELLONE_H

#include <QMainWindow>
#include <QUrl>

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
    void load_video(QString path);
    void load_question();
    Ui::Cervellone *ui;
    QUrl video_path;
};

#endif // CERVELLONE_H
