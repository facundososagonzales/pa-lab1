#include "../class/BarcoPasajeros.h"

BarcoPasajeros::BarcoPasajeros(){}

BarcoPasajeros::BarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio):Barco(nombre,id){
    this->cantPasajeros=cantPasajeros;
    this->tamanio=tamanio;
}

void BarcoPasajeros::setcantPasajeros(int cantPasajeros) {
    this->cantPasajeros=cantPasajeros;
}

int BarcoPasajeros::getcantPasajeros() {
    return this->cantPasajeros;
}

void BarcoPasajeros::settamanio(TipoTamanio tamanio) {
    this->tamanio=tamanio;
}

TipoTamanio BarcoPasajeros::gettipoTamanio() {
    return this->tamanio;
}

void BarcoPasajeros::arribar(float cargaDespacho) {}

BarcoPasajeros::~BarcoPasajeros(){}







