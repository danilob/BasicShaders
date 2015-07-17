#include "bilhar.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <QFileInfo>
using namespace std;
#define RADIUS 0.02

Bilhar::Bilhar()
{
    size = 0;
    color_old = Vec4(1,1,1); //0~1 red,green,blue
    color_new = Vec4(1,0,0);
}

bool Bilhar::loadArquivo(QString Arq)
{
    size = 0;
    color_old = Vec4(1,1,1);
    color_new = Vec4(1,0,0);
    //Arq.toStdString();
    ifstream file(Arq.toStdString().data(), ios::in);
    if(!file)
    {
        cerr << "File \"" << Arq.toStdString() << "\" not found." << endl;
        return false;
    }

    string header;
    int id;
    file >> header;
    file >> header;
    file >> header;
    file >> header;
    file >> header;
    file >> header;
    float x,y,mag,vx,vy;
    long int i = 0;
    long int interval_min=0, interval_max=800000;
    while (!file.eof()){
        i++;
        file >> id >> x >> y >> mag >> vx >> vy;
        if(i>interval_min && i<interval_max){
            CelulaBilhar newCell(size,Vec4(x,y),Vec4(vx,vy),mag,color_old);
            celulas.append(newCell);
            size++;
            qDebug() << id;
        }
    }


    file.close();
    return true;
}

void Bilhar::showBilhar(int type)
{
    if(type == 0){
        long int i = 0;
        while (i<celulas.size()){
            celulas[i].drawCelula();
            i++;
        }
    }
    if (type == 1){
        long int i = 0;
        while (i<celulas.size()){
            if(celulas[i].type==false)
                 celulas[i].drawCelula();
            i++;
        }
    }
    if(type == 2){
        long int i = 0;
        while (i<celulas.size()){
            if(celulas[i].type==true)
                 celulas[i].drawCelula();
            i++;
        }
    }
}

void Bilhar::interpolateCells()
{
    long int oldsize = celulas.size();
    for (long int i=0;i<oldsize;i++){
        CelulaBilhar celselc = celulas[i];
        for(long int j=0;j<oldsize;j++){
            CelulaBilhar celcomp = celulas[j];
            if(i!=j && (!celselc.isVisinho(celcomp.idcel))){
                if ((celcomp.coord - celselc.coord).module()<RADIUS){ //faça a interpolação
                    Vec4 coord = (celcomp.coord + celselc.coord)/2.;
                    Vec4 veloc = (celcomp.velocity + celselc.velocity)/2.;
                    float mag = (celcomp.magnitude + celselc.magnitude)/2.;
                    CelulaBilhar newCell(size,coord,veloc,mag,color_new,true);
                    celulas.append(newCell);
                    celcomp.addVisinho(celselc.idcel);
                    celselc.addVisinho(celcomp.idcel);
                    //qDebug() << "Cell select: " << celselc.idcel << " Cell comp: " << celcomp.idcel;
                    size++;
                }
            }
        }
        //celselc.showVisinhos();
    }
    qDebug()<< "Total Size: " << celulas.size();
    qDebug()<< "Total Size: " << size;
}
