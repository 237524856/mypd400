
#pragma once
#pragma execution_character_set("utf-8")
#ifndef MIX_MAIN_VIEW_H
#define MIX_MAIN_VIEW_H

#include <QMainWindow>

class mix_main_view : public QMainWindow
{
    Q_OBJECT
public:
    explicit mix_main_view(QWidget *parent = nullptr);

signals:

};

#endif // MIX_MAIN_VIEW_H
