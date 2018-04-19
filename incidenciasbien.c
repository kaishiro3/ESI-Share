#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "incidenciasbien.h"

static int menu_inciusu();
static int menu_inciadmin();

int main(){

    return 0;
}

int menu_inciusu(){

 int resp=0;
 do{
    printf("1. Crear incidencia: \n");
    printf("2. Consultar incidencia: \n");
    printf("Introduce un numero para elegir una opcion: \n");
    scanf("%i", &resp);
 }while(resp<1 || resp>2);

}

int menu_inciadmin(){

 int resp=0;
 do{
    printf("1. Crear incidencia: \n");
    printf("2. Eliminar incidencia: \n");
    printf("3. Modificar incidencia: \n");
    printf("4. Listar incidencias: \n");
    printf("5. Validar incidencias: \n");
    printf("6. Bloquear usuarios: \n");
    printf("Introduce un numero para elegir una opcion: \n");
    scanf("%i", &resp);
 }while(resp<1 || resp>6);

}

void modif_inciden(incidencias *m_incidencias, int *lon, int i, incidencias modif){

    m_incidencias[i]=modif;
}

void list_inciden(){

    int i;

    for(i=0;i<*lon;i++){
        printf("Id del viaje: %d \n Id del usuario que registra: %d \n Id del usuario sobre el que recae: %d \n Descripcion: %s \n Estado: %s \n",m_incidencias[i].id_viaje,m_incidencias[i].id_us_registra,m_incidencias[i].id_us_incidencia,m_incidencias[i].desc_incidencia,m_incidencias[i].est_incidencia);
}
}



