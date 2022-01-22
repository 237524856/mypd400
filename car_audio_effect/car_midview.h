#ifndef CAR_MIDVIEW_H
#define CAR_MIDVIEW_H

#include <QWidget>
#include <QLabel>
#include <QButtonGroup>
#include <QCheckBox>

class car_midView : public QWidget
{
    Q_OBJECT
public:
    explicit car_midView(QWidget *parent = nullptr);


    void createUI();

    QButtonGroup *m_buttonGroup;

    QLabel *m_top_image;

    QLabel *m_back_left_image;


public slots:
void dianpin_click_status(bool);
void guanbi_click_status(bool);
void mute_click(int);
void guanbi_btn_click(int);

signals:

};

#endif // CAR_MIDVIEW_H
