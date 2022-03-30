#ifndef MYLINE_EDIT2_H
#define MYLINE_EDIT2_H

#include <QWidget>
#include <QLineEdit>

class myline_edit2 : public QLineEdit
{
    Q_OBJECT
public:
    explicit myline_edit2(QWidget *parent = nullptr);
    void set_mystyle();
    void keyPressEvent(QKeyEvent *);

signals:

    void block_key_up(int);
    void block_key_down(int);

};

#endif // MYLINE_EDIT2_H
