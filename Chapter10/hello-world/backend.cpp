#include "backend.h"
#include <iio.h>

Backend::Backend(QObject *parent) :
    QObject(parent)
{
    iio_context* context = iio_create_local_context();
    iio_device* device = iio_context_find_device(context, "tsl2591");
    m_iioChannel = iio_device_find_channel(device, "illuminance", false);
}

QString Backend::lightIntensity()
{
    double intensity;
    iio_channel_attr_read_double(m_iioChannel, "input", &intensity);
    return QString::number(intensity, 'f', 1);
}
