#include "database_controller.h"

database_controller::database_controller()
{

    qDebug()<<openDB();
    QSqlQuery query(db);

    qDebug()<<query.exec("select * from cervellone");
    while(query.next()){
        qDebug()<<query.value(query.record().indexOf("Domanda")).toString();

    }
}
bool database_controller::openDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("prova_cervellone.sqlite3");
    return db.open();
}
