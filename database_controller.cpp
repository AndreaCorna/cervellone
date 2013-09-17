#include "database_controller.h"

database_controller::database_controller()
{

    qDebug()<<openDB();
    ask_db();
}

bool database_controller::openDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("prova_cervellone.sqlite3");
    return db.open();
}

void database_controller::ask_db(){

    QSqlQuery query(db);
    qDebug()<<query.exec("select * from cervellone");
    while(query.next()){
        QVector<QString> answer;
        answer.append(query.value(query.record().indexOf("A")).toString());
        answer.append(query.value(query.record().indexOf("B")).toString());
        answer.append(query.value(query.record().indexOf("C")).toString());
        answer.append(query.value(query.record().indexOf("D")).toString());
        QString text = query.value(query.record().indexOf("Domanda")).toString();
        QString correct = query.value(query.record().indexOf("Corretta")).toString();
        QString type = query.value(query.record().indexOf("Tipo")).toString();

        question *tmp = new question(text,correct,type,answer);
        questions.append(tmp);
        qDebug()<<query.value(query.record().indexOf("Domanda")).toString();
        qDebug()<<query.value(query.record().indexOf("Corretta")).toString();
        qDebug()<<query.value(query.record().indexOf("A")).toString();
        qDebug()<<query.value(query.record().indexOf("B")).toString();
        qDebug()<<query.value(query.record().indexOf("C")).toString();
        qDebug()<<query.value(query.record().indexOf("D")).toString();
        qDebug()<<query.value(query.record().indexOf("Tipo")).toString();
    }
}
