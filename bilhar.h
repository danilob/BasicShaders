#ifndef BILHAR_H
#define BILHAR_H
#include <QList>
#include "celulabilhar.h"

class Bilhar
{
    QList<CelulaBilhar> celulas;
    Vec4 color_old;
    Vec4 color_new;
    long int size;

public:
    Bilhar();
    bool loadArquivo(QString Arq);   
    void showBilhar(int type = 0);
    void interpolateCells();

};

#endif // BILHAR_H
