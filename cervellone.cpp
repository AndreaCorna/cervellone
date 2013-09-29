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
    hello_window hello;
    hello.setModal(true);
    hello.exec();
    next_question();
}

Cervellone::~Cervellone()
{
    delete ui;
}


void Cervellone::setup_database(){
    db = new database_controller();
    number_question = 0;
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
    ui->question_frame->setStyleSheet("background-image: url(./image/back.png);background-repeat:repeat-x;");

}


void Cervellone::next_question(){

    number_question++;
    QString number = QString::number(number_question);
    ui->number_question_label->setText("Question "+number);
    question *curr_quest = db->next_question();
    if(curr_quest==NULL){
        QMessageBox msgBox;
        msgBox.setText("Non esiste una domanda succesiva");
        msgBox.exec();
    }
    else
    {
        if(ui->videoPlayer->isPlaying()){
            ui->videoPlayer->stop();
        }
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
    Phonon::MediaObject *attesa;
    if(db->get_current_question() != NULL){
        clicked = qobject_cast<QPushButton *>(sender());
        QString answer = sender()->objectName();
        QString correct = db->get_current_question()->get_correct();
        attesa =
        Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource("music/attesa_prova.mp3"));
        attesa->play();
        clicked->setStyleSheet("background-color: yellow");
        clicked->setUpdatesEnabled(true);
        update();
        qApp->processEvents();
        sleep(5);
        if(answer.compare(correct) == 0){
            attesa->stop();
            clicked->setStyleSheet("background-color: green");
            Phonon::MediaObject *music =
            Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource("music/corretta_finale.mp3"));
            music->play();
        }
        else{
          attesa->stop();
          clicked->setStyleSheet("background-color: red");
          Phonon::MediaObject *music =
          Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource("music/errore_finale.mp3"));
          music->play();
        }
   }
}

void Cervellone::show_question(question *curr_quest){

    setup_controllers();

    QString question_type = curr_quest->get_type();
    if (question_type=="t"){
        qDebug()<<curr_quest->get_text();
        ui->label_text->setText(curr_quest->get_text());
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
        qDebug()<<video_name;
        load_question_video();
    }

}

void Cervellone::load_question_video(){

    qDebug()<<QDir::currentPath();
    //enable control buttons
    ui->stop_button->setEnabled(true);
    ui->play_button->setEnabled(true);
    ui->restart_button->setEnabled(true);
    ui->seekSlider->setEnabled(true);

    //load video
    video_path.setUrl(video_name);
    qDebug()<<video_path;
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
