#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include"vehiculos.h"

typedef struct {

        char matricula[7];
        int id_Usuario;
        int plazas;
        char definicion[50];

 }vehiculos ;

void borrar_vehiculo(vehiculos **,int *,char *);
void agregar_vehiculo(vehiculos **,int *,int);
void modificar_vehiculo(vehiculos *,int,int,vehiculos);
void cargar_fich_vehiculos(vehiculos **,int *);
void guardar_fich_vehiculos(vehiculos *,int);
void mostrar_lista(vehiculos *,int);
int mostrar_vehiculos_de_usuario(vehiculos *,int,int);

//Main de prueba
/*void main(){
    vehiculos *x;
	FILE *fich;
	int n,i,id,oper;
	n=0;
    cargar_fich_vehiculos(&x,&n);
		do
		{
			printf("ID de Usuario: ");
			scanf("%i",&id);
		}while(id<1);
		oper=mostrar_vehiculos_de_usuario(x,n,id);
		if(oper!=-1)
		{
			if(oper=-2)
			{
				agregar_vehiculo(&x,&n,id);
			}
		}
	guardar_fich_vehiculos(x,n);
}*/

void cargar_fich_vehiculos(vehiculos **m_vehiculos,int *lon)
{
	FILE *fich;
	int i,j;
	char aux;
	if ((fich = fopen("Vehiculos.txt", "r")) == NULL) printf("No se puede abrir el fichero.\n");
	else
	{
		*lon=0;
		do
		{
			i=fgetc(fich);
			if(i=='\n' || i==EOF) *lon=*lon+1;
		}while(i!=EOF);
		rewind(fich);
		if(((*m_vehiculos)=(vehiculos *)malloc((*lon)*sizeof(vehiculos)))==NULL) puts("No hay espacio suficiente");
		else
        {
            for(i=0;i<*lon;i++)
            {
                fgets((*m_vehiculos)[i].matricula,8,fich);
                (*m_vehiculos)[i].matricula[7]='\0';
                fseek(fich,1,SEEK_CUR);
                (*m_vehiculos)[i].id_Usuario=0;
                for(j=1000;j>0;j=j/10)
                {
                    (*m_vehiculos)[i].id_Usuario=(*m_vehiculos)[i].id_Usuario+((fgetc(fich)-48)*j);
                }
                fseek(fich,1,SEEK_CUR);
                (*m_vehiculos)[i].plazas=fgetc(fich)-48;
                fseek(fich,1,SEEK_CUR);
                j=0;
                do
                {
                    aux=fgetc(fich);
                    if(aux!='\n' && aux!=EOF) (*m_vehiculos)[i].definicion[j]=aux;
                    else (*m_vehiculos)[i].definicion[j]='\0';
                    j++;
                }while(aux!='\0' && aux!='\n' && aux!=EOF && j<=50);
            }
        }
	fclose (fich);
    }
}

void guardar_fich_vehiculos(vehiculos *m_vehiculos,int lon)
{
	FILE *fich;
	int i,j,aux;
if ((fich = fopen("Vehiculos.txt", "w")) == NULL) {
 printf("No se ha podido guardar el fichero.\n");
}
else
{
	for(i=0;i<lon;i++)
	{
		for(j=0;j<7;j++)
		{
			if(m_vehiculos[i].matricula[j]=='\0' || m_vehiculos[i].matricula[j]=='\n') fputc(' ',fich);
			else fputc(m_vehiculos[i].matricula[j],fich);
		}
		fputc('-',fich);
		aux=m_vehiculos[i].id_Usuario;

		for(j=1000;j>0;j=j/10)
		{
			fputc((aux/j)+48,fich);
			aux=aux-((aux/j)*j);
		}
		fputc('-',fich);
		fputc(m_vehiculos[i].plazas+48,fich);
		fputc('-',fich);
		j=0;
		while(m_vehiculos[i].definicion[j]!='\0' && m_vehiculos[i].definicion[j]!='\n' && j<=50)
		{
		fputc(m_vehiculos[i].definicion[j],fich);
		j++;
		}
		if(i!=lon-1) fputc('\n',fich);
	}
	fclose (fich);
}
}

void mostrar_lista(vehiculos *m_vehiculos,int lon)
{
	int i;
	for(i=0;i<lon;i++)
	{
		printf("elemento %i:\n",i);
		printf("Matricula: %s\n",m_vehiculos[i].matricula);
		printf("ID de Usuario: %i\n",m_vehiculos[i].id_Usuario);
		printf("Plazas: %i\n",m_vehiculos[i].plazas);
		printf("%s\n",m_vehiculos[i].definicion);

	}

}

int mostrar_vehiculos_de_usuario(vehiculos *m_vehiculos,int lon,int id)
{
	int i,j,cursor;
	i=j=0;
	puts("");
	while(i<lon && m_vehiculos[i].id_Usuario!=id) i++;
	while(i<lon && m_vehiculos[i].id_Usuario==id)
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
    if(((*m_vehiculos)=(vehiculos *)realloc((*m_vehiculos),*lon*sizeof(m_vehiculos)))==NULL) puts("Error al borrar vehiculos");
}

void modificar_vehiculo(vehiculos *m_vehiculos,int lon,int indice,vehiculos modif)
{
    m_vehiculos[indice]=modif;
    guardar_fich_vehiculos(m_vehiculos,lon);
}
