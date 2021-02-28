
#ifndef Util_H
#define Util_H

#include "Lista.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Asignatura{
  int codigo;
  char *nombre;
  char *descripcion;
  int creditos;
};

struct Estudiante{
  int id;
  int codigo;
  char *nombre;
  char *apellido;
  int semestre;
  int creditos;
  Lista<Asignatura*> *asignaturas;
};
void crearEstudiante(Lista<Estudiante*> *estudiantes,int id, int codigo,
  char*  nombre, char* apellido, int semestre);
bool crearAsignatura(Lista<Estudiante*> *estudiantes,int idEst,int codigo,
  char*nombre,char *descripcion,int creditos,int opt);
Estudiante* buscarEstudiante(Nodo<Estudiante*> *estudiantes, int id,int opt);
void acomodarAsignatura(Lista<Asignatura*> *asignaturas);
void imprimirAsignaturas(Nodo<Asignatura*> *asignaturas,int i);
Estudiante* buscarEstudianteNombre(Nodo<Estudiante*> *estudiantes, char* nombre);
void imprimirEstudiantes(Nodo<Estudiante*> *estudiantes,int i);


//____________________________________________________________



void crearEstudiante(Lista<Estudiante*> *estudiantes,int id, int codigo,
  char*  nombre, char* apellido, int semestre){
  Estudiante *estudiante=new Estudiante;
  estudiante->nombre=new char[30];
  estudiante->apellido=new char[30];
  strcpy(estudiante->nombre, nombre);
  strcpy(estudiante->apellido, apellido);
  estudiante->id=id;
  estudiante->codigo=codigo;
  estudiante->nombre=nombre;
  estudiante->apellido=apellido;
  estudiante->semestre=semestre;
  estudiante->creditos=0;
  estudiante->asignaturas=crearLista<Asignatura*>();
  insertar(estudiantes,estudiante);
}

bool crearAsignatura(Lista<Estudiante*> *estudiantes,int idEst,int codigo,
  char*nombre,char *descripcion,int creditos,int opt){
  Asignatura *asignatura=new Asignatura;
  asignatura->nombre=new char[30];
  asignatura->descripcion=new char[80];
  asignatura->codigo=codigo;
  asignatura->creditos=creditos;
  strcpy(asignatura->nombre,nombre);
  strcpy(asignatura->descripcion,descripcion);
  Estudiante *est=buscarEstudiante(estudiantes->cab,idEst,opt);
  if(est!= NULL && est->creditos+creditos<=20){
    est->creditos+=creditos;
    insertar(est->asignaturas,asignatura);
    acomodarAsignatura(est->asignaturas);
    return true;
  }
  return false;
}

//si opt ==0 se busca por id, de lo contrario se busca por codigo
Estudiante* buscarEstudiante(Nodo<Estudiante*> *estudiantes, int id,int opt){
  Estudiante *est=estudiantes->info;
  int val;
  if(opt==0){
    val=est->id;
  }else{
    val=est->codigo;
  }
  if(val==id){
    return est;
  }
  Nodo<Estudiante*> *next=estudiantes->sig;
  if(next==NULL){
    return NULL;
  }
  return buscarEstudiante(next,id,opt);
}

Estudiante* buscarEstudianteNombre(Nodo<Estudiante*> *estudiantes, char* nombre){
  Estudiante *est;
  if(estudiantes==NULL){
    return NULL;
  }
  est=estudiantes->info;
  cout<<nombre<<'\n';
  cout<<est->nombre<<'\n';
  if(strcmp(est->nombre,nombre)==0){
    return est;
  }
  Nodo<Estudiante*> *next=estudiantes->sig;
  return buscarEstudianteNombre(next,nombre);
}

void imprimirAsignaturas(Nodo<Asignatura*> *asignaturas,int i){
  Asignatura* asignatura;
  if(asignaturas==NULL){
    return;
  }
  asignatura=asignaturas->info;
  cout<<i<<")"<<asignatura->nombre<<'\n';
  cout<<"   "<<asignatura->codigo<<'\n';
  cout<<"   "<<asignatura->descripcion<<'\n';
  cout<<"   "<<asignatura->creditos<<'\n'<<'\n';
  imprimirAsignaturas(asignaturas->sig,i+1);
}

void imprimirEstudiantes(Nodo<Estudiante*> *estudiantes,int i){
  if(estudiantes==NULL){
    return;
  }
  cout<<i<<")"<<estudiantes->info->nombre<<" "<<
  estudiantes->info->apellido<<'\n';
  imprimirEstudiantes(estudiantes->sig,i+1);
}

void acomodarAsignatura(Lista<Asignatura*> *asignaturas){
  Asignatura *a1,*a2;
  for(int j=0;j<asignaturas->tam-1;j++){
    for(int i=0;i<asignaturas->tam-1;i++){
      a1=obtenerDato(asignaturas,i);
      a2=obtenerDato(asignaturas,i+1);
      if(strcmp(a1->nombre,a2->nombre)>0){
        swap(asignaturas,i);
      }
    }
  }
}

#endif
