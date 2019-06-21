#include "otherwindow.h"
#include "ui_otherwindow.h"

OtherWindow::OtherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OtherWindow)
{
    ui->setupUi(this);
    connectSLOT();
}

OtherWindow::~OtherWindow()
{
    delete ui;
    uint16_t a;
}

void OtherWindow::connectSLOT()
{

}


void OtherWindow::on_btnBack_clicked()
{
    hide();
}

void OtherWindow::on_pushButtonA_clicked()
{

     QString Subdivision=tenToHex(ui->lineEditA_Subdivision->text());
     QString MinRpmCw=tenToHex(ui->lineEditA_MinRpmCw->text());
     QString MaxRpmCw=tenToHex(ui->lineEditA_MaxRpmCw->text());
     QString MinRpmCcw=tenToHex(ui->lineEditA_MinRpmCcw->text());
     QString MaxRpmCcw=tenToHex(ui->lineEditA_MaxRpmCcw->text());
     QString ZeroCw=tenToHex(ui->lineEditA_ZeroCw->text());
     QString ZeroCcw=tenToHex(ui->lineEditA_ZeroCcw->text());

     QString settingCmd= QString("EE 53 01 10 00 00 %1 %2 %3 %4 %5 %6 %7 FF FC FF FF ").arg(Subdivision,MinRpmCw,
                                                                                            MaxRpmCw,MinRpmCcw,
                                                                                            MaxRpmCcw,ZeroCw,
                                                                                            ZeroCcw);
     emit cmd(settingCmd);

}

void OtherWindow::closeEvent(QCloseEvent *e)
{
    qDebug()<<"close";
}
QString OtherWindow::tenToHex(QString str)
{
    int dec = str.toInt();

    QString hex = QString("%1").arg(dec,4, 16, QChar('0'));  // 保留2位，不足补零

    return hex.toUpper().right(2)+hex.toUpper().left(2);
}
