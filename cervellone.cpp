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
    ui->label_image->setVisible(false);
    ui->A->setStyleSheet("");
    ui->B->setStyleSheet("");
    ui->C->setStyleSheet("");
    ui->D->setStyleSheet("");

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
    QPushButton *clicked;
    if(db->get_current_question() != NULL){
        clicked = qobject_cast<QPushButton *>(sender());
        clicked->setStyleSheet("background-color: yellow");
        QString answer = sender()->objectName();
        QString correct = db->get_current_question()->get_correct();
        if(answer.compare(correct) == 0){
            clicked->setStyleSheet("background-color: green");
            Phonon::MediaObject *music =
            Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource("beep_tagliato.mp3"));
            music->play();
            QMessageBox::information(NULL,"Bravo","Bravo hai risposto bene!");
        }
        else{
          clicked->setStyleSheet("background-color: red");
          Phonon::MediaObject *music =
          Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource("beep_tagliato.mp3"));
          music->play();
          QMessageBox::information(NULL,"Coglione","Capra ignorante");

        }
   }
}

void Cervellone::show_question(question *curr_quest){

    setup_controllers();

    QString question_type = curr_quest->get_type();
    if (question_type=="t"){
        qDebug()<<curr_quest->get_text();
        ui->label_text->setText(QString("<p style=\" font-family: SansSerif; font-size: 0pt;margin-left: 20px; \">%1</p>").arg(curr_quest->get_text()));
        ui->label_text->setVisible(true);
        ui->label_video->setVisible(false);
    }
    else{
        ui->label_video->setText(curr_quest->get_text());
        ui->label_video->setVisible(true);
        ui->label_text->setVisible(false);

        qDebug()<<curr_quest->get_text();

    }
    ui->A->setText("A - "+curr_quest->get_answers().at(0));
    ui->B->setText("B - "+curr_quest->get_answers().at(1));
    ui->C->setText("C - "+curr_quest->get_answers().at(2));
    ui->D->setText("D - "+curr_quest->get_answers().at(3));

    if (question_type=="i"){
        image_name = curr_quest->get_file();
        load_question_image();
    }else if(question_type=="v"){
        video_name = curr_quest->get_file();
        load_question_video();
    }

}

void Cervellone::load_question_video(){

    //enable control buttons
    ui->stop_button->setEnabled(true);
    ui->play_button->setEnabled(true);
    ui->restart_button->setEnabled(true);
    ui->seekSlider->setEnabled(true);

    //load video
    video_path.setUrl(video_name);
    ui->videoPlayer->show();
    ui->videoPlayer->load(video_path);

    //load slider control
    Phonon::MediaObject *file = ui->videoPlayer->mediaObject();
    ui->seekSlider->setMediaObject(file);
    ui->seekSlider->show();

}


void Cervellone::load_question_image(){
    QPixmap image(image_name);
    ui->label_image->setPixmap(image);
    ui->label_image->setVisible(true);

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
