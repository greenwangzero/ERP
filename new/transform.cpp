#include "transform.h"
#include "ui_transform.h"
#include "hetong.h"
transform::transform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::transform)
{
    ui->setupUi(this);
}

transform::~transform()
{
    delete ui;
}

void transform::on_fhr_dateChanged(const QDate &date)
{
    QDate now = date;
    ui->fkqx->setDate(now.addDays(30));
}

void transform::on_toolButton_3_clicked()//添加合同
{
    QFrame *frame = new hetong;
    ui->addlayout->addWidget(frame);

}
