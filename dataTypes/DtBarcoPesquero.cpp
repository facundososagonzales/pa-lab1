#include "../dataTypes/DtBarcoPesquero.h"

DtBarcoPesquero::DtBarcoPesquero(){}

DtBarcoPesquero::DtBarcoPesquero(string nombre, string id, int capacidad, int carga): DtBarco(nombre,id){
    this->carga=carga;
    this->capacidad=capacidad;
}

int DtBarcoPesquero::getcapacidad() {
    return this->capacidad;
}

int DtBarcoPesquero::getcarga() {
    return this->carga;
}

DtBarcoPesquero::~DtBarcoPesquero(){}

ostream& operator <<(ostream& salida, const DtBarcoPesquero& dtb){
	cout <<(DtBarco) dtb << "Capacidad: " << dtb.capacidad << "\n" 
		"Carga: " << dtb.carga << endl;
	return salida;
}



