#include "../dataTypes/DtBarcoPasajero.h"

DtBarcoPasajero::DtBarcoPasajero(){}

DtBarcoPasajero::DtBarcoPasajero(string nombre, string id, int cantPasajeros, TipoTamanio tamanio): DtBarco(nombre,id){
    this->cantPasajeros=cantPasajeros;
    this->tamanio=tamanio;
}

int DtBarcoPasajero::getcantPasajeros() {
    return this->cantPasajeros;
}

TipoTamanio DtBarcoPasajero::gettamanio() {
    return this->tamanio;
}

DtBarcoPasajero::~DtBarcoPasajero(){}

ostream& operator <<(ostream& salida, const DtBarcoPasajero& dtb){
    string tmo[4] = {"bote","crucero","galeon","transatlantico"};
	cout <<(DtBarco) dtb << "Cantidad de pasajeros: " << dtb.cantPasajeros << "\n" 
		"Tamanio: " << tmo[dtb.tamanio] << endl;
	return salida;
}


