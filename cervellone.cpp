#include "cervellone.h"
#include "ui_cervellone.h"


Cervellone::Cervellone(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cervellone)
{
    ui->setupUi(this);


   /* QUrl url;
    url.setUrl("/home/andrea/prova.mp3");
    ui->videoPlayer->show();

    ui->videoPlayer->play(url);

*/

   load_video("/home/andrea/Scaricati/prova.mp4");
   start_video();
}

Cervellone::~Cervellone()
{
    delete ui;
}

void Cervellone::load_video(QString path){
    video_path.setUrl(path);
    ui->videoPlayer->show();
    ui->videoPlayer->load(video_path);
}

void Cervellone::start_video(){
    ui->videoPlayer->play();
}

void Cervellone::stop_video(){
    ui->videoPlayer->pause();
}
