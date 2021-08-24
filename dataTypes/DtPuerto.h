#ifndef DTPUERTO_H
#define DTPUERTO_H

#include<iostream>
#include "../dataTypes/DtFecha.h"

using namespace std;

class DtPuerto{
    private:
        string nombre;
        string id;
        DtFecha fechaCreacion;
        int cantArribos;
    public:
        DtPuerto();
        DtPuerto(string,string,DtFecha,int);
        string getnombre();
        string getid();
        DtFecha getfechaCreacion();
        int getcantArribos();
        ~DtPuerto();

        friend ostream& operator << (ostream&, const DtPuerto&);
};

#endif