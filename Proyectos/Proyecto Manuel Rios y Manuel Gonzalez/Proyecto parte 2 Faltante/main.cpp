#include <iostream>
#include <string.h>
#include "CLAVES.h"
using namespace std;



int main()
{
    cout<<"//------ESTE PROYECTO CONTIENE UN ARCHIVO DE PRUEBA TIPO .TXT DENTRO DE SU CARPETA------//"<<endl;
    cout<<"...PROYECTO POR Manuel Alejandro Rios, Manuel Alejandro Gonzales..."<<endl;
    int *num=new int;

    cout<<"\nIngrese la cantidad de codigos a leer: ";
    cin>>*num;
    char **Cadenas= new char*[*num];
    Cadenas=crearMat(num);
    Cadenas=guardarCodigos(Cadenas, num);
    imprimirDobleCadenas(Cadenas, num);

    Cadenas=clavesCorrectas(Cadenas,num);

    imprimirDobleCadenas(Cadenas, num);

    delete num;
    return 0;
}


