#include "cervellone.h"
#include "ui_cervellone.h"


Cervellone::Cervellone(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cervellone)
{
    ui->setupUi(this);

    setup_controllers();
   /* QUrl url;
    url.setUrl("/home/andrea/prova.mp3");
    ui->videoPlayer->show();

    ui->videoPlayer->play(url);

*/
    video_name = new QString("/home/andrea/Scaricati/prova.mp4");
    load_video();
    start_video();
}

Cervellone::~Cervellone()
{
    delete ui;
}

void Cervellone::setup_controllers(){
    ui->stop_button->setEnabled(false);
    ui->play_button->setEnabled(false);
    ui->restart_button->setEnabled(false);
    ui->seekSlider->setEnabled(false);
}

void Cervellone::load_video(){

    //enable control buttons
    ui->stop_button->setEnabled(true);
    ui->play_button->setEnabled(true);
    ui->restart_button->setEnabled(true);
    ui->seekSlider->setEnabled(true);

    //load video
    video_path.setUrl(*video_name);
    ui->videoPlayer->show();
    ui->videoPlayer->load(video_path);
    //load slider control
    Phonon::MediaObject *file = ui->videoPlayer->mediaObject();
    ui->seekSlider->setMediaObject(file);
    ui->seekSlider->show();

}

void Cervellone::start_video(){
    ui->videoPlayer->play();
}

void Cervellone::stop_video(){
    ui->videoPlayer->pause();
}
