#ifndef PURCHASE_H
#define PURCHASE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidgetItem>
#include <QTreeWidgetItem>
#include "helper.h"
namespace Ui {
class purchase;
}

class purchase : public QWidget
{
    Q_OBJECT

public:
    explicit purchase(QWidget *parent = 0);
    ~purchase();

private slots:
    void on_tianjia_clicked();

    void on_tijiao_clicked();

    void on_chaxun_clicked();

    void on_mjdj_textChanged(const QString &arg1);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_shanchu_clicked();

    void on_sl_textChanged(const QString &arg1);

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::purchase *ui;
    QString database;
    QStringList title ;
    int  num=0;
    QVBoxLayout * layout;//料号
    helper help;
};

#endif // PURCHASE_H
