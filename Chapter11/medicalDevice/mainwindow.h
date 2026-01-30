#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <iio.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void getLightIntensity();
    void on_setButton_clicked();
    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    iio_channel *m_iioChannel;
    QTimer *lightTimer;

    typedef enum {
        ALARM_STATE_GREEN,
        ALARM_STATE_RED,
    } AlarmState_e;

    AlarmState_e currentAlarmState;
    double threshold;
};
#endif // MAINWINDOW_H
