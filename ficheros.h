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

void cargar_ficheros();
void guardar_ficheros();

/*Descripcion: Lee el fichero "Vehiculos.txt" y devuelve en m_vehiculos
cada uno de los elementos y en lon la cantidad de elementos*/
void cargar_fich_vehiculos(vehiculos **,int *);

//Precondicion: m_vehiculos inicializado y en lon la longitud de vm_vehiculos
//Descripcion: Sobrescribe "Vehiculos.txt" con los datos de m_vehiculos
void guardar_fich_vehiculos();

void cargar_fich_usuarios(usuarios **,int *);

void guardar_fich_usuarios();

void cargar_fich_incidencias(incidencias **,int *);

void guardar_fich_incidencias();

/*Descripcion: lee el fichero "viajes.txt" y devuelve en m_viajes cada uno de los elementos
y en l_viajes la cantidad de elementos*/
//Precondicion: m_viajes inicializado y en lon>1
//Postcondicion: sobreescribe el actual m_viajes con el archivo en txt
//en caso de no haber un archivo llamado "viajes.txt" lo crearÃ¡ con el actual m_viajes actualizado
void cargar_fich_viajes(viajes **m_viajes, int *lon);

void guardar_fich_viajes();

void cargar_fich_pasos(pasos **m_pasos,int *lon);

void guardar_fich_pasos();


