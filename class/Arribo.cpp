#include "../class/Arribo.h"

Arribo::Arribo(){}

Arribo::Arribo(DtFecha fecha,float carga){
    this->fecha=fecha;
    this->carga=carga;
}

DtFecha Arribo::getfecha() {
    return this->fecha;
}

void Arribo::setfecha(DtFecha fecha) {
    this->fecha=fecha;
}

float Arribo::getcarga() {
    return this->carga;
}

void Arribo::setcarga(float carga) {
    this->carga=carga;
}



Arribo::~Arribo(){}