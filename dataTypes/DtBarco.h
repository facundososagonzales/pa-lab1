#ifndef DTBARCO_H
#define DTBARCO_H

#include<iostream>
using namespace std;

class DtBarco{
    private:
        string nombre;
        string id;
    public:
        DtBarco();
        DtBarco(string,string);
        string getnombre();
        string getid();
        ~DtBarco();

        friend ostream& operator << (ostream&, const DtBarco&);
};

#endif
