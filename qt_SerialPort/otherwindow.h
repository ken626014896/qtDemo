#ifndef OTHERWINDOW_H
#define OTHERWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QCloseEvent>

#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QDataStream >
#include <QSettings>
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
        QString n1;
        QString n11;
        QString n2;
        QString n22;
        QString n3;
        QString n33;
        QString n4;
        QString n44;
        QString n5;
        QString n55;
        QString n6;
        QString n66;
        QString n7;
        QString n77;
    };
    void connectSLOT();//连接信号与槽
    void initParm();
    QString tenToHex(QString);
    QString tenToHex2(QString);
private slots:
    void on_getCmd();
    void on_btnBack_clicked();

    void closeEvent(QCloseEvent * e);//重载窗口关闭函数

    void on_btnRead_clicked();

    void on_btnSave_clicked();

    void on_btnWrite_clicked();

private:
    Ui::OtherWindow *ui;
    Settings settingA;
    Settings settingB;
    Settings settingC;
    Settings settingD;
    Settings_S settingAC;
    Settings_S settingBC;
    Settings_S settingCC;
    Settings_S settingDC;
signals:
    void cmd(QString);
};

#endif // OTHERWINDOW_H
