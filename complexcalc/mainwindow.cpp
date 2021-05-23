#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)                                //МЕНЮ//
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QMovie *mov = new QMovie(":/clock.gif");
    ui->clock->setMovie(mov);
    mov->start();

    algWindow = new alg1();
    trigWindow = new trig1();
    expWindow = new exp1();

    connect(algWindow, &alg1::firstWindow, this, &MainWindow::show);
    connect(trigWindow, &trig1::firstWindow, this, &MainWindow::show);
    connect(expWindow, &exp1::firstWindow, this, &MainWindow::show);

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_exp_clicked()
{
    expWindow->show();
}
void MainWindow::on_trig_clicked()
{
    trigWindow->show();
}
void MainWindow::on_alg_clicked()
{
    algWindow->show();
}

