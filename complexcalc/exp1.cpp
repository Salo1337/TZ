#include "exp1.h"
#include "ui_exp1.h"
#include <QMainWindow>
#include <complex>
#include <cmath>
#include<cstdlib>
#include<string>
#include<sstream>
#include <QMessageBox>
#include <QString>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <iomanip>
#include <QMovie>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QValidator>
#include <QRegExpValidator>

#define DOUBLE_RX "^[0-9]+\\.?[0-9]*$"
#define PI 3.14159265358979323846

using namespace std;

exp1::exp1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exp1)
{
    ui->setupUi(this);

    QMovie *mov = new QMovie(":red.gif");
    ui->fon->setMovie(mov);
    mov->start();
    ui->pow->hide();
    ui->alg->hide();
    ui->clear->hide();

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->real->setValidator(new QRegExpValidator(QRegExp("[-1-9][0-9]{1,11}\\.[0-9]{1,5}|[0-9]\\.[0-9]{1,5}")));
    ui->imag->setValidator(new QRegExpValidator(QRegExp("[-1-9][0-9]{1,11}\\.[0-9]{1,5}|[0-9]\\.[0-9]{1,5}")));
    ui->pow->setValidator(new QRegExpValidator(QRegExp("[-1-9][0-9]{1,11}")));
    ui->rez->setAlignment(Qt::AlignCenter);
    ui->AAA1->setAlignment(Qt::AlignCenter);
    ui->trigout->setAlignment(Qt::AlignCenter);
}

exp1::~exp1()
{
    delete ui;
}

void exp1::on_first_currentTextChanged(const QString &arg1)
{
    ui->real_push->show();
    ui->real_push_2->show();
    if((ui->first->currentIndex()==0))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Выберите форму чисел");
        messageBox.setFixedSize(500,200);
    } else {
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
}


void exp1::on_real_push_clicked()
{
    ui->real->clear();
    ui->real_push->hide();
}


void exp1::on_real_push_2_clicked()
{
    ui->imag->clear();
    ui->real_push_2->hide();
}


void exp1::on_podtv_clicked()
{
    if (ui->first->currentIndex()==0)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Сделайте выбор");
        messageBox.setFixedSize(500,200);
    }
    else
    {
     ui->alg->show();
     ui->alg_2->hide();
     ui->podtv->hide();
     ui->real_push->show();
     ui->real_push_2->show();
     ui->clear->show();

    QPropertyAnimation *anim = new QPropertyAnimation(ui->first, "geometry");
    anim->setDuration(500);
    anim->setStartValue(QRect(184, 199, 151, 22));
    anim->setEndValue(QRect(184, 90, 151, 22));
    anim->start();

    QPropertyAnimation *per = new QPropertyAnimation(ui->per, "geometry");
    per->setDuration(500);
    per->setStartValue(QRect(220, 250, 80, 22));
    per->setEndValue(QRect(220, 130, 80, 22));
    per->start();

    QPropertyAnimation *real1 = new QPropertyAnimation(ui->real, "geometry");
    real1->setDuration(500);
    real1->setStartValue(QRect(-160, 190, 160, 31));
    real1->setEndValue(QRect(75, 175, 160, 31));
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
    imag1->setStartValue(QRect(550, 190, 160, 31));
    imag1->setEndValue(QRect(285, 175, 160, 31));
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
    imag1_push->setStartValue(QRect(550, 190, 160, 31));
    imag1_push->setEndValue(QRect(285, 175, 160, 31));
    imag1_push->start();

    QPropertyAnimation *real1_push = new QPropertyAnimation(ui->real_push, "geometry");
    real1_push->setDuration(500);
    real1_push->setStartValue(QRect(-170, 190, 160, 31));
    real1_push->setEndValue(QRect(75, 175, 160, 31));
    real1_push->start();

    QPropertyAnimation *oper = new QPropertyAnimation(ui->oper, "geometry");
    oper->setDuration(500);
    oper->setStartValue(QRect(194, 450, 131, 22));
    oper->setEndValue(QRect(194, 215, 131, 22));
    oper->start();
    QPropertyAnimation* oper1 = new QPropertyAnimation(ui->oper);//Код для QPushButton
    QGraphicsOpacityEffect* grEffect7 = new QGraphicsOpacityEffect(ui->oper);
    ui->oper->setGraphicsEffect(grEffect7);
    oper1->setTargetObject(grEffect7);
    oper1->setPropertyName("opacity");
    oper1->setStartValue(0.0);
    oper1->setEndValue(2.0);
    oper1->setDuration(1000);
    oper1->start();

    QPropertyAnimation *ramka = new QPropertyAnimation(ui->ramka, "geometry");
    ramka->setDuration(500);
    ramka->setStartValue(QRect(10, 500, 500, 120));
    ramka->setEndValue(QRect(10, 260, 500, 145));
    ramka->start();
}
}


void exp1::on_per_clicked()
{
    if (ui->first->currentIndex()==0)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Сделайте выбор");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        complex <double> e;

        double a,b,realCH,imagCH,delInaR,sincos, sincos1,REAL,IMAG;

        string real1viv,imag1viv,newText, newText2, newTextAAA,Atan;
        QString newText1,newText3, newTextAA,Qatan,Qreal1,Qimag1,Qx;

        int AAA,x;

        a= ui-> real->text().toDouble();
        Qreal1=QString::number(a);
        b = ui-> imag->text().toDouble();
        Qimag1=QString::number(b);                               //1 число
        complex <double> c(a,b);
        x = ui->pow->text().toDouble();
        Qx=QString::number(x);

        if(ui->oper->currentIndex()==1)
        {
          e = sqrt(c);
        }
        if(ui->oper->currentIndex()==2)
        {
          e = pow(c,x);
        }
        if(ui->oper->currentIndex()==3)
        {
          e = log10(c);
        }
        if(ui->oper->currentIndex()==4)
        {
          e = log(c);
        }


        realCH = real(e);
        imagCH = imag(e);

        AAA = sqrt(pow(realCH,2)+pow(imagCH,2));
        delInaR = imagCH/realCH;

        sincos = 180/PI*atan(delInaR);
        stringstream Atan_temp;
        Atan_temp << fixed << setprecision(2) << sincos;
        Atan = Atan_temp.str();


        if (Atan[Atan.size()-1]=='0')
        for (size_t i=Atan.size()-1; Atan[i]=='0'; i--)
        Atan.erase(i,1);
        if (Atan[Atan.size()-1]=='.')
        Atan.erase(Atan.size()-1,1);

        Qatan=QString::fromStdString(Atan);
        newText = to_string(realCH);

        if (newText[newText.size()-1]=='0')
        for (size_t i=newText.size()-1; newText[i]=='0'; i--)
        newText.erase(i,1);
        if (newText[newText.size()-1]=='.')
        newText.erase(newText.size()-1,1);


        newText2 = to_string(imagCH);

        if (newText2[newText2.size()-1]=='0')
        for (size_t i=newText2.size()-1; newText2[i]=='0'; i--)
        newText2.erase(i,1);
        if (newText2[newText2.size()-1]=='.')
        newText2.erase(newText2.size()-1,1);

        newText1=QString::fromStdString(newText);
        newText3=QString::fromStdString(newText2);

        newTextAAA = to_string(AAA);
        newTextAA=QString::fromStdString(newTextAAA);
        if(ui->first->currentIndex()==1)
        {
            if(ui->oper->currentIndex()==1)                
                {
                ui->rez->setText("√("+Qreal1+" + i*" + Qimag1 + ") = (" + newText1 + " + i*" + newText3 + ")");
                }
            if(ui->oper->currentIndex()==2)
                {
                ui->rez->setText("("+Qreal1+" + i*" + Qimag1 + ")^"+ Qx +" = (" + newText1 + " + i*" + newText3 + ")");
                }
            if(ui->oper->currentIndex()==3)
                {
                ui->rez->setText("Log(10)(" + Qreal1 +" + i*" + Qimag1 + ") = (" + newText1 + " + i*" + newText3 + ")");
                }
            if(ui->oper->currentIndex()==4)
                {
                ui->rez->setText("Log(e)(" + Qreal1 +" + i*" + Qimag1 + ") = (" + newText1 + " + i*" + newText3 + ")");
                }
            ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
            ui->trigout->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
        }

        if((ui->first->currentIndex()==2)||(ui->first->currentIndex()==3))
        {

            x = ui->pow->text().toDouble();
            Qx=QString::number(x);


            sincos1 = (PI*b/180);

            REAL = a*cos(sincos1);
            IMAG = a*sin(sincos1);

            complex <double> c(REAL,IMAG);

            if(ui->oper->currentIndex()==1)
            {
                e = sqrt(c);
            }
            if(ui->oper->currentIndex()==2)
            {
                e = pow(c,x);
            }
            if(ui->oper->currentIndex()==3)
            {
                e = log10(c);
            }
            if(ui->oper->currentIndex()==4)
            {
                e = log(c);
            }


           realCH = real(e);
           imagCH = imag(e);

           AAA = sqrt(pow(realCH,2)+pow(imagCH,2));
           delInaR = imagCH/realCH;

           sincos = 180/PI*atan(delInaR);
           stringstream Atan_temp;
           Atan_temp << fixed << setprecision(2) << sincos;
           Atan = Atan_temp.str();


           if (Atan[Atan.size()-1]=='0')
           for (size_t i=Atan.size()-1; Atan[i]=='0'; i--)
           Atan.erase(i,1);
           if (Atan[Atan.size()-1]=='.')
           Atan.erase(Atan.size()-1,1);

           Qatan=QString::fromStdString(Atan);
           newText = to_string(realCH);

           if (newText[newText.size()-1]=='0')
           for (size_t i=newText.size()-1; newText[i]=='0'; i--)
           newText.erase(i,1);
           if (newText[newText.size()-1]=='.')
           newText.erase(newText.size()-1,1);


           newText2 = to_string(imagCH);

           if (newText2[newText2.size()-1]=='0')
           for (size_t i=newText2.size()-1; newText2[i]=='0'; i--)
           newText2.erase(i,1);
           if (newText2[newText2.size()-1]=='.')
           newText2.erase(newText2.size()-1,1);

           newText1=QString::fromStdString(newText);
           newText3=QString::fromStdString(newText2);

           newTextAAA = to_string(AAA);
           newTextAA=QString::fromStdString(newTextAAA);

            if(ui->first->currentIndex()==2)
            {
                if(ui->oper->currentIndex()==1)
                    {
                    ui->rez->setText("√( "+Qreal1 + "*(cos("+ Qimag1 + "°) + i*sin(" + Qimag1+"°)) = " + newText1 + " + i*(" + newText3 + ")");
                    }
                if(ui->oper->currentIndex()==2)
                    {
                    ui->rez->setText("( "+Qreal1 + "*(cos("+ Qimag1 + "°) + i*sin(" + Qimag1+"°))^" + Qx + " = " + newText1 + " + i*(" + newText3 + ")");
                    }
                if(ui->oper->currentIndex()==3)
                    {
                    ui->rez->setText("Log(10)( "+Qreal1 + "*(cos("+ Qimag1 + "°) + i*sin(" + Qimag1+"°))  = " + newText1 + " + i*(" + newText3 + ")");
                    }
                if(ui->oper->currentIndex()==4)
                    {
                    ui->rez->setText("Log(e)( "+Qreal1 + "*(cos("+ Qimag1 + "°) + i*sin(" + Qimag1+"°)) = " + newText1 + " + i*(" + newText3 + ")");
                    }
                ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
                ui->trigout->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
            }

            if(ui->first->currentIndex()==3)
            {
                if(ui->oper->currentIndex()==1)
                    {
                    ui->rez->setText("√("+Qreal1 + "*e^("+ Qimag1 + "°*i)) = (" + newText1 + " + i*" + newText3 + ")");
                    }
                if(ui->oper->currentIndex()==2)
                    {
                    ui->rez->setText("("+Qreal1 + "*e^("+ Qimag1 + "°*i))^" + Qx + " = (" + newText1 + " + i*" + newText3 + ")");
                    }
                if(ui->oper->currentIndex()==3)
                    {
                    ui->rez->setText("Log(10)("+Qreal1 + "*e^("+ Qimag1 + "°*i)) = (" + newText1 + " + i*" + newText3 + ")");
                    }
                if(ui->oper->currentIndex()==4)
                    {
                    ui->rez->setText("Log(e)("+Qreal1 + "*e^("+ Qimag1 + "°*i)) = (" + newText1 + " + i*" + newText3 + ")");
                    }
                ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
                ui->trigout->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
            }
        }
    }
}





void exp1::on_oper_currentTextChanged(const QString &arg1)
{
    if(ui->oper->currentIndex()==1)
        {
        ui->pow->hide();
        }
    if(ui->oper->currentIndex()==2)
        {
        ui->pow->show();
        }
    if(ui->oper->currentIndex()==3)
        {
        ui->pow->hide();
        }
    if(ui->oper->currentIndex()==4)
        {
        ui->pow->hide();
        }
}

