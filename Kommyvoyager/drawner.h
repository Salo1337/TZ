#ifndef DRAWNER_H
#define DRAWNER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class drawner
{
public:
    drawner();

public:
    void draw(QPainter *painter, QPaintEvent *event);
    void addMatr();
    void city_add();
    void city_del();
    QBrush front;

private:
    QBrush back;
    QFont glFont;
    QPen textPen;
};

#endif // DRAWNER_H
