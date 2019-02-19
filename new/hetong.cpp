#include "hetong.h"
#include "ui_hetong.h"

hetong::hetong(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::hetong)
{
    ui->setupUi(this);
}

hetong::~hetong()
{
    delete ui;
}
