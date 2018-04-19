#ifndef _FICHEROS_
#define _FICHEROS_

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct {

    int id_Usuario;
    char nombre[21];
    char poblacion[21];
    int perfil; //si es admin o usuario normal Usuario=0
    char user[6];
    char password[9];
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

    int id_viaje;
    int id_us_registra; //el usuario CULPABLE
    int id_us_incidencia; //el usuario que registra el incidente
    char desc_incidencia[101];
    int est_incidencia; // Abierto, valido, cerrado

}incidencias;

usuarios *m_usuarios;
vehiculos *m_vehiculos;
viajes *m_viajes;
incidencias *m_incidencias;

int l_usuarios;
int l_vehiculos;
int l_viajes;
int l_incidencias;


#endif

//Funciones
void cargar_ficheros();
void guardar_ficheros();
void proc_leer_string_fich(char *,int ,FILE *);

void cargar_fich_vehiculos(vehiculos **,int *);
void guardar_fich_vehiculos(vehiculos *,int);

void cargar_fich_usuarios(usuarios **,int *);

void cargar_fich_incidencias(incidencias **,int *);
