#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include"vehiculos.h"

void mostrar_lista()
{
	int i;
	for(i=0;i<l_vehiculos;i++)
	{
		printf("elemento %i:\n",i);
		printf("Matricula: %s\n",m_vehiculos[i].matricula);
		printf("ID de Usuario: %i\n",m_vehiculos[i].id_Usuario);
		printf("Plazas: %i\n",m_vehiculos[i].plazas);
		printf("%s\n",m_vehiculos[i].definicion);

	}

}

int mostrar_vehiculos_de_usuario(int id)
{
	int i,j,cursor;
	i=j=0;
	puts("");
	while(i<l_vehiculos && m_vehiculos[i].id_Usuario!=id) i++;
	while(i<l_vehiculos && m_vehiculos[i].id_Usuario==id)
	{
		j++;
		printf("%i.- %s\n",j,m_vehiculos[i].definicion);
		i++;
	}
	if(j==0) puts("No tiene ningun vehiculo disponible");
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
}

void agregar_vehiculo(vehiculos **m_vehiculos,int *lon,int id)
{
	vehiculos x;
	int i,aux;

	*lon=*lon+1;
	if(((*m_vehiculos)=(vehiculos *)realloc((*m_vehiculos),(*lon)*sizeof(vehiculos)))==NULL) puts("No hay espacio suficiente");
	else
	{
		printf("\nMatricula: ");
		fflush(stdin);
		fgets(x.matricula,8,stdin);
		fflush(stdin);
		x.id_Usuario=id;
		do
		{
			printf("Numero de plazas: ");
			scanf("%i",&aux);
		}while(aux<2 || aux>8);
		x.plazas=aux;
		fflush(stdin);
		printf("Definicion: ");
		fflush(stdin);
		fgets(x.definicion,51,stdin);
		fflush(stdin);
		i=0;
		while(i<*lon-1 && (*m_vehiculos)[i].id_Usuario!=id) i++;
		while(i<*lon-1 && (*m_vehiculos)[i].id_Usuario==id) i++;
		aux=*lon-1;
		while(aux>i)
		{
			(*m_vehiculos)[aux]=(*m_vehiculos)[aux-1];
			aux--;
		}
		modificar_vehiculo((*m_vehiculos),*lon,i,x);
	}


}

void borrar_vehiculo(vehiculos **m_vehiculos,int *lon,char *matricula)
{
    int i,ind_vehiculo;

    ind_vehiculo=-1;
    for(i=0;i<*lon;i++)
    {
     if(ind_vehiculo==-1) //Se cumple la condicion si el indice de la matricula no ha sido asignado
        {
            if(strcmp((*m_vehiculos)[i].matricula,matricula)==0)
            ind_vehiculo=i;
            (*m_vehiculos)[i]=(*m_vehiculos)[i+1]; //reemplaza una estructura con la siguiente en el array
        }
        else
        {
            (*m_vehiculos)[i]=(*m_vehiculos)[i+1]; //reemplaza una estructura con la siguiente en el array
        }
    }
    *lon=*lon-1;
    if(((*m_vehiculos)=(vehiculos *)realloc((*m_vehiculos),*lon*sizeof(vehiculos)))==NULL) puts("Error al borrar vehiculos");
}

void modificar_vehiculo(vehiculos *m_vehiculos,int lon,int indice,vehiculos modif)
{
    m_vehiculos[indice]=modif;
    guardar_fich_vehiculos(m_vehiculos,lon);
}

int buscar_vehiculo(vehiculos *m_vehiculos,int lon,char *matricula)
{
	int i;
	for(i=0;i<lon;i++)
	{
		if(strcmp(m_vehiculos[i].matricula,matricula)==0)
		return i;
	}
	return -1;
}

int menu_admin_vehiculos()
{
	int i,j,cursor;
	for(i=0;i<l_vehiculos;i++)
	{
		printf("%i.- %s\n",j,m_vehiculos[i].definicion);
	}
	printf("\n%i.- A%cadir\n%i.- Salir\n\n",i+1,164,i+2);
	do
		{
			printf("Introduzca operacion: ");
			scanf("%i",&cursor);
		}while(cursor<1 || cursor>i+2);

	if(cursor==i+1) cursor=-2;
	else
	{
		if(cursor==i+2) cursor=-1;
	}
	return cursor;
}
