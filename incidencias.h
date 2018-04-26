#ifndef _INCIDENCIAS_
#define _INCIDENCIAS_
#include <stdio.h>
#endif // _INCIDENCIAS_

void crear_inciden(incidencias **,viajes **,int *, int);
void consult_inciden(incidencias *,int,int);
void elimin_inciden(incidencias **, int *, int);
void modif_inciden(incidencias *m_incidencias, int lon, int i, incidencias modif);
void list_inciden(int *lon);
void valid_inciden(incidencias *);
void bloquear_usu(usuarios *);
void menu_inciusu();
void menu_inciadmin();
