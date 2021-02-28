#ifndef CLAVES_H_INCLUDED
#define CLAVES_H_INCLUDED

char **crearMat(int *num); //se crea la matriz de N numero de cadenas

char **guardarCodigos(char **cadena,int *num); //permite ingresar datos en cada cadena de manera individual

void imprimirDobleCadenas(char **cadena,int *num); //imprime la cadena ingresada con su tamaño

char **clavesCorrectas(char **cadena, int *num); //Halla el valor de ? usando el metodo del proyecto

#endif // CLAVES_H_INCLUDED
