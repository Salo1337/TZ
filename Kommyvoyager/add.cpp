#include "add.h"
#include "ui_add.h"

#include <QFile>
#include <QTextStream>

QFile MSize("C:/Qt/Kommyvoyager/MatrixSize.txt");
QTextStream MMSize(&MSize);
QFile MMatrix("C:/Qt/Kommyvoyager/Matrix.txt");
QTextStream MMMatrix(&MMatrix);

int ADDW;
int** ADDMatrix;

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);

    MSize.open(QFile::ReadOnly | QFile::Text);
    ADDW = MMSize.readLine().toInt(0, 10) + 1;
    MSize.flush();
    MSize.close();
    MSize.open(QFile::WriteOnly | QFile::Text);
    MMSize << QString::number(ADDW);
    MSize.flush();
    MSize.close();
    ADDMatrix = new int* [ADDW];
    for (int i = 0; i < ADDW; i++)
    {
        ADDMatrix[i] = new int [ADDW];
    }

    for (int i = 0; i < ADDW; i++)
    {
        for (int j = 0; j < ADDW; j++)
        {
            ADDMatrix[i][j] = 0;
        }
    }
     connect(ui->btnAdd, &QPushButton::clicked, this, &Add::City);

}



void Add::City()
{
    MMatrix.close();
    MMatrix.open(QFile::ReadOnly | QFile::Text);
    for (int i = 0; i < ADDW - 1; i++)
    {
        for (int j = 0; j < ADDW - 1; j++)
        {
            ADDMatrix[i][j] = MMMatrix.readLine().toInt(0, 10);
        }
    }
    MMatrix.flush();
    MMatrix.close();
    MMatrix.open(QFile::WriteOnly | QFile::Text);
    for (int i = 0; i < ADDW; i++)
    {
        for (int j = 0; j < ADDW; j++)
        {
            MMMatrix << QString::number(ADDMatrix[i][j]) << "\n";
        }
    }
    MMatrix.close();
    close();
}

Add::~Add()
{
    delete ui;
}
