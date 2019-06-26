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
    connect(ui->pushButtonA,SIGNAL(clicked()),this,SLOT(on_getCmd()));
    connect(ui->pushButtonB,SIGNAL(clicked()),this,SLOT(on_getCmd()));
    connect(ui->pushButtonC,SIGNAL(clicked()),this,SLOT(on_getCmd()));
    connect(ui->pushButtonD,SIGNAL(clicked()),this,SLOT(on_getCmd()));

    connect(ui->pushButtonAC,SIGNAL(clicked()),this,SLOT(on_getCmd()));
    connect(ui->pushButtonBC,SIGNAL(clicked()),this,SLOT(on_getCmd()));
    connect(ui->pushButtonCC,SIGNAL(clicked()),this,SLOT(on_getCmd()));
    connect(ui->pushButtonDC,SIGNAL(clicked()),this,SLOT(on_getCmd()));


}

void OtherWindow::initParm()
{
    settingA.nSubdivision=ui->lineEditA_Subdivision->text();
    settingA.nMinRpmCw=ui->lineEditA_MinRpmCw->text();
    settingA.nMaxRpmCw=ui->lineEditA_MaxRpmCw->text();
    settingA.nMinRpmCcw=ui->lineEditA_MinRpmCcw->text();
    settingA.nMaxRpmCcw=ui->lineEditA_MaxRpmCcw->text();
    settingA.nZeroCw=ui->lineEditA_ZeroCw->text();
    settingA.nZeroCcw=ui->lineEditA_ZeroCcw->text();

    settingB.nSubdivision=ui->lineEditB_Subdivision->text();
    settingB.nMinRpmCw=ui->lineEditB_MinRpmCw->text();
    settingB.nMaxRpmCw=ui->lineEditB_MaxRpmCw->text();
    settingB.nMinRpmCcw=ui->lineEditB_MinRpmCcw->text();
    settingB.nMaxRpmCcw=ui->lineEditB_MaxRpmCcw->text();
    settingB.nZeroCw=ui->lineEditB_ZeroCw->text();
    settingB.nZeroCcw=ui->lineEditB_ZeroCcw->text();

    settingC.nSubdivision=ui->lineEditC_Subdivision->text();
    settingC.nMinRpmCw=ui->lineEditC_MinRpmCw->text();
    settingC.nMaxRpmCw=ui->lineEditC_MaxRpmCw->text();
    settingC.nMinRpmCcw=ui->lineEditC_MinRpmCcw->text();
    settingC.nMaxRpmCcw=ui->lineEditC_MaxRpmCcw->text();
    settingC.nZeroCw=ui->lineEditC_ZeroCw->text();
    settingC.nZeroCcw=ui->lineEditC_ZeroCcw->text();

    settingD.nSubdivision=ui->lineEditD_Subdivision->text();
    settingD.nMinRpmCw=ui->lineEditD_MinRpmCw->text();
    settingD.nMaxRpmCw=ui->lineEditD_MaxRpmCw->text();
    settingD.nMinRpmCcw=ui->lineEditD_MinRpmCcw->text();
    settingD.nMaxRpmCcw=ui->lineEditD_MaxRpmCcw->text();
    settingD.nZeroCw=ui->lineEditD_ZeroCw->text();
    settingD.nZeroCcw=ui->lineEditD_ZeroCcw->text();

    settingAC.n1=(ui->lineEditA1->text());
    settingAC.n11=(ui->lineEditA11->text());
    settingAC.n2=(ui->lineEditA2->text());
    settingAC.n22=(ui->lineEditA22->text());
    settingAC.n3=(ui->lineEditA3->text());
    settingAC.n33=(ui->lineEditA33->text());
    settingAC.n4=(ui->lineEditA4->text());
    settingAC.n44=(ui->lineEditA44->text());
    settingAC.n5=(ui->lineEditA5->text());
    settingAC.n55=(ui->lineEditA55->text());
    settingAC.n6=(ui->lineEditA6->text());
    settingAC.n66=(ui->lineEditA66->text());
    settingAC.n7=(ui->lineEditA7->text());
    settingAC.n77=(ui->lineEditA77->text());

    settingBC.n1=(ui->lineEditB1->text());
    settingBC.n11=(ui->lineEditB11->text());
    settingBC.n2=(ui->lineEditB2->text());
    settingBC.n22=(ui->lineEditB22->text());
    settingBC.n3=(ui->lineEditB3->text());
    settingBC.n33=(ui->lineEditB33->text());
    settingBC.n4=(ui->lineEditB4->text());
    settingBC.n44=(ui->lineEditB44->text());
    settingBC.n5=(ui->lineEditB5->text());
    settingBC.n55=(ui->lineEditB55->text());
    settingBC.n6=(ui->lineEditB6->text());
    settingBC.n66=(ui->lineEditB66->text());
    settingBC.n7=(ui->lineEditB7->text());
    settingBC.n77=(ui->lineEditB77->text());

    settingCC.n1=ui->lineEditC1->text();
    settingCC.n11=ui->lineEditC11->text();
    settingCC.n2=ui->lineEditC2->text();
    settingCC.n22=ui->lineEditC22->text();
    settingCC.n3=(ui->lineEditC3->text());
    settingCC.n33=(ui->lineEditC33->text());
    settingCC.n4=(ui->lineEditC4->text());
    settingCC.n44=(ui->lineEditC44->text());
    settingCC.n5=(ui->lineEditC5->text());
    settingCC.n55=(ui->lineEditC55->text());
    settingCC.n6=(ui->lineEditC6->text());
    settingCC.n66=(ui->lineEditC66->text());
    settingCC.n7=(ui->lineEditC7->text());
    settingCC.n77=(ui->lineEditC77->text());


    settingDC.n1=(ui->lineEditD1->text());
    settingDC.n11=(ui->lineEditD11->text());
    settingDC.n2=(ui->lineEditD2->text());
    settingDC.n22=(ui->lineEditD22->text());
    settingDC.n3=(ui->lineEditD3->text());
    settingDC.n33=(ui->lineEditD33->text());
    settingDC.n4=(ui->lineEditD4->text());
    settingDC.n44=(ui->lineEditD44->text());
    settingDC.n5=(ui->lineEditD5->text());
    settingDC.n55=(ui->lineEditD55->text());
    settingDC.n6=(ui->lineEditD6->text());
    settingDC.n66=(ui->lineEditD66->text());
    settingDC.n7=(ui->lineEditD7->text());
    settingDC.n77=(ui->lineEditD77->text());
}

void OtherWindow::on_getCmd()
{
     QPushButton  *btn=qobject_cast<QPushButton*>(sender());
     if(btn->objectName()=="pushButtonA")
     {


         QString settingCmd= QString("EE 53 01 10 00 00 %1 %2 %3 %4 %5 %6 %7 FF FC FF FF ").arg(
                 tenToHex(ui->lineEditA_Subdivision->text()),
                 tenToHex(ui->lineEditA_MinRpmCw->text()),
                 tenToHex(ui->lineEditA_MaxRpmCw->text()),
                 tenToHex(ui->lineEditA_MinRpmCcw->text()),
                 tenToHex(ui->lineEditA_MaxRpmCcw->text()),
                 tenToHex(ui->lineEditA_ZeroCw->text()),
                 tenToHex(ui->lineEditA_ZeroCcw->text()));
         emit cmd(settingCmd);
     }
     else if(btn->objectName()=="pushButtonB"){



         QString settingCmd= QString("EE 53 02 10 00 00 %1 %2 %3 %4 %5 %6 %7 FF FC FF FF ").arg(
                 tenToHex(ui->lineEditB_Subdivision->text()),
                 tenToHex(ui->lineEditB_MinRpmCw->text()),
                 tenToHex(ui->lineEditB_MaxRpmCw->text()),
                 tenToHex(ui->lineEditB_MinRpmCcw->text()),
                 tenToHex(ui->lineEditB_MaxRpmCcw->text()),
                 tenToHex(ui->lineEditB_ZeroCw->text()),
                 tenToHex(ui->lineEditB_ZeroCcw->text()));
         emit cmd(settingCmd);
     }
     else if(btn->objectName()=="pushButtonC"){



         QString settingCmd= QString("EE 53 03 10 00 00 %1 %2 %3 %4 %5 %6 %7 FF FC FF FF ").arg(
                 tenToHex(ui->lineEditC_Subdivision->text()),
                 tenToHex(ui->lineEditC_MinRpmCw->text()),
                 tenToHex(ui->lineEditC_MaxRpmCw->text()),
                 tenToHex(ui->lineEditC_MinRpmCcw->text()),
                 tenToHex(ui->lineEditC_MaxRpmCcw->text()),
                 tenToHex(ui->lineEditC_ZeroCw->text()),
                 tenToHex(ui->lineEditC_ZeroCcw->text()));
         emit cmd(settingCmd);
     }
     else if(btn->objectName()=="pushButtonD"){



         QString settingCmd= QString("EE 53 04 10 00 00 %1 %2 %3 %4 %5 %6 %7 FF FC FF FF ").arg(
                 tenToHex(ui->lineEditD_Subdivision->text()),
                 tenToHex(ui->lineEditD_MinRpmCw->text()),
                 tenToHex(ui->lineEditD_MaxRpmCw->text()),
                 tenToHex(ui->lineEditD_MinRpmCcw->text()),
                 tenToHex(ui->lineEditD_MaxRpmCcw->text()),
                 tenToHex(ui->lineEditD_ZeroCw->text()),
                 tenToHex(ui->lineEditD_ZeroCcw->text()));
         emit cmd(settingCmd);
     }

     else if(btn->objectName()=="pushButtonAC")
     {



         QString settingCmd1= QString("EE 53 05 0E %1 %2 %3 %4 %5 %6 %7 %8").arg(
                 tenToHex2(ui->lineEditA1->text()),
                 tenToHex2(ui->lineEditA11->text()),
                 tenToHex2(ui->lineEditA2->text()),
                 tenToHex2(ui->lineEditA22->text()),
                 tenToHex2(ui->lineEditA3->text()),
                 tenToHex2(ui->lineEditA33->text()),
                 tenToHex2(ui->lineEditA4->text()),
                 tenToHex2(ui->lineEditA44->text()));

         QString settingCmd2= QString("%1 %2 %3 %4 %5 %6 FF FC FF FF").arg(
                 tenToHex2(ui->lineEditA55->text()),
                 tenToHex2(ui->lineEditA6->text()),
                 tenToHex2(ui->lineEditA66->text()),
                 tenToHex2(ui->lineEditA7->text()),
                 tenToHex2(ui->lineEditA77->text()));
         emit cmd(settingCmd1+settingCmd2);
     }
     else if(btn->objectName()=="pushButtonBC"){




         QString settingCmd1= QString("EE 53 06 0E %1 %2 %3 %4 %5 %6 %7 %8").arg(
                 tenToHex2(ui->lineEditB1->text()),
                 tenToHex2(ui->lineEditB11->text()),
                 tenToHex2(ui->lineEditB2->text()),
                 tenToHex2(ui->lineEditB22->text()),
                 tenToHex2(ui->lineEditB3->text()),
                 tenToHex2(ui->lineEditB33->text()),
                 tenToHex2(ui->lineEditB4->text()),
                 tenToHex2(ui->lineEditB44->text()));
         QString settingCmd2= QString("%1 %2 %3 %4 %5 %6 FF FC FF FF").arg(
                 tenToHex2(ui->lineEditB5->text()),
                 tenToHex2(ui->lineEditB55->text()),
                 tenToHex2(ui->lineEditB6->text()),
                 tenToHex2(ui->lineEditB66->text()),
                 tenToHex2(ui->lineEditB7->text()),
                 tenToHex2(ui->lineEditB77->text()));
         emit cmd(settingCmd1+settingCmd2);
     }
     else if(btn->objectName()=="pushButtonCC"){




         QString settingCmd1= QString("EE 53 07 0E %1 %2 %3 %4 %5 %6 %7 %8").arg(
                 tenToHex2(ui->lineEditC1->text()),
                 tenToHex2(ui->lineEditC11->text()),
                 tenToHex2(ui->lineEditC2->text()),
                 tenToHex2(ui->lineEditC22->text()),
                 tenToHex2(ui->lineEditC3->text()),
                 tenToHex2(ui->lineEditC33->text()),
                 tenToHex2(ui->lineEditC4->text()),
                 tenToHex2(ui->lineEditC44->text()));
         QString settingCmd2= QString("%1 %2 %3 %4 %5 %6 FF FC FF FF").arg(
                 tenToHex2(ui->lineEditC5->text()),
                 tenToHex2(ui->lineEditC55->text()),
                 tenToHex2(ui->lineEditC6->text()),
                 tenToHex2(ui->lineEditC66->text()),
                 tenToHex2(ui->lineEditC7->text()),
                 tenToHex2(ui->lineEditC77->text()));
         emit cmd(settingCmd1+settingCmd2);
     }
     else if(btn->objectName()=="pushButtonDC"){




         QString settingCmd1= QString("EE 53 08 0E %1 %2 %3 %4 %5 %6 %7 %8").arg(
                 tenToHex2(ui->lineEditD1->text()),
                 tenToHex2(ui->lineEditD11->text()),
                 tenToHex2(ui->lineEditD2->text()),
                 tenToHex2(ui->lineEditD22->text()),
                 tenToHex2(ui->lineEditD3->text()),
                 tenToHex2(ui->lineEditD33->text()),
                 tenToHex2(ui->lineEditD4->text()),
                 tenToHex2(ui->lineEditD44->text()));
         QString settingCmd2= QString("%1 %2 %3 %4 %5 %6 FF FC FF FF").arg(
                 tenToHex2(ui->lineEditD5->text()),
                 tenToHex2(ui->lineEditD55->text()),
                 tenToHex2(ui->lineEditD6->text()),
                 tenToHex2(ui->lineEditD66->text()),
                 tenToHex2(ui->lineEditD7->text()),
                 tenToHex2(ui->lineEditD77->text()));
         emit cmd(settingCmd1+settingCmd2);
     }
}
void OtherWindow::on_btnBack_clicked()
{
    hide();
}



void OtherWindow::closeEvent(QCloseEvent *e)
{
    qDebug()<<"close";
}
QString OtherWindow::tenToHex(QString str)
{
    int dec = str.toInt();

    QString hex = QString("%1").arg(dec,4, 16, QChar('0'));  // 保留4位，不足补零

    return hex.toUpper().right(2)+hex.toUpper().left(2);
}

QString OtherWindow::tenToHex2(QString str)
{
    int dec = str.toInt();

    QString hex = QString("%1").arg(dec,2, 16, QChar('0'));  // 保留2位，不足补零

    return hex.toUpper();
}



void OtherWindow::on_btnRead_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"open file",QDir::currentPath(),tr("Text files (*.ini)"));

//     qDebug()<<filename;
    if(filename.isEmpty()){

        QMessageBox::information(this,"error message","Please select a file");

    }
   QSettings *pIni = new QSettings(filename, QSettings::IniFormat);
   ui->lineEditA_Subdivision->setText(pIni->value("/settingA/nSubdivision").toString());
   ui->lineEditA_MinRpmCw->setText(pIni->value("/settingA/nMinRpmCw").toString());
   ui->lineEditA_MaxRpmCw->setText(pIni->value("/settingA/nMaxRpmCw").toString());
   ui->lineEditA_MinRpmCcw->setText(pIni->value("/settingA/nMinRpmCcw").toString());
   ui->lineEditA_MaxRpmCcw->setText(pIni->value("/settingA/nMaxRpmCcw").toString());
   ui->lineEditA_ZeroCw->setText(pIni->value("/settingA/nZeroCw").toString());
   ui->lineEditA_ZeroCcw->setText(pIni->value("/settingA/nZeroCcw").toString());

   ui->lineEditB_Subdivision->setText(pIni->value("/settingB/nSubdivision").toString());
   ui->lineEditB_MinRpmCw->setText(pIni->value("/settingB/nMinRpmCw").toString());
   ui->lineEditB_MaxRpmCw->setText(pIni->value("/settingB/nMaxRpmCw").toString());
   ui->lineEditB_MinRpmCcw->setText(pIni->value("/settingB/nMinRpmCcw").toString());
   ui->lineEditB_MaxRpmCcw->setText(pIni->value("/settingB/nMaxRpmCcw").toString());
   ui->lineEditB_ZeroCw->setText(pIni->value("/settingB/nZeroCw").toString());
   ui->lineEditB_ZeroCcw->setText(pIni->value("/settingB/nZeroCcw").toString());

   ui->lineEditC_Subdivision->setText(pIni->value("/settingC/nSubdivision").toString());
   ui->lineEditC_MinRpmCw->setText(pIni->value("/settingC/nMinRpmCw").toString());
   ui->lineEditC_MaxRpmCw->setText(pIni->value("/settingC/nMaxRpmCw").toString());
   ui->lineEditC_MinRpmCcw->setText(pIni->value("/settingC/nMinRpmCcw").toString());
   ui->lineEditC_MaxRpmCcw->setText(pIni->value("/settingC/nMaxRpmCcw").toString());
   ui->lineEditC_ZeroCw->setText(pIni->value("/settingC/nZeroCw").toString());
   ui->lineEditC_ZeroCcw->setText(pIni->value("/settingC/nZeroCcw").toString());

   ui->lineEditD_Subdivision->setText(pIni->value("/settingD/nSubdivision").toString());
   ui->lineEditD_MinRpmCw->setText(pIni->value("/settingD/nMinRpmCw").toString());
   ui->lineEditD_MaxRpmCw->setText(pIni->value("/settingD/nMaxRpmCw").toString());
   ui->lineEditD_MinRpmCcw->setText(pIni->value("/settingD/nMinRpmCcw").toString());
   ui->lineEditD_MaxRpmCcw->setText(pIni->value("/settingD/nMaxRpmCcw").toString());
   ui->lineEditD_ZeroCw->setText(pIni->value("/settingD/nZeroCw").toString());
   ui->lineEditD_ZeroCcw->setText(pIni->value("/settingD/nZeroCcw").toString());


   ui->lineEditA1->setText(pIni->value("/settingAC/n1").toString());
   ui->lineEditA11->setText(pIni->value("/settingAC/n11").toString());
   ui->lineEditA2->setText(pIni->value("/settingAC/n2").toString());
   ui->lineEditA22->setText(pIni->value("/settingAC/n22").toString());
   ui->lineEditA3->setText(pIni->value("/settingAC/n3").toString());
   ui->lineEditA33->setText(pIni->value("/settingAC/n33").toString());
   ui->lineEditA4->setText(pIni->value("/settingAC/n4").toString());
   ui->lineEditA44->setText(pIni->value("/settingAC/n44").toString());
   ui->lineEditA5->setText(pIni->value("/settingAC/n5").toString());
   ui->lineEditA55->setText(pIni->value("/settingAC/n55").toString());
   ui->lineEditA6->setText(pIni->value("/settingAC/n6").toString());
   ui->lineEditA66->setText(pIni->value("/settingAC/n66").toString());
   ui->lineEditA7->setText(pIni->value("/settingAC/n7").toString());
   ui->lineEditA77->setText(pIni->value("/settingAC/n77").toString());

   ui->lineEditB1->setText(pIni->value("/settingBC/n1").toString());
   ui->lineEditB11->setText(pIni->value("/settingBC/n11").toString());
   ui->lineEditB2->setText(pIni->value("/settingBC/n2").toString());
   ui->lineEditB22->setText(pIni->value("/settingBC/n22").toString());
   ui->lineEditB3->setText(pIni->value("/settingBC/n3").toString());
   ui->lineEditB33->setText(pIni->value("/settingBC/n33").toString());
   ui->lineEditB4->setText(pIni->value("/settingBC/n4").toString());
   ui->lineEditB44->setText(pIni->value("/settingBC/n44").toString());
   ui->lineEditB5->setText(pIni->value("/settingBC/n5").toString());
   ui->lineEditB55->setText(pIni->value("/settingBC/n55").toString());
   ui->lineEditB6->setText(pIni->value("/settingBC/n6").toString());
   ui->lineEditB66->setText(pIni->value("/settingBC/n66").toString());
   ui->lineEditB7->setText(pIni->value("/settingBC/n7").toString());
   ui->lineEditB77->setText(pIni->value("/settingBC/n77").toString());

   ui->lineEditC1->setText(pIni->value("/settingCC/n1").toString());
   ui->lineEditC11->setText(pIni->value("/settingCC/n11").toString());
   ui->lineEditC2->setText(pIni->value("/settingCC/n2").toString());
   ui->lineEditC22->setText(pIni->value("/settingCC/n22").toString());
   ui->lineEditC3->setText(pIni->value("/settingCC/n3").toString());
   ui->lineEditC33->setText(pIni->value("/settingCC/n33").toString());
   ui->lineEditC4->setText(pIni->value("/settingCC/n4").toString());
   ui->lineEditC44->setText(pIni->value("/settingCC/n44").toString());
   ui->lineEditC5->setText(pIni->value("/settingCC/n5").toString());
   ui->lineEditC55->setText(pIni->value("/settingCC/n55").toString());
   ui->lineEditC6->setText(pIni->value("/settingCC/n6").toString());
   ui->lineEditC66->setText(pIni->value("/settingCC/n66").toString());
   ui->lineEditC7->setText(pIni->value("/settingCC/n7").toString());
   ui->lineEditC77->setText(pIni->value("/settingCC/n77").toString());

   ui->lineEditD1->setText(pIni->value("/settingDC/n1").toString());
   ui->lineEditD11->setText(pIni->value("/settingDC/n11").toString());
   ui->lineEditD2->setText(pIni->value("/settingDC/n2").toString());
   ui->lineEditD22->setText(pIni->value("/settingDC/n22").toString());
   ui->lineEditD3->setText(pIni->value("/settingDC/n3").toString());
   ui->lineEditD33->setText(pIni->value("/settingDC/n33").toString());
   ui->lineEditD4->setText(pIni->value("/settingDC/n4").toString());
   ui->lineEditD44->setText(pIni->value("/settingDC/n44").toString());
   ui->lineEditD5->setText(pIni->value("/settingDC/n5").toString());
   ui->lineEditD55->setText(pIni->value("/settingDC/n55").toString());
   ui->lineEditD6->setText(pIni->value("/settingDC/n6").toString());
   ui->lineEditD66->setText(pIni->value("/settingDC/n66").toString());
   ui->lineEditD7->setText(pIni->value("/settingDC/n7").toString());
   ui->lineEditD77->setText(pIni->value("/settingDC/n77").toString());
}

void OtherWindow::on_btnSave_clicked()
{
    QString saveFilename=QFileDialog::getSaveFileName(this,"save file",QDir::currentPath(),tr("Text files (*.ini)"));
    initParm();
//     qDebug()<<filename;
    if(saveFilename.isEmpty()){

        QMessageBox::information(this,"error message","Please select a file");

    }

    //创建配置文件
       QSettings *pIni = new QSettings(saveFilename, QSettings::IniFormat);
       //写入数据
       pIni->setValue("/settingA/nSubdivision", settingA.nSubdivision);
       pIni->setValue("/settingA/nMinRpmCw", settingA.nMinRpmCw);
       pIni->setValue("/settingA/nMaxRpmCw", settingA.nMaxRpmCw);
       pIni->setValue("/settingA/nMinRpmCcw", settingA.nMinRpmCcw);
       pIni->setValue("/settingA/nMaxRpmCcw", settingA.nMaxRpmCcw);
       pIni->setValue("/settingA/nZeroCw", settingA.nZeroCw);
       pIni->setValue("/settingA/nZeroCcw", settingA.nZeroCcw);

       pIni->setValue("/settingB/nSubdivision", settingB.nSubdivision);
       pIni->setValue("/settingB/nMinRpmCw", settingB.nMinRpmCw);
       pIni->setValue("/settingB/nMaxRpmCw", settingB.nMaxRpmCw);
       pIni->setValue("/settingB/nMinRpmCcw", settingB.nMinRpmCcw);
       pIni->setValue("/settingB/nMaxRpmCcw", settingB.nMaxRpmCcw);
       pIni->setValue("/settingB/nZeroCw", settingB.nZeroCw);
       pIni->setValue("/settingB/nZeroCcw", settingB.nZeroCcw);

       pIni->setValue("/settingC/nSubdivision", settingC.nSubdivision);
       pIni->setValue("/settingC/nMinRpmCw", settingC.nMinRpmCw);
       pIni->setValue("/settingC/nMaxRpmCw", settingC.nMaxRpmCw);
       pIni->setValue("/settingC/nMinRpmCcw", settingC.nMinRpmCcw);
       pIni->setValue("/settingC/nMaxRpmCcw", settingC.nMaxRpmCcw);
       pIni->setValue("/settingC/nZeroCw", settingC.nZeroCw);
       pIni->setValue("/settingC/nZeroCcw", settingC.nZeroCcw);

       pIni->setValue("/settingD/nSubdivision", settingD.nSubdivision);
       pIni->setValue("/settingD/nMinRpmCw", settingD.nMinRpmCw);
       pIni->setValue("/settingD/nMaxRpmCw", settingD.nMaxRpmCw);
       pIni->setValue("/settingD/nMinRpmCcw", settingD.nMinRpmCcw);
       pIni->setValue("/settingD/nMaxRpmCcw", settingD.nMaxRpmCcw);
       pIni->setValue("/settingD/nZeroCw", settingD.nZeroCw);
       pIni->setValue("/settingD/nZeroCcw", settingD.nZeroCcw);


       pIni->setValue("/settingAC/n1", settingAC.n1);
       pIni->setValue("/settingAC/n11", settingAC.n11);
       pIni->setValue("/settingAC/n2", settingAC.n2);
       pIni->setValue("/settingAC/n22", settingAC.n22);
       pIni->setValue("/settingAC/n3", settingAC.n3);
       pIni->setValue("/settingAC/n33", settingAC.n33);
       pIni->setValue("/settingAC/n4", settingAC.n4);
       pIni->setValue("/settingAC/n44", settingAC.n44);
       pIni->setValue("/settingAC/n5", settingAC.n5);
       pIni->setValue("/settingAC/n55", settingAC.n55);
       pIni->setValue("/settingAC/n6", settingAC.n6);
       pIni->setValue("/settingAC/n66",settingAC.n66);
       pIni->setValue("/settingAC/n7", settingAC.n7);
       pIni->setValue("/settingAC/n77", settingAC.n77);

       pIni->setValue("/settingBC/n1", settingBC.n1);
       pIni->setValue("/settingBC/n11", settingBC.n11);
       pIni->setValue("/settingBC/n2", settingBC.n2);
       pIni->setValue("/settingBC/n22", settingBC.n22);
       pIni->setValue("/settingBC/n3", settingBC.n3);
       pIni->setValue("/settingBC/n33", settingBC.n33);
       pIni->setValue("/settingBC/n4", settingBC.n4);
       pIni->setValue("/settingBC/n44", settingBC.n44);
       pIni->setValue("/settingBC/n5", settingBC.n5);
       pIni->setValue("/settingBC/n55", settingBC.n55);
       pIni->setValue("/settingBC/n6", settingBC.n6);
       pIni->setValue("/settingBC/n66",settingBC.n66);
       pIni->setValue("/settingBC/n7", settingBC.n7);
       pIni->setValue("/settingBC/n77", settingBC.n77);

       pIni->setValue("/settingCC/n1", settingCC.n1);
       pIni->setValue("/settingCC/n11", settingCC.n11);
       pIni->setValue("/settingCC/n2", settingCC.n2);
       pIni->setValue("/settingCC/n22", settingCC.n22);
       pIni->setValue("/settingCC/n3", settingCC.n3);
       pIni->setValue("/settingCC/n33", settingCC.n33);
       pIni->setValue("/settingCC/n4", settingCC.n4);
       pIni->setValue("/settingCC/n44", settingCC.n44);
       pIni->setValue("/settingCC/n5", settingCC.n5);
       pIni->setValue("/settingCC/n55", settingCC.n55);
       pIni->setValue("/settingCC/n6", settingCC.n6);
       pIni->setValue("/settingCC/n66",settingCC.n66);
       pIni->setValue("/settingCC/n7", settingCC.n7);
       pIni->setValue("/settingCC/n77", settingCC.n77);

       pIni->setValue("/settingDC/n1", settingDC.n1);
       pIni->setValue("/settingDC/n11", settingDC.n11);
       pIni->setValue("/settingDC/n2", settingDC.n2);
       pIni->setValue("/settingDC/n22", settingDC.n22);
       pIni->setValue("/settingDC/n3", settingDC.n3);
       pIni->setValue("/settingDC/n33", settingDC.n33);
       pIni->setValue("/settingDC/n4", settingDC.n4);
       pIni->setValue("/settingDC/n44", settingDC.n44);
       pIni->setValue("/settingDC/n5", settingDC.n5);
       pIni->setValue("/settingDC/n55", settingDC.n55);
       pIni->setValue("/settingDC/n6", settingDC.n6);
       pIni->setValue("/settingDC/n66",settingDC.n66);
       pIni->setValue("/settingDC/n7", settingDC.n7);
       pIni->setValue("/settingDC/n77", settingDC.n77);

       delete pIni;



}

void OtherWindow::on_btnWrite_clicked()
{

}
