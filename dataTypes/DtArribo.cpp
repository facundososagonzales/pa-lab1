#include "../dataTypes/DtArribo.h"

DtArribo::DtArribo(){}

DtArribo::DtArribo(DtFecha fecha,float carga,DtBarco barco){
    this->fecha=fecha;
    this->carga=carga;
    this->barco=barco;
}

DtFecha DtArribo::getfecha() {
    return this->fecha;
}

float DtArribo::getcarga() {
    return this->carga;
}

DtBarco DtArribo::getBarco() {
    return this->barco;
}

ostream& operator <<(ostream& salida, const DtArribo& dta){
        cout << "Fecha: " << dta.fecha << "\n"
        "Carga: " << dta.carga << "\n"
        "--- Barco --- " << dta.barco << endl;
	return salida;
}

DtArribo::~DtArribo(){}



