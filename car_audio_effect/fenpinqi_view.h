#ifndef FENPINQI_VIEW_H
#define FENPINQI_VIEW_H

#include <QWidget>
#include <QPushButton>

class fenpinqi_view : public QPushButton
{
    Q_OBJECT
public:
    explicit fenpinqi_view(QWidget *parent = nullptr);

signals:

};

#endif // FENPINQI_VIEW_H
