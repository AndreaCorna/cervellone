#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H

#include <QVector>
#include "question.h"

class database_controller
{
public:
    database_controller();

private:
    QVector<question*> questions;
};

#endif // DATABASE_CONTROLLER_H
