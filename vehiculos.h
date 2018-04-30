#ifndef _VEHICULOS_
#define _VEHICULOS_

#include <stdio.h>
#include "ficheros.h"

#endif

//Postcondicion: Imprime en pantalla cada uno de los datos de m_vehiculos.
void mostrar_lista_vehiculos();

//Precondicion: id_Usuario > 0.
//Postcondicion: Accede al menu de vehiculos de usuarios estandar mostrando los vehiculos pertenecientes a id.
void menu_usuario_vehiculos(int id_Usuario);

//Precondicion: m_vehiculos e id inicializados y en lon la longitud de m_vehiculos.
//Postcondicion: Imprime en pantalla un formulario para agregar un nuevo vehiculos a m_vehiculos a id.
//Devuelve m_vehiculos y lon actualizados*/
void agregar_vehiculo(vehiculos **m_vehiculos,int *lon,int id);

//Precondicion: m_vehiculos y matricula inicializados y en lon la longitud de m_vehiculos.
//Descripcion: Elimina de m_vehiculos el elemento que le corresponde el valor de indice.
void borrar_vehiculo(vehiculos **m_vehiculos,int *lon,int indice);

//Precondicion: matricula inicializada.
//Postcondicion: Busca vehiculo por matricula devuelve su posicion en m_vehiculos y -1 si no se encontro.
int buscar_vehiculo(char *matricula);

//Precondicion: id_Usuario > 0.
//Postcondicion: Accede al menu de vehiculos de usuarios admin mostrando todos los vehiculos.
void menu_admin_vehiculos(int id_Usuario);
