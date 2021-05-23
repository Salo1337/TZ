#include "GL.h"
#include "drawner.h"
#include <QPainter>

GlW::GlW(QWidget *parent)
    :QOpenGLWidget(parent)
{
    Drawner = new drawner;
}

void GlW::paintEvent(QPaintEvent *event)
{
    QPainter paint;
    paint.begin(this);
    Drawner->draw(&paint, event);
    paint.end();
}

