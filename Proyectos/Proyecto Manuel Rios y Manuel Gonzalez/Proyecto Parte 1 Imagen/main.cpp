#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "CODIFICADO.h"

using namespace std;


int main()
{
    cout<<"\nESTE PROGRAMA TIENE UN ARCHIVO .TXT DENTRO DE SU CARPETA PARA REALIZAR LA PRUEBA DE DATOS..."<<endl;
    cout<<"...POR Manuel Alejandro Rios, Manuel Alejandro Gonzales..."<<endl;
    int pos; //usado para almacenar una posicion en cadena
    int tam;
    char alpnormal[37]="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    cout<<"\n Ingrese la cadena de caracteres de decodificacion: "<<endl;
    char *codificar=new char[37];//crear cadena para recibir la clave de decodificacion
    cin.getline(codificar,37);

    cout<<"\nIngrese la segunda cadena (para decodificar): ";
    char *encryp=new char[500];//crear cadena para recibir imagen
    cin.getline(encryp,500);

    cout<<"\nCadena para poder decodificar: ";
    imprimir(codificar);
    cout<<"\nImagen desencryptada: ";
    imprimir(encryp);

    char *cadenaFinal=new char[500];
    cadenaFinal=descodificar(codificar,encryp,alpnormal); //encryp es la imagen desencryptada
    cout<<endl;
    cout<<"\nLa cadena final es: ";
    imprimir(cadenaFinal);
    imagen(cadenaFinal);

    delete codificar;
    delete encryp;
    delete cadenaFinal;
    cout<<endl;
    //system ("pause");
    return 0;
}




