#ifndef BARCO
#define BARCO

#include<iostream>

using namespace std;

class Barco
{
private:
    string nombre;
    string id;
public:
    Barco();
    Barco(string, string);

    string getnombre();
    void setnombre(string);

    string getid();
    void setid(string);

    virtual void arribar()=0;

    ~Barco();
};

#endif