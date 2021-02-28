#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "CODIFICADO.h"

using namespace std;
void imprimir (char *cadena)
{
    int tam=strlen(cadena);
    cout<<endl;
    for(int i=0; i<tam; i++)
    {
        cout<<"|"<<(*(cadena+i));
    }
}

char *descodificar(char *codificar, char *encryp,char *alpnormal)
{



    for(int i=0; i<strlen(encryp); i++)
    {
        for(int j=0; j<strlen(codificar); j++)
        {
            if(*(encryp+i)== *(codificar+j))
            {
                *(encryp+i)=*(alpnormal+j);
            }

        }

    }
    return encryp;
}


void imagen(char*cadenaFinal) //imprimir la cadena comprimida como imagen
{
    cout<<endl<<"Imagen: "<<endl;

    int salto=(*(cadenaFinal)-48);
    int contador=0;

    char *aux1;
    char *aux2;
    int tam;

    for(int i=1; i<(strlen(cadenaFinal)); i++)
    {
        aux1=(cadenaFinal+i);
        aux2=(cadenaFinal+i+1);


        if ((*aux2)>='0'&&(*aux2)<='9')//si es un numero
        {
            tam=((int)*aux2)-48;

            for(int j=0; j<(tam); j++)
            {
                cout<<*aux1;
                contador=contador+1;
                if(contador==salto)
                {
                    cout<<endl;
                    contador=0;
                }
            }
        }

        if((*aux2)>='A'&& (*aux2)<='Z'&&(*aux1)>='A'&& (*aux1)<='Z')//si es una letra
        {
            cout<<*aux1;
            contador=contador+1;
               if(contador==salto)
                {
                    cout<<endl;
                    contador=0;
                }

        }
    }

}
