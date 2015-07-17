#ifndef CELULABILHAR_H
#define CELULABILHAR_H
#include "math/vec4.h"
#include <GL/glut.h>
class CelulaBilhar
{
public:
    long int  idcel;
    Vec4 coord;
    Vec4 velocity;
    float magnitude;
    Vec4 color;
    QList<int> visinhos;
    bool type;

public:
    CelulaBilhar();
    CelulaBilhar(int id, Vec4 coord, Vec4 velocity, float magnitude, Vec4 color, bool type=false);
    void drawCelula();
    void addVisinho(long int idv);
    bool isVisinho(long int idc); //verifica visinhança
    void showVisinhos();

};

#endif // CELULABILHAR_H
