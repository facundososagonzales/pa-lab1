#ifndef BARCOPESQUERO
#define BARCOPESQUERO

#include "../class/Barco.h"

class BarcoPesquero : public Barco{
private:
    int capacidad;
    int carga;
public:
    BarcoPesquero();
    BarcoPesquero(string, string, int, int);

    void setcapacidad(int);
    int getcapacidad();

    void setcarga(int);
    int getcarga();

    ~BarcoPesquero();
};

#endif