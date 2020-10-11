#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include <QDesktopWidget>
#include <QPushButton>
#include <QLabel>
#include "allpigfarmscene.h"
#include <QMovie>
#include "aboutgamescene.h"

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    setFixedSize(600,950);//设置固定大小

    QDesktopWidget *desktop = QApplication::desktop();
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2-40);//将窗口移至屏幕中间

    this->setWindowIcon(QIcon(":/Image/pigapp.jpg"));//设置图标

    this->setWindowTitle("KD's PigFarm");//设置窗口名

    QPushButton * newgame = new QPushButton;//设置主页三个按钮
    QPushButton * openoldgame = new QPushButton;
    QPushButton * aboutgame = new QPushButton;
    newgame->setParent(this);
    openoldgame->setParent(this);
    aboutgame->setParent(this);

    newgame->setText("开始新游戏");
    newgame->setFixedSize(150,80);
    newgame->setStyleSheet("QPushButton{"
                                        "border:3px solid black;"
                                        "border-radius:5px;"
                                        "font-family:'华文新魏';"
                                        "font-size:28px"
                                        "}");
    newgame->move(50,550);

    openoldgame->setText("打开存档");
    openoldgame->setFixedSize(150,80);
    openoldgame->setStyleSheet("QPushButton{"
                                        "border:3px solid black;"
                                        "border-radius:5px;"
                                        "font-family:'华文新魏';"
                                        "font-size:28px"
                                        "}");
    openoldgame->move(225,550);


    aboutgame->setText("关于游戏");
    aboutgame->setFixedSize(150,80);
    aboutgame->setStyleSheet("QPushButton{"
                                        "border:3px solid black;"
                                        "border-radius:5px;"
                                        "font-family:'华文新魏';"
                                        "font-size:28px"
                                        "}");
    aboutgame->move(400,550);

    QLabel * klabel = new QLabel;
    klabel->setParent(this);
    QFont kfont_about_klabel;
    kfont_about_klabel.setFamily("Brush Script MT");
    kfont_about_klabel.setPointSize(39);
    klabel->setFont(kfont_about_klabel);
    klabel->setText("Welcome to KD's PigFarm");//设置"Welcome to KD's PigFarm"标题
    klabel->move(10,-150);


    allpigfarmscene * kallpigfarmscene = new allpigfarmscene;

    connect(kallpigfarmscene,&allpigfarmscene::Backtomainscene,[=](){
        kallpigfarmscene->hide(); //将选择关卡场景 隐藏掉
        this->show(); //重新显示主场景
    });

    connect(newgame,&QPushButton::clicked,[=](){

        kallpigfarmscene->setGeometry(this->geometry());
        kallpigfarmscene->show();

        this->hide();

    });

    aboutgamescene * kaboutgamescene = new aboutgamescene;

    connect(aboutgame,&QPushButton::clicked,[=](){
        kaboutgamescene->show();
    });

}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter kpainter(this);
    QPixmap kpix;
    kpix.load(":/Image/timg.jpg");
    kpainter.drawPixmap(0,0,this->width(),this->height(),kpix);
    kpix.load(":/Image/tiantianyangzhutiantiankaixin.png");
    kpix = kpix.scaled(this->width(),kpix.height()*1.4);//图片缩放
    kpainter.drawPixmap(0,this->height()-kpix.height(),kpix.width(),kpix.height(),kpix);

}


MainScene::~MainScene()
{
    delete ui;
}
