#include <stdio.h>
#include <vehiculos.c>

void borrar_vehiculo(vehiculos **,int *,char *);
void desplazar_vehiculos(vehiculos *,int,int,int);
void add_vehiculo(vehiculos *,int,int);
void modificar_vehiculo(vehiculos *,int,int,vehiculos);
void cargar_fich_vehiculos(vehiculos *,int);
void guardar_fich_vehiculos(vehiculos *,int);
void mostrar_lista(vehiculos *,int);
int mostrar_vehiculos_de_usuario(vehiculos *,int,int);
