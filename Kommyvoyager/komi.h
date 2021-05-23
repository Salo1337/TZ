#ifndef KOMI_H
#define KOMI_H

#include <QString>

class komi
{
public:
    komi();
    ~komi();

    QString GetResult(QString root);
    QString WayLength(QString root);

private:
    int cityNum(int I, int J);
    void delCity(int I, int J);
    void Way(int Node);
    void Matrix_Size();

private:
    int Mainlen;
    int di;
    int** MainMatrix;
    int** Mtemp;
    int** roads;
    int Result = 0;
    int start;
    QString way;
    int counter;
};

#endif // KOMI_H
