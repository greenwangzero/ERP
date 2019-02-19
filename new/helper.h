#ifndef HELPER_H
#define HELPER_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QSqlError>
class helper
{
public:
    helper(){};

QString getsentence(QStringList list,char split=',',char add=NULL){
    QString sen;
    for(int i=0;i<list.size();i++){
        if(i){
            sen+=split;
        }
        if(add!=NULL){
            sen+=add+list[i]+add;
        }
    }
    return sen;
}
void settitle(QTableWidget *tableWidget,QStringList title){
    tableWidget->setHorizontalHeaderLabels(title);
}

void tablewidgetclean(QTableWidget *tableWidget){
    int tablerow = tableWidget->rowCount();
        tableWidget->clear();
        for (int n=0; n<tablerow; n++)
        {
            tableWidget->removeRow(0);
        }
}
void connection(QString *str){
    QString DBname = *str;   //数据库名字
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); //QODBC链接
    QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)}; FIL={MS Access};DBQ=%1;").arg(DBname);
    db.setDatabaseName(dsn);
    db.setUserName("");
    db.setPassword("");
    bool ok = db.open();  //判断是否链接成功
    if(!ok){
        //如果链接数据库成功，返回消息盒
        QMessageBox message;
        message.setText("databaes error");
        message.exec();
        db.close();
    }
}
void showall(QString str,QString table,QTableWidget *tableWidget){
    QString DBname = str;   //数据库名字
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); //QODBC链接
    QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)}; FIL={MS Access};DBQ=%1;").arg(DBname);
    db.setDatabaseName(dsn);
    db.setUserName("");
    db.setPassword("");
    bool ok = db.open();  //判断是否链接成功
    if(!ok){
        //如果链接数据库成功，返回消息盒
        QMessageBox message;
        message.setText("databaes error");
        message.exec();
        qDebug() << db.lastError();
        db.close();
    }

    QString sen="select * from " + table;
    QSqlQuery query;  //sql语句
    query.exec(sen);//从表sold中查询数据
    int col = query.record().count();//获得表单列数


    int i=0,j=0;
    tablewidgetclean(tableWidget);
    while(query.next()){ //遍历每一条数据
        tableWidget->insertRow(j); //插入新行
             for(i=0;i<col;i++){//把每一个单位中的数据展示到表单中
                 tableWidget->setItem(j,i,new QTableWidgetItem(query.value(i).toString()));
             }
             j++;
        }
    query.clear();
    db.close();
}
void showtoget(int num,QTableWidget *tableWidget){
    int row_count = tableWidget->rowCount();
        int col_count = tableWidget->columnCount();
        QString name;
        for(int i=0;i<num;i++){
            //name=tableWidget->item(0,i)->text();
            for(int j=0;j<row_count;j++){
                name=tableWidget->item(j,i)->text();
                int blank=1;
                int s_row=j;
                /*if(tableWidget->item(j,i)!=NULL&&tableWidget->item(j,i)->text()!= ""){
                     while(j+1<row_count&&(tableWidget->item(j+1,i)->text()== ""||tableWidget->item(j+1,i)->text()== "0")){
                         blank++;
                         j++;
                     }
                     tableWidget->setSpan(s_row,i,blank,1);
                }
                */
                while(j+1<row_count&&tableWidget->item(j+1,i)->text()==name){
                    blank++;
                    j++;
                }
                tableWidget->setSpan(s_row,i,blank,1);
                //name = tableWidget->item(j,i)->text();
            }
        }
}
void inserttable(QString str,QString table,QStringList headerList){
    QString DBname = str;   //数据库名字
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); //QODBC链接
    QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)}; FIL={MS Access};DBQ=%1;").arg(DBname);
    db.setDatabaseName(dsn);
    db.setUserName("");
    db.setPassword("");
    bool ok = db.open();  //判断是否链接成功
    if(!ok){
        //如果链接数据库成功，返回消息盒
        QMessageBox message;
        message.setText("databaes error");
        message.exec();
        qDebug() << db.lastError();
        db.close();
    }

    QString sen=QString("insert into %1 values(").arg(table);
    sen+="'"+headerList[0]+"'";
    for(int i=1;i<headerList.length();i++){
        sen+=",'"+headerList[i]+"'";
    }
    sen+=")";
    qDebug()<<sen;
    QSqlQuery query;  //sql语句
    query.exec(sen);//从表sold中查询数据

    db.close();

}


void selectAndShow(QString str,QString table,QStringList list,QStringList item,QTableWidget *tableWidget){
    QString DBname = str;   //数据库名字
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); //QODBC链接
    QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)}; FIL={MS Access};DBQ=%1;").arg(DBname);
    db.setDatabaseName(dsn);
    db.setUserName("");
    db.setPassword("");
    bool ok = db.open();  //判断是否链接成功
    if(!ok){
        //如果链接数据库成功，返回消息盒
        QMessageBox message;
        message.setText("databaes error");
        message.exec();
        qDebug() << db.lastError();
        db.close();
    }

    QString sen="select * ";
    sen+="from "+table+" where ";
    bool first=true;
    for(int i=0;i<list.size();i++){
         if(!first&&item[i]!=NULL)
         sen+=" AND "+list[i]+"='"+item[i]+"'";
         else if(item[i]!=NULL){
             sen+=list[i]+"='"+item[i]+"'";
             first = false;
         }
    }
    qDebug()<<sen;
    QSqlQuery query;  //sql语句
    query.exec(sen);//从表sold中查询数据
    int col = query.record().count();//获得表单列数
    int i=0,j=0;
    tablewidgetclean(tableWidget);
    while(query.next()){ //遍历每一条数据
        tableWidget->insertRow(j); //插入新行
             for(i=0;i<col;i++){//把每一个单位中的数据展示到表单中
                 tableWidget->setItem(j,i,new QTableWidgetItem(query.value(i).toString()));
             }
             j++;
        }
    query.clear();
    showtoget(1,tableWidget);
    db.close();
}
void deletedata(QString str,QString table,QStringList list,QStringList item,QTableWidget *tableWidget){
    QString DBname = str;   //数据库名字
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); //QODBC链接
    QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)}; FIL={MS Access};DBQ=%1;").arg(DBname);
    db.setDatabaseName(dsn);
    db.setUserName("");
    db.setPassword("");
    bool ok = db.open();  //判断是否链接成功
    if(!ok){
        //如果链接数据库成功，返回消息盒
        QMessageBox message;
        message.setText("databaes error");
        message.exec();
        qDebug() << db.lastError();
        db.close();
    }

    QString sen="delete ";
    sen+="from "+table+" where ";
    for(int i=0;i<list.size();i++){
         if(i&&item[i]!=NULL)
         sen+=" AND "+list[i]+"='"+item[i]+"'";
         else if(item[i]!=NULL)sen+=list[i]+"='"+item[i]+"'";
    }
    qDebug()<<sen;
    QSqlQuery query;  //sql语句
    query.exec(sen);//从表sold中查询数据
    int col = query.record().count();//获得表单列数
    int i=0,j=0;
    tablewidgetclean(tableWidget);
    while(query.next()){ //遍历每一条数据
        tableWidget->insertRow(j); //插入新行
             for(i=0;i<col;i++){//把每一个单位中的数据展示到表单中
                 tableWidget->setItem(j,i,new QTableWidgetItem(query.value(i).toString()));
             }
             j++;
        }
    query.clear();
    db.close();
}

};

#endif // HELPER_H
