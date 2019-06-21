#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QLineEdit>
#include "otherwindow.h"
#include <QCloseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setSpinBox();

    void setReset();//清零
    void setGrid();//调正网格布局里面的控件位置
private slots:
    void on_pushButton_test_clicked();
    void serialPort_readyRead();
    void openserialPort();
    void closeserialPort();
    void on_timeReset();//位置清零的槽
    void on_positionReset();//时间清零的槽

    void on_noStopSend(); //不停的发送
    void on_btnA_up_slim_pressed();

    void on_btnA_up_slim_released();

    void on_pushButton_4_clicked(); //打开参数设置页面
    void closeEvent(QCloseEvent * e);//重载窗口关闭函数
    void on_sendSetttingCmd(QString);
private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTimer *timer;
    OtherWindow *otherwin;

};

#endif // MAINWINDOW_H
