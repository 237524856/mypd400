QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basewindow.cpp \
    carEffect/animation_view.cpp \
    carEffect/car_effect_mainview.cpp \
    carEffect/chlider_curve_view.cpp \
    carEffect/curve_view.cpp \
    carEffect/dragpushbutton.cpp \
    car_leftview.cpp \
    car_mainwondow.cpp \
    car_midview.cpp \
    car_rightview.cpp \
    common_datasource.cpp \
    custom_list_item.cpp \
    fenpinqi_view.cpp \
    main.cpp \
    mainwindow.cpp \
    mix_view/mix_main_view.cpp \
    myline_edit.cpp \
    myline_edit2.cpp \
    mylist_view.cpp \
    mytitlebar.cpp \
    show_list_view.cpp \
    signal_view/main_signal_view.cpp \
    sub_custom_list_item.cpp \
    sub_show_list_view.cpp

HEADERS += \
    basewindow.h \
    carEffect/animation_view.h \
    carEffect/car_effect_mainview.h \
    carEffect/chlider_curve_view.h \
    carEffect/curve_view.h \
    carEffect/dragpushbutton.h \
    car_leftview.h \
    car_mainwondow.h \
    car_midview.h \
    car_rightview.h \
    common_datasource.h \
    custom_list_item.h \
    fenpinqi_view.h \
    mainwindow.h \
    mix_view/mix_main_view.h \
    myline_edit.h \
    myline_edit2.h \
    mylist_view.h \
    mytitlebar.h \
    show_list_view.h \
    signal_view/main_signal_view.h \
    sub_custom_list_item.h \
    sub_show_list_view.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
