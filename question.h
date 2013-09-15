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

private:
    QHash<QString,QString> information;
};

#endif // QUESTION_H
