#include<stdio.h>
#include<string.h>

typedef struct {
        
        char* matricula;
        int id_Usuario;
        int plazas;
        char *definicion[50];
        
 }vehiculos ;

void borrar_vehiculo(vehiculos *,int *,char *);
void modificar_vehiculo(vehiculos *,int,vehiculos);

void borrar_vehiculo(vehiculos *m_vehiculos,int *lon,char *matricula)
{
    int i,ind_vehiculo;
    
    ind_vehiculo=-1;
    for(i=0;i<lon;i++)
    {
     if(ind_vehiculo==-1) //Se cumple la condicion si el indice de la matricula no ha sido asignado   
        {
            if(strcmp(m_vehiculos[i].matricula,matricula)==0)
            ind_vehiculo=i;
            m_vehiculos[i]=m_vehiculos[i+1]; //reemplaza una estructura con la siguiente en el array
        }
        else
        {
            m_vehiculos[i]=m_vehiculos[i+1]; //reemplaza una estructura con la siguiente en el array
        }
    }
    *lon=*lon-1;
}

void modificar_vehiculo(vehiculos *m_vehiculos,int indice,vehiculos modif)
{
    m_vehiculos[indice]=modif;
}
