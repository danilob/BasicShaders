#include "celulabilhar.h"

#define SIZEPOINT 0.3

CelulaBilhar::CelulaBilhar()
{
}

CelulaBilhar::CelulaBilhar(int id, Vec4 coord, Vec4 velocity, float magnitude, Vec4 color, bool type)
{
    this->idcel = id;
    this->coord = coord;
    this->velocity = velocity;
    this->magnitude = magnitude;
    this->color = color;
    this->type = type;
}

void CelulaBilhar::drawCelula()
{
    glPointSize(SIZEPOINT);
    glColor3f(color.x(),color.y(), color.z());
    glBegin(GL_POINTS);
        glVertex3f(coord.x(),coord.y(),0);
    glEnd();
}

void CelulaBilhar::addVisinho(long int idv)
{
    visinhos.append(idv);
}

bool CelulaBilhar::isVisinho(long int idc)
{
    for (long int i=0;i<visinhos.size();i++){
        if (idc==visinhos.at(i)){
            return true;
        }
    }
    return false;
}

void CelulaBilhar::showVisinhos()
{
    qDebug() << "Cell: "<< idcel;
    for (long int i=0;i<visinhos.size();i++){
            printf("%d \t" ,visinhos.at(i));

    }
}

