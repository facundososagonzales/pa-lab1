#include "../class/BarcoPesquero.h"

BarcoPesquero::BarcoPesquero(){}

BarcoPesquero::BarcoPesquero(string nombre, string id, int capacidad, int carga):Barco(nombre,id){
    this->capacidad=capacidad;
    this->carga=carga;
}

void BarcoPesquero::setcapacidad(int capacidad) {
    this->capacidad=capacidad;
}

int BarcoPesquero::getcapacidad() {
    return this->capacidad;
}

void BarcoPesquero::setcarga(int carga) {
    this->carga=carga;
}

int BarcoPesquero::getcarga(){
    return this->carga;
}

BarcoPesquero::~BarcoPesquero(){}





