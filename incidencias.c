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
}

void consult_inciden(incidencias *m_incidencias,int lon,int id){
	int i;
	for(i=0;i<lon;i++)
	{
		if(strcmp(m_incidencias[i].id_us_registra,id)==0 || strcmp(m_incidencias[i].id_us_incidencia,id)==0)
		        printf("Id del viaje: %d \n Id del usuario que registra: %d \n Id del usuario sobre el que recae: %d \n Descripcion: %s \n Estado: %s \n",m_incidencias[i].id_viaje,m_incidencias[i].id_us_registra,m_incidencias[i].id_us_incidencia,m_incidencias[i].desc_incidencia,m_incidencias[i].est_incidencia);
	}
}
void elimin_inciden(incidencias **m_incidencias, int *lon, int indice){
 int i;

    for(i=indice;i<*lon;i++)
    {
        (*m_incidencias)[i]=(*m_incidencias)[i+1]; //reemplaza una estructura con la siguiente en el array
    }
    *lon=*lon-1;
    if(((*m_incidencias)=(incidencias *)realloc((*m_incidencias),*lon*sizeof(incidencias)))==NULL) puts("Error al borrar la incidencia");
}

