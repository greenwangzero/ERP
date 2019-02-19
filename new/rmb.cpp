#include "rmb.h"
#include "ui_rmb.h"
#include <QDebug>
rmb::rmb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rmb)
{
    num=0;//料号数量
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    database = "G://new//purchase.accdb";
    help.helper::showall(database,"rmb",ui->tableWidget);
    layout = new QVBoxLayout(ui->addwidget);//料号
    help.helper::showtoget(1,ui->tableWidget);
    title<<"合同"<<"料号"<<"数量"<<"总长度"<<"人民币单价"<<"人民币总价"<<"备注";
    ui->tableWidget->setHorizontalHeaderLabels(title);
    ui->addwidget->hide();
    ui->setupUi(this);
}

rmb::~rmb()
{
    delete ui;
}

void rmb::on_tijiao_clicked()
{
    QStringList item;
    item<<ui->hth->text()<<ui->lh->text()<<ui->sl->text();
    item<<ui->zcd->text()<<ui->mjdj->text()<<ui->mjzj->text()<<ui->bz->text();
    help.helper::inserttable(database,"rmb",item);
    if(num){
        QList<QLineEdit*> lineEditList = ui->addwidget->findChildren<QLineEdit*>();
        for(int i=0;i<lineEditList.size();i+=5){
            item.clear();
            item<<item<<ui->hth->text();
            for(int j=0;j<5;j++){
                QLineEdit *temp = lineEditList.at(i+j);
                item<<temp->text();
            }
            item<<ui->bz->text();
        }
        help.inserttable(database,"rmb",item);
    }
    help.helper::showall(database,"rmb",ui->tableWidget);
    help.helper::showtoget(1,ui->tableWidget);
    ui->tableWidget->setHorizontalHeaderLabels(title);
}

void rmb::on_shanchu_clicked()
{
    QStringList item,list;
    list<<"合同号"<<"料号"<<"数量（卷）"<<"总长度（英尺）"<<"人民币单价"<<"人民币总价"<<"备注";
    item<<ui->hth->text()<<ui->lh->text()<<ui->sl->text();
    item<<ui->zcd->text()<<ui->mjdj->text()<<ui->mjzj->text()<<ui->bz->text();
    help.helper::deletedata(database,"rmb",list,item,ui->tableWidget);
    help.helper::showall(database,"rmb",ui->tableWidget);
    help.helper::showtoget(1,ui->tableWidget);
    ui->tableWidget->setHorizontalHeaderLabels(title);
}

void rmb::on_chaxun_clicked()
{
    QString hth = ui->cxhth->text();
    QString lh=ui->cxlh->text();
    QStringList item,list;
    list<<"合同号"<<"料号";
    item<<hth<<lh;
    help.helper::selectAndShow(database,"rmb",list,item,ui->tableWidget);
    ui->tableWidget->setHorizontalHeaderLabels(title);
}
