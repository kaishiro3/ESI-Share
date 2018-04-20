#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include"ficheros.h"

//	Descripcion: lee la siguiente palabra en el fichero
//	Precondicion: fichero ya abierto en la palabre que quiere ser leida
//y en lon la longitudad maxima que acepta cadena
//	Postcondicion: lee la desde la posicion del puntero fich en el fichero hasta que encuentra un guion
//hasta que encuentra un guion y guarda la cadena sin el guion en la raiable cadena
static void leer_string_fich(char * cadena, int lon, FILE * fich);

static int leer_int_fich(int digitos,FILE * fich);

void leer_string_fich(char * cadena, int lon,FILE * fich)
{
	int j=0;
	char aux;
	do
	{
            aux=fgetc(fich);
            if(aux!='-') cadena[j]=aux;
            else cadena[j]='\0';
            j++;
    }while(aux!='-' && j<lon);
}

int leer_int_fich(int digitos,FILE * fich)
{
	int i,aux=0;
	for(i=pow(10,digitos-1);i>0;i=i/10) //Procedimiento para leer el id de Usuario
    {
    	aux=aux+((fgetc(fich)-48)*i);
    }
    return aux;
}

void cargar_ficheros()
{
	cargar_fich_usuarios(&m_usuarios,&l_usuarios);
	cargar_fich_vehiculos(&m_vehiculos,&l_vehiculos);
	cargar_fich_viajes(&m_viajes,&l_viajes);
	cargar_fich_pasos(&m_pasos,&l_pasos);
	cargar_fich_incidencias(&m_incidencias,&l_incidencias);
}

void guardar_ficheros()
{
	guardar_fich_vehiculos(m_vehiculos,l_vehiculos);
}

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
                leer_string_fich((*m_vehiculos)[i].matricula,8,fich);; //Lee la matricula
                
                (*m_vehiculos)[i].id_Usuario=leer_int_fich(4,fich);
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
				(*m_usuarios)[i].id_Usuario=leer_int_fich(4,fich);
            	fseek(fich,1,SEEK_CUR); //Omision del guion
            	leer_string_fich((*m_usuarios)[i].nombre,21,fich);
                leer_string_fich((*m_usuarios)[i].poblacion,21,fich);

				j=0;
            	do //Procedimiento para leer el perfil
            	{
            	    aux=fgetc(fich);
            	    if(aux!='-') aux2[j]=aux;
            	    else aux2[j]='\0';
            	    j++;
            	}while(aux!='-' && j<16);
            	if(strcmp(aux2,"usuario")==0)
            	(*m_usuarios)[i].perfil=0;
            	else (*m_usuarios)[i].perfil=1;
            	j=0;
            	leer_string_fich((*m_usuarios)[i].user,6,fich);
                leer_string_fich((*m_usuarios)[i].password,9,fich);

            	do //Procedimiento para leer el estado
            	{
            	    aux=fgetc(fich);
            	    if(aux!='\n' && aux!=EOF && aux!='\0') aux2[j]=aux;
            	    else aux2[j]='\0';
            	    j++;
            	}while(j<16 && aux!='\0' && aux!='\n' && aux!=EOF);
            	if(strcmp(aux2,"activo")==0) (*m_usuarios)[i].estado=1;
            	else (*m_usuarios)[i].estado=0;
        	}
    	}
	fclose (fich);
    }
}

void cargar_fich_viajes(viajes **m_viajes,int *lon)
{
	FILE *fich;
	int i,j;
	char aux,aux2[15];

	if ((fich = fopen("Viajes.txt", "r")) == NULL) printf("No se puede abrir Viajes.txt\n");
	else
	{
		*lon=0;
		do
		{
			i=fgetc(fich);
			if(i=='\n' || i==EOF) *lon=*lon+1;
		}while(i!=EOF);
		rewind(fich);
		if(((*m_viajes)=(viajes *)malloc((*lon)*sizeof(viajes)))==NULL) puts("No hay espacio suficiente");
		else
        {
            for(i=0;i<*lon;i++)
            {
				(*m_viajes)[i].id_viaje=leer_int_fich(6,fich);
				fseek(fich,1,SEEK_CUR); //Omision del guion
				
				leer_string_fich((*m_viajes)[i].matricula,8,fich);; //Lee la matricula
				
            	(*m_viajes)[i].Fecha_inicio[0]=leer_int_fich(2,fich);
            	fseek(fich,1,SEEK_CUR);
            	(*m_viajes)[i].Fecha_inicio[1]=leer_int_fich(2,fich);
            	fseek(fich,1,SEEK_CUR);
            	(*m_viajes)[i].Fecha_inicio[2]=leer_int_fich(4,fich);
            	fseek(fich,1,SEEK_CUR);
            	
            	(*m_viajes)[i].Hora_inicio[0]=leer_int_fich(2,fich);
            	fseek(fich,1,SEEK_CUR);
            	(*m_viajes)[i].Hora_inicio[1]=leer_int_fich(2,fich);
            	fseek(fich,1,SEEK_CUR);
            	(*m_viajes)[i].Hora_final[0]=leer_int_fich(2,fich);
            	fseek(fich,1,SEEK_CUR);
            	(*m_viajes)[i].Hora_final[1]=leer_int_fich(2,fich);
            	fseek(fich,1,SEEK_CUR);
				
				(*m_viajes)[i].Plazas_libres=fgetc(fich)-48; //Lee el numero de plazas que es un solo digito
				fseek(fich,1,SEEK_CUR);
				
				j=0;
            	do //Procedimiento para leer si es ida o vuelta
            	{
            	    aux=fgetc(fich);
            	    if(aux!='-') aux2[j]=aux;
            	    else aux2[j]='\0';
            	    j++;
            	}while(aux!='-' && j<7);
            	if(strcmp(aux2,"ida")==0) (*m_viajes)[i].ida_vuelta=1;
            	else (*m_viajes)[i].ida_vuelta=0;
            	
            	(*m_viajes)[i].precio=fgetc(fich)-48; //Lee el precio que es un solo digito
            	fseek(fich,2,SEEK_CUR); //Omision del Guion y el simbolo del Euro
            	
				j=0;
				do{
            	    aux=fgetc(fich);
            	    if(aux!='\n' && aux!=EOF) aux2[j]=aux;
            	    else aux2[j]='\0';
            	    j++;
            	}while(j<16 && aux!='\0' && aux!='\n' && aux!=EOF);
            	if(strcmp(aux2,"abierto")==0) (*m_viajes)[i].estado=0;
            	else
                {
                    if(strcmp(aux2,"cerrado")==0) (*m_viajes)[i].estado=1;
                    else
                    {
                    	if(strcmp(aux2,"finalizado")==0) (*m_viajes)[i].estado=2;
                    	else
						{
                    		if(strcmp(aux2,"cancelado")==0) (*m_viajes)[i].estado=3;
                    		else (*m_viajes)[i].estado=4;
						}
					}
                }
        	}
    	}
	fclose (fich);
    }
}

void cargar_fich_pasos(pasos **m_pasos,int *lon)
{
	FILE *fich;
	int i,j;
	char aux;

	if ((fich = fopen("Pasos.txt", "r")) == NULL) printf("Pasos.txt\n");
	else
	{
		*lon=0;
		do
		{
			i=fgetc(fich);
			if(i=='\n' || i==EOF) *lon=*lon+1;
		}while(i!=EOF);
		rewind(fich);
		if(((*m_pasos)=(pasos *)malloc((*lon)*sizeof(pasos)))==NULL) puts("No hay espacio suficiente");
		else
        {
            for(i=0;i<*lon;i++)
            {
                (*m_pasos)[i].id_viaje=leer_int_fich(4,fich);
                fseek(fich,1,SEEK_CUR);
                
                j=0;
                do //Procedimiento para leer la definicion
                {
                    aux=fgetc(fich);
                    if(aux!='\n' && aux!=EOF) (*m_pasos)[i].poblacion[j]=aux;
                    else (*m_pasos)[i].poblacion[j]='\0';
                    j++;
                }while(aux!='\0' && aux!='\n' && aux!=EOF && j<21);
            }
        }
	fclose (fich);
    }
}

void cargar_fich_incidencias(incidencias **m_incidencias,int *lon)
{
	FILE *fich;
	int i,j;
	char aux,aux2[15];

	if ((fich = fopen("Incidencias.txt", "r")) == NULL) printf("No se puede abrir Incidencias.txt\n");
	else
	{
		*lon=0;
		do
		{
			i=fgetc(fich);
			if(i=='\n' || i==EOF) *lon=*lon+1;
		}while(i!=EOF);
		rewind(fich);
		if(((*m_incidencias)=(incidencias *)malloc((*lon)*sizeof(incidencias)))==NULL) puts("No hay espacio suficiente");
		else
        {
            for(i=0;i<*lon;i++)
            {
            	(*m_incidencias)[i].id_viaje=leer_int_fich(6,fich);
				fseek(fich,1,SEEK_CUR); //Omision del guion
            	
				(*m_incidencias)[i].id_us_registra=leer_int_fich(4,fich);
            	fseek(fich,1,SEEK_CUR); //Omision del guion
            	
            	(*m_incidencias)[i].id_us_incidencia=leer_int_fich(4,fich);
            	fseek(fich,1,SEEK_CUR); //Omision del guion


            	leer_string_fich((*m_incidencias)[i].desc_incidencia,101,fich);

				j=0;
            	do //Procedimiento para leer el perfil
            	{
            	    aux=fgetc(fich);
            	    if(aux!='\n' && aux!=EOF && aux!='\0') aux2[j]=aux;
            	    else aux2[j]='\0';
            	    j++;
            	}while(j<16 && aux!='\0' && aux!='\n' && aux!=EOF);
            	if(strcmp(aux2,"Abierta")==0) (*m_incidencias)[i].est_incidencia=0;
            	else
                {
                    if(strcmp(aux2,"Validada")==0) (*m_incidencias)[i].est_incidencia=1;
                    else (*m_incidencias)[i].est_incidencia=2;
                }
        	}
    	}
	fclose (fich);
    }
}
