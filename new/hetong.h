#ifndef HETONG_H
#define HETONG_H

#include <QFrame>

namespace Ui {
class hetong;
}

class hetong : public QFrame
{
    Q_OBJECT

public:
    explicit hetong(QWidget *parent = 0);
    ~hetong();

private:
    Ui::hetong *ui;
};

#endif // HETONG_H
