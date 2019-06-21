#ifndef OTHERWINDOW_H
#define OTHERWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCloseEvent>
namespace Ui {
class OtherWindow;
}
//电机参数设置界面类，包含电机各种参数
class OtherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OtherWindow(QWidget *parent = nullptr);
    ~OtherWindow();
    struct Settings {
        QString nSubdivision;
        QString nMinRpmCw;
        QString nMaxRpmCw;
        QString nMinRpmCcw;
        QString nMaxRpmCcw;
        QString nZeroCw;
        QString nZeroCcw;
    };
    struct Settings_S {
        QString nSubdivision;
        QString nMinRpmCw;
        QString nMaxRpmCw;
        QString nMinRpmCcw;
        QString nMaxRpmCcw;
        QString nZeroCw;
        QString nZeroCcw;
    };
    void connectSLOT();//连接信号与槽
    QString tenToHex(QString);
private slots:


    void on_btnBack_clicked();

    void on_pushButtonA_clicked();
    void closeEvent(QCloseEvent * e);//重载窗口关闭函数

private:
    Ui::OtherWindow *ui;
    Settings settingA;
    Settings settingB;
    Settings settingC;
    Settings settingD;
signals:
    void cmd(QString);
};

#endif // OTHERWINDOW_H
