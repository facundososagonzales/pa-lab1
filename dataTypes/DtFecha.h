#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>

using namespace std;


class DtFecha{
    private:
        int Dia;
        int Mes;
        int Anio;
    public:
        DtFecha();
        DtFecha(int,int,int);
        int getDia();
        int getMes();
        int getAnio();
        ~DtFecha();
        
        friend bool operator <(const DtFecha&,const DtFecha&);
        friend bool operator ==(const DtFecha&,const DtFecha&);
		friend ostream& operator <<(ostream&,const DtFecha&);

};

#endif
