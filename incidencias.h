#ifndef _INCIDENCIAS_
#define _INCIDENCIAS_
#include <stdio.h>
#include "ficheros.h"
#endif // _INCIDENCIAS_

//Precondicion: m_incidencias, m_viajes e id como valores inicializados y lon siendo la longitud de m_incidencias.
//Postcondicion: Imprime en pantalla un formulario para crear una incidencia en m_incidencias y actualiza m_incidencias y lon.
void crear_inciden(incidencias **,viajes **,int *, int);

//Precondicion: m_incidencias e id como valores inicializados y lon siendo la longitud de m_incidencias.
//Postcondicion: Consulta incidencia por id, mostrando tanto las registradas por ese id como las incidencias que le han caido a ese id.
void consult_inciden(incidencias *,int,int);

//Precondicion: m_incidencias e indice como valores inicializados y lon siendo la longitud de m_incidencias.
//Postcondicion: Elimina en m_incidencias la fila que le corresponde con el valor del indice.
void elimin_inciden(incidencias **, int *, int);

//Precondicion:
//Postcondicion:
void modif_inciden(incidencias *, int , int , incidencias);

//Precondicion: lon es la longitud de m_incidencias.
//Postcondiciones: Muestra toda la lista de incidencias.
void list_inciden(int *);

//Precondicion:
//Postcondicion:
void valid_inciden(incidencias **, int *);

//Precondicion:
//Postcondicion:
void bloquear_usu(incidencias *, usuarios **, int);

//Postcondicion: Muestra las operaciones que puede realizar un usuario estandar.
void menu_inciusu();

//Postcondicion: Muestra las operaciones que puede realizar un usuario administrador.
void menu_inciadmin();
