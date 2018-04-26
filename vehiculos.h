#ifndef _VEHICULOS_
#define _VEHICULOS_

#include <stdio.h>
#include "ficheros.h"

#endif

//Descripcion: Imprime en pantalla cada uno de los datos de m_vehiculos
void mostrar_lista_vehiculos();

//Precondicion: id inicializado
/*Descripcion: Imprime en pantalla un menu con los vehiculos pertenecientes a id.
Devuelve el indice del vehiculo elegido en m_vehiculos, -2 si desea agregar un vehiculo y -1 si desea salir */
void menu_usuario_vehiculos(int id);

//Precondicion: m_vehiculos y id inicializados y en lon la longitud de m_vehiculos
/*Descripcion: Imprime en pantalla un formulario para agregar un nuevo vehiculos a m_vehiculos a id.
Devuelve m_vehiculos y lon actualizados*/
void agregar_vehiculo(vehiculos **m_vehiculos,int *lon,int id);

//Precondicion: m_vehiculos y matricula inicializados y en lon la longitud de m_vehiculos
/*Descripcion: Elimina de m_vehiculos el elemento al que le pertenezca el valor en matricula*/
void borrar_vehiculo(vehiculos **m_vehiculos,int *lon,char *matricula);

//Precondicion: m_vehiculos y modif inicializados, en lon la longitud de m_vehiculos e -1<indice<longitud
/*Descripcion: Reemplaza m_vehiculos[indice] con modif*/
void modificar_vehiculo(vehiculos *m_vehiculos,int lon,int indice,vehiculos modif);

//Busca vehiculo por matricula devuelve su posicion en m_vehiculos y -1 si no se encontro
int buscar_vehiculo(char *matricula);

void menu_admin_vehiculos(int id_Usuario);
