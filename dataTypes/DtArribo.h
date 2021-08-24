#ifndef DTARRIBO_H
#define DTARRIBO_H

#include<iostream>
#include "../dataTypes/DtFecha.h"
#include "../dataTypes/DtBarco.h"

using namespace std;

class DtArribo{
    private:
        DtFecha fecha;
        float carga;
        DtBarco barco;
    public:
        DtArribo();
        DtArribo(DtFecha,float,DtBarco);
        DtFecha getfecha();
        float getcarga();
        DtBarco getBarco();
        ~DtArribo();

        friend ostream& operator << (ostream&, const DtArribo&);
};

#endif