#ifndef RMB_H
#define RMB_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidgetItem>
#include <QTreeWidgetItem>
#include "helper.h"
namespace Ui {
class rmb;
}

class rmb : public QWidget
{
    Q_OBJECT

public:
    explicit rmb(QWidget *parent = 0);
    ~rmb();

private slots:
    void on_tijiao_clicked();

    void on_shanchu_clicked();

    void on_chaxun_clicked();

private:
    Ui::rmb *ui;
    QString database;
    QStringList title ;
    int  num=0;
    QVBoxLayout * layout;//料号
    helper help;
};

#endif // RMB_H
