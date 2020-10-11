#include "allpigfarmscene.h"
#include <QPainter>
#include <QPushButton>
allpigfarmscene::allpigfarmscene(QWidget *parent) : QMainWindow(parent)
{

    setFixedSize(600,950);//设置固定大小

    setWindowIcon(QIcon(":/Image/pigapp.jpg"));//设置图标

    setWindowTitle("KD's PigFarm");//设置窗口名

    //返回按钮
    QPushButton * backBtn = new QPushButton;
    backBtn->setStyleSheet("QPushButton{border:0px;}");
    QPixmap backpix;
    backpix.load(":/Image/BackButton.png");
    backBtn->setIcon(backpix);
    backBtn->setIconSize(QSize(backpix.width(),backpix.height()));
    backBtn->setFixedSize(backpix.width(),backpix.height());
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());

    //点击返回
    connect(backBtn,&QPushButton::clicked,[=](){
        //告诉主场景 我返回了，主场景监听返回按钮
        emit this->Backtomainscene();

    });


}

void allpigfarmscene::paintEvent(QPaintEvent *event)
{
    QPainter kpainter(this);
    QPixmap kpix;
    kpix.load(":/Image/muchangbackgaound.jpg");
    kpainter.drawPixmap(0,0,this->width(),this->height(),kpix);
}
