#ifndef CAR_MIDVIEW_H
#define CAR_MIDVIEW_H

#include <QWidget>
#include <QLabel>

class car_midView : public QWidget
{
    Q_OBJECT
public:
    explicit car_midView(QWidget *parent = nullptr);


    void createUI();

signals:

};

#endif // CAR_MIDVIEW_H
