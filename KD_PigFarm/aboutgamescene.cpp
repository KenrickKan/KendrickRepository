#include "aboutgamescene.h"
#include "kglobal.h"
#include <QIcon>
#include <QPainter>
#include <QLabel>
aboutgamescene::aboutgamescene(QWidget *parent) : QWidget(parent)
{

    setFixedSize(500,400);//设置固定大小

    setWindowIcon(QIcon(":/Image/pigtouming.png"));//

    setWindowTitle("KD's PigFarm");//设置窗口名

    QLabel * aboutgamescenelabel = new QLabel;
    aboutgamescenelabel->setParent(this);
    aboutgamescenelabel->setText("Created by Kan Dong");

    ///////////还没做完

}


void aboutgamescene::paintEvent(QPaintEvent *event)
{
    QPainter kpainter(this);
    QPixmap kpix;
    kpix.load(":/Image/muchangbackgaound.jpg");
    kpainter.drawPixmap(0,0,this->width(),this->height(),kpix);
}
