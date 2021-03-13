#include "DtFecha.h"

DtFecha::DtFecha(){}
DtFecha::DtFecha(int Dia, int Mes, int Anio){
	this->Dia=Dia;
	this->Mes=Mes;	
	this->Anio=Anio;
}
int DtFecha::getDia(){
    return Dia;
}
int DtFecha::getMes(){
    return Mes;
}
int DtFecha::getAnio(){
    return Anio;
}
DtFecha::~DtFecha(){}

bool operator <(const DtFecha& dtf1,const DtFecha& dtf2){
	bool retorno;
	if (dtf1.Anio < dtf2.Anio){
		retorno=true;
	}else if(dtf1.Anio == dtf2.Anio){
		if (dtf1.Mes < dtf2.Mes){
			retorno=true;
		}else if(dtf1.Mes == dtf2.Mes){
			if (dtf1.Dia < dtf2.Dia){
				retorno=true;
			}else{
				retorno=false;
			}
		}
	}
	return retorno;
}
bool operator ==(const DtFecha& dtf1,const DtFecha& dtf2){
	bool retorno;
	if (dtf1.Anio == dtf2.Anio){
		retorno=true;
	}else if(dtf1.Anio == dtf2.Anio){
		if (dtf1.Mes == dtf2.Mes){
			retorno=true;
		}else if(dtf1.Mes == dtf2.Mes){
			if (dtf1.Dia == dtf2.Dia){
				retorno=true;
			}else{
				retorno=false;
			}
		}
	}
	return retorno;
}

ostream& operator <<(ostream& salida,const DtFecha& dtf){
	cout << dtf.Dia << "/" << dtf.Mes << "/" << dtf.Anio <<endl;
	return salida;
}


