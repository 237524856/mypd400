
#pragma once
#pragma execution_character_set("utf-8")

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include "QDesktopWidget"
#include <QFontDatabase>
#include <QDebug>
#include <QStandardPaths>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : basewindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont(":/image/MBS_400/SourceHanSansCN Medium.ttf");
    setFixedSize(1023,737);

//    QLabel *back_left_image = new QLabel(this);
//    back_left_image->resize(this->width(),this->height());
//    back_left_image->move(0,0);
   // back_left_image->setPixmap(QPixmap(":/images/bg_image.png"));

    //this->setWindowIcon(QIcon(":/images/logo.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

