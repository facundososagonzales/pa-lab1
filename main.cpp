#include <iostream>
#include "class/Puerto.h"
#include "dataTypes/DtBarcoPesquero.h"
#include "dataTypes/DtBarcoPasajero.h"

using namespace std;

void func1();
 
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
}