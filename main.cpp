#include <iostream>
#include <string.h>
#include <stdexcept>
#include <typeinfo>
#include <stdlib.h>
#include "class/Puerto.h"
#include "class/BarcoPasajeros.h"
#include "class/BarcoPesquero.h"
#include "dataTypes/DtPuerto.h"
#include "dataTypes/DtArribo.h"
#include "dataTypes/DtBarcoPesquero.h"
#include "dataTypes/DtBarcoPasajero.h"

#define MAX_PUERTOS 100
#define MAX_BARCOS 100

using namespace std;

struct{
	Puerto* Puertos[MAX_PUERTOS];
	int topePuertos=0;
}cP;

struct{
	Barco* Barcos[MAX_BARCOS];
	int topeBarcos=0;
}cB;

////////////////////////////////////////////> Operaciones A <//////////////////////////////////////////////////

void agregarPuerto();
void agregarPuerto(string  id,  string  nombre,  const DtFecha& fechaCreacion);
void intentarRegistro (string ci);

////////////////////////////////////////////> Operaciones B <//////////////////////////////////////////////////

void agregarBarco();
void agregarBarco(DtBarco& barco);
void intentarIngresarIdBarco(string id);
DtBarco ingresarBarco(string id);

////////////////////////////////////////////> Operaciones c <//////////////////////////////////////////////////

DtPuerto** listarPuertos();

void agregarArribo(string idPuerto, string idBarco, float cargaDespacho);

DtArribo** obtenerInfoArribosEnPuerto(string idPuerto);

void eliminarArribos(string idPuerto, const DtFecha&fecha);

DtBarco** listarBarcos();


void menu(){
		//system("clear");
		cout <<"____________________________________________"<<endl;
		cout <<"___________________Puerto___________________"<<endl;
		cout <<"_________________Bienvenido_________________"<<endl;
		cout <<"________________Elija opcion:_______________"<<endl;
		cout <<"____________________________________________"<<endl;
		cout <<"__________1. Agregar Puerto_________________"<<endl;
		cout <<"__________2. Agregar Barco__________________"<<endl;
		cout <<"__________3. Listar Puertos_________________"<<endl;
		cout <<"__________4. Agregar Arribo_________________"<<endl;
		cout <<"__________5. Obtener info de arribos________"<<endl;
		cout <<"__________6. Eliminar Arribos_______________"<<endl;
		cout <<"__________7. Listar Barcos__________________"<<endl;
		cout <<"__________8. Salir__________________________"<<endl;
		cout <<"____________________________________________"<<endl;
		cout <<"OPCION: ";
}

int main(){
	int opcion;
	menu();
	cin >> opcion;
	while(opcion != 8){
		switch(opcion){
			case 1:
				agregarPuerto();
			break;

			case 2:
				agregarBarco();
			break;
			
			case 3:
			break;
		
			case 4:
			break;
	
			case 5:
			break;

			case 6:
			break;

			case 7:
			break;

			default:
				cout << "OPCIÓN INCORRECTA" << endl;
		}
		menu();
		cin >> opcion;
	}
	cout << "SALIENDO..." << endl;
}


////////////////////////////////////////////> Operaciones A <//////////////////////////////////////////////////

void agregarPuerto(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______________ AGREGAR PUERTO________________"<< endl;
	cout <<"_____________________________________________" <<endl;
	string id;
	cout << endl << "Ingrese su ID: ";
	cin >> id;
	try{
		intentarRegistro(id);
	}catch (invalid_argument& e){
		cout << e.what() << endl;
	}
}

void intentarRegistro (string id){
	int cont=0;
	bool verificar=false;
	while (cP.topePuertos>cont && !verificar){
		if (strcmp(id.c_str(),cP.Puertos[cont]->getid().c_str())==0){
			verificar=true;
		}else
			cont++;
	}
	if (verificar){
		throw invalid_argument ("La ID ingresada ya pertenece a un Puerto");
	}else{
		int dia, mes, anio;
		string nombre;
		cout << "Ingrese su nombre: "; cin >> nombre;
		verificar=false;
		cout <<"Ingrese el dia: "; cin >> dia;
		if(0<dia && dia<32){
			cout <<"Ingrese el mes: "; cin >> mes;
			if (0<mes && mes<13){
				cout <<"Ingrese el anio: "; cin >> anio;
				if (1900<=anio)
					verificar=true;
			}
		}
		if(!verificar){
			throw invalid_argument ("La fecha ingresada no es valida");
		}
		DtFecha fechaIng = DtFecha(dia,mes,anio);
		agregarPuerto(id,nombre,fechaIng);
	}
}

void agregarPuerto(string  id,  string  nombre,  const DtFecha& fechaCreacion){
	Puerto *puerto = new Puerto(id,nombre,fechaCreacion);
	cP.Puertos[cP.topePuertos]=puerto;
	cout << "El Puerto " << cP.Puertos[cP.topePuertos]->getnombre() <<  " se ha registrado" << endl;
	cP.topePuertos++;
}

////////////////////////////////////////////> Operaciones B <//////////////////////////////////////////////////

void agregarBarco(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"_______________ AGREGAR BARCO________________"<< endl;
	cout <<"_____________________________________________" <<endl;
	string id;
	cout << endl << "Ingresar ID del barco: ";
	cin >> id;
	try{
		intentarIngresarIdBarco(id);
		DtBarco dtb = ingresarBarco(id);
		agregarBarco(dtb);
	}catch (invalid_argument& e){
		cout << e.what() << endl;
	}
}

void intentarIngresarIdBarco(string id){
	bool verificar=false;
	int cont=0;
	while (cont<cB.topeBarcos && !verificar){
		if (cB.Barcos[cont]->getid()==id){
			verificar=true;
		}else
			cont++;
	}
	if (verificar)
		throw invalid_argument ("El Barco que se intenta ingresar ya existe");
}

DtBarco ingresarBarco(string id){
	string nombre_barco;
	cout << "Ingresar el nombre del barco";
	cin >> nombre_barco;

	int tipo_Barco;
	cout << "En caso de barco de pasajeros presionar 1, en caso de barco pesquero presionar 2: ";
	cin >> tipo_Barco;

	while(tipo_Barco!=1 && tipo_Barco!=2){
		cout << "Entrada incorrecta, intentar nuevamente: ";
		cin >> tipo_Barco;
	}

	if (tipo_Barco==1){
		int cantidad_Pasajeros;
		cout << "Ingresar la cantidad de pasajeros: ";
		cin >> cantidad_Pasajeros;
		
		cout << "Ingresar el nuemro correspondiente al tamanio del barco" << endl;
		cout << "\n    1 - bote" << endl; 
		cout << "\n    2 - crucero" << endl;
		cout << "\n    3 - galeon" << endl; 
		cout << "\n    4 - transatlantico" << endl;
		
		int tamanio_barco;
		cin >> tamanio_barco;
		while(tamanio_barco<1 && tamanio_barco>5){
			cout << "Entrada incorrecta, intentar nuevamente" << endl;
			cout << "\n    1 - bote" << endl; 
			cout << "\n    2 - crucero" << endl;
			cout << "\n    3 - galeon" << endl; 
			cout << "\n    4 - transatlantico" << endl;
		}

		TipoTamanio tamanio;
		switch(tamanio_barco){
			case 1: tamanio = bote; 		  break;
			case 2: tamanio = crucero; 		  break;
			case 3: tamanio = galeon; 		  break;
			case 4: tamanio = transatlantico; break;
		}
		DtBarcoPasajero dtb_pasajeros = DtBarcoPasajero(nombre_barco,id,cantidad_Pasajeros,tamanio);
		return dtb_pasajeros;
	}

	else if (tipo_Barco==2){
		int capacidad_Barco;
		cout << "Ingresar la capacidad del barco pesquero: ";
		cin >> capacidad_Barco;

		int carga_barco;
		cout << "ingresar la carga actual del barco pesquero: ";
		cin >> carga_barco;

		while (carga_barco<0 && carga_barco>capacidad_Barco){
			cout << "Entrada incorrecta, intentar nuevamente" << endl;
			cin >> carga_barco;
		}
		DtBarcoPesquero dtb_pesquero = DtBarcoPesquero(nombre_barco,id,capacidad_Barco,carga_barco);
		return dtb_pesquero;
	}
}

void agregarBarco(DtBarco& barco){
	try{
		DtBarcoPasajero& dtb_pasajero = dynamic_cast<DtBarcoPasajero&>(barco);
		BarcoPasajeros* barco_pasajeros = new BarcoPasajeros(dtb_pasajero.getnombre(),dtb_pasajero.getid(),dtb_pasajero.getcantPasajeros(),dtb_pasajero.gettamanio());
		cB.Barcos[cB.topeBarcos] = barco_pasajeros;
		cB.topeBarcos++;
	}catch(bad_cast){
		try{
			DtBarcoPesquero& dtb_pesquero = dynamic_cast<DtBarcoPesquero&>(barco);
			BarcoPesquero* barco_pesquero = new BarcoPesquero(dtb_pesquero.getnombre(),dtb_pesquero.getid(),dtb_pesquero.getcapacidad(),dtb_pesquero.getcarga());
			cB.Barcos[cB.topeBarcos] = barco_pesquero;
			cB.topeBarcos++;
		}catch(bad_cast){}
	}
}

////////////////////////////////////////////> Operaciones C <//////////////////////////////////////////////////

DtPuerto** listarPuertos(){}

void agregarArribo(string idPuerto, string idBarco, float cargaDespacho){}

DtArribo** obtenerInfoArribosEnPuerto(string idPuerto){}

void eliminarArribos(string idPuerto, const DtFecha&fecha){}

DtBarco** listarBarcos(){}