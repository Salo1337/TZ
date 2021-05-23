#ifndef ALG1_H
#define ALG1_H
#include <QWidget>
#include <QMovie>

namespace Ui {
class alg1;
}
class alg1 : public QWidget
{
    Q_OBJECT

public:
    explicit alg1(QWidget *parent = nullptr);
    ~alg1();
signals:
    void firstWindow();
private slots:

    void on_rez_pressed();
    void on_podtv_clicked();
    void on_first_currentTextChanged(const QString &arg1);
    void on_second_currentTextChanged(const QString &arg1);
    void on_imag2_push_clicked();
    void on_imag1_push_clicked();
    void on_real1_push_clicked();
    void on_real2_push_clicked();

private:
    Ui::alg1 *ui;
    QMovie mo;
};


#endif // ALG1_H
