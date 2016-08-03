#ifndef ROTATERENDER_H
#define ROTATERENDER_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

namespace Ui {
class RotateRender;
}

class RotateRender : public QMainWindow
{
    Q_OBJECT

public:
    explicit RotateRender(QWidget *parent = 0);
    ~RotateRender();

protected:
    void paintEvent(QPaintEvent*);

    void timeOut();
private:
    Ui::RotateRender *ui;

    QTimer* timer;

    Qt::GlobalColor left;
    Qt::GlobalColor down;
    Qt::GlobalColor right;
    Qt::GlobalColor up;
    Qt::GlobalColor mid;

    int times;
};

#endif // ROTATERENDER_H
