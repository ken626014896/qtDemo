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
    connect(otherwin,SIGNAL(cmd(QString)),this,SLOT(on_sendSetttingCmd(QString)));
    connect(timer, SIGNAL(timeout()), this, SLOT(on_noStopSend()));
    setSpinBox();
    openserialPort();

    setReset();
    setGrid();


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
            serial.close();	//然后关闭串口，为什么要关闭啊。。。。。因为这段代码打开串口只是为了查找串口可以用不可用而已，而且还要打开下一个串口查看可用不可用呢!
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



void MainWindow::openserialPort()
{
    serial=new QSerialPort();

    serial->setPortName(ui->spinBox->text());
    if(this->serial->open(QIODevice::ReadWrite) == true){
               ui->textEdit->clear();
               ui->textEdit->append("Open Success");
               ui->pushButton->setText(QStringLiteral("关闭"));
       }else {
           qDebug()<<"Open Fail";
       }//判断串口是否打开

    serial->setBaudRate(38400);//设置波特率

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
    ui->pushButton->setText(QStringLiteral("开启"));
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

void MainWindow::on_noStopSend()
{
    qDebug()<<QStringLiteral("发送脉冲");
}


void MainWindow::on_btnA_up_slim_pressed()
{
      timer->start(100);
}

void MainWindow::on_btnA_up_slim_released()
{
     timer->stop();
}

void MainWindow::on_pushButton_4_clicked() //打开参数设置页面
{

    otherwin->show();
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    otherwin->close();
}

void MainWindow::on_sendSetttingCmd(QString cmd)
{
    serial->write(QByteArray::fromHex(cmd.toLatin1()));  //写入16进制的字节流
}
