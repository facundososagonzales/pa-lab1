#include <iostream>
#include "class/Puerto.h"
#include "dataTypes/DtBarco.h"

using namespace std;

void func1();
 
int main(){
     
    DtFecha FechaIng;
    DtBarco DtBarcos;
    Puerto *p = new Puerto();
    func1();

}

void func1(){
    cout<<"hello, world!!" << endl;
}