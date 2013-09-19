#include "question.h"

question::question(QString text, QString correct, QString type, QVector<QString> answers)
{
    this->text = text;
    this->correct_answer = correct;
    this->type = type;
    this->answers = answers;
}

question::question(QString text, QString correct, QString type, QVector<QString> answers, QString file){
    this->text = text;
    this->correct_answer = correct;
    this->type = type;
    this->answers = answers;
    this->name_file = file;
}


QString question::get_type(){
    return type;
}

QVector<QString> question::get_answers(){
    return answers;
}

QString question::get_text(){
    return text;
}

QString question::get_correct(){
    return correct_answer;
}

QString question::get_file(){
    return name_file;
}
