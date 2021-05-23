#include "del.h"
#include "ui_del.h"

#include <QFile>
#include <QTextStream>
#include <QMovie>
QFile DelSize("C:/Qt/Kommyvoyager/MatrixSize.txt");
QTextStream DDelSize(&DelSize);
QFile DelMatrix("C:/Qt/Kommyvoyager/Matrix.txt");
QTextStream DDelMatrix(&DelMatrix);

int Delw;       // Delete len
int** delmatrix;  // Matrix (уже с удалённым элементом)
int** temp_matr;     // Matrix

Del::Del(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Del)
{
    ui->setupUi(this);

    QMovie *mov = new QMovie(":/Files/del.gif");
    ui->del->setMovie(mov);
    mov->start();
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    DelSize.open(QFile::ReadOnly | QFile::Text);
    bool ok;
    QString row = DDelSize.readLine();
    if (row.toInt(&ok, 10))
    {
        Delw = row.toInt(0, 10);
        Delw--;
        temp_matr = new int* [Delw + 1];
        delmatrix = new int*[Delw];
        for (int i = 0; i < Delw; i++)
        {
            temp_matr[i] = new int[Delw + 1];
            delmatrix[i] = new int [Delw];
        }
        temp_matr[Delw] = new int[Delw + 1];
        DelMatrix.close();
        DelMatrix.open(QFile::ReadOnly | QFile::Text);
        for (int i = 0; i < Delw + 1; i++)
        {
            for (int j = 0; j < Delw + 1; j++)
            {
                temp_matr[i][j] = DDelMatrix.readLine().toInt(0, 10);
            }
        }
        DelMatrix.flush();
        DelMatrix.close();

        connect(ui->btnDelete, &QPushButton::clicked, this, &Del::delCity);
    }
}

void Del::delCity()
{
    bool isWritten;
    if ((ui->deleteNode->toPlainText().toInt(&isWritten, 10)))
    {
        int Idel = ui->deleteNode->toPlainText().toInt(0, 10) - 1,
            Jdel = ui->deleteNode->toPlainText().toInt(0, 10) - 1;

        int k = 0;
        for (int i = 0; i < Delw + 1; i++)
        {
            if (i != Idel)
            {
                int l = 0;
                for (int j = 0; j < Delw + 1; j++)
                {
                    if (j != Jdel)
                    {
                        delmatrix[k][l] = temp_matr[i][j];
                        l++;
                    }
                }
                k++;
            }
        }
        DelSize.flush();
        DelSize.close();
        DelSize.open(QFile::WriteOnly | QFile::Text);
        DDelSize << QString::number(Delw);
        DelSize.flush();
        DelSize.close();
        DelMatrix.open(QFile::WriteOnly | QFile::Text);
        for (int i = 0; i < Delw; i++)
        {
            for (int j = 0; j < Delw; j++)
            {
                DDelMatrix << QString::number(delmatrix[i][j]) << "\n";
            }
        }
        DelMatrix.close();
        close();
    }
}

Del::~Del()
{
    delete ui;
}
