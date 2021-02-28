#include <iostream>
#include <string.h>
#include "CLAVES.h"

using namespace std;

char **crearMat(int *num)
{
    char **Cadenas= new char*[*num]; //crea la cadena doble apuntador
    for(int i=0; i<*num; i++)
    {
        (*(Cadenas+i))=new char[15]; //en el ciclo se crean cadenas para cada region de la cadena primera
        cout<<"\nCadena numero "<<i+1<<" creada..."; //se confirma que se creo la N cadena
    }
    cout<<endl;

    return Cadenas;

    for(int i=0; i<*num; i++) // se borra la cadena por fuera
    {
        delete (*(Cadenas+i));
    }

    delete Cadenas; //se borra lo final de la cadena
}

char **guardarCodigos(char **cadena,int *num)
{
    int tam=*num;
    cin.ignore();
    for(int i=0; i<tam; i++)
    {
        cout<<"\nIngrese el valor de la cadena "<<i+1<<" : ";
        cin.getline( *(cadena+i), 15 );
    }
    return cadena;
}


void imprimirDobleCadenas(char **cadena, int *num)
{
    int tam=*num; //almacena el tamaño de la cadena
    cout<<endl;
    for(int i=0; i<tam; i++) //recorre horizontal
    {
        cout<<endl;
        for(int j=0; j<(strlen(*(cadena+i))); j++) //recorre de manera vertical
        {
            cout<<" | "<<(*(*(cadena+i)+j)); //imprime valor i+j de  la cadena uno a uno
        }
    }
}

char **clavesCorrectas(char **cadena, int *num)
{
    int tam=*num; //numero de cadenas
    int izquierda=0, derecha=0; //acumuladores de izquierda y derecha
    int posicion=0; //para guardar la posicion en la cadena del ?
    bool cambio=false; //bandera por si ya se encontro el signo de ?

    for(int i=0; i<tam; i++) //recorre horizontal
    {
        for(int j=0; j<(strlen(*(cadena+i))); j++) //recorre de manera vertical
        {
            if(*(*(cadena+i)+j)!='?' && cambio==false) //condicional si esta en el lado izquierdo (aun no encuentra el ?)
            {
                izquierda=izquierda+ (int)*(*(cadena+i)+j); //sumar numeros del lado izquierdo
            }
            if((*(*cadena+i)+j)!='?'&&cambio==true) //condicional si esta en el lado derecho (ya encontro el ?)
            {
                derecha=derecha+ (int)*(*(cadena+i)+j); //sumar numeros del lado derecho
            }

            else
            {
                cambio=true;
                posicion=j;
            }
        }

        int aux=0, suma=0;

        if(izquierda>derecha) //si los numeros dela izquierda son mayores que los de la derecha
        {
            while(izquierda != 0) //sumar los digitos de un numero
            {
                aux = izquierda % 10;
                izquierda /= 10;
                suma += aux;
            }
        }
        else //si los de la derecha son mayores que los de la izquierda
        {
            while(derecha != 0) // sumar los digitos de un numero
            {
                aux = derecha % 10;
                derecha /= 10;
                suma += aux;
            }
        }
        (*(*(cadena+i)+posicion))=(char)suma;
    }
    return cadena;
}

