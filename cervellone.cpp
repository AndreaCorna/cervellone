#include "cervellone.h"
#include "ui_cervellone.h"
#include "QMessageBox"


Cervellone::Cervellone(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cervellone)
{
    ui->setupUi(this);
    setup_database();
    setup_controllers();
   /* QUrl url;
    url.setUrl("/home/andrea/prova.mp3");
    ui->videoPlayer->show();

    ui->videoPlayer->play(url);

*/
    video_name = new QString("/home/andrea/Scaricati/prova.mp4");
   // load_video();
  //  start_video();
}

Cervellone::~Cervellone()
{
    delete ui;
}


void Cervellone::setup_database(){
    db = new database_controller();
}

void Cervellone::setup_controllers(){
    ui->stop_button->setEnabled(false);
    ui->play_button->setEnabled(false);
    ui->restart_button->setEnabled(false);
    ui->seekSlider->setEnabled(false);
    ui->videoPlayer->setVisible(false);
    ui->label_text->setVisible(false);
    ui->label_video->setVisible(false);

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
void Cervellone::next_question(){
    question *curr_quest = db->next_question();
    if(curr_quest==NULL){
        QMessageBox msgBox;
        msgBox.setText("Non esiste una domanda succesiva");
        msgBox.exec();
    }
    else
    {
        show_question(curr_quest);

    }
}
void Cervellone::prev_question(){
    question *curr_quest = db->prev_question();
    if(curr_quest==NULL){
        QMessageBox msgBox;
        msgBox.setText("Non esiste una domanda precedente");
        msgBox.exec();
    }
    else
    {
        show_question(curr_quest);
    }
}

void Cervellone::verify_answer(){
    QString answer = ui->comboBox->currentText();
    QString correct = db->get_current_question()->get_correct();
}

void Cervellone::show_question(question *curr_quest){
    ui->answer1_label->setText(curr_quest->get_answers().at(0));
    ui->answer2_label->setText(curr_quest->get_answers().at(1));
    ui->answer3_label->setText(curr_quest->get_answers().at(2));
    ui->answer4_label->setText(curr_quest->get_answers().at(3));
}

void Cervellone::show_answer(){
    question *curr_quest=db->get_current_question();
    QMessageBox msgBox;
    if (curr_quest==NULL){
        msgBox.setText("Nessuna domanda selezionata");
    }
    else{
        msgBox.setText("La risposta esatta e' la "+curr_quest->get_correct());
    }
    msgBox.exec();
}

void Cervellone::start_video(){
    ui->videoPlayer->play();
}

void Cervellone::stop_video(){
    ui->videoPlayer->pause();
}
