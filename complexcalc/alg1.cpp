#include "alg1.h"
#include "ui_alg1.h"
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
#include <QValidator>

#define DOUBLE_RX "^[0-9]+\\.?[0-9]*$"
#define PI 3.14159265358979323846


using namespace std;


alg1::alg1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::alg1)
{
     ui->setupUi(this);
     QMovie *mov = new QMovie(":/orange/orange.gif");
     ui->back->setMovie(mov);
     mov->start();

     setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

     ui->alg_text->setAlignment(Qt::AlignCenter);
     ui->atan->setAlignment(Qt::AlignCenter);
     ui->AAA1->setAlignment(Qt::AlignCenter);

     ui->clear->hide();
     ui->ramka->setReadOnly(true);
     ui->alg_2->hide();

ui->real1->setValidator(new QRegExpValidator(QRegExp("[-1-9][0-9]{1,11}\\.[0-9]{1,5}|[0-9]\\.[0-9]{1,5}")));
ui->imag1->setValidator(new QRegExpValidator(QRegExp("[-1-9][0-9]{1,11}\\.[0-9]{1,5}|[0-9]\\.[0-9]{1,5}")));
ui->real2->setValidator(new QRegExpValidator(QRegExp("[-1-9][0-9]{1,11}\\.[0-9]{1,5}|[0-9]\\.[0-9]{1,5}")));
ui->imag2->setValidator(new QRegExpValidator(QRegExp("[-1-9][0-9]{1,11}\\.[0-9]{1,5}|[0-9]\\.[0-9]{1,5}")));

}

alg1::~alg1()
{
    delete ui;
}

void alg1::on_rez_pressed()
{
    ui -> ramka -> show();
    if((ui->first->currentIndex()==0)||(ui->second->currentIndex()==0))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Выберите форму чисел");
        messageBox.setFixedSize(500,200);
    }
    else
        if(ui->oper->currentIndex()==0)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Выберите операцию");
        messageBox.setFixedSize(500,200);
    }
    else
    {
    complex <double> e;

    double a,b,k,m,realCH,imagCH,delInaR,sincos, sincos1,REAL,IMAG,sincos2,REAL1,IMAG1;

    string real1viv,imag1viv,newText, newText2, newTextAAA,Atan;
    QString newText1,newText3, newTextAA,Qatan,Qreal1,Qimag1,Qreal2,Qimag2;

    int AAA;

    a= ui-> real1->text().toDouble();
    Qreal1=QString::number(a);
    b = ui-> imag1->text().toDouble();
    Qimag1=QString::number(b);                               //1 число
    complex <double> c(a,b);



    k = ui-> real2->text().toDouble();
    Qreal2=QString::number(k);
    m = ui-> imag2->text().toDouble();
    Qimag2=QString::number(m);                                      //2 число
    complex <double> r(k,m);


    if(ui->oper->currentIndex()==1)
    {
      e = c+r;
    }

    if(ui->oper->currentIndex()==2)
    {
      e = c-r;
    }
    if(ui->oper->currentIndex()==3)
    {
      e = c*r;
    }
    if(ui->oper->currentIndex()==4)
    {
      e = c/r;
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


if(ui->first->currentIndex()==1 && ui->second->currentIndex()==1){
   if(ui->oper->currentIndex()==1)
   {
    ui->alg_text->setText("(" + Qreal1 + "+ i*"+ Qimag1+ ") + (" + Qreal2 + "+ i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
   }
   if(ui->oper->currentIndex()==2)
   {
    ui->alg_text->setText("(" + Qreal1 + "+ i*"+ Qimag1+ ") - (" + Qreal2 + "+ i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
   }
   if(ui->oper->currentIndex()==3)
   {
    ui->alg_text->setText("(" + Qreal1 + "+ i*"+ Qimag1+ ") * (" + Qreal2 + "+ i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
   }
   if(ui->oper->currentIndex()==4)
   {
    ui->alg_text->setText("(" + Qreal1 + "+ i*"+ Qimag1+ ") / (" + Qreal2 + "+ i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
   }
   ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
   ui->atan->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
    }
   if((ui->first->currentIndex()==1 && ui->second->currentIndex()==2)||(ui->first->currentIndex()==1 && ui->second->currentIndex()==3))
   {
        sincos1 = (PI/180)*m;

        REAL = k*cos(sincos1);
        IMAG = k*sin(sincos1);

        complex <double> r(REAL,IMAG);

       if(ui->oper->currentIndex()==1)
       {
         e = c+r;
       }

       if(ui->oper->currentIndex()==2)
       {
         e = c-r;
       }
       if(ui->oper->currentIndex()==3)
       {
         e = c*r;
       }
       if(ui->oper->currentIndex()==4)
       {
         e = c/r;
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

if (ui->first->currentIndex()==1 && ui->second->currentIndex()==2){
       if(ui->oper->currentIndex()==1)
       {
        ui->alg_text->setText("(" + Qreal1 + " + i*"+ Qimag1+ ") + " + Qreal2 + "*(cos(" + Qimag2 + "°) + sin(" + Qimag2+ "°)) = (" + newText1 + " + i*" + newText3+")");
       }
       if(ui->oper->currentIndex()==2)
       {
           ui->alg_text->setText("(" + Qreal1 + "+ i*"+ Qimag1+ ") - " + Qreal2 + "*(cos(" + Qimag2 + "°) + sin(" + Qimag2+ "°)) = (" + newText1 + " + " +"i*" + newText3+")");
       }
       if(ui->oper->currentIndex()==3)
       {
           ui->alg_text->setText("(" + Qreal1 + "+ i*"+ Qimag1+ ") * " + Qreal2 + "*(cos(" + Qimag2 + "°) + sin(" + Qimag2+ "°)) = (" + newText1 + " + " +"i*" + newText3+")");
       }
       if(ui->oper->currentIndex()==4)
       {
            ui->alg_text->setText("(" + Qreal1 +"+" +"i*"+ Qimag1+ ")"+"/"+"(" + Qreal2 + "*(cos(" + Qimag2 + ") + sin(" + Qimag2+ ") = " + newText1 + " + " +"i*" + newText3);
       }
       ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
       ui->atan->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
       }
if( ui->first->currentIndex()==1 && ui->second->currentIndex()==3)
       {
       if(ui->oper->currentIndex()==1)
       {
        ui->alg_text->setText("(" + Qreal1 +" + i*"+ Qimag1+ ") + " + Qreal2 + "*(e^" + Qimag2 + "*i) = (" + newText1 + " + " +"i*" + newText3 + ")");
       }
       if(ui->oper->currentIndex()==2)
       {
           ui->alg_text->setText("(" + Qreal1 +" + i*"+ Qimag1+ ") - " + Qreal2 + "*(e^" + Qimag2 + "*i) = (" + newText1 + " + " +"i*" + newText3 + ")");
       }
       if(ui->oper->currentIndex()==3)
       {
           ui->alg_text->setText("(" + Qreal1 +" + i*"+ Qimag1+ ") * " + Qreal2 + "*(e^" + Qimag2 + "*i) = (" + newText1 + " + " +"i*" + newText3 + ")");
       }
       if(ui->oper->currentIndex()==4)
       {
           ui->alg_text->setText("(" + Qreal1 +" + i*"+ Qimag1+ ") / " + Qreal2 + "*(e^" + Qimag2 + "*i) = (" + newText1 + " + " +"i*" + newText3 + ")");
       }
       ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
       ui->atan->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
       }
   }
if(ui->first->currentIndex()==2 && ui->second->currentIndex()==1)
{
    sincos1 = (PI/180)*b;

    REAL = a*cos(sincos1);
    IMAG = a*sin(sincos1);

    complex <double> c(REAL,IMAG);
    complex <double> r(k,m);

    if(ui->oper->currentIndex()==1)
    {
      e = c+r;
    }
    if(ui->oper->currentIndex()==2)
    {
      e = c-r;
    }
    if(ui->oper->currentIndex()==3)
    {
      e = c*r;
    }
    if(ui->oper->currentIndex()==4)
    {
      e = c/r;
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

    if(ui->oper->currentIndex()==1)
    {
     ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1 + "°) + i*sin("+ Qimag1 +"°)) + (" + Qreal2 +" + i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
    }
    if(ui->oper->currentIndex()==2)
    {
        ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1 + "°) + i*sin("+ Qimag1 +"°)) - (" + Qreal2 +" + i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
    }
    if(ui->oper->currentIndex()==3)
    {
        ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1 + "°) + i*sin("+ Qimag1 +"°)) * (" + Qreal2 +" + i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
    }
    if(ui->oper->currentIndex()==4)
    {
        ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1 + "°) + i*sin("+ Qimag1 +"°)) / (" + Qreal2 +" + i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
    }
    ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
    ui->atan->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
}
if((ui->first->currentIndex()==2 && ui->second->currentIndex()==2) || (ui->first->currentIndex()==3 && ui->second->currentIndex()==3))
{
     sincos1 = (PI/180)*b;
     sincos2 = (PI/180)*m;

     REAL = a*cos(sincos1);
     IMAG = a*sin(sincos1);

     REAL1 = k*cos(sincos2);
     IMAG1 = k*sin(sincos2);

    complex <double> c(REAL,IMAG);
    complex <double> r(REAL1,IMAG1);

    if(ui->oper->currentIndex()==1)
    {
      e = c+r;
    }
    if(ui->oper->currentIndex()==2)
    {
      e = c-r;
    }
    if(ui->oper->currentIndex()==3)
    {
      e = c*r;
    }
    if(ui->oper->currentIndex()==4)
    {
      e = c/r;
    }

    realCH = real(e);
    imagCH = imag(e);

    AAA = sqrt(pow(realCH,2)+pow(imagCH,2));
    delInaR = imagCH/realCH;
    sincos = (180/PI)*atan(delInaR);

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

if(ui->first->currentIndex()==2 && ui->second->currentIndex()==2){
    if(ui->oper->currentIndex()==1)
    {
     ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1 + "°)+i*sin("+ Qimag1 +"°)) + " + Qreal2 + "*(cos(" + Qimag2 + "°)+i*sin("+ Qimag2 +"°)) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==2)
    {
        ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1 + "°)+i*sin("+ Qimag1 +"°)) - " + Qreal2 + "*(cos(" + Qimag2 + "°)+i*sin("+ Qimag2 +"°)) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==3)
    {
        ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1 + "°)+i*sin("+ Qimag1 +"°)) * " + Qreal2 + "*(cos(" + Qimag2 + "°)+i*sin("+ Qimag2 +"°)) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==4)
    {
        ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1 + "°)+i*sin("+ Qimag1 +"°)) / " + Qreal2 + "*(cos(" + Qimag2 + "°)+i*sin("+ Qimag2 +"°)) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
    ui->atan->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
}

if(ui->first->currentIndex()==3 && ui->second->currentIndex()==3){
    if(ui->oper->currentIndex()==1)
    {
     ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1+ "°*i) + " + Qreal2 + "*e^(" + Qimag2+ "°*i) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==2)
    {
        ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1+ "°*i) - " + Qreal2 + "*e^(" + Qimag2+ "°*i) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==3)
    {
        ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1+ "°*i) * " + Qreal2 + "*e^(" + Qimag2+ "°*i) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==4)
    {
        ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1+ "°*i) / " + Qreal2 + "*e^(" + Qimag2+ "°*i) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
    ui->atan->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
}
}

if((ui->first->currentIndex()==2 && ui->second->currentIndex()==3)||(ui->first->currentIndex()==3 && ui->second->currentIndex()==2))
{
     sincos1 = (PI/180)*b;
     sincos2 = (PI/180)*m;

     REAL = a*cos(sincos1);
     IMAG = a*sin(sincos1);

     REAL1 = k*cos(sincos2);
     IMAG1 = k*sin(sincos2);

    complex <double> c(REAL,IMAG);
    complex <double> r(REAL1,IMAG1);

    if(ui->oper->currentIndex()==1)
    {
      e = c+r;
    }
    if(ui->oper->currentIndex()==2)
    {
      e = c-r;
    }
    if(ui->oper->currentIndex()==3)
    {
      e = c*r;
    }
    if(ui->oper->currentIndex()==4)
    {
      e = c/r;
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
if(ui->first->currentIndex()==2 && ui->second->currentIndex()==3)
{
    if(ui->oper->currentIndex()==1)
    {
     ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1+ "°)+i*sin("+Qimag1+"°)) + " + Qreal2 + "*e^(" + Qimag2+ "°*i) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==2)
    {
        ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1+ "°)+i*sin("+Qimag1+"°)) - " + Qreal2 + "*e^(" + Qimag2+ "°*i) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==3)
    {
        ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1+ "°)+i*sin("+Qimag1+"°)) * " + Qreal2 + "*e^(" + Qimag2+ "°*i) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==4)
    {
        ui->alg_text->setText(Qreal1 + "*(cos(" + Qimag1+ "°)+i*sin("+Qimag1+"°)) / " + Qreal2 + "*e^(" + Qimag2+ "°*i) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
    ui->atan->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
}
if(ui->first->currentIndex()==3 && ui->second->currentIndex()==2)
{
    if(ui->oper->currentIndex()==1)
    {
     ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1+ "°*i) + " + Qreal2 + "*(cos(" + Qimag2+ "°)+i*sin("+Qimag2+"°)) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==2)
    {
        ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1+ "°*i) - " + Qreal2 + "*(cos(" + Qimag2+ "°)+i*sin("+Qimag2+"°)) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==3)
    {
        ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1+ "°*i) * " + Qreal2 + "*(cos(" + Qimag2+ "°)+i*sin("+Qimag2+"°)) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    if(ui->oper->currentIndex()==4)
    {
        ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1+ "°*i) / " + Qreal2 + "*(cos(" + Qimag2+ "°)+i*sin("+Qimag2+"°)) = (" + newText1 + " + " +"i*" + newText3+")");
    }
    ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
    ui->atan->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
}
}
if(ui->first->currentIndex()==3 && ui->second->currentIndex()==1)
{
     sincos1 = (PI/180)*b;

     REAL = a*cos(sincos1);
     IMAG = a*sin(sincos1);

    complex <double> c(REAL,IMAG);
    complex <double> r(k,m);

    if(ui->oper->currentIndex()==1)
    {
      e = c+r;
    }
    if(ui->oper->currentIndex()==2)
    {
      e = c-r;
    }
    if(ui->oper->currentIndex()==3)
    {
      e = c*r;
    }
    if(ui->oper->currentIndex()==4)
    {
      e = c/r;
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

    if(ui->oper->currentIndex()==1)
    {
     ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1 + "°*i) + (" + Qreal2 +"+ i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
    }

    if(ui->oper->currentIndex()==2)
    {
        ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1 + "°*i) - (" + Qreal2 +"+ i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
    }
    if(ui->oper->currentIndex()==3)
    {
        ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1 + "°*i) - (" + Qreal2 +"+ i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
    }
    if(ui->oper->currentIndex()==4)
    {
        ui->alg_text->setText(Qreal1 + "*e^(" + Qimag1 + "°*i) / (" + Qreal2 +"+ i*"+ Qimag2+ ") = (" + newText1 + " + i*" + newText3 + ")");
    }
    ui->AAA1->setText(newTextAA +"*e^" + "("+Qatan+"°*i)");
    ui->atan->setText(newTextAA +"*(" +"cos"+ "("+Qatan+"°) +" + " i*sin(" + Qatan + "°))");
}
}
}

void alg1::on_podtv_clicked()
{
    if((ui->first->currentIndex()==0)||(ui->second->currentIndex()==0))
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Выберите форму числа");
        messageBox.setFixedSize(500,200);
    }
    else
    {
        ui->alg->hide();
        ui->alg_2->show();
        ui->podtv->hide();
        ui->clear->show();

        QPropertyAnimation *animation = new QPropertyAnimation(ui->rez, "geometry");
        animation->setDuration(500);
        animation->setStartValue(QRect(220, 183, 80, 22));
        animation->setEndValue(QRect(80, 100, 80, 22));
        animation->start();



        QPropertyAnimation *anim = new QPropertyAnimation(ui->first, "geometry");
        anim->setDuration(500);
        anim->setStartValue(QRect(190, 148, 141, 22));
        anim->setEndValue(QRect(20, 60, 141, 22));
        anim->start();

        QPropertyAnimation *anima = new QPropertyAnimation(ui->second, "geometry");
        anima->setDuration(500);
        anima->setStartValue(QRect(190, 218, 141, 22));
        anima->setEndValue(QRect(20, 140, 141, 22));
        anima->start();


        QPropertyAnimation *real1 = new QPropertyAnimation(ui->real1, "geometry");
        real1->setDuration(500);
        real1->setStartValue(QRect(170, -200, 160, 31));
        real1->setEndValue(QRect(170, 60, 160, 31));
        real1->start();
        QPropertyAnimation* real11 = new QPropertyAnimation(ui->real1);//Код для QPushButton
        QGraphicsOpacityEffect* grEffect5 = new QGraphicsOpacityEffect(ui->real1);
        ui->real1->setGraphicsEffect(grEffect5);
        real11->setTargetObject(grEffect5);
        real11->setPropertyName("opacity");
        real11->setStartValue(0.0);
        real11->setEndValue(2.0);
        real11->setDuration(1000);
        real11->start();


        QPropertyAnimation *imag1 = new QPropertyAnimation(ui->imag1, "geometry");
        imag1->setDuration(500);
        imag1->setStartValue(QRect(340, -200, 160, 31));
        imag1->setEndValue(QRect(340, 60, 160, 31));
        imag1->start();
        QPropertyAnimation* imag11 = new QPropertyAnimation(ui->imag1);//Код для QPushButton
        QGraphicsOpacityEffect* grEffect4 = new QGraphicsOpacityEffect(ui->imag1);
        ui->imag1->setGraphicsEffect(grEffect4);
        imag11->setTargetObject(grEffect4);
        imag11->setPropertyName("opacity");
        imag11->setStartValue(0.0);
        imag11->setEndValue(2.0);
        imag11->setDuration(1000);
        imag11->start();


        QPropertyAnimation *real2 = new QPropertyAnimation(ui->real2, "geometry");
        real2->setDuration(500);
        real2->setStartValue(QRect(170, 500, 160, 31));
        real2->setEndValue(QRect(170, 140, 160, 31));
        real2->start();
        QPropertyAnimation* real22 = new QPropertyAnimation(ui->real2);//Код для QPushButton
        QGraphicsOpacityEffect* grEffect = new QGraphicsOpacityEffect(ui->real2);
        ui->real2->setGraphicsEffect(grEffect);
        real22->setTargetObject(grEffect);
        real22->setPropertyName("opacity");
        real22->setStartValue(0.0);
        real22->setEndValue(2.0);
        real22->setDuration(1000);
        real22->start();


        QPropertyAnimation *imag2 = new QPropertyAnimation(ui->imag2, "geometry");
        imag2->setDuration(500);
        imag2->setStartValue(QRect(340, 500, 160, 31));
        imag2->setEndValue(QRect(340, 140, 160, 31));
        imag2->start();

        QPropertyAnimation* imag22 = new QPropertyAnimation(ui->imag2);//Код для QPushButton
        QGraphicsOpacityEffect* grEffect1 = new QGraphicsOpacityEffect(ui->imag2);
        ui->imag2->setGraphicsEffect(grEffect1);
        imag22->setTargetObject(grEffect1);
        imag22->setPropertyName("opacity");
        imag22->setStartValue(0.0);
        imag22->setEndValue(2.0);
        imag22->setDuration(1000);
        imag22->start();


        QPropertyAnimation *oper = new QPropertyAnimation(ui->oper, "geometry");
        oper->setDuration(500);
        oper->setStartValue(QRect(600, 100, 131, 22));
        oper->setEndValue(QRect(260, 105, 131, 22));
        oper->start();

        QPropertyAnimation* oper1 = new QPropertyAnimation(ui->oper);//Код для QPushButton
        QGraphicsOpacityEffect* grEffect2 = new QGraphicsOpacityEffect(ui->oper);
        ui->oper->setGraphicsEffect(grEffect2);
        oper1->setTargetObject(grEffect2);
        oper1->setPropertyName("opacity");
        oper1->setStartValue(0.0);
        oper1->setEndValue(1.0);
        oper1->setDuration(1000);
        oper1->start();


        QPropertyAnimation *ramka = new QPropertyAnimation(ui->ramka, "geometry");
        ramka->setDuration(750);
        ramka->setStartValue(QRect(10, 500, 520, 140));
        ramka->setEndValue(QRect(10, 220, 500, 140));
        ramka->start();


        QPropertyAnimation *real2_push = new QPropertyAnimation(ui->real2_push, "geometry");
        real2_push->setDuration(500);
        real2_push->setStartValue(QRect(170, 110, 160, 31));
        real2_push->setEndValue(QRect(170, 140, 160, 31));
        real2_push->start();
    }
}

void alg1::on_first_currentTextChanged(const QString &arg1)
{
    ui->imag1_push->show();
    ui->real1_push->show();

    if(ui->first->currentIndex()==1)
      {
          ui->real1->setText("Действительная ч.");
      }

    if((ui->first->currentIndex()==2)||(ui->first->currentIndex()==3))
      {
          ui->real1->setText("Модуль числа");
      }

    if(ui->first->currentIndex()==1)
      {
          ui->imag1->setText("Мнимая часть");
      }

    if((ui->first->currentIndex()==2)||(ui->first->currentIndex()==3))
      {
          ui->imag1->setText("Аргумент Ф.");
      }
}

void alg1::on_second_currentTextChanged(const QString &arg1)
{
   ui->imag2_push->show();
   ui->real2_push->show();
    if(ui->second->currentIndex()==1)
      {
          ui->real2->setText("Действительная ч.");
      }
    if((ui->second->currentIndex()==2)||(ui->second->currentIndex()==3))
      {
          ui->real2->setText("Модуль числа");
      }
    if(ui->second->currentIndex()==1)
      {
          ui->imag2->setText("Мнимая часть");
      }
    if((ui->second->currentIndex()==2)||(ui->second->currentIndex()==3))
      {
          ui->imag2->setText("Аргумент Ф.");
      }
}

void alg1::on_imag2_push_clicked()
{
    ui->imag2->clear();
    ui->imag2_push->hide();
}

void alg1::on_imag1_push_clicked()
{
    ui->imag1->clear();
    ui->imag1_push->hide();
}

void alg1::on_real1_push_clicked()
{
    ui->real1->clear();
    ui->real1_push->hide();
}

void alg1::on_real2_push_clicked()
{
    ui->real2->clear();
    ui->real2_push->hide();
}


