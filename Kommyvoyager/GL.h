#ifndef GL_H
#define GL_H

#include "drawner.h"
#include <QOpenGLWidget>

class GlW : public QOpenGLWidget
{
    Q_OBJECT

public:
    GlW( QWidget *parent);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    drawner *Drawner;
};


#endif // GL_H

