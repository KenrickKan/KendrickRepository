#ifndef ALLPIGFARMSCENE_H
#define ALLPIGFARMSCENE_H

#include <QMainWindow>
#include <QPushButton>

class allpigfarmscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit allpigfarmscene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);


signals:

    void Backtomainscene();

public slots:
};

#endif // ALLPIGFARMSCENE_H
