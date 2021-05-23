#ifndef EXP1_H
#define EXP1_H
#include <QWidget>

namespace Ui {
class exp1;
}

class exp1 : public QWidget
{
    Q_OBJECT

public:
    explicit exp1(QWidget *parent = nullptr);
    ~exp1();
signals:
    void firstWindow();
private slots:

    void on_first_currentTextChanged(const QString &arg1);
    void on_real_push_clicked();
    void on_real_push_2_clicked();
    void on_podtv_clicked();

    void on_per_clicked();

    void on_oper_currentTextChanged(const QString &arg1);

private:
    Ui::exp1 *ui;
};

#endif // EXP1_H
