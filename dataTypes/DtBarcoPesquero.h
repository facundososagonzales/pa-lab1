#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H

#include<iostream>
#include "../dataTypes/DtBarco.h"
using namespace std;

class DtBarcoPesquero : public DtBarco{
    private:
        int capacidad;
        int carga;
    public:
        DtBarcoPesquero();
        DtBarcoPesquero(string,string,int,int);
        int getcapacidad();
        int getcarga();
        ~DtBarcoPesquero();

        friend ostream& operator << (ostream&, const DtBarcoPesquero&);
};

#endif
