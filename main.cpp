#include <iostream>
#include <ctime>
#include <string.h>
#include <stdexcept>
#include <typeinfo>
#include <stdlib.h>
#include "class/Puerto.h"
#include "class/Barco.h"
#include "class/Arribo.h"
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
void ingresarBarco(string id);

////////////////////////////////////////////> Operaciones C <//////////////////////////////////////////////////

void listarPuertos();

////////////////////////////////////////////> Operaciones D <//////////////////////////////////////////////////

void agregarArribo();
void agregarArribo(string id_Puerto, string id_Barco, float carga_A_Despachar);
void BarcoExiste(string id);
void PuertoExiste(string id);

////////////////////////////////////////////> Operaciones E <//////////////////////////////////////////////////

void obtenerInfoArribosEnPuerto();
void verificarPuerto(string id_Puerto);
void noExistePuerto();
DtArribo** obtenerInfoArribosEnPuerto(string id_Puerto);

////////////////////////////////////////////> Operaciones F <//////////////////////////////////////////////////

void eliminarArribos();
void eliminarArribos(string idPuerto, const DtFecha&fecha);

////////////////////////////////////////////> Operaciones G <//////////////////////////////////////////////////

void listarBarcos();
DtBarco** listarBarcos(int& cantBarcos);


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
				listarPuertos();
			break;
		
			case 4:
				agregarArribo();
			break;
	
			case 5:
				obtenerInfoArribosEnPuerto();
			break;

			case 6:
				eliminarArribos();
			break;

			case 7:
				listarBarcos();
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
		ingresarBarco(id);
	}catch (invalid_argument& e){
		cout << e.what() << endl;
	}
}

void intentarIngresarIdBarco(string id){
	bool verificar=false;
	int cont=0;
	while ((cont<cB.topeBarcos) && (!verificar)){
		if (cB.Barcos[cont]->getid()==id){
			verificar=true;
		}else
			cont++;
	}
	if (verificar)
		throw invalid_argument ("El Barco que se intenta ingresar ya existe");
}

void ingresarBarco(string id){
	string nombre_barco;
	cout << "Ingresar el nombre del barco: ";
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
		cout << "\n\nNumero: ";
		int tamanio_barco;
		cin >> tamanio_barco;

		while(1>tamanio_barco || tamanio_barco>4){
			cout << "Entrada incorrecta, intentar nuevamente" << endl;
			cout << "\n    1 - bote" << endl; 
			cout << "\n    2 - crucero" << endl;
			cout << "\n    3 - galeon" << endl; 
			cout << "\n    4 - transatlantico" << endl;
			cout << "\n\nNumero: ";
			cin >> tamanio_barco;
		}

		TipoTamanio tamanio;
		switch(tamanio_barco){
			case 1: tamanio = bote; 		  break;
			case 2: tamanio = crucero; 		  break;
			case 3: tamanio = galeon; 		  break;
			case 4: tamanio = transatlantico; break;
		}
		DtBarcoPasajero dtb_pasajeros = DtBarcoPasajero(nombre_barco,id,cantidad_Pasajeros,tamanio);
		agregarBarco(dtb_pasajeros);
		cout << "El barco de pasajeros " << dtb_pasajeros.getnombre() <<  " se ha registrado" << endl;
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
		agregarBarco(dtb_pesquero);
		cout << "El barco pesquero " << dtb_pesquero.getnombre() <<  " se ha registrado" << endl;
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

void listarPuertos(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______________ Listar Puertos________________"<< endl;
	cout <<"_____________________________________________" <<endl;

	DtPuerto** lp = new DtPuerto * [cP.topePuertos];
	for (int i = 0; i < cP.topePuertos; i++) {
		DtPuerto* dtp = new DtPuerto(cP.Puertos[i]->getnombre(),cP.Puertos[i]->getid(),cP.Puertos[i]->getfechaCreacion(),cP.Puertos[i]->getTope());
		lp[i] = dtp;
	}

	for (int i = 0; i < cP.topePuertos; i++) {
		cout << *lp[i] << endl;
	}

}

////////////////////////////////////////////> Operaciones D <//////////////////////////////////////////////////

void agregarArribo(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"______________ AGREGAR ARRIBO________________"<< endl;
	cout <<"_____________________________________________" <<endl;

	string id_Barco; string id_Puerto;
	bool condicion=false;
	if (cP.topePuertos == 0) {
		cout << "No existe ningun puerto en el sistema" << endl;
	}else if (cB.topeBarcos == 0){
		cout << "No existe ningun barco en el sistema para realizar un arribo" << endl;
	}else {
		while (!condicion) {
			cout << "Ingrese el id del Puerto al que se va a arribar: ";
			cin >> id_Puerto;
			try {
				PuertoExiste(id_Puerto);
				condicion = true;
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl;
			}
		}
		condicion = false;

		while (!condicion) {
			cout << "Ingrese el id del Barco que desea arribar: ";
			cin >> id_Barco;
			try {
				BarcoExiste(id_Barco);
				condicion = true;
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl;
			}
		}

		float carga_A_Despachar;
		cout << "Ingresar carga a despachar, en caso de barco pasajero ingresar 0: ";
		cin >> carga_A_Despachar;

		agregarArribo(id_Puerto, id_Barco, carga_A_Despachar);
		cout << "El arribo ha sido completado" << endl;
	}
}

void agregarArribo(string id_Puerto, string id_Barco, float carga_A_Despachar){
	time_t t = time(0); 
	tm* now = localtime(&t);
	DtFecha dtf = DtFecha (now->tm_mday,now->tm_mon + 1,now->tm_year + 1900);

	bool verificar=false;
	int i_Barco=0; int i_Puerto=0;
	while ((i_Barco<cB.topeBarcos) && (!verificar)){
		if (cB.Barcos[i_Barco]->getid()==id_Barco){
			verificar=true;
		}else{
			i_Barco++;
		}
	}
	verificar=false;
	while ((i_Puerto<cP.topePuertos) && (!verificar)){
		if (cP.Puertos[i_Puerto]->getid()==id_Puerto){
			verificar=true;
		}else{
			i_Puerto++;
		}
	}
	BarcoPasajeros* b_pasajero = dynamic_cast<BarcoPasajeros*>(cB.Barcos[i_Barco]);
	if(b_pasajero!=NULL){
		try{
			if (carga_A_Despachar==0){
				Arribo* arribo = new Arribo(dtf,carga_A_Despachar,b_pasajero);
				cP.Puertos[i_Puerto]->addToArribos(arribo);
			}else{
				throw invalid_argument ("La carga a despachar del barco de pasajeros debe ser 0");
			}
		}catch (invalid_argument& e){
			cout << e.what() << endl;
		}
	}else{
		BarcoPesquero* b_pesquero = dynamic_cast<BarcoPesquero*>(cB.Barcos[i_Barco]);
		if(b_pesquero!=NULL){
			try{
				if(carga_A_Despachar>=0){
					if(carga_A_Despachar<=b_pesquero->getcarga()){
						Arribo* arribo = new Arribo(dtf,carga_A_Despachar,b_pesquero);
						b_pesquero->arribar(carga_A_Despachar);
						cP.Puertos[i_Puerto]->addToArribos(arribo);
					}else{
						throw invalid_argument ("La carga a despachar no puede ser mayor a la carga del barco pesquero");
					}
				}else{
					if((b_pesquero->getcarga()-carga_A_Despachar)<=b_pesquero->getcapacidad()){
						Arribo* arribo = new Arribo(dtf,carga_A_Despachar,b_pesquero);
						b_pesquero->arribar(carga_A_Despachar);
						cP.Puertos[i_Puerto]->addToArribos(arribo);
					}else{
						throw invalid_argument ("La carga  no puede superar la carga del barco");
					}
				}
			}catch (invalid_argument& e){
				cout << e.what() << endl;
			}
		}
	}
}

void BarcoExiste(string id){
	bool verificar=false;
	int cont=0;
	while ((cont<cB.topeBarcos) && (!verificar)){
		if (cB.Barcos[cont]->getid()==id){
			verificar=true;
		}else
			cont++;
	}
	if (!verificar)
		throw invalid_argument ("El Barco que se intenta ingresar no existe en el sistema");
}

void PuertoExiste(string id){
	bool verificar=false;
	int cont=0;
	while ((cont<cP.topePuertos) && (!verificar)){
		if (cP.Puertos[cont]->getid()==id){
			verificar=true;
		}else
			cont++;
	}
	if (!verificar)
		throw invalid_argument ("El Puerto que intenta ingresar no existe en el sistema");
}

////////////////////////////////////////////> Operaciones E <//////////////////////////////////////////////////

void obtenerInfoArribosEnPuerto() {
	system("clear");
	cout << "_____________________________________________" << endl;
	cout << "______________ OBTENER ARRIBOS_______________" << endl;
	cout << "_____________________________________________" << endl;
	string id_Puerto;
	bool condicion = false;

	if (cP.topePuertos == 0){
		cout << "No existe ningun puerto en el sistema" << endl;
	}else{
		while (!condicion) {
			cout << endl << "Ingrese el ID del puerto: ";
			cin >> id_Puerto;
			try {
				verificarPuerto(id_Puerto);
				condicion = true;
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl;
			}
		}

		DtArribo** dtArribos = obtenerInfoArribosEnPuerto(id_Puerto);

		bool verificar = false;
		int i_Puerto = 0;
		while ((i_Puerto < cP.topePuertos) && (!verificar)) {
			if (cP.Puertos[i_Puerto]->getid() == id_Puerto) {
				verificar = true;
			}
			else
				i_Puerto++;
		}

		for (int i = 0; i < cP.Puertos[i_Puerto]->getTope(); i++) {
			cout << *dtArribos[i];
		}
	}
}

void verificarPuerto(string id_Puerto){
	bool verificar=false;
	int cont=0;
	while ((cont<cP.topePuertos) && (!verificar)){
		if (cP.Puertos[cont]->getid()==id_Puerto){
			verificar=true;
		}else
			cont++;
	}
	if (!verificar)
		throw invalid_argument ("El puerto ingresado no existe en el sistema");
}

void noExistePuerto(){
	throw invalid_argument("No existe ningun puerto en el sistema");
}

DtArribo** obtenerInfoArribosEnPuerto(string id_Puerto){
	bool verificar=false;
	int i_Puerto=0;
	while ((i_Puerto<cP.topePuertos) && (!verificar)){
		if (cP.Puertos[i_Puerto]->getid()==id_Puerto){
			verificar=true;
		}else
			i_Puerto++;
	}

	DtArribo** dtArribos = new DtArribo* [cP.Puertos[i_Puerto]->getTope()];

	if (cP.Puertos[i_Puerto]->getTope() == 0)
		cout << "El puerto ingresado no tiene arribos" << endl;

	for (int i=0; i<cP.Puertos[i_Puerto]->getTope(); i++){
		Arribo* arribo = cP.Puertos[i_Puerto]->getArribo(i);
		BarcoPasajeros* b_pasajero = dynamic_cast<BarcoPasajeros*>(arribo->getBarco());
		if(b_pasajero!=NULL){
			DtBarcoPasajero dtb_pasajero = DtBarcoPasajero(b_pasajero->getnombre(),b_pasajero->getid(),b_pasajero->getcantPasajeros(),b_pasajero->gettipoTamanio());
			DtArribo* dta = new DtArribo(arribo->getfecha(),arribo->getcarga(),dtb_pasajero);
			dtArribos[i] = dta;

		}else{
			BarcoPesquero* b_pesquero = dynamic_cast<BarcoPesquero*>(arribo->getBarco());
			if(b_pesquero!=NULL){
				DtBarcoPesquero dtb_pesquero = DtBarcoPesquero(b_pesquero->getnombre(),b_pesquero->getid(),b_pesquero->getcapacidad(),b_pesquero->getcarga());
				DtArribo* dta = new DtArribo(arribo->getfecha(),arribo->getcarga(),dtb_pesquero);
				dtArribos[i] = dta;
			}
		}
	}
	return dtArribos;
}

////////////////////////////////////////////> Operaciones F <//////////////////////////////////////////////////

void eliminarArribos(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"_______________ELIMINAR ARRIBO_______________"<< endl;
	cout <<"_____________________________________________" <<endl;
	string id_Puerto;
	bool condicion = false;

	if (cP.topePuertos == 0) {
		cout << "No existe ningun puerto en el sistema" << endl;
	}
	else {
		while (!condicion) {
			cout << endl << "Ingrese el ID del puerto: ";
			cin >> id_Puerto;
			try {
				verificarPuerto(id_Puerto);
				condicion = true;
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl;
			}
		}

		int dia, mes, anio;
		bool verificar = false;
		while(!verificar){
			cout << "Ingrese el dia: "; cin >> dia;
			if (0 < dia && dia < 32) {
				cout << "Ingrese el mes: "; cin >> mes;
				if (0 < mes && mes < 13) {
					cout << "Ingrese el anio: "; cin >> anio;
					if (1900 <= anio)
						verificar = true;
				}
			}
			if (!verificar) {
				cout << "La fecha ingresada no es valida, intente de nuevo" << endl;
			}
		}

		DtFecha Fecha_Ing = DtFecha(dia, mes, anio);
		eliminarArribos(id_Puerto, Fecha_Ing);
	}
}

void eliminarArribos(string idPuerto, const DtFecha&fecha){
	int j_ward = 0; int i_Puerto = 0;
	bool verificar = false;
	
	while ((i_Puerto < cP.topePuertos) && (!verificar)) {
		if (cP.Puertos[i_Puerto]->getid() == idPuerto) {
			verificar = true;
		}
		else
			i_Puerto++;
	}
	int i_ward=0;
	while (cP.Puertos[i_Puerto]->getTope()>=i_ward){
		while (cP.Puertos[i_Puerto]->getTope() > j_ward) {
			if (fecha == cP.Puertos[i_Puerto]->getArribo(j_ward)->getfecha()) {
				if ((cP.Puertos[i_Puerto]->getTope() > 1)) {
					Arribo* arriboF = cP.Puertos[i_Puerto]->getArribo(cP.Puertos[i_Puerto]->getTope() - 1);
					cP.Puertos[i_Puerto]->eliminarArribo(j_ward, arriboF);
				}else{
					delete cP.Puertos[i_Puerto]->getArribo(0);
					cP.Puertos[i_Puerto]->setTope(0);
				}
				cout << j_ward ;
				j_ward++;
			}
			else {
				j_ward++;
			}
		}
		j_ward=0;
		i_ward++;
	}
}

////////////////////////////////////////////> Operaciones G <//////////////////////////////////////////////////

void listarBarcos(){
	system("clear");
	cout <<"_____________________________________________" <<endl;
	cout <<"________________Listar Barcos________________" <<endl;
	cout <<"_____________________________________________" <<endl;
	cout << "\n";
	int cant_Barcos;
	DtBarco** dtBarcos = listarBarcos(cant_Barcos);
	for(int i=0;i<cB.topeBarcos;i++){
		DtBarcoPasajero* barco_pasajero = dynamic_cast<DtBarcoPasajero*>(dtBarcos[i]);
		if(barco_pasajero!=NULL)
			cout << *barco_pasajero << endl;
		else{
			DtBarcoPesquero* barco_pesquero = dynamic_cast<DtBarcoPesquero*>(dtBarcos[i]);
			if(barco_pesquero!=NULL)
				cout << *barco_pesquero << endl;
		}
	}

}

DtBarco** listarBarcos(int& cantBarcos){
	DtBarco** dtbarcos = new DtBarco*[cB.topeBarcos];
	for(int i=0;i<cB.topeBarcos;i++){
		if(BarcoPasajeros* barco_Pasajero = dynamic_cast<BarcoPasajeros*>(cB.Barcos[i])){
			DtBarcoPasajero* dtb_pasajero = new DtBarcoPasajero(barco_Pasajero->getnombre(),barco_Pasajero->getid(),barco_Pasajero->getcantPasajeros(),barco_Pasajero->gettipoTamanio());
			dtbarcos[i]=dtb_pasajero;
		}else{
			if(BarcoPesquero* barco_pesquero = dynamic_cast<BarcoPesquero*>(cB.Barcos[i])){
				DtBarcoPesquero* dtb_pesquero = new DtBarcoPesquero(barco_pesquero->getnombre(),barco_pesquero->getid(),barco_pesquero->getcapacidad(),barco_pesquero->getcarga());
				dtbarcos[i]=dtb_pesquero;
			}
		}
		cantBarcos++;
	}	
	return dtbarcos;
}