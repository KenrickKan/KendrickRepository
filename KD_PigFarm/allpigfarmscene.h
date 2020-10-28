#ifndef ALLPIGFARMSCENE_H
#define ALLPIGFARMSCENE_H

#include <QMainWindow>
#include <QPushButton>
#include "onepighome.h"

class allpigfarmscene : public QMainWindow
{
    Q_OBJECT
public:
    allpigfarmscene();

    void paintEvent(QPaintEvent *event);

    onepighome* kpighome [100];//初始化100个猪圈

    bool ifallpighomeinfected();
    void onpighomeinfectneiboronepighome(int num);//相邻猪圈比会被传染
    void bianlionepighomeinfect();
    void clearpighouse();


signals:

    void Backtomainscene();

public slots:
};

#endif // ALLPIGFARMSCENE_H
