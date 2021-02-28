#include "util.h"
#include "Lista.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void ingresarEstudiante(Lista<Estudiante*> *estudiantes);
void mostrarAsignaturas(Lista<Estudiante*> *estudiantes);
void agregarAsignatura(Lista<Estudiante*> *estudiantes);
void eliminarAsignatura(Lista<Estudiante*> *estutiantes);
void eliminarEstudiantes(Lista<Estudiante*> *estudiantes);

int main(){
  int o=-1;
  Lista<Estudiante*> *estudiantes=crearLista<Estudiante*>();
  while(o!=0){
    cout<<"1)Crear estudiante con sus materias"<<'\n';
    cout<<"2)Mostrar materias estudiante"<<'\n';
    cout<<"3)Agregar asignatura a estudiante"<<'\n';
    cout<<"4)Eliminar asignaturas a estudiante"<<'\n';
    cout<<"5)Eliminar estudiantes"<<'\n';
    cout<<"0)Salir"<<'\n';
    cin>>o;
    switch (o){
      case 1:
        ingresarEstudiante(estudiantes);
        cout<<estudiantes->tam<<'\n';
      break;
      case 2:
        mostrarAsignaturas(estudiantes);
      break;
      case 3:
        agregarAsignatura(estudiantes);
      break;
      case 4:
        eliminarAsignatura(estudiantes);
      break;
      case 5:
        eliminarEstudiantes(estudiantes);
      break;
    }
  }
}


void ingresarEstudiante(Lista<Estudiante*> *estudiantes){
  int id,codigo,semestre,creditos,numAsignaturas;
  char *nombre=new char[30];
  char *apellido=new char[30];
  char *descripcion=new char[80];
  cout<<"Ingrese los datos del estudiante:"<<'\n';
  cout<<"   Id:";cin>>id;
  cout<<"   Codigo:";cin>>codigo;
  cout<<"   Nombre:";cin>>nombre;
  cout<<"   Apellido:";cin>>apellido;
  cout<<"   Semestre:";cin>>semestre;
  crearEstudiante(estudiantes,id,codigo,nombre,apellido,semestre);
  cout<<"Ingrese cuantas asignaturas inscribira el estudiante:";cin>>numAsignaturas;
  for(int i=0;i<numAsignaturas;i++){
    nombre=new char[30];
    descripcion=new char[30];
    cout<<"Ingrese los datos de la asignatura No. "<<i<<":"<<'\n';
      cout<<"   Codigo:";cin>>codigo;
      cout<<"   Nombre:";cin>>nombre;
      cout<<"   Descripcion:";cin>>descripcion;
      cout<<"   Creditos:";cin>>creditos;
      crearAsignatura(estudiantes,id,codigo,nombre,descripcion,creditos,0);
  }
  cout<<"Asignaturas inscritas"<<'\n'<<'\n';
}

void mostrarAsignaturas(Lista<Estudiante*> *estudiantes){
  Estudiante* est;
  char *nombre=new char[30];
  cout<<"Ingresar el nombre del estudiante:";cin>>nombre;
  est=buscarEstudianteNombre(estudiantes->cab,nombre);
  if(est!=NULL){
    imprimirAsignaturas(est->asignaturas->cab,0);
  }else{
    cout<<"No se encontro al estudiante"<<'\n';
  }
}

void agregarAsignatura(Lista<Estudiante*> *estudiantes){
  int o=0,id,codigo,creditos;
  cout<<"Escoja una opcion:"<<'\n';
  cout<<"   0)Buscar estudiante por id"<<'\n';
  cout<<"   1)Buscar estudiante por codigo"<<'\n';
  cin>>o;
  cout<<"Ingrese el id/codigo:";cin>>id;
  char *nombre=new char[30];
  char *descripcion=new char[30];
  cout<<"Ingrese los datos de la asignatura:"<<'\n';
  cout<<"   Codigo:";cin>>codigo;
  cout<<"   Nombre:";cin>>nombre;
  cout<<"   Descripcion:";cin>>descripcion;
  cout<<"   Creditos:";cin>>creditos;
  if(crearAsignatura(estudiantes,id,codigo,nombre,descripcion,creditos,o)){
    cout<<"Operacion exitosa!"<<'\n';
  }else{
    cout<<"Operacion fallida"<<'\n';
  }
}

void eliminarAsignatura(Lista<Estudiante*> *estudiantes){
  int o=0,id,codigo,creditos,n;
  cout<<"Escoja una opcion:"<<'\n';
  cout<<"   0)Buscar estudiante por id"<<'\n';
  cout<<"   1)Buscar estudiante por codigo"<<'\n';
  cin>>o;
  cout<<"Ingrese el id/codigo:";cin>>id;
  Estudiante *est=buscarEstudiante(estudiantes->cab,id,o);
  while(n>=0){
    if(est!=NULL){
      imprimirAsignaturas(est->asignaturas->cab,0);
    }else{
      cout<<"No se encontro al estudiante"<<'\n';
    }
    cout<<"Ingrese el enumerador de la asignatura"<<'\n';
    cout<<"ej:#)asignatura     # es el enumerador"<<'\n';
    cout<<"ingrese un numero negativo para volver al menu"<<'\n';
    cin>>n;
    if(n>=0 && n<est->asignaturas->tam){
      eliminar(est->asignaturas,n);
    }
  }
}

void eliminarEstudiantes(Lista<Estudiante*> *estudiantes){
  int n=0;
  while(n>=0){
    imprimirEstudiantes(estudiantes->cab,0);
    cout<<"Ingrese el enumerador del estudiante"<<'\n';
    cout<<"ej:#)nombre apellido     # es el enumerador"<<'\n';
    cout<<"Ingrese un numero negativo para volver al menu"<<'\n';
    cin>>n;
    if(n>=0 && n<estudiantes->tam){
      eliminar(estudiantes,n);
    }
  }
}
