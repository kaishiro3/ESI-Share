#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include"ficheros.h"

void cargar_fich_vehiculos(vehiculos **m_vehiculos,int *lon)
{
	FILE *fich;
	int i,j;
	char aux;
	
	if ((fich = fopen("Vehiculos.txt", "r")) == NULL) printf("No se puede abrir Vehiculos.txt\n");
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
                fgets((*m_vehiculos)[i].matricula,8,fich); //Lee la matricula
                (*m_vehiculos)[i].matricula[7]='\0';
                fseek(fich,1,SEEK_CUR); //Omision del guion
                (*m_vehiculos)[i].id_Usuario=0;
                for(j=1000;j>0;j=j/10) //Procedimiento para leer el id de Usuario
                {
                    (*m_vehiculos)[i].id_Usuario=(*m_vehiculos)[i].id_Usuario+((fgetc(fich)-48)*j);
                }
                fseek(fich,1,SEEK_CUR);
                (*m_vehiculos)[i].plazas=fgetc(fich)-48; //Lee el numero de plazas que es un solo digito
                fseek(fich,1,SEEK_CUR);
                j=0;
                do //Procedimiento para leer la definicion
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

void cargar_fich_usuarios(usuarios **m_usuarios,int *lon)
{
	FILE *fich;
	int i,j;
	char aux,aux2[15];
	
	if ((fich = fopen("Usuarios.txt", "r")) == NULL) printf("No se puede abrir Usuarios.txt\n");
	else
	{
		*lon=0;
		do
		{
			i=fgetc(fich);
			if(i=='\n' || i==EOF) *lon=*lon+1;
		}while(i!=EOF);
		rewind(fich);
		if(((*m_usuarios)=(usuarios *)malloc((*lon)*sizeof(usuarios)))==NULL) puts("No hay espacio suficiente");
		else
        {
            for(i=0;i<*lon;i++)
            {
				for(j=1000;j>0;j=j/10) //Procedimiento para leer el id de Usuario
          		{
					(*m_usuarios)[i].id_Usuario=(*m_usuarios)[i].id_Usuario+((fgetc(fich)-48)*j);
        	    }
            	j=0;
            	fseek(fich,1,SEEK_CUR); //Omision del guion
            	
            	do //Procedimiento para leer el nombre
            	{
            	    aux=fgetc(fich);
            	    (*m_usuarios)[i].nombre[j]=aux;
            	    j++;
            	}while(aux!='-' && j<20);
            	(*m_usuarios)[i].nombre[j]='\0';
            	j=0;
            	fseek(fich,1,SEEK_CUR); //Omision del guion
            	
            	do //Procedimiento para leer la poblacion
            	{
            	    aux=fgetc(fich);
            	    (*m_usuarios)[i].poblacion[j]=aux;
            	    j++;
            	}while(aux!='-' && j<20);
            	(*m_usuarios)[i].poblacion[j]='\0';
            	j=0;
            	fseek(fich,1,SEEK_CUR); //Omision del guion
            	
            	do //Procedimiento para leer el perfil
            	{
            	    aux=fgetc(fich);
            	    aux2[j]=aux;
            	    j++;
            	}while(aux!='-' && j<15);
            	aux2[j]='\0';
            	if(strcmp(aux2,"usuario")==0)
            	(*m_usuarios)[i].perfil=0;
            	j=0;
            	fseek(fich,1,SEEK_CUR); //Omision del guion
            	
            	do //Procedimiento para leer el user
            	{
            	    aux=fgetc(fich);
            	    (*m_usuarios)[i].user[j]=aux;
            	    j++;
            	}while(aux!='-' && j<5);
            	(*m_usuarios)[i].user[j]='\0';
            	j=0;
            	fseek(fich,1,SEEK_CUR); //Omision del guion
            	
            	do //Procedimiento para leer la contraseña
            	{
            	    aux=fgetc(fich);
            	    (*m_usuarios)[i].password[j]=aux;
            	    j++;
            	}while(aux!='-' && j<8);
            	(*m_usuarios)[i].password[j]='\0';
            	j=0;
            	fseek(fich,1,SEEK_CUR); //Omision del guion
            	
            	do //Procedimiento para leer el estado
            	{
            	    aux=fgetc(fich);
            	    aux2[j]=aux;
            	    j++;
            	}while(aux!='-' && j<15);
            	aux2[j]='\0';
            	if(strcmp(aux2,"activo")==0)
            	(*m_usuarios)[i].estado=1;
        	}
    	}
	fclose (fich);
    }
}
