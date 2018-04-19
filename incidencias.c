#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "incidencias.h"


void menu_inciusu(){

 int resp=0;
 do{
    printf("1. Crear incidencia: \n");
    printf("2. Consultar incidencia: \n");
    printf("3. Volver.")
    printf("Introduce un numero para elegir una opcion: \n");
    scanf("%i", &resp);
 }while(resp<1 || resp>3);
if (resp==1){
    crear_inciden();

}
if (resp==2){
    consult_inciden();
}

}
void menu_inciadmin(){

 int resp=0;
 do{
    printf("1. Crear incidencia: \n");
    printf("2. Eliminar incidencia: \n");
    printf("3. Modificar incidencia: \n");
    printf("4. Listar incidencias: \n");
    printf("5. Validar incidencias: \n");
    printf("6. Bloquear usuarios: \n");
    printf("7. Volver.\n")
    printf("Introduce un numero para elegir una opcion: \n");
    scanf("%i", &resp);
 }while(resp<1 || resp>7);
switch(resp){
case 1:
    crear_inciden();
    break;
case 2:
    elimin_inciden();
    break;
case 3:
    modif_inciden();
    break;
case 4:
    list_inciden(&l_incidencias);
    break;
case 5:
    valid_inciden();
    break;
case 6:
    bloquear_usu();
    break;
}

}


void modif_inciden(incidencias *m_incidencias, int lon, int i, incidencias modif){

    m_incidencias[i]=modif;
}

void list_inciden(int *lon){

    int i;

    for(i=0;i<*lon;i++){
        printf("Id del viaje: %d \n Id del usuario que registra: %d \n Id del usuario sobre el que recae: %d \n Descripcion: %s \n Estado: %s \n",m_incidencias[i].id_viaje,m_incidencias[i].id_us_registra,m_incidencias[i].id_us_incidencia,m_incidencias[i].desc_incidencia,m_incidencias[i].est_incidencia);
}

void consult_inciden(int id){
     int i,j,cursor;
     i=j=0;
     puts("");
     while(i<l_incidencias && m_incidencias[i].id_us_incidencia!=id) i++;
     while(i<l_incidencias && m_incidencias[i].id_us_incidencia==id)
     {
          j++;
          printf("%i.- %s\n",j,m_incidencias[i].desc_incidencia);
          i++;
     }
     if(j==0) puts("No tiene ninguna incidencia a su nombre");
     printf("\n%i.- A%cadir\n%i.- Salir\n\n",j+1,164,j+2);
     do
     {
           printf("Introduzca operacion: ");
           scanf("%i",&cursor);
     }while(cursor<1 || cursor>j+2);

     if(cursor==j+1) cursor=-2;
     else
     {
           if(cursor==j+2) cursor=-1;
           else cursor=i-j+cursor;
     }
    return cursor;


