#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QLineEdit>
#include "otherwindow.h"
#include <QCloseEvent>
#include <QMessageBox>
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
    void sendCmd(QByteArray);//发送命令到下位机
    void connectSLOT();
    QString tenToHex(QString);
private slots:
    void on_pushButton_test_clicked();
    void serialPort_readyRead();
    void openserialPort();
    void closeserialPort();
    void on_timeReset();//位置清零的槽
    void on_positionReset();//时间清零的槽

    void on_noStopSend(); //不停的发送
    void btnSlim_pressed();
    void btnSlim_released();

    void on_pushButton_4_clicked(); //打开参数设置页面
    void closeEvent(QCloseEvent * e);//重载窗口关闭函数
    void on_sendSetttingCmd(QString);

    void on_sendPulse();


    void on_btn_switch_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTimer *timer;
    OtherWindow *otherwin;


    QByteArray byte;

};

#endif // MAINWINDOW_H
