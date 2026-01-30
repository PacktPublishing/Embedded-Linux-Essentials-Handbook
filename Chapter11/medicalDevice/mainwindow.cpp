#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iio_context* context = iio_create_local_context();
    iio_device* device = iio_context_find_device(context, "tsl2591");
    m_iioChannel = iio_device_find_channel(device, "illuminance", false);

    lightTimer = new QTimer(this);
    lightTimer->setInterval(1000);
    lightTimer->start();

    connect(lightTimer, SIGNAL(timeout()), this, SLOT(getLightIntensity()));

    threshold = 0;
    currentAlarmState = ALARM_STATE_GREEN;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getLightIntensity()
{
    double intensity;
    iio_channel_attr_read_double(m_iioChannel, "input", &intensity);

    ui->lightIntensity->setText(QString::number(intensity, 'f', 1));

    if (intensity < threshold) {
        currentAlarmState = ALARM_STATE_RED;
        ui->Status->setStyleSheet("background-color: red");
    }
}

void MainWindow::on_setButton_clicked()
{
    threshold = ui->Threshold->toPlainText().toDouble();
}

void MainWindow::on_clearButton_clicked()
{
    ui->Status->setStyleSheet("background-color: green");
    currentAlarmState = ALARM_STATE_GREEN;
}

