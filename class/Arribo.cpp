#include "../class/Arribo.h"

Arribo::Arribo(){}

Arribo::Arribo(DtFecha fecha,float carga, Barco* barco){
    this->fecha=fecha;
    this->carga=carga;
    this->barco=barco;
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

Barco* Arribo::getBarco(){
    return this->barco;
}


Arribo::~Arribo(){}