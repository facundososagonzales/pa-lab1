#include "../dataTypes/DtBarco.h"

DtBarco::DtBarco(){}

DtBarco::DtBarco(string nombre,string id){
    this->id=id;
    this->nombre=nombre;
}

string DtBarco::getnombre() {
    return this->nombre;
}

string DtBarco::getid() {
    return this->id;
}

DtBarco::~DtBarco(){}


ostream& operator <<(ostream& salida, const DtBarco& dtb){
	cout << "id: " << dtb.id << "\n" 
		"nombre: " << dtb.nombre << endl;
	return salida;
}



