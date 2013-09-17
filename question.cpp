#include "question.h"

question::question(QString text, QString correct, QString type, QVector<QString> answers)
{
    this->text = text;
    this->correct_answer = correct;
    this->type = type;
    this->answers = answers;
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
