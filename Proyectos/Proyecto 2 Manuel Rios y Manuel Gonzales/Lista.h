
#ifndef Listas_H
#define Listas_H

#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

template<typename T>
struct Nodo
{
       Nodo<T> * sig;
       T info; //Esta es la informacion de la Lista
};

template <typename T>
struct Lista
{
       Nodo<T> * cab;
       int tam;
};

template<typename T>
Lista<T> * crearLista();
template<typename T>
void imprimir(Lista<T> *);
template<typename T>
void insertar(Lista<T> *, T); //Este metodo cambia segun el tipo de dato de la informacion de la Lista<T>
template<typename T>
void insertarAlInicio(Lista<T> *, T);
template<typename T>
void insertarEnUnaPosicion (Lista<T> *, T, int);
template<typename T>
bool vacia(Lista<T> *);
template<typename T>
int tamano(Lista<T> *);
template<typename T>
T obtenerDato(Lista<T> *, int);
template<typename T>
bool eliminar(Lista<T> *, int);
template<typename T>
void swap(Lista<T>*, int i);
//________________________________________________________________________________________________


template<typename T>
Lista<T> * crearLista()
{
      Lista<T> * lista = new Lista<T>;
      lista->tam = 0;
      lista->cab = NULL;
      return lista;
}

template<typename T>
void imprimir(Lista<T> * lista)
{
     if(vacia(lista))
     {
          cout<<"La lista no tiene Informacion"<<'\n';
     }
     else
     {
         cout<<"La informacion de la lista es:"<<'\n';
         Nodo<T> * aux;
         aux = lista->cab;
         int pos = 1;
         while(aux != NULL)
         {
                   cout<<"Info "<<pos<<": "<<aux->info<<'\n';
                   aux = aux->sig;
                   pos++;
         }
     }
}

//Este metodo cambia segun el tipo de dato de la informacion de la lista
//Inserta la informacion en la ultima posicion de la lista
template<typename T>
void insertar(Lista<T> * lista, T infoNueva)
{
     Nodo<T> * nuevo;
     nuevo = new Nodo<T>;
     nuevo->info = infoNueva;
     nuevo->sig = NULL;
     if(lista->tam == 0)
     {
         lista->cab = nuevo;
         lista->tam++;
     }
     else
     {
         Nodo<T> * aux;
         aux = lista->cab;
         while(aux->sig != NULL)
         {
            aux = aux->sig;
         }
         aux->sig = nuevo;
         lista->tam++;
     }
}
//Este metodo cambia segun el tipo de dato de la informacion de la lista
//Inserta la informacion en la primera posicion de la lista
template<typename T>
void insertarAlInicio(Lista<T> * lista, T infoNueva){
     Nodo<T> * nuevo;
     nuevo = new Nodo<T>;
     nuevo->info = infoNueva;
     nuevo->sig = NULL;

     nuevo->sig= lista->cab;
     lista->cab=nuevo;
     lista->tam++;
     return;
}
//Este metodo cambia segun el tipo de dato de la informacion de la lista
//Inserta la informacion en la primera posicion de la lista
template<typename T>
void insertarEnUnaPosicion (Lista<T> * lista, T infoNueva, int pos){
     Nodo<T> * nuevo;
     nuevo = new Nodo<T>;
     nuevo->info = infoNueva;
     nuevo->sig = NULL;

     Nodo<T> * aux;
     aux = lista->cab;
     int p = 1;
     while(aux != NULL)
     {
           if(pos-1 == p)
           {
                  nuevo->sig=aux->sig;
                  aux->sig=nuevo;
                  break;
           }
           aux = aux->sig;
           p++;
     }
}
//Informa si la lista esta vacia
template<typename T>
bool vacia(Lista<T> * lista)
{
     if(lista->tam == 0)
     {
         return true;
     }
     else
     {
         return false;
     }
}

template<typename T>
int tamano(Lista<T> * lista)
{
    return lista->tam;
}

//Retorna la informacion de la lista en la posicon pos, empezando desde cero
template<typename T>
T obtenerDato(Lista<T> * lista, int pos)
{
    T dummy;
    Nodo<T> * aux;
    aux = lista->cab;
    int p = 0;
    while(aux != NULL)
    {
           if(pos == p)
           {
                  return aux->info;
           }
           aux = aux->sig;
           p++;
    }
    return dummy;
}

//Elimina la informacion de la posicion pos, retorna true si lo puede eliminar
template<typename T>
bool eliminar(Lista<T> * lista, int pos)
{
     if(lista->tam > pos)
     {
         if(pos == 0)
         {
             Nodo<T> * temp;
             temp = lista->cab;
             lista->cab = temp->sig;
             temp->sig = NULL;
             delete temp;
             lista->tam--;
             return true;
         }
         else
         {
             Nodo<T> * aux;
             aux = lista->cab;
             for(int i=0;i<pos-1;i++)
             {
                aux = aux->sig;
             }
             Nodo<T> *temp;
             temp = aux->sig;
             aux->sig = temp->sig;
             temp->sig = NULL;
             delete temp;
             lista->tam--;
             return true;
         }
     }
     else
     {
         return false;
     }
}

template<typename T>
void swap(Lista<T>* lista, int i){
  if(lista==NULL && i>=lista->tam-1){
    return;
  }
  Nodo<T> *nodo=lista->cab;
  for(int j=0;j<i;j++){
    nodo=nodo->sig;
  }
  Nodo<T> *next=nodo->sig;
  T aux=nodo->info;
  nodo->info=next->info;
  next->info=aux;
}


#endif
