#ifndef QTWINDOW_H
#define QTWINDOW_H

#include <QMainWindow>
#include "GL.h"
#include "add.h"
#include "route.h"
#include "del.h"
#include "komi.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Add1();
    void Ed1();
    void Del1();
    void on_btnAnswerr_clicked();
    void on_btnAnswer_clicked();

private:
    Ui::MainWindow *ui;
    GlW *openGLW;
    komi komi;
};

#endif // QTWINDOW_H
