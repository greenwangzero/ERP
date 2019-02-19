#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    api *sample = new api;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionTian_triggered()
{
    purchase *purchase_page =  new purchase();
    setCentralWidget(purchase_page);
}

void MainWindow::on_second_triggered()
{
    transform *transform_page =  new transform();
    setCentralWidget(transform_page);
}

void MainWindow::on_actionJin_triggered()
{
    transform *transform_page =  new transform();
    setCentralWidget(transform_page);
}

void MainWindow::on_actionR_triggered()
{
    rmb *rmb_page =  new rmb();
    setCentralWidget(rmb_page);
}
