#ifndef PLANEMAINWIDGET_H
#define PLANEMAINWIDGET_H

#include <QWidget>
#include "planegamewidget.h"
class planemainwidget : public QWidget
{
    Q_OBJECT

public:
    planemainwidget(QWidget *parent = 0);
    ~planemainwidget();
private:
    planegamewidget *sonwidget;
    void paintEvent(QPaintEvent *ev);
};

#endif // PLANEMAINWIDGET_H
