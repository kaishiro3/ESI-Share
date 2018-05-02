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

    char matricula[8];
    int id_Usuario;
    int plazas;
    char definicion[51];

 }vehiculos;

typedef struct {

	int id_viaje;
    char matricula[8];
    int Fecha_inicio[3];
    int Hora_inicio[2];
	int Hora_final[2];
	int id_usuario;
    int Plazas_libres;
    int ida_vuelta; //booleano de si es ida=1 o vuelta=0
    int precio;
    int estado; //si es abierto=0, cerrado=1, finalizado=2, cancelado=3, iniciado=4;

}viajes;

	typedef struct {

	int id_viaje;
    char poblacion[21];

}pasos;

    typedef struct {

    int id_viaje;
    int id_us_registra; //el usuario CULPABLE
    int id_us_incidencia; //el usuario que registra el incidente
    char desc_incidencia[101];
    int est_incidencia; // Abierta = 0, Validada = 1, Cerrada = 2

}incidencias;

usuarios *m_usuarios;
vehiculos *m_vehiculos;
viajes *m_viajes;
pasos *m_pasos;
incidencias *m_incidencias;

int l_usuarios;
int l_vehiculos;
int l_viajes;
int l_pasos;
int l_incidencias;


#endif

//Funciones

//Precondicion: cadena inicializada y que lon contenga su longitud
//Postcondicion: reemplaza '-' con ' ' y '\n' con '\0'
void fix_string(char *cadena,int lon);

//Postcondicion: Lee todos los ficheros y devuelve en los vectores globales los valores obtenidos
//con sus respectivas longitudes
void cargar_ficheros();
//Precondicion: variables globales inicializadas
//Postcondicion: Sobrescribe todos los ficheros con los datos de los vectores globales
void guardar_ficheros();

//Postcondicion: Lee el fichero "Vehiculos.txt" y devuelve en m_vehiculos
//cada uno de los elementos y en l_vehiculos la cantidad de elementos
void cargar_fich_vehiculos(vehiculos **,int *);

//Precondicion: m_vehiculos inicializado y en l_vehiculos la longitud
//Postcondicion: Sobrescribe "Vehiculos.txt" con los datos de m_vehiculos
void guardar_fich_vehiculos();

//Postcondicion: Lee el fichero "Usuarios.txt" y devuelve en m_usuarios
//cada uno de los elementos y en l_usuarios la cantidad de elementos.
void cargar_fich_usuarios(usuarios **,int *);

//Precondicion: m_vehiculos inicializado y en l_usuarios la longitud
//Postcondicion: Sobrescribe "Usuarios.txt" con los datos de m_usuarios.
void guardar_fich_usuarios();

//Postcondicion: Lee el fichero "Incidencias.txt" y devuelve en m_incidencias
//cada uno de los elementos y en l_incidencias la cantidad de elementos.
void cargar_fich_incidencias(incidencias **,int *);

//Precondicion: m_incidencias inicializado y en l_incidencias la longitud.
//Postcondicion: Sobrescribe "Incidencias.txt" con los datos de m_incidencias.
void guardar_fich_incidencias();

//Postcondicion: Lee el fichero "Viajes.txt" y devuelve en m_viajes
//cada uno de los elementos y en l_viajes la cantidad de elementos.
void cargar_fich_viajes(viajes **m_viajes, int *lon);

//Precondicion: m_viajes inicializado y en l_viajes la longitud.
//Postcondicion: Sobrescribe "Viajes.txt" con los datos de m_viajes.
void guardar_fich_viajes();

//Postcondicion: Lee el fichero "Pasos.txt" y devuelve en m_pasos
//cada uno de los elementos y en l_pasos la cantidad de elementos.
void cargar_fich_pasos(pasos **m_pasos,int *lon);

//Precondicion: m_pasos inicializado y en l_viajes la longitud.
//Postcondicion: Sobrescribe "Pasos.txt" con los datos de m_pasos.
void guardar_fich_pasos();
