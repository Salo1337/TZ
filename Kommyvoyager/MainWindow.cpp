#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
#include <QProcess>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openGLW = new GlW(this);
    ui->grid->addWidget(openGLW, 0, 0);
    ui->white->setReadOnly(true);
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::Add1);
    connect(ui->btnEdit, &QPushButton::clicked, this, &MainWindow::Ed1);
    connect(ui->btnDelete, &QPushButton::clicked, this, &MainWindow::Del1);
}


void MainWindow::Add1()
{
    Add window;
    window.setModal(true);
    window.exec();
}

void MainWindow::Ed1()
{
    Ed window;
    window.setModal(true);
    window.exec();
}

void MainWindow::Del1()
{
    Del window;
    window.setModal(true);
    window.exec();

}


void MainWindow::on_btnAnswerr_clicked()
{
    ui->put->setText(komi.GetResult(ui->rootText->toPlainText()));
    ui->lengthText->setText(komi.WayLength(ui->rootText->toPlainText()));
}


void MainWindow::on_btnAnswer_clicked()
{
    ui->put->setText(komi.GetResult(ui->rootText->toPlainText()));
    ui->lengthText->setText(komi.WayLength(ui->rootText->toPlainText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
