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
    question();
    QString get_type();
    QVector<QString*> get_answers();
    QString get_text();

private:
    QString text;
    QVector<QString*> answers;
    QString correct_answer;
    QString type;
};

#endif // QUESTION_H
