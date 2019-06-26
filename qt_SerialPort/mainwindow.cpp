#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include <QList>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    qDebug()<<QStringLiteral("begain");
    timer=new QTimer(this);
    otherwin=new OtherWindow();
    serial=new QSerialPort();

    connect(otherwin,SIGNAL(cmd(QString)),this,SLOT(on_sendSetttingCmd(QString)));
    connect(timer, SIGNAL(timeout()), this, SLOT(on_noStopSend()));
    setSpinBox();
//    openserialPort();

    setReset();
    setGrid();


    connectSLOT();


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setGrid()
{
    ui->gridLayout->setContentsMargins(1,1, 1,1);
    ui->gridLayout->setAlignment(ui->btnA_clear,Qt::AlignBottom);
    ui->gridLayout_2->setAlignment(ui->btnC_clear,Qt::AlignBottom);
    ui->gridLayout->setAlignment(ui->btnB_clear,Qt::AlignTop);
    ui->gridLayout_2->setAlignment(ui->btnD_clear,Qt::AlignTop);

}



void MainWindow::connectSLOT()
{
      connect(ui->btnA_up,SIGNAL(clicked()),this,SLOT(on_sendPulse()));
      connect(ui->btnA_down,SIGNAL(clicked()),this,SLOT(on_sendPulse()));
      connect(ui->btnB_left,SIGNAL(clicked()),this,SLOT(on_sendPulse()));
      connect(ui->btnB_right,SIGNAL(clicked()),this,SLOT(on_sendPulse()));
      connect(ui->btnC_up,SIGNAL(clicked()),this,SLOT(on_sendPulse()));
      connect(ui->btnC_down,SIGNAL(clicked()),this,SLOT(on_sendPulse()));
      connect(ui->btnD_left,SIGNAL(clicked()),this,SLOT(on_sendPulse()));
      connect(ui->btnD_right,SIGNAL(clicked()),this,SLOT(on_sendPulse()));


      //微速脉冲
      connect(ui->btnA_up_slim,SIGNAL(pressed()),this,SLOT(btnSlim_pressed()));
      connect(ui->btnA_up_slim,SIGNAL(released()),this,SLOT(btnSlim_released()));

      connect(ui->btnA_down_slim,SIGNAL(pressed()),this,SLOT(btnSlim_pressed()));
      connect(ui->btnA_down_slim,SIGNAL(released()),this,SLOT(btnSlim_released()));

      connect(ui->btnB_left_slim,SIGNAL(pressed()),this,SLOT(btnSlim_pressed()));
      connect(ui->btnB_left_slim,SIGNAL(released()),this,SLOT(btnSlim_released()));

      connect(ui->btnB_right_slim,SIGNAL(pressed()),this,SLOT(btnSlim_pressed()));
      connect(ui->btnB_right_slim,SIGNAL(released()),this,SLOT(btnSlim_released()));

      connect(ui->btnC_up_slim,SIGNAL(pressed()),this,SLOT(btnSlim_pressed()));
      connect(ui->btnC_up_slim,SIGNAL(released()),this,SLOT(btnSlim_released()));

      connect(ui->btnC_down_slim,SIGNAL(pressed()),this,SLOT(btnSlim_pressed()));
      connect(ui->btnC_down_slim,SIGNAL(released()),this,SLOT(btnSlim_released()));

      connect(ui->btnD_left_slim,SIGNAL(pressed()),this,SLOT(btnSlim_pressed()));
      connect(ui->btnD_left_slim,SIGNAL(released()),this,SLOT(btnSlim_released()));

      connect(ui->btnD_right_slim,SIGNAL(pressed()),this,SLOT(btnSlim_pressed()));
      connect(ui->btnD_right_slim,SIGNAL(released()),this,SLOT(btnSlim_released()));


}


void MainWindow::setSpinBox()
{
    int numCom=0;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {

            QSerialPort serial;	//在循环语句内部实例化类，因为可用串口不一定只就一个
            serial.setPort(info); //设置能够用的串口端口
            if(serial.open(QIODevice::ReadWrite))	//用ReadWrite可读写的方式打开串口
            {
            numCom++;
            serial.close();	//只为了查找串口可以用不可用
            }

        }
    ui->spinBox->setMaximum(numCom);
}
void MainWindow::setReset()
{
   connect(ui->btnA_clear,SIGNAL(clicked()),this,SLOT(on_positionReset()));
   connect(ui->btnB_clear,SIGNAL(clicked()),this,SLOT(on_positionReset()));
   connect(ui->btnC_clear,SIGNAL(clicked()),this,SLOT(on_positionReset()));
   connect(ui->btnD_clear,SIGNAL(clicked()),this,SLOT(on_positionReset()));

   connect(ui->AB_clear,SIGNAL(clicked()),this,SLOT(on_timeReset()));
   connect(ui->CD_clear,SIGNAL(clicked()),this,SLOT(on_timeReset()));
}


void MainWindow::on_timeReset()
{
    QPushButton  *btn=qobject_cast<QPushButton*>(sender());
    if(btn->objectName().contains("AB"))
    {
        ui->lineEditA_up_time->setText("0");
        ui->lineEditA_down_time->setText("0");
        ui->lineEditB_left_time->setText("0");
        ui->lineEditB_right_time->setText("0");

    }

    else {

        ui->lineEditC_up_time->setText("0");
        ui->lineEditC_down_time->setText("0");
        ui->lineEditD_left_time->setText("0");
        ui->lineEditD_right_time->setText("0");
    }

}

void MainWindow::on_positionReset()
{
    QPushButton  *btn=qobject_cast<QPushButton*>(sender());
    if(btn->objectName().contains("A"))
        ui->lineEditA_position->setText("0");
    else if(btn->objectName().contains("B"))
        ui->lineEditB_position->setText("0");
    else if(btn->objectName().contains("C"))
        ui->lineEditC_position->setText("0");
    else {
        ui->lineEditD_position->setText("0");
    }


}


void MainWindow::on_btn_switch_clicked()
{
    if(ui->btn_switch->isChecked())
    {
        openserialPort();
        ui->spinBox->setEnabled(false);
    }

    else{
       closeserialPort();
       ui->spinBox->setEnabled(true);
    }

}

void MainWindow::openserialPort()
{

    serial->setPortName(ui->spinBox->text());
    if(this->serial->open(QIODevice::ReadWrite) == true){
               ui->textEdit->clear();
               ui->textEdit->append("Open Success");
               ui->btn_switch->setChecked(true);
       }else {
           qDebug()<<"Open Fail";
           ui->textEdit->clear();
           ui->textEdit->append("Open Fail");
       }//判断串口是否打开

    serial->setBaudRate(115200);//设置波特率

    serial->setDataBits(QSerialPort::Data8);//设置数据位

    serial->setStopBits(QSerialPort::OneStop);//设置停止位

    serial->setParity(QSerialPort::NoParity);//设置是否有奇偶校验

    connect(serial,SIGNAL(readyRead()),this,SLOT(serialPort_readyRead()));
}

void MainWindow::closeserialPort()
{
    if (serial->isOpen())
        serial->close();
    ui->textEdit->clear();
    ui->textEdit->append("Close Success");

}


void MainWindow::serialPort_readyRead()
{
    QByteArray msg = serial->readAll();
    QString str=msg.toHex().data();
    ui->textEdit->clear();
    ui->textEdit->append(str);
}



void MainWindow::on_pushButton_test_clicked()
{
    QString msg1 = ui->textEdit->toPlainText();
    QString msg2="EE530110000040 06 64 00 E8 03 64 00 E8 03 00 00 00 00 FF FC FF FF ";
    serial->write(QByteArray::fromHex(msg2.toLatin1()));  //写入16进制的字节流
}



void MainWindow::on_pushButton_4_clicked() //打开参数设置页面
{

    otherwin->show();
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    otherwin->close();
}

void MainWindow::on_sendSetttingCmd(QString cmd) //发送设置页面的参数到串口
{
    if (!serial->isOpen())
         QMessageBox::information(this,"error message",QStringLiteral("请连接串口"));
    else

       serial->write(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
}


void MainWindow::on_noStopSend()
{
      serial->write(byte);  //写入16进制的字节流
//    qDebug()<<"ok";
}
void MainWindow::btnSlim_pressed()  //发送微型脉冲的槽
{
    QPushButton  *btn=qobject_cast<QPushButton*>(sender());


   //发送微速脉冲
    if(btn->objectName()=="btnA_up_slim")
    {

        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 01 04 %1 00 00 FF FC FF FF").arg(str);
        byte=QByteArray::fromHex(cmd.toLatin1());  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnA_down_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 02 04 %1 00 00 FF FC FF FF").arg(str);
        byte=QByteArray::fromHex(cmd.toLatin1());  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnB_right_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 03 04 %1 00 00 FF FC FF FF").arg(str);
        byte=QByteArray::fromHex(cmd.toLatin1());  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnB_left_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 04 04 %1 00 00 FF FC FF FF").arg(str);
        byte=QByteArray::fromHex(cmd.toLatin1());  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnC_up_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 05 04 %1 00 00 FF FC FF FF").arg(str);
        byte=QByteArray::fromHex(cmd.toLatin1());  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnC_down_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 06 04 %1 00 00 FF FC FF FF").arg(str);
        byte=QByteArray::fromHex(cmd.toLatin1());  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnD_right_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 07 04 %1 00 00 FF FC FF FF").arg(str);
        byte=QByteArray::fromHex(cmd.toLatin1());  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnD_left_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 08 04 %1 00 00 FF FC FF FF").arg(str);
        byte=QByteArray::fromHex(cmd.toLatin1());  //写入16进制的字节流
    }
    timer->start(100);
}

void MainWindow::btnSlim_released()
{
    timer->stop();
}

void MainWindow::on_sendPulse() //发送脉冲的槽
{
    QPushButton  *btn=qobject_cast<QPushButton*>(sender());

    if(btn->objectName()=="btnA_up")
    {

        QString str=tenToHex(ui->lineEditA_pulse->text());
        QString cmd=QString("EE 4D 01 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));   //写入16进制的字节流
    }
    else if (btn->objectName()=="btnA_down") {
        QString str=tenToHex(ui->lineEditA_pulse->text());
        QString cmd=QString("EE 4D 02 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnB_right") {
        QString str=tenToHex(ui->lineEditA_pulse->text());
        QString cmd=QString("EE 4D 03 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));   //写入16进制的字节流
    }
    else if (btn->objectName()=="btnB_left") {
        QString str=tenToHex(ui->lineEditA_pulse->text());
        QString cmd=QString("EE 4D 04 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));   //写入16进制的字节流
    }
    else if (btn->objectName()=="btnC_up") {
        QString str=tenToHex(ui->lineEditA_pulse->text());
        QString cmd=QString("EE 4D 05 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnC_down") {
        QString str=tenToHex(ui->lineEditA_pulse->text());
        QString cmd=QString("EE 4D 06 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));   //写入16进制的字节流
    }
    else if (btn->objectName()=="btnD_right") {
        QString str=tenToHex(ui->lineEditA_pulse->text());
        QString cmd=QString("EE 4D 07 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1())); //写入16进制的字节流
    }
    else if (btn->objectName()=="btnD_left") {
        QString str=tenToHex(ui->lineEditA_pulse->text());
        QString cmd=QString("EE 4D 08 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
    }

   //发送微速脉冲
    else if(btn->objectName()=="btnA_up_slim")
    {

        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 01 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnA_down_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 02 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1())); //写入16进制的字节流
    }
    else if (btn->objectName()=="btnB_right_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 03 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));   //写入16进制的字节流
    }
    else if (btn->objectName()=="btnB_left_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 04 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnC_up_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 05 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnC_down_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 06 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
    }
    else if (btn->objectName()=="btnD_right_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 07 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));   //写入16进制的字节流
    }
    else if (btn->objectName()=="btnD_left_slim") {
        QString str=tenToHex(ui->lineEdit_slim_pulse->text());
        QString cmd=QString("EE 4D 08 04 %1 00 00 FF FC FF FF").arg(str);
        sendCmd(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
    }
}
QString MainWindow::tenToHex(QString str)
{
    int dec = str.toInt();

    QString hex = QString("%1").arg(dec,4, 16, QChar('0'));  // 保留2位，不足补零

    return hex.toUpper().right(2)+hex.toUpper().left(2);
}
void MainWindow::sendCmd(QByteArray cmd)
{
    if (!serial->isOpen())
         QMessageBox::information(this,"error message",QStringLiteral("请连接串口"));
    else
        serial->write(cmd);
}
