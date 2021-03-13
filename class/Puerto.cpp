#include "../class/Puerto.h"

Puerto::Puerto(){};

Puerto::Puerto(string id,string nombre,DtFecha fechaCreacio){
      this->id=id;
      this->nombre=nombre;
      this->fechaCreacio=fechaCreacio;
      this->topeA = 0;
}

string Puerto::getid() {
    return this->id;
}

void Puerto::setid(string id) {
    this->id=id;
}

string Puerto::getnombre() {
    return this->nombre;
}

void Puerto::setnombre(string nombre) {
    this->nombre=nombre;
}

DtFecha Puerto::getfechaCreacion() {
    return this->fechaCreacio;
}

void Puerto::setfechaCreacion(DtFecha fechaCreacio) {
    this->fechaCreacio=fechaCreacio;
}

Arribo* Puerto::getArribo(int topeA) {
    return this->arribos[topeA];
}

void Puerto::addToArribos(Arribo *a) {
    this->arribos[this->topeA]=a;
    this->topeA = this->topeA++;
}

int Puerto::getTope() {
    return this->topeA;
}

Puerto::~Puerto(){}