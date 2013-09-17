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

private:
    bool openDB();
    void ask_db();

    QSqlDatabase db;
    QVector<question*> questions;
};

#endif // DATABASE_CONTROLLER_H
