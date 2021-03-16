#include "../dataTypes/DtPuerto.h"

DtPuerto::DtPuerto(){}

DtPuerto::DtPuerto(string nombre,string id,DtFecha fechaCreacion,int cantArribos){
    this->nombre=nombre;
    this->id=id;
    this->fechaCreacion=fechaCreacion;
    this->cantArribos=cantArribos;

}

string DtPuerto::getnombre() {
    return this->nombre;
}

string DtPuerto::getid() {
    return this->id;
}

DtFecha DtPuerto::getfechaCreacion() {
    return this->fechaCreacion;
}

int DtPuerto::getcantArribos(){
    return this->cantArribos;
}

DtPuerto::~DtPuerto(){}


ostream& operator <<(ostream& salida, const DtPuerto& dtb){
	cout << "id: " << dtb.id << "\n" 
		"nombre: " << dtb.nombre << "\n"
        "Fecha de creacion: " << dtb.fechaCreacion << "\n"
        "Cantidad de arribos: " << dtb.cantArribos << endl;
	return salida;
}