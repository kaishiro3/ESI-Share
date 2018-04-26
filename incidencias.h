#ifndef _INCIDENCIAS_
#define _INCIDENCIAS_
#include <stdio.h>
#endif // _INCIDENCIAS_

void crear_inciden(incidencias **,viajes **,int *, int);
void consult_inciden(incidencias *,int,int);
void elimin_inciden(incidencias **, int *, int);
void modif_inciden(incidencias *, int , int , incidencias);
void list_inciden(int *);
void valid_inciden(incidencias *);
void bloquear_usu(usuarios *);
void menu_inciusu();
void menu_inciadmin();
