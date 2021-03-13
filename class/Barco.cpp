#include "../class/Barco.h"

Barco::Barco(){}

Barco::Barco(string nombre, string id){
    this->nombre=nombre;
    this->id=id;
}

string Barco::getnombre() {
    return this->nombre;
}

void Barco::setnombre(string nombre) {
    this->nombre=nombre;
}

string Barco::getid() {
    return this->id;
}

void Barco::setid(string id) {
    this->id=id;
}

Barco::~Barco(){}







