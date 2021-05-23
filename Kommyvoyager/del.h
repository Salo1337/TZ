#ifndef DELEH_H
#define DELEH_H

#include <QDialog>

namespace Ui {
class Del;
}

class Del : public QDialog
{
    Q_OBJECT

public:
    explicit Del(QWidget *parent = nullptr);
    ~Del();

private slots:

    void delCity();


private:
    Ui::Del *ui;
};

#endif // DELEH_H
