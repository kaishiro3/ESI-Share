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
static void escribir_int_fich(int numero,int digitos,FILE * fich);

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

void escribir_int_fich(int numero,int digitos,FILE * fich)
{
	int i,aux=0;
	for(i=pow(10,digitos-1);i>0;i=i/10) //Procedimiento para leer cada uno de los digitos de mayor a menor importancia
    {
    	fputc((numero/i)+48,fich);
		numero=numero-((numero/i)*i);
    }
}

void fix_string(char *cadena,int lon)
{
	int i=0;
	while(cadena[i]!='\n' && cadena[i]!='\0' && i<lon-1)
	{
		if(cadena[i]=='-') cadena[i]=' ';
		i++;
	}
	cadena[i]='\0';
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
	guardar_fich_usuarios();
	guardar_fich_vehiculos();
	guardar_fich_viajes();
	guardar_fich_pasos();
	guardar_fich_incidencias();
}
void guardar_fich_usuarios()
{
	FILE *fich;
	int i;
if ((fich = fopen("Usuarios.txt", "w")) == NULL) {
 printf("No se ha podido guardar Usuarios.txt.\n");
}
else
{
	for(i=0;i<l_usuarios;i++)
	{
		escribir_int_fich(m_usuarios[i].id_Usuario,4,fich);
		fprintf(fich,"-%s-%s-",m_usuarios[i].nombre,m_usuarios[i].poblacion);

		if(m_usuarios[i].perfil==0) fprintf(fich,"usuario");
		else fprintf(fich,"administrador");
		
        fprintf(fich,"-%s-%s-",m_usuarios[i].user,m_usuarios[i].password);

		if(m_usuarios[i].estado==0) fprintf(fich,"bloqueado");
		else fprintf(fich,"activo");
		if(i!=l_usuarios-1) fputc('\n',fich);
	}
	fclose (fich);
}
}


void guardar_fich_vehiculos()
{
	FILE *fich;
	int i,j;

if ((fich = fopen("Vehiculos.txt", "w")) == NULL) {
 printf("No se ha podido guardar Vehiculos.txt.\n");
}
else
{

	for(i=0;i<l_vehiculos;i++)
	{
		for(j=0;j<7;j++)
		{
			if(m_vehiculos[i].matricula[j]=='\0' || m_vehiculos[i].matricula[j]=='\n') fputc(' ',fich);
			else fputc(m_vehiculos[i].matricula[j],fich);
		}
		fputc('-',fich);
		escribir_int_fich(m_vehiculos[i].id_Usuario,4,fich);
		fputc('-',fich);
		fputc(m_vehiculos[i].plazas+48,fich);
		fprintf(fich,"-%s",m_vehiculos[i].definicion);
		if(i!=l_vehiculos-1) fputc('\n',fich);
	}
	fclose (fich);
}
}

void guardar_fich_viajes()
{
	FILE *fich;
	int i,j;
if ((fich = fopen("Viajes.txt", "w")) == NULL) {
 printf("No se ha podido guardar Viajes.txt.\n");
}
else
{
	for(i=0;i<l_viajes;i++)
	{
		escribir_int_fich(m_viajes[i].id_viaje,6,fich);
		fputc('-',fich);

		for(j=0;j<7;j++)
		{
			if(m_viajes[i].matricula[j]=='\0' || m_viajes[i].matricula[j]=='\n') fputc(' ',fich);
			else fputc(m_viajes[i].matricula[j],fich);
		}
		fputc('-',fich);

		escribir_int_fich(m_viajes[i].Fecha_inicio[0],2,fich);
		fputc('/',fich);
		escribir_int_fich(m_viajes[i].Fecha_inicio[1],2,fich);
		fputc('/',fich);
		escribir_int_fich(m_viajes[i].Fecha_inicio[2],4,fich);
		fputc('-',fich);

		escribir_int_fich(m_viajes[i].Hora_inicio[0],2,fich);
		fputc(':',fich);
		escribir_int_fich(m_viajes[i].Hora_inicio[1],2,fich);
		fputc('-',fich);

		escribir_int_fich(m_viajes[i].Hora_final[0],2,fich);
		fputc(':',fich);
		escribir_int_fich(m_viajes[i].Hora_final[1],2,fich);
		fputc('-',fich);

		if(m_viajes[i].ida_vuelta==0) fprintf(fich,"vuelta");
		else fprintf(fich,"ida");
		fputc('-',fich);

		escribir_int_fich(m_viajes[i].precio,1,fich);
		fprintf(fich,"�-");

		switch (m_viajes[i].estado)
		{
            case 0:
            	fprintf(fich,"abierto");
                break;
            case 1:
            	fprintf(fich,"cerrado");
                break;
            case 2:
            	fprintf(fich,"finalizado");
                break;
            case 3:
            	fprintf(fich,"cancelado");
                break;
            case 4:
            	fprintf(fich,"iniciado");
                break;
        }

		if(i!=l_viajes-1) fputc('\n',fich);
	}
	fclose (fich);
}
}

void guardar_fich_pasos()
{
	FILE *fich;
	int i,j;
if ((fich = fopen("Pasos.txt", "w")) == NULL) {
 printf("No se ha podido guardar Pasos.txt.\n");
}
else
{
	for(i=0;i<l_pasos;i++)
	{
		escribir_int_fich(m_pasos[i].id_viaje,6,fich);
		fprintf(fich,"-%s",m_pasos[i].poblacion);
		if(i!=l_pasos-1) fputc('\n',fich);
	}
	fclose (fich);
}
}

void guardar_fich_incidencias()
{
	FILE *fich;
	int i,j;
if ((fich = fopen("Incidencias.txt", "w")) == NULL) {
 printf("No se ha podido guardar Incidencias.txt.\n");
}
else
{
	for(i=0;i<l_incidencias;i++)
	{
		escribir_int_fich(m_incidencias[i].id_viaje,6,fich);
		fputc('-',fich);
		escribir_int_fich(m_incidencias[i].id_us_registra,4,fich);
		fputc('-',fich);
		escribir_int_fich(m_incidencias[i].id_us_incidencia,4,fich);
		fprintf(fich,"-%s-",m_incidencias[i].desc_incidencia);
		switch (m_incidencias[i].est_incidencia)
		{
            case 0:
            	fprintf(fich,"Abierta");
                break;
            case 1:
            	fprintf(fich,"Validada");
                break;
            case 2:
            	fprintf(fich,"Cerrada");
                break;
        }

		if(i!=l_incidencias-1) fputc('\n',fich);
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

				(*m_viajes)[i].id_usuario=-1;
				j=0;
				while(j<l_vehiculos && (*m_viajes)[i].id_usuario==-1)
				{
				if(strcmp(m_vehiculos[j].matricula,(*m_viajes)[i].matricula)==0) (*m_viajes)[i].id_usuario=j;
				j++;
				}
	
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
                (*m_pasos)[i].id_viaje=leer_int_fich(6,fich);
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
