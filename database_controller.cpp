﻿ #include "database_controller.h"

database_controller::database_controller()
{
    curr_question = -1;
    if(!openDB()){
        qDebug()<<"Database open error";
    }
    else{
        load_db();
    }
}

bool database_controller::openDB(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("prova_cervellone.sqlite3");
    return db.open();
}

void database_controller::load_db(){
    question *tmp;
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
        if ( type.compare("v") == 0 || type.compare("i") == 0){
            QString file = query.value(query.record().indexOf("File")).toString();
            tmp = new question(text,correct,type,answer,file);
        }
        else{
            tmp = new question(text,correct,type,answer);
        }
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

question* database_controller::next_question(){
    if(curr_question+1>questions.size()-1){
        return NULL;
    }
    else{
        curr_question++;
        return questions.value(curr_question);
    }
}

question* database_controller::get_current_question(){
    return questions.value(curr_question);
}

question* database_controller::prev_question(){
    if(curr_question-1<0){
        return NULL;
    }
    else{
        curr_question--;
        return questions.value(curr_question);
    }
}


