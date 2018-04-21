#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include"vehiculos.h"

void mostrar_lista_vehiculos()
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

void menu_usuario_vehiculos(int id)
{
	int i,j,cursor,cursor2;
	char aux;
	do{
		i=j=0;
		system("cls");
		printf("\n\t Mis Vehiculos\n\n");
		while(i<l_vehiculos && m_vehiculos[i].id_Usuario!=id) i++;
		while(i<l_vehiculos && m_vehiculos[i].id_Usuario==id)
			{
			j++;
			printf("%i.- %s\n",j,m_vehiculos[i].definicion);
			i++;
		}
		if(j==0) puts("No tiene ningun vehiculo disponible");
		printf("\n%i.- A%cadir\n%i.- Volver\n\n",j+1,164,j+2);
		do
		{
				printf("Introduzca operacion: ");
				scanf("%i",&cursor);
		}while(cursor<1 || cursor>j+2);

		if(cursor==j+1) agregar_vehiculo(&m_vehiculos,&l_vehiculos,id);
		else
		{
			if(cursor==j+2) cursor=-1;
			else
			{
				cursor=i-j+cursor-1;
				do
				{
					do
					{
						system("cls");
						printf("\n\t %s\n\n",m_vehiculos[cursor].matricula);
						printf("\n1.- Definicion: %s\n2.- Plazas: %i\n3.- Borrar\n4.- Volver\n\n",m_vehiculos[cursor].definicion,m_vehiculos[cursor].plazas);
						printf("Introduzca operacion: ");
						scanf("%i",&cursor2);
					}while(cursor2<0 || cursor2>4);	
				
				switch (cursor2)
				{
            	case 1: 			//Definicion
					system("cls");
					printf("Nueva Definicion: ");
					fflush(stdin);
					fgets(m_vehiculos[cursor].definicion,51,stdin);
					fflush(stdin);
            	    break;
            	case 2:             //Plazas
            	    system("cls");
					do
					{
						printf("Nuevo Numero de plazas: ");
						scanf("%i",&aux);
					}while(aux<2 || aux>8);
					m_vehiculos[cursor].plazas=aux;
            	    break;
            	case 3:
					borrar_vehiculo(&m_vehiculos,&l_vehiculos,cursor);
            	    break;
            		}
				}while(cursor2!=4 && cursor2!=3);
			}
		}
	}while(cursor!=-1);
}

void agregar_vehiculo(vehiculos **m_vehiculos,int *lon,int id)
{
	vehiculos x;
	int i,aux;

	*lon=*lon+1;
	if(((*m_vehiculos)=(vehiculos *)realloc((*m_vehiculos),(*lon)*sizeof(vehiculos)))==NULL) puts("No hay espacio suficiente");
	else
	{
		system("cls");
		printf("\n\t Agregar un Vehiculo\n\n");
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

void borrar_vehiculo(vehiculos **m_vehiculos,int *lon,int indice)
{
    int i;

    for(i=indice;i<*lon;i++)
    {
        (*m_vehiculos)[i]=(*m_vehiculos)[i+1]; //reemplaza una estructura con la siguiente en el array
    }
    *lon=*lon-1;
    if(((*m_vehiculos)=(vehiculos *)realloc((*m_vehiculos),*lon*sizeof(vehiculos)))==NULL) puts("Error al borrar vehiculos");
}

void modificar_vehiculo(vehiculos *m_vehiculos,int lon,int indice,vehiculos modif)
{
    m_vehiculos[indice]=modif;
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

void menu_admin_vehiculos(int id_Usuario)
{
	int i,cursor,cursor2,aux;
	
	do
	{
		system("cls");
		printf("\n\t Lista de Vehiculos\n\n");
		for(i=0;i<l_vehiculos;i++)
		{
			aux=buscar_usuario_id(m_vehiculos[i].id_Usuario);
			if(aux!=-1) printf("%i.- %s de %s\n",i,m_vehiculos[i].definicion,m_usuarios[aux].user);
			else printf("%i.- %s\n",i,m_vehiculos[i].definicion);
		}
		printf("\n%i.- A%cadir\n%i.- Salir\n\n",i+1,164,i+2);
		do
			{
				printf("Introduzca operacion: ");
				scanf("%i",&cursor);
			}while(cursor<1 || cursor>i+2);

		if(cursor==i+1) agregar_vehiculo(&m_vehiculos,&l_vehiculos,id_Usuario);
		else
		{
			if(cursor==i+2) cursor=-1;
			else
			{
				do
				{
					do
					{
						system("cls");
						printf("\n\t %s\n\n",m_vehiculos[cursor].matricula);
						printf("\n1.- Definicion: %s\n2.- Plazas: %i\n3.- Lista de Viajes\n4.- Borrar\n5.- Volver\n\n",m_vehiculos[cursor].definicion,m_vehiculos[cursor].plazas);
						printf("Introduzca operacion: ");
						scanf("%i",&cursor2);
					}while(cursor2<0 || cursor2>5);	
				
				switch (cursor2)
				{
            	case 1: 			//Definicion
					system("cls");
					printf("Nueva Definicion: ");
					fflush(stdin);
					fgets(m_vehiculos[cursor].definicion,51,stdin);
					fflush(stdin);
            	    break;
            	case 2:             //Plazas
            	    system("cls");
					do
					{
						printf("Nuevo Numero de plazas: ");
						scanf("%i",&aux);
					}while(aux<2 || aux>8);
					m_vehiculos[cursor].plazas=aux;
            	    break;
            	case 3: //Lista de Viajes
            		break;
            	case 4:
					borrar_vehiculo(&m_vehiculos,&l_vehiculos,cursor);
            	    break;
            		}
				}while(cursor2!=4 && cursor2!=3 && cursor2!=5);
			}
		}
		
	}while(cursor!=-1);
}
