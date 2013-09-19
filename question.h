#ifndef QUESTION_H
#define QUESTION_H

#include <map>
#include <time.h>
#include <QString>
#include "QDebug"
#include "QMap"

class question
{
public:
    question(QString text, QString correct, QString type, QVector<QString> answers);
    question(QString text, QString correct, QString type, QVector<QString> answers, QString file);
    QString get_type();
    QVector<QString> get_answers();
    QString get_text();
    QString get_correct();
    QString get_file();


private:
    QString text;
    QVector<QString> answers;
    QString correct_answer;
    QString type;
    QString name_file;
};

#endif // QUESTION_H
