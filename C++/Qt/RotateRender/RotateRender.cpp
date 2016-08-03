#include "RotateRender.h"
#include "ui_RotateRender.h"
#include <QConicalGradient>

RotateRender::RotateRender(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RotateRender)
{
    ui->setupUi(this);

    times = 0;
//    up = Qt::red;
//    left = Qt::white;
//    down = Qt::blue;
//    right = Qt::green;
    up = Qt::red;
    left = Qt::white;
    down = Qt::white;
    right = Qt::white;
    mid = Qt::white;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RotateRender::timeOut);
    timer->start(200);
}

RotateRender::~RotateRender()
{
    delete ui;
}

void RotateRender::paintEvent(QPaintEvent*)
{
    QConicalGradient con_g;
    con_g.setCenter(QPoint(width() / 2, height() / 2));
    con_g.setColorAt(0, up);
    con_g.setColorAt(0.2, left);
    con_g.setColorAt(0.4, down);
    con_g.setColorAt(0.6,right);
    con_g.setColorAt(0.8, mid);
    con_g.setColorAt(1, up);

    QPoint center = QPoint(width() / 2, height() / 2);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.save();
    painter.setBrush(QBrush(con_g));
    painter.drawRoundRect(QRect(center - QPoint(80, 80), center + QPoint(80, 80)), 30, 30);
//    painter.drawEllipse(center, 80, 80);
    painter.restore();
    painter.setBrush(QBrush(Qt::white));
//    painter.drawEllipse(center, 60, 60);
    painter.drawRoundRect(QRect(center - QPoint(70, 70), center + QPoint(70, 70)), 30, 30);
}

void RotateRender::timeOut()
{
    switch (times) {
    case 0:
//        up = Qt::red;
//        left = Qt::white;
//        down = Qt::blue;
//        right = Qt::green;
        up = Qt::red;
        left = Qt::white;
        down = Qt::white;
        right = Qt::white;
        mid = Qt::white;
        break;
    case 1:
//        up = Qt::green;
//        left = Qt::red;
//        down = Qt::white;
//        right = Qt::blue;
        up = Qt::white;
        left = Qt::red;
        down = Qt::white;
        right = Qt::white;
         mid = Qt::white;
        break;
    case 2:
//        up = Qt::blue;
//        left = Qt::green;
//        down = Qt::red;
//        right = Qt::white;
        up = Qt::white;
        left = Qt::white;
        down = Qt::red;
        right = Qt::white;
         mid = Qt::white;
        break;
    case 3:
//        up = Qt::white;
//        left = Qt::blue;
//        down = Qt::green;
//        right = Qt::red;
        up = Qt::white;
        left = Qt::white;
        down = Qt::white;
        right = Qt::red;
         mid = Qt::white;
        break;
    case 4:
        up = Qt::white;
        left = Qt::white;
        down = Qt::white;
        right = Qt::white;
         mid = Qt::red;
    default:
        break;
    }
    times++;
    if(times == 5)
        times = 0;

    update();
}
