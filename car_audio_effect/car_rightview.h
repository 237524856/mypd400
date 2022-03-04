#ifndef CAR_RIGHTVIEW_H
#define CAR_RIGHTVIEW_H

#include <QWidget>

class car_rightView : public QWidget
{
    Q_OBJECT
public:
    explicit car_rightView(QWidget *parent = nullptr);
    void createUI();

signals:


public slots:
    void shuchu_click();

};

#endif // CAR_RIGHTVIEW_H
