#ifndef COMMON_DATASOURCE_H
#define COMMON_DATASOURCE_H

#include <QObject>

class common_datasource : public QObject
{
    Q_OBJECT
public:
    explicit common_datasource(QObject *parent = nullptr);

signals:

};

#endif // COMMON_DATASOURCE_H
