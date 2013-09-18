#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H

#include <QVector>
#include "question.h"
#include <qsqldatabase.h>
#include <QDebug>
#include "QtSql/QtSql"

class database_controller
{
public:
    database_controller();
    question* next_question();
    question* prev_question();


private:
    bool openDB();
    void load_db();
    
    int curr_question;
    QSqlDatabase db;
    QVector<question*> questions;
};

#endif // DATABASE_CONTROLLER_H
