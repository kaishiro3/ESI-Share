#ifndef _INCIDENCIAS_
#define _INCIDENCIAS_
#include <stdio.h>
#endif // _INCIDENCIAS_

typedef struct {

   int id_viaje[6];
   int id_us_registra[4];
   int id_us_incidencia[4];
   char desc_incidencia[100];
   char est_incidencia[20];
}incidencias;

void crear_inciden(incidencias **m_incidencias, int *n, int id);
void consult_inciden(int id_us_incidencia);
void elimin_inciden(incidencias **m_incidencias, int *n, int *viaje);
void modif_inciden(incidencias *m_incidencias, int n, int i, incidencias modif);
void list_inciden();
void valid_inciden(incidencias *);
void bloquear_usu(usuarios *);
void cargar_fich_inci(incidencias **m_incidencias, int *n);
void guardar_fich_inci(incidencias *m_incidencias, int n);
