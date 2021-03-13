#ifndef BARCOPASJEROS
#define BARCOPASJEROS

#include "../class/Barco.h"
#include "../dataTypes/TipoTamanio.h"

class BarcoPasajeros : public Barco{
private:
    int cantPasajeros;
    TipoTamanio tamanio;
public:
    BarcoPasajeros();
    BarcoPasajeros(string, string, int, TipoTamanio);

    void setcantPasajeros(int);
    int getcantPasajeros();

    void settamanio(TipoTamanio);
    TipoTamanio gettipoTamanio();

    ~BarcoPasajeros();
};

#endif