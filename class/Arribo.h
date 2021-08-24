#ifndef ARRIBO
#define ARRIBO

#include<iostream>
#include "../dataTypes/DtFecha.h"
#include "../class/Barco.h"

class Arribo
{
private:
    DtFecha fecha;
    float carga;
    Barco* barco;
public:
    Arribo();
    Arribo(DtFecha,float, Barco*);

    DtFecha getfecha();
    void setfecha(DtFecha fecha);
    float getcarga();
    void setcarga(float carga);
    Barco* getBarco();

    ~Arribo();
};

#endif