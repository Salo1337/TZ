#ifndef TRIG_H
#define TRIG_H
#include <QWidget>

namespace Ui {
class trig1;
}

class trig1 : public QWidget
{
    Q_OBJECT

signals:
    void firstWindow();

public:
    explicit trig1(QWidget *parent = nullptr);
    ~trig1();

private slots:

    void on_per_pressed();


    void on_first_currentTextChanged(const QString &arg1);


    void on_podtv_clicked();


    void on_real_push_clicked();

    void on_real_push_2_clicked();

private:
    Ui::trig1 *ui;
};

#endif // TRIG_H
