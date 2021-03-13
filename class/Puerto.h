#ifndef PUERTO
#define PUERTO

#include<iostream>
#include "../dataTypes/DtFecha.h"
#include"../class/Arribo.h"

#define MAX_ARRIBO 30

using namespace std;

class Puerto
{
private:
    string id;
    string nombre;
    DtFecha fechaCreacio;
    Arribo * arribos[MAX_ARRIBO];
    int topeA;
public:
    Puerto();
    Puerto(string,string,DtFecha);
    
    string getid();
    void setid(string);

    string getnombre();
    void setnombre(string);

    DtFecha getfechaCreacion();
    void setfechaCreacion(DtFecha);

    Arribo * getArribo(int);
    void addToArribos(Arribo*);
    int getTope();

    
    ~Puerto();

};

#endif