#ifndef MAIN_SIGNAL_VIEW_H
#define MAIN_SIGNAL_VIEW_H

#pragma once
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include <QButtonGroup>
#include <QLabel>

class main_signal_view : public QMainWindow
{
    Q_OBJECT
public:
    explicit main_signal_view(QWidget *parent = nullptr);

    QButtonGroup *m_buttonGroup;

    QLabel *m_left_label;
    QLabel *m_right_label;

signals:

};

#endif // MAIN_SIGNAL_VIEW_H
