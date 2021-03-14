#ifndef DTBARCOPASAJERO_H
#define DTBARCOPASAJERO_H

#include<iostream>
#include "../dataTypes/DtBarco.h"
#include "../dataTypes/TipoTamanio.h"

using namespace std;

class DtBarcoPasajero : public DtBarco{
    private:
        int cantPasajeros;
        TipoTamanio tamanio;
    public:
        DtBarcoPasajero();
        DtBarcoPasajero(string,string,int,TipoTamanio);
        int getcantPasajeros();
        TipoTamanio gettamanio();
        ~DtBarcoPasajero();

        friend ostream& operator << (ostream&, const DtBarcoPasajero&);
};

#endif