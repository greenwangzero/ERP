#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "purchase.h"
#include "transform.h"
#include "api.h"
#include "rmb.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionTian_triggered();

    void on_second_triggered();

    void on_actionJin_triggered();

    void on_actionR_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
