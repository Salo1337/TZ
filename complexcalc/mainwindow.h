#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "alg1.h"
#include "trig.h"
#include "exp1.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }                      //МЕНЮ//
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

void on_exp_clicked();
void on_trig_clicked();
void on_alg_clicked();

private:
    Ui::MainWindow *ui;
    alg1 *algWindow;
    trig1 *trigWindow;
    exp1 *expWindow;
};
#endif // MAINWINDOW_H
