#include <iostream>
#include "class/Puerto.h"
#include "dataTypes/DtPuerto.h"
#include "dataTypes/DtArribo.h"
#include "dataTypes/DtBarcoPesquero.h"
#include "dataTypes/DtBarcoPasajero.h"

using namespace std;

/*void func1();
 
int main(){
     
    DtFecha FechaIng;
    DtBarcoPesquero dtb = DtBarcoPesquero("barco","1",20,200);
    DtBarcoPasajero dtbp = DtBarcoPasajero("barco","1",500,crucero);
    Puerto *p = new Puerto();
    cout << dtb << endl;
    cout << dtbp << endl;
    func1();

}

void func1(){
    cout<<"hello, world!!" << endl;
}*/

void  agregarPuerto(string  id,  string  nombre,  const DtFecha& fechaCreacion);

void agregarBarco(DtBarco& barco);

//Se puede usar List o Vector
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
			break;

			case 2:
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

void  agregarPuerto(string  id,  string  nombre,  const DtFecha& fechaCreacion){}

void agregarBarco(DtBarco& barco){}

DtPuerto** listarPuertos(){}

void agregarArribo(string idPuerto, string idBarco, float cargaDespacho){}

DtArribo** obtenerInfoArribosEnPuerto(string idPuerto){}

void eliminarArribos(string idPuerto, const DtFecha&fecha){}

DtBarco** listarBarcos(){}