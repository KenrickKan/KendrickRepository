#include "allpigfarmscene.h"
#include "kglobal.h"
#include "kpig.h"
#include <QPainter>
#include <QPushButton>
#include "onepighome.h"
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
allpigfarmscene::allpigfarmscene()
{
        setFixedSize(600,950);//设置固定大小

        setWindowIcon(QIcon(":/Image/pigtouming.png"));//设置图标

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

            DateTimer->stop();

           //告诉主场景 我返回了，主场景监听返回按钮
            emit this->Backtomainscene();

            QFile kPigFarmFile("kPigFarmFile.txt");

            QTextStream out(&kPigFarmFile);

            kPigFarmFile.open(QIODevice::WriteOnly | QIODevice::Text);
            //kPigFarmFile.write();
            out<<DateTime<<endl;
            out<<AllMoney<<endl;
            for(int i=0;i<100;i++)
            {
                out<<i<<endl;
                for(int j=0;j<10;j++)
                {
                    out<<j<<endl;
                    out<<kpighome[i]->onepighomekpig[j]->weight<<endl;
                    out<<kpighome[i]->onepighomekpig[j]->day<<endl;
                    out<<kpighome[i]->onepighomekpig[j]->pigtype<<endl;
                    out<<kpighome[i]->onepighomekpig[j]->ifinfected<<endl;
                }

            }
            kPigFarmFile.close();

            //qDebug()<<DateTime<<endl;
            //qDebug()<<AllMoney<<endl;


        });

        QPushButton * pausebutton = new QPushButton;//////////暂停按钮
        pausebutton->setStyleSheet("QPushButton{border:0px;}");
        QPixmap pausepix;
        pausepix.load(":/Image/PauseButton.JPG");
        pausebutton->setIcon(pausepix);
        pausebutton->setIconSize(QSize(backpix.width(),backpix.height()));
        pausebutton->setFixedSize(backpix.width(),backpix.height());
        pausebutton->setParent(this);
        pausebutton->move(this->width() - pausebutton->width()-80 , this->height() - pausebutton->height());

        connect(pausebutton,&QPushButton::clicked,[=](){

            DateTimer->stop();

        });

        QPushButton * beginbutton = new QPushButton;///////////开始按钮
        beginbutton->setStyleSheet("QPushButton{border:0px;}");
        QPixmap beginpix;
        beginpix.load(":/Image/beginbutton.JPG");
        beginbutton->setIcon(beginpix);
        beginbutton->setIconSize(QSize(backpix.width(),backpix.height()));
        beginbutton->setFixedSize(backpix.width(),backpix.height());
        beginbutton->setParent(this);
        beginbutton->move(this->width() - beginbutton->width()-160 , this->height() - beginbutton->height());

        connect(beginbutton,&QPushButton::clicked,[=](){

            DateTimer->start(1000);

        });


        //static int DateTime = 1;//日期

        QLabel * DateLabel = new QLabel;//日期label
        DateLabel->setParent(this);
        QFont kfont_about_DateLabel;
        kfont_about_DateLabel.setFamily("Brush Script MT");//设置字体
        kfont_about_DateLabel.setPointSize(30);
        DateLabel->setFont(kfont_about_DateLabel);
        DateLabel->move(0,-200);
        connect(DateTimer,&QTimer::timeout,[=](){

            DateTime+=10;
            DateLabel->setText(QString("Day %1").arg(DateTime));//每秒增加10天
        });


        QLabel * AllMoneyLabel = new QLabel;//Money label
        AllMoneyLabel->setParent(this);
        AllMoneyLabel->setFont(kfont_about_DateLabel);
        AllMoneyLabel->move(0,-160);
        connect(DateTimer,&QTimer::timeout,[=](){
            AllMoneyLabel->setText(QString("Money:%1").arg(AllMoney));//每秒增加10天
        });


        connect(DateTimer,&QTimer::timeout,[=](){
            if(ifallpighomeinfected()==true)
            {
                overinfectday=DateTime;
                qDebug()<<overinfectday;
                DateTimer->stop();
                QMessageBox::information(this,"info",QString("从第%1天开始感染，在第%2天整个猪场全部被感染").arg(begininfectday).arg(overinfectday));
            }
        });


        for( int i = 0 ; i < 100 ;i ++)
        {
            onepighome * newpighome =new onepighome;
            kpighome[i]=newpighome;
        }


        for( int i = 0 ; i < 100 ;i ++)
        {
            QPushButton * pighome = new QPushButton;
            QPixmap menupix;
            menupix.load(":/Image/pighome.png");
            pighome->setFixedSize( menupix.width()/8,menupix.height()/8);
            //qDebug()<<menupix.width()/8<<" "<<menupix.height()/8<<endl;
            pighome->setStyleSheet("QPushButton{border:0px;}");
            pighome->setIcon(menupix);
            pighome->setParent(this);
            pighome->move(i % 10 * 55 + 20,i / 10 * 70 + 210);
            pighome->setIconSize(QSize(menupix.width()/8,menupix.height()/8));



            QLabel * kpighomePixLabel = new QLabel;//猪圈pix Label
            kpighomePixLabel->setParent(this);
            kpighomePixLabel->setFixedSize(61,53);
            kpighomePixLabel->move(i % 10 * 55 + 20,i / 10 * 70 + 210);
            kpighomePixLabel->setPixmap(kpighome[i]->kpighomepix);
            kpighomePixLabel->setScaledContents(true);
            //设置让鼠标进行穿透   51号属性
            kpighomePixLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
            connect(DateTimer,&QTimer::timeout,[=](){

                kpighomePixLabel->setPixmap(kpighome[i]->kpighomepix);
            });




            //监听每个按钮的点击事件
            connect(pighome,&QPushButton::clicked,[=](){
            //QString str = QString("您选择的是第 %1 关 ").arg( i + 1);
            //qDebug() <<str;


                kpighome[i]->setGeometry(this->geometry());
                kpighome[i]->show();
                this->hide();//点击进入游戏场景

                connect(kpighome[i],&onepighome::Backtoallpigfarmscene,[=](){
                    this->show();
                    kpighome[i]->hide();
                });//检测返回

            });

            QFont kfont_about_kpighomelabel;
            kfont_about_kpighomelabel.setFamily("Brush Script MT");//设置字体
            kfont_about_kpighomelabel.setPointSize(17);
            QLabel * kpighomelabel = new QLabel;
            kpighomelabel->setParent(this);
            kpighomelabel->setFixedSize(menupix.width()/8,menupix.height()/8);
            kpighomelabel->setFont(kfont_about_kpighomelabel);
            kpighomelabel->setText(QString::number(i));
            kpighomelabel->move(i % 10 * 55 + 20,i / 10 * 70 + 250);

            //设置 label上的文字对齐方式 水平居中和 垂直居中
            kpighomelabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            //设置让鼠标进行穿透   51号属性
            kpighomelabel->setAttribute(Qt::WA_TransparentForMouseEvents);


            connect(DateTimer,&QTimer::timeout,[=](){
                kpighome[i]->ifallinfected();
                kpighome[i]->ifpartinfected();
            });


        }


            connect(DateTimer,&QTimer::timeout,[=](){
                this->bianlionepighomeinfect();
            });




}


void allpigfarmscene::clearpighouse()
{

    for(int i=0;i<100;i++)
    {
        for(int j=0;j<10;j++)
        {
            kpig * temppig= kpighome[i]->onepighomekpig[j];
            delete temppig;
            kpighome[i]->onepighomekpig[j]=new kpig;
        }
    }
}

bool allpigfarmscene::ifallpighomeinfected()
{
    for(int i=0;i<100;i++)
    {
        if(kpighome[i]->ifallinfected()==false)
            return false;
    }
    return true;
}

void allpigfarmscene::onpighomeinfectneiboronepighome(int num)
{
    int P1,P2,P3,P4,P5,P6,P7,P8;
    P1=rand()%100;
    P2=rand()%100;
    P3=rand()%100;
    P4=rand()%100;
    P5=rand()%100;
    P6=rand()%100;
    P7=rand()%100;
    P8=rand()%100;
    int tenloc=num/10;//该猪圈编号的十位；
    int geloc=num-tenloc*10;
    if((tenloc-1)>=0)
    {
        if(kpighome[(tenloc-1)*10+geloc]->ifinfected==false&&(P1>=0)&&(P1<15))
            kpighome[(tenloc-1)*10+geloc]->onepigisinfected();//它的上方猪圈开始感染
        if((geloc-1)>=0)
            if(kpighome[(tenloc-1)*10+geloc-1]->ifinfected==false&&(P2>=0)&&(P2<15))
                kpighome[(tenloc-1)*10+geloc-1]->onepigisinfected();//左上方猪圈开始感染
        if((geloc+1)<=9)
            if(kpighome[(tenloc-1)*10+geloc+1]->ifinfected==false&&(P3>=0)&&(P3<15))
                kpighome[(tenloc-1)*10+geloc+1]->onepigisinfected();//右上方猪圈开始感染
    }
    if((tenloc+1)<=9)
    {
        if(kpighome[(tenloc+1)*10+geloc]->ifinfected==false&&(P4>=0)&&(P4<15))
            kpighome[(tenloc+1)*10+geloc]->onepigisinfected();//它的下方猪圈开始感染
        if((geloc-1)>=0)
            if(kpighome[(tenloc+1)*10+geloc-1]->ifinfected==false&&(P5>=0)&&(P5<15))
                kpighome[(tenloc+1)*10+geloc-1]->onepigisinfected();//左下方猪圈开始感染
        if((geloc+1)<=9)
            if(kpighome[(tenloc+1)*10+geloc+1]->ifinfected==false&&(P6>=0)&&(P6<15))
                kpighome[(tenloc+1)*10+geloc+1]->onepigisinfected();//右下方猪圈开始感染
    }
    if((geloc-1)>=0)
        if(kpighome[(tenloc)*10+geloc-1]->ifinfected==false&&(P7>=0)&&(P7<15))
            kpighome[(tenloc)*10+geloc-1]->onepigisinfected();//左方猪圈开始感染
    if((geloc+1)<=9)
        if(kpighome[(tenloc)*10+geloc+1]->ifinfected==false&&(P8>=0)&&(P8<15))
            kpighome[(tenloc)*10+geloc+1]->onepigisinfected();//右方猪圈开始感染

}

void allpigfarmscene::bianlionepighomeinfect()
{
    for(int i=0;i<100;i++)
    {
        if(kpighome[i]->ifinfected==true)
        {
            this->onpighomeinfectneiboronepighome(i);
        }
    }
}



void allpigfarmscene::paintEvent(QPaintEvent *event)
{
    QPainter kpainter(this);
    QPixmap kpix;
    kpix.load(":/Image/muchangbackgaound.jpg");
    kpainter.drawPixmap(0,0,this->width(),this->height(),kpix);
}
