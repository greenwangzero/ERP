#include "purchase.h"
#include "ui_purchase.h"

#include <QDebug>
purchase::purchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::purchase)
{
    num=0;//料号数量
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    database = "G://new//purchase.accdb";
    help.showall(database,"purchase",ui->tableWidget);
    layout = new QVBoxLayout(ui->addwidget);//料号
    help.showtoget(1,ui->tableWidget);
    title<<"合同"<<"料号"<<"数量"<<"总长度"<<"美金单价"<<"美金总价"<<"汇率"<<"备注";
    ui->tableWidget->setHorizontalHeaderLabels(title);
    ui->addwidget->hide();
}

purchase::~purchase()
{
    delete ui;
}

void purchase::on_tijiao_clicked()
{
    QStringList item;
    item<<ui->hth->text()<<ui->lh->text()<<ui->sl->text();
    item<<ui->zcd->text()<<ui->mjdj->text()<<ui->mjzj->text();
    item<<ui->hl->text()<<ui->bz->text();
    help.inserttable(database,"purchase",item);
    if(num){
        QList<QLineEdit*> lineEditList = ui->addwidget->findChildren<QLineEdit*>();
        for(int i=0;i<lineEditList.size();i+=5){
            item.clear();
            item<<item<<ui->hth->text();
            for(int j=0;j<5;j++){
                QLineEdit *temp = lineEditList.at(i+j);
                item<<temp->text();
            }
            item<<ui->hl->text()<<ui->bz->text();
        }
        help.inserttable(database,"purchase",item);
    }
    help.showall(database,"purchase",ui->tableWidget);
    help.showtoget(1,ui->tableWidget);
    ui->tableWidget->setHorizontalHeaderLabels(title);
}

void purchase::on_chaxun_clicked()
{
    QString hth = ui->cxhth->text();
    QString lh=ui->cxlh->text();
    QStringList item,list;
    list<<"合同号"<<"料号";
    item<<ui->cxhth->text()<<ui->cxlh->text();
    help.selectAndShow(database,"purchase",list,item,ui->tableWidget);
    ui->tableWidget->setHorizontalHeaderLabels(title);
}
void purchase::on_tianjia_clicked(){

    ui->addwidget->show();
    num++;
    QHBoxLayout * layout1 = new QHBoxLayout;

    layout1->addWidget(new QLabel("料号"+QString::number(num)));
    //QLineEdit *lh=new QLineEdit;
    //lh->setObjectName("料号"+QString::number(num));
    layout1->addWidget(new QLineEdit);
    //layout1->addWidget(lh);
    layout1->addWidget(new QLabel("总长度"));
    layout1->addWidget(new QLineEdit);
    layout1->addWidget(new QLabel("数量"));
    layout1->addWidget(new QLineEdit);
    layout1->addWidget(new QLabel("美金单价"));
    layout1->addWidget(new QLineEdit);
    layout1->addWidget(new QLabel("美金总价"));
    layout1->addWidget(new QLineEdit);
    QToolButton *button = new QToolButton;
    //layout1->addWidget(new QToolButton);
    button->setText("删除");
    layout1->addWidget(button);
   // QToolButton *button = layout1->findChild<QToolButton*>();
   // connect(button,SIGNAL(clicked()), this, SLOT(ClickButton()));

    layout->addLayout(layout1);
    ui->addwidget->setLayout(layout);
}


void purchase::on_mjdj_textChanged(const QString &arg1)
{
    int dj=arg1.toInt();
    int number=ui->sl->text().toInt();
    int sum=dj*number;
    ui->mjzj->setText(QString::number(sum));
}

void purchase::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    qDebug() << item->column()<<" "<<item->row()<<endl;
    int row=item->row();
    /*int number=0;
    for(int i=row;i<ui->tableWidget->rowCount();i++){
        if(ui->tableWidget->itemAt(i,0)->text()==NULL){
            number++;
        }
    }
    qDebug()<<number;*/
    if(item->column()){

    }
    ui->hth->setText(ui->tableWidget->item(row,0)->text());
    ui->lh->setText(ui->tableWidget->item(row,1)->text());
    ui->sl->setText(ui->tableWidget->item(row,2)->text());
    ui->zcd->setText(ui->tableWidget->item(row,3)->text());
    ui->mjdj->setText(ui->tableWidget->item(row,4)->text());
    ui->mjzj->setText(ui->tableWidget->item(row,5)->text());
    ui->hl->setText(ui->tableWidget->item(row,6)->text());
    ui->bz->setText(ui->tableWidget->item(row,7)->text());
}

void purchase::on_shanchu_clicked()
{
    QString hth = ui->hth->text();
    QString lh = ui->lh->text();
    QString sl = ui->sl->text();
    QString zcd = ui->zcd->text();
    QString mjdj = ui->mjdj->text();
    QString mjzj = ui->mjzj->text();
    QString hl = ui->hl->text();
    QStringList item,list;
    list<<"合同号"<<"料号"<<"数量（卷）"<<"总长度（英尺）"<<"美金单价"<<"美金总价"<<"汇率"<<"备注";
    item<<ui->hth->text()<<ui->lh->text()<<ui->sl->text();
    item<<ui->zcd->text()<<ui->mjdj->text()<<ui->mjzj->text();
    item<<ui->hl->text()<<ui->bz->text();
    help.deletedata(database,"purchase",list,item,ui->tableWidget);
    help.showall(database,"purchase",ui->tableWidget);
    help.showtoget(1,ui->tableWidget);
    ui->tableWidget->setHorizontalHeaderLabels(title);
}

void purchase::on_sl_textChanged(const QString &arg1)
{
    int number=arg1.toInt();
    int dj=ui->mjdj->text().toInt();
    int sum=dj*number;
    ui->mjzj->setText(QString::number(sum));
}

