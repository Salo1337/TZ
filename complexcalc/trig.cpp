#include "trig.h"
#include "ui_trig.h"
#include "ui_alg1.h"
#include <QMainWindow>
#include <complex>
#include <cmath>
#include<cstdlib>
#include<string>
#include<sstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <iomanip>
#include <QMovie>
#define PI 3.14159265358979323846

using namespace std;
trig1::trig1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::trig1)
{
    ui->setupUi(this);

    QMovie *mov = new QMovie(":blue1.gif");
    ui->back->setMovie(mov);
    mov->start();

    ui->real_push->hide();
    ui->real_push_2->hide();
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->real->setValidator(new QRegExpValidator(QRegExp("[-1-9][0-9]{1,11}\\.[0-9]{1,5}|[0-9]\\.[0-9]{1,5}")));
    ui->imag->setValidator(new QRegExpValidator(QRegExp("[-1-9][0-9]{1,11}\\.[0-9]{1,5}|[0-9]\\.[0-9]{1,5}")));
    ui->rez->setAlignment(Qt::AlignCenter);

    ui->clear->hide();
}

trig1::~trig1()
{
    delete ui;
}



void trig1::on_per_pressed()
{
    double a,b,realCH,imagCH;

    int AAA;

    a = ui-> real->text().toDouble();
    b = ui-> imag->text().toDouble();

    complex <double> e(a,b);


    string newText, newText2, newTextAAA,Atan,Atan1;
    QString newText1,newText3, newTextAA,Qatan,Qreal1,Qimag1,Qreal2,Qimag2,A1,B1,Qatan1;

    A1=QString::number(a);
    B1=QString::number(b);

    realCH = real(e);
    imagCH = imag(e);

    double delInaR;
    double sincos,sincos1;

    AAA = sqrt(pow(realCH,2)+pow(imagCH,2));


    newTextAAA = to_string(AAA);
    newTextAA=QString::fromStdString(newTextAAA);
    delInaR = imagCH/realCH;

   sincos = 180/PI*atan(delInaR);

   sincos1 = atan(delInaR);

   stringstream Atan_temp,Atan_temp1;

   Atan_temp1 << fixed << setprecision(2) << sincos1;
   Atan_temp << fixed << setprecision(2) << sincos;

    Atan = Atan_temp.str();
    Atan1 = Atan_temp1.str();

    if (Atan1[Atan1.size()-1]=='0')
    for (size_t i=Atan1.size()-1; Atan1[i]=='0'; i--)
    Atan1.erase(i,1);
    if (Atan1[Atan1.size()-1]=='.')
    Atan1.erase(Atan1.size()-1,1);

    if (Atan1[Atan1.size()-1]=='0')
    for (size_t i=Atan1.size()-1; Atan1[i]=='0'; i--)
    Atan1.erase(i,1);
    if (Atan1[Atan1.size()-1]=='.')
    Atan1.erase(Atan1.size()-1,1);


   Qatan=QString::fromStdString(Atan);
    Qatan1=QString::fromStdString(Atan1);




    if (ui->first->currentIndex()==0||ui->second->currentIndex()==0){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Сделайте выбор");
        messageBox.setFixedSize(500,200);
    }
    if (ui->first->currentIndex()==1 && ui->second->currentIndex()==2)
    {
        ui->rez->setText("Введенное число = (" + A1 + " + i*" + B1 + ")\n"
        + "Число в алгебраической форме имеет вид: (a+i*b) \n"
        + "Число в тригонометрической форме имеет вид: A*(cos(x) + sin(X))\n"
        +"A=√(a^2+b^2)= √(" + A1 + "^2" +"+"+ B1 + "^2" + ")=" + newTextAA +"\n"
        + "X=arctg(b/a) = arctg(" + B1 +"/" +A1+ ") = "+ Qatan1+" = " +Qatan+"°"+ "\n"
        +"Преобразованное число = " + newTextAA +  "*(" +"cos("+Qatan+"°)" + " + i*sin("+Qatan+"°"+"))");

    }
    if (ui->first->currentIndex()==1 && ui->second->currentIndex()==3)
    {
        ui->rez->setText("Введенное число = (" + A1 + " + i*" + B1 + ")\n"
        + "Число в алгебраической форме имеет вид: (a+i*b) \n"
        + "Число в экспоненциальной форме имеет вид: A*e^(i*X)" + "\n"
        +"A=√(a^2+b^2)= √(" + A1 + "^2" +"+"+ B1 + "^2" + ")=" + newTextAA +"\n"
        + "X=arctg(b/a) = arctg(" + B1 +"/" +A1+ ") = "+ Qatan1+" = " +Qatan+"°"+ "\n"
        + "Преобразованное число = " + newTextAA +  "*" +"e^(i*"+Qatan+"°"+")");
    }



    if (ui->first->currentIndex()==2 && ui->second->currentIndex()==3)
    {
        double sin,A;

        sin = ui-> imag->text().toDouble();
        A = ui-> real->text().toDouble();

        string AA,pow;
        QString AA1,pow1;

        pow = to_string(sin);
        AA = to_string(A);

        if (pow[pow.size()-1]=='0')
        for (size_t i=pow.size()-1; pow[i]=='0'; i--)
        pow.erase(i,1);
        if (pow[pow.size()-1]=='.')
        pow.erase(pow.size()-1,1);

        if (AA[AA.size()-1]=='0')
        for (size_t i=AA.size()-1; AA[i]=='0'; i--)
        AA.erase(i,1);
        if (AA[AA.size()-1]=='.')
        AA.erase(AA.size()-1,1);



        pow1=QString::fromStdString(pow);
        AA1=QString::fromStdString(AA);

        ui->rez->setText("Введенное число = " + AA1 + "*(cos(" + pow1 + "°)+" + "i*sin(" + pow1 + "°))" + "\n"
        + "Число в тригонометрической форме имеет вид: A*(cos(x) + sin(X))\n"
        + "Число в экспоненциальной форме имеет вид: A*e^(i*X)" + "\n"
        + "A= "+ AA1 + "; X= " + pow1 + ";\n"
        + "Преобразованное число:" + AA1 + "*e^(i*" + pow1 + ")");
    }

    if (ui->first->currentIndex()==3 && ui->second->currentIndex()==2)
    {
        double sin,A;

        sin = ui-> imag->text().toDouble();
        A = ui-> real->text().toDouble();

        string AA,pow;
        QString AA1,pow1;

        pow = to_string(sin);
        AA = to_string(A);

        if (pow[pow.size()-1]=='0')
        for (size_t i=pow.size()-1; pow[i]=='0'; i--)
        pow.erase(i,1);
        if (pow[pow.size()-1]=='.')
        pow.erase(pow.size()-1,1);

        if (AA[AA.size()-1]=='0')
        for (size_t i=AA.size()-1; AA[i]=='0'; i--)
        AA.erase(i,1);
        if (AA[AA.size()-1]=='.')
        AA.erase(AA.size()-1,1);



        pow1=QString::fromStdString(pow);
        AA1=QString::fromStdString(AA);

        ui->rez->setText("Введенное число = " + AA1 + "*(e^i*" + pow1 + ")\n"
        +"Число в экспоненциальной форме имеет вид: A*e^(i*X)\n"
        + "Число в тригонометрической форме имеет вид: A*(cos(x) + sin(X))\n"
        + "A= "+ AA1 + "; X= " + pow1 + ";\n"
        + "Преобразованное число:" + AA1 + "*(cos(" + pow1 + "°)+" + "i*sin(" + pow1 + "°))");
    }


    if (ui->first->currentIndex()==2 && ui->second->currentIndex()==1)
    {
        double sinn,A,REAL,IMAG,sincos;

        string RE,IM;

        RE = ui-> real->text().toStdString();
        IM = ui-> imag->text().toStdString();

        QString RE1,IM1;
        RE1=QString::fromStdString(RE);
        IM1=QString::fromStdString(IM);


        sinn = ui-> imag->text().toDouble();
        A = ui-> real->text().toDouble();

        sincos = (PI/180)*sinn;

        REAL = A*cos(sincos);
        IMAG = A*sin(sincos);

        string AA,pow;
        QString AA1,pow1;

        pow = to_string(IMAG);
        AA = to_string(REAL);

        if (pow[pow.size()-1]=='0')
        for (size_t i=pow.size()-1; pow[i]=='0'; i--)
        pow.erase(i,1);
        if (pow[pow.size()-1]=='.')
        pow.erase(pow.size()-1,1);

        if (AA[AA.size()-1]=='0')
        for (size_t i=AA.size()-1; AA[i]=='0'; i--)
        AA.erase(i,1);
        if (AA[AA.size()-1]=='.')
        AA.erase(AA.size()-1,1);

        pow1=QString::fromStdString(pow);
        AA1=QString::fromStdString(AA);

        ui->rez->setText("Введенное число = " + RE1 + "*(cos(" + IM1 + "°) + sin("+ IM1 +"°))\n"
        + "Число а в тригонометрической форме имеет вид: A*(cos(X)+sin(X)) \n"
        + "Число в алгебраической форме имеет вид: (a+i*b) \n"
        + "a=A*cos(X) = "+ AA1 + "; b=A*sin(x) = " + pow1 + ";\n"
        + "Преобразованное число: (" + AA1 + " + i*" + pow1 + ")");
    }


    if (ui->first->currentIndex()==3 && ui->second->currentIndex()==1)
    {
        double sinn,A,REAL,IMAG,sincos;

        string RE,IM;

        QString RE1,IM1;


        A = ui-> real->text().toDouble();
        sinn = ui-> imag->text().toDouble();
        RE1=QString::number(A);
        IM1=QString::number(sinn);

        sincos = (PI/180)*sinn;

        REAL = A*cos(sincos);
        IMAG = A*sin(sincos);

        string AA,pow;
        QString AA1,pow1;

        pow = to_string(IMAG);
        AA = to_string(REAL);

        if (pow[pow.size()-1]=='0')
        for (size_t i=pow.size()-1; pow[i]=='0'; i--)
        pow.erase(i,1);
        if (pow[pow.size()-1]=='.')
        pow.erase(pow.size()-1,1);

        if (AA[AA.size()-1]=='0')
        for (size_t i=AA.size()-1; AA[i]=='0'; i--)
        AA.erase(i,1);
        if (AA[AA.size()-1]=='.')
        AA.erase(AA.size()-1,1);

        pow1=QString::fromStdString(pow);
        AA1=QString::fromStdString(AA);

        ui->rez->setText("Введенное число = " + RE1 + "*e^(i*"+ IM1 +"°)\n"
        +"Число в экспоненциальной форме имеет вид: A*e^(i*X)\n"
        + "Число в алгебраической форме имеет вид: (a+i*b) \n"
        + "a=A*cos(X) = "+ AA1 + "; b=A*sin(x) = " + pow1 + ";\n"
        + "Преобразованное число: (" + AA1 + " + i*" + pow1 + ")");
    }

    if (ui->first->currentIndex()==1 && ui->second->currentIndex()==1)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Выберете форму числа");
        messageBox.setFixedSize(500,200);
    }

    if (ui->first->currentIndex()==2 && ui->second->currentIndex()==2)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Выберете форму числа");
        messageBox.setFixedSize(500,200);
    }
    if (ui->first->currentIndex()==3 && ui->second->currentIndex()==3)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Выберете форму числа");
        messageBox.setFixedSize(500,200);
    }

}



void trig1::on_first_currentTextChanged(const QString &arg1)
{
    ui->real_push->show();
    ui->real_push_2->show();
    if(ui->first->currentIndex()==1)
      {
          ui->real->setText("Действительная ч.");
      }

    if((ui->first->currentIndex()==2)||(ui->first->currentIndex()==3))
      {
          ui->real->setText("Модуль числа");
      }

    if(ui->first->currentIndex()==1)
      {
          ui->imag->setText("Мнимая часть");
      }

    if((ui->first->currentIndex()==2)||(ui->first->currentIndex()==3))
      {
          ui->imag->setText("Аргумент Ф.");
      }
}


void trig1::on_podtv_clicked()
{
    ui->clear->show();
    ui->podtv->hide();
    ui->real_push->show();
    ui->real_push_2->show();

    if((ui->first->currentIndex()==0))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Выберите форму чисел");
        messageBox.setFixedSize(500,200);
    } else
    {

    QPropertyAnimation *ramka = new QPropertyAnimation(ui->ramka, "geometry");
    ramka->setDuration(500);
    ramka->setStartValue(QRect(10, 500, 500, 120));
    ramka->setEndValue(QRect(10, 276, 500, 120));
    ramka->start();


    QPropertyAnimation *anim = new QPropertyAnimation(ui->first, "geometry");
    anim->setDuration(500);
    anim->setStartValue(QRect(184, 150, 151, 22));
    anim->setEndValue(QRect(184, 96, 151, 22));
    anim->start();

    QPropertyAnimation *anima = new QPropertyAnimation(ui->second, "geometry");
    anima->setDuration(500);
    anima->setStartValue(QRect(184, 250, 151, 22));
    anima->setEndValue(QRect(184, 146, 151, 22));
    anima->start();


    QPropertyAnimation *per = new QPropertyAnimation(ui->per, "geometry");
    per->setDuration(500);
    per->setStartValue(QRect(220, 200, 80, 22));
    per->setEndValue(QRect(220, 181, 80, 22));
    per->start();


    QPropertyAnimation *real1 = new QPropertyAnimation(ui->real, "geometry");
    real1->setDuration(500);
    real1->setStartValue(QRect(-170, 230, 160, 31));
    real1->setEndValue(QRect(75, 221, 160, 31));
    real1->start();
    QPropertyAnimation* real11 = new QPropertyAnimation(ui->real);//Код для QPushButton
    QGraphicsOpacityEffect* grEffect5 = new QGraphicsOpacityEffect(ui->real);
    ui->real->setGraphicsEffect(grEffect5);
    real11->setTargetObject(grEffect5);
    real11->setPropertyName("opacity");
    real11->setStartValue(0.0);
    real11->setEndValue(2.0);
    real11->setDuration(1000);
    real11->start();


    QPropertyAnimation *imag1 = new QPropertyAnimation(ui->imag, "geometry");
    imag1->setDuration(500);
    imag1->setStartValue(QRect(550, 230, 160, 31));
    imag1->setEndValue(QRect(285, 221, 160, 31));
    imag1->start();
    QPropertyAnimation* imag11 = new QPropertyAnimation(ui->imag);//Код для QPushButton
    QGraphicsOpacityEffect* grEffect4 = new QGraphicsOpacityEffect(ui->imag);
    ui->imag->setGraphicsEffect(grEffect4);
    imag11->setTargetObject(grEffect4);
    imag11->setPropertyName("opacity");
    imag11->setStartValue(0.0);
    imag11->setEndValue(2.0);
    imag11->setDuration(1000);
    imag11->start();

    QPropertyAnimation *imag1_push = new QPropertyAnimation(ui->real_push_2, "geometry");
    imag1_push->setDuration(500);
    imag1_push->setStartValue(QRect(550, 230, 160, 31));
    imag1_push->setEndValue(QRect(285, 221, 160, 31));
    imag1_push->start();

    QPropertyAnimation *real1_push = new QPropertyAnimation(ui->real_push, "geometry");
    real1_push->setDuration(500);
    real1_push->setStartValue(QRect(-170, 230, 160, 31));
    real1_push->setEndValue(QRect(75, 221, 160, 31));
    real1_push->start();
}
}


void trig1::on_real_push_clicked()
{
    ui->real->clear();
    ui->real_push->hide();
}


void trig1::on_real_push_2_clicked()
{
    ui->imag->clear();
    ui->real_push_2->hide();
}

