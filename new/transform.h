#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QWidget>
#include <QHBoxLayout>
namespace Ui {
class transform;
}

class transform : public QWidget
{
    Q_OBJECT

public:
    explicit transform(QWidget *parent = 0);
    QHBoxLayout * layout ;
    ~transform();

private slots:
    void on_fhr_dateChanged(const QDate &date);

    void on_toolButton_3_clicked();

private:
    Ui::transform *ui;
};

#endif // TRANSFORM_H
