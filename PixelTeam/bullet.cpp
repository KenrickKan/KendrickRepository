#include "bullet.h"
Bullet::Bullet(int x,int y,QWidget *parent) : QLabel(parent)
{
    resize(13,13);
    this->setPixmap(QPixmap(":/img/bullet1.png").scaled(13,13));
    this->bulletx=x+28;
    this->bullety=y-18;
    this->move(bulletx,bullety);
    this->show();
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        static int id=0;
        this->id=id++;
        this->move(bulletx,bullety-=4);//每次timer响应，坐标减4，及子弹向上移动
        if(bullety<0){
             timer->stop();
             this->hide();
             for(int i=0;i<list->length();i++){
                 if(list->at(i)==this){
                     delete this;
                     list->removeAt(i);//当子弹移出屏幕外之后，上一步是删除这个子弹，然后remove这个子弹在list中的位置
                 }
             }
        }
    });
    timer->start(10);
}
void Bullet::setlist(QList<Bullet*> *list){
    this->list=list;
}
