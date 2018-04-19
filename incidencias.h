#ifndef _INCIDENCIAS_
#define _INCIDENCIAS_
#include <stdio.h>
#endif // _INCIDENCIAS_

void crear_inciden(incidencias **m_incidencias, int *lon, int id);
void consult_inciden(int id_us_incidencia);
void elimin_inciden(incidencias **m_incidencias, int *lon, int *viaje);
void modif_inciden(incidencias *m_incidencias, int lon, int i, incidencias modif);
void list_inciden(int *lon);
void valid_inciden(incidencias *);
void bloquear_usu(usuarios *);
void menu_inciusu();
void menu_inciadmin();
