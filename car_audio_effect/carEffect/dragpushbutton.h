#ifndef DRAGPUSHBUTTON_H
#define DRAGPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>

class dragpushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit dragpushbutton(QWidget *parent = nullptr);

    QPoint m_move_Point;
signals:
void refresh_btn_location(QPoint,QString);
void btn_press_location(QPoint,QString);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint pressPoint;


};

#endif // DRAGPUSHBUTTON_H
