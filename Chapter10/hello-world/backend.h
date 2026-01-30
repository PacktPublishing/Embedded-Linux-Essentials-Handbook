#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQmlEngine>

class Backend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString q_lightIntensity READ lightIntensity)

    QML_ELEMENT
public:
    explicit Backend(QObject *parent = nullptr);

    QString lightIntensity();
private:
    iio_channel *m_iioChannel;
    QString m_lightIntensity;
};

#endif // BACKEND_H
