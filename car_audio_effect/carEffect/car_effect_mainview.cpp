#include "car_effect_mainview.h"
#include "curve_view.h"

car_effect_mainView::car_effect_mainView(QWidget *parent) : QMainWindow(parent)
{

    this->setAttribute(Qt::WA_StyledBackground,true);
    this->setStyleSheet("background-color:yellow");

    this->resize(900,600);
    curve_view *view =new curve_view(this);
    view->resize(800,500);
    view->move(50,20);
    view->setStyleSheet("background-color:black");
    view->createUI();
}
