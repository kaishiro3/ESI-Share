#ifndef _FICHEROS_
#define _FICHEROS_

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
        
    int id_Usuario;
    char nombre[20]; 
    char poblacion[20];
    int perfil; //si es admin o usuario normal Usuario=0
    int plazas;
    char user[5]; 
    char password[8];
    int estado; //activo=1 o bloqueado=0
    
}usuarios;

typedef struct {

    char matricula[7];
    int id_Usuario;
    int plazas;
    char definicion[50];

 }vehiculos;

typedef struct {
        
	int id_viaje[6];
    char* matricula; 
    int Fecha_inicio[3];
    int Hora_inicio[2];
	int Hora_final[2];
    int Plazas_libres;
    int ida_vuelta; //booleano de si es ida o vuelta
    int precio;
    int estado; //si es abierto, cerrado, finalizado, cancelado, iniciado;
    //localizacion* pasos[]; //las localizaciones por las que pasa;
    
}viajes;

    typedef struct {
        
    int id_viaje[6];
    int id_usuario; //el usuario CULPABLE
    int id_registra; //el usuario que registra el incidente
    char* definicion[100];
    int estado; // Abierto, valido, cerrado
    
}incidencias;

#endif

//Funciones
void cargar_fich_vehiculos(vehiculos **,int *);
void guardar_fich_vehiculos(vehiculos *,int);

void cargar_fich_usuarios(usuarios **,int *);
