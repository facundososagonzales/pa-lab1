#ifndef ARRIBO
#define ARRIBO

#include<iostream>
#include "../dataTypes/DtFecha.h"

class Arribo
{
private:
    DtFecha fecha;
    float carga;
public:
    Arribo();
    Arribo(DtFecha,float);

    DtFecha getfecha();
    void setfecha(DtFecha fecha);
    float getcarga();
    void setcarga(float carga);

    ~Arribo();
};

#endif