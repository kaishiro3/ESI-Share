#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include"vehiculos.h"

void mostrar_lista_vehiculos()
{
	int i;
	//Bucle que imprime por pantalla cada uno de los atributos de los elementos de m_vehiculos
	for(i=0;i<l_vehiculos;i++)
	{
		printf("elemento %i:\n",i);
		printf("Matricula: %s\n",m_vehiculos[i].matricula);
		printf("ID de Usuario: %i\n",m_vehiculos[i].id_Usuario);
		printf("Plazas: %i\n",m_vehiculos[i].plazas);
		printf("%s\n",m_vehiculos[i].definicion);

	}
}

void menu_usuario_vehiculos(int id_Usuario)
{
	int i,j,cursor,cursor2;
	char aux;
	do{
		i=j=0;
		system("cls");
		printf("\n\t Mis Vehiculos\n\n"); //Titulo del menú
		//Bucle que busca el primer vehiculo de id_Usuario
		while(i<l_vehiculos && m_vehiculos[i].id_Usuario!=id_Usuario) i++;
		//Bucle que imprime en pantalla la definicion de cada uno de los vehiculos de id_Usuario
		while(i<l_vehiculos && m_vehiculos[i].id_Usuario==id_Usuario)
			{
			j++;
			printf("%i.- %s\n",j,m_vehiculos[i].definicion);
			i++;
		}
		//Si no se entra en ninguno de los bucles, quiere decir que no se encontro ningun vehiculo, por lo que j=0
		if(j==0) puts("No tiene ningun vehiculo disponible");
		//Resto de opciones del menu
		printf("\n%i.- A%cadir\n%i.- Volver\n\n",j+1,164,j+2);
		do
		{
				printf("Introduzca operacion: ");
				scanf("%i",&cursor);
		}while(cursor<1 || cursor>j+2); //Bucle que verifica que el usuario ha seleccionado una opcion valida

		if(cursor==j+1) agregar_vehiculo(&m_vehiculos,&l_vehiculos,id_Usuario); //El usuario selecciona agregar
		else
		{
			if(cursor==j+2) cursor=-1; //Si el usuario selecciona Volver el cursor se reemplaza con -1
			else
			{
				//En otro caso el usuario habra seleccionado uno de sus vehiculos por lo que
				//se reemplaza el cursor con la posicion del vehiculo seleccionado en el array
				cursor=i-j+cursor-1;
				do
				{
					do
					{
						system("cls");
						printf("\n\t %s\n\n",m_vehiculos[cursor].matricula); //Titulo del submenu del vehiculo seleccionado
						//Se imprime las opciones del submenu
						printf("\n1.- Definicion: %s\n2.- Plazas: %i\n3.- Borrar\n4.- Volver\n\n",m_vehiculos[cursor].definicion,m_vehiculos[cursor].plazas);
						printf("Introduzca operacion: ");
						scanf("%i",&cursor2);
					}while(cursor2<0 || cursor2>4);	//Bucle que verifica que el usuario ha seleccionado una opcion valida
				
				switch (cursor2)
				{
            	case 1: 			//Modificar la Definicion
					system("cls");
					printf("Nueva Definicion: ");
					fflush(stdin);
					fgets(m_vehiculos[cursor].definicion,51,stdin);
					fix_string(m_vehiculos[cursor].definicion,51);
					fflush(stdin);
            	    break;
            	case 2:             //Modificar el numero de Plazas
            	    system("cls");
					do
					{
						printf("Nuevo Numero de plazas: ");
						scanf("%i",&aux);
					}while(aux<2 || aux>8); //Bucle que verifica que el numero de plazas este entre 2 y 8
					m_vehiculos[cursor].plazas=aux;
            	    break;
            	case 3:				//Borrar el vehiculo
					borrar_vehiculo(&m_vehiculos,&l_vehiculos,cursor);
            	    break;
            		}
				}while(cursor2!=4 && cursor2!=3); //Sale del bucle si el usuario ha seleccionada volver o borrar
			}
		}
	}while(cursor!=-1);//Sale del bucle si el usuario ha seleccionada volver
}

void agregar_vehiculo(vehiculos **m_vehiculos,int *lon,int id)
{
	vehiculos x;
	int i,aux;

	*lon=*lon+1;
	//Redistribucion de la memoria de m_vehiculos
	if(((*m_vehiculos)=(vehiculos *)realloc((*m_vehiculos),(*lon)*sizeof(vehiculos)))==NULL) puts("No hay espacio suficiente");
	else
	{
		system("cls");
		//Formulario para que el usuario agre su nuevo vehiculo
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
		}while(aux<2 || aux>8);//Bucle que verifica que el numero de plazas este entre 2 y 8
		x.plazas=aux;
		fflush(stdin);
		printf("Definicion: ");
		fflush(stdin);
		fgets(x.definicion,51,stdin);
		fflush(stdin);
		fix_string(x.definicion,51);
		i=0;
		//Bucle que busca el primer vehiculo de id_Usuario
		while(i<*lon-1 && (*m_vehiculos)[i].id_Usuario!=id) i++; 
		//Bucle que devuelve en i la posicion que tendra el nuevo vehiculo, la cual sera la siguiente al ultimo vehiculo de id_Usuario
		while(i<*lon-1 && (*m_vehiculos)[i].id_Usuario==id) i++; 
		aux=*lon-1;
		while(aux>i)
		{
			(*m_vehiculos)[aux]=(*m_vehiculos)[aux-1]; //reemplaza un vehiculo con el anterior en el array dejando espacio para el nuevo vehiculo
			aux--;
		}
		(*m_vehiculos)[i]=x;
	}


}

void borrar_vehiculo(vehiculos **m_vehiculos,int *lon,int indice)
{
    int i;

    for(i=indice;i<*lon;i++)
    {
        (*m_vehiculos)[i]=(*m_vehiculos)[i+1]; //reemplaza una estructura con la siguiente en el array dejando fuera (*m_vehiculos)[indice]
    }
    *lon=*lon-1;
    //Redistribucion de la memoria de m_vehiculos
    if(((*m_vehiculos)=(vehiculos *)realloc((*m_vehiculos),*lon*sizeof(vehiculos)))==NULL) puts("Error al borrar vehiculos");
}

int buscar_vehiculo(char *matricula)
{
	int i;
	for(i=0;i<l_vehiculos;i++) //Bucle que busca el vehiculo al que le corresponda la matricula
	{
		if(strcmp(m_vehiculos[i].matricula,matricula)==0)
		return i;
	}
	return -1; //Si no se encuentra, se devuelve -1
}

void menu_admin_vehiculos(int id_Usuario)
{
	int i,cursor,cursor2,aux;
	
	do
	{
		system("cls");
		printf("\n\t Lista de Vehiculos\n\n"); //Titulo del menú
		for(i=0;i<l_vehiculos;i++) //Bucle que imprime los vehiculos con un id de usuario valido en m_vehiculos
		{
			aux=buscar_usuario_id(m_vehiculos[i].id_Usuario);
			if(aux!=-1) printf("%i.- %s de %s\n",i+1,m_vehiculos[i].definicion,m_usuarios[aux].user);
		}
		//Resto de opciones del menu
		printf("\n%i.- A%cadir\n%i.- Salir\n\n",i+1,164,i+2);
		do
			{
				printf("Introduzca operacion: ");
				scanf("%i",&cursor);
			}while(cursor<1 || cursor>i+2);  //Bucle que verifica que el usuario ha seleccionado una opcion valida

		if(cursor==i+1) agregar_vehiculo(&m_vehiculos,&l_vehiculos,id_Usuario); //El usuario selecciona agregar
		else
		{
			if(cursor==i+2) cursor=-1; //Si el usuario selecciona Volver el cursor se reemplaza con -1
			else
			{
				//En otro caso el usuario habra seleccionado uno de sus vehiculos por lo que
				//se reemplaza el cursor con la posicion del vehiculo seleccionado en el array
				cursor--;
				do
				{
					do
					{
						system("cls");
						printf("\n\t %s\n",m_vehiculos[cursor].matricula); //Titulo del submenu del vehiculo seleccionado
						//Se imprime las opciones del submenu
						printf("\n1.- Definicion: %s\n2.- Plazas: %i\n3.- Lista de Viajes\n4.- Borrar\n5.- Volver\n\n",m_vehiculos[cursor].definicion,m_vehiculos[cursor].plazas);
						printf("Introduzca operacion: ");
						scanf("%i",&cursor2);
					}while(cursor2<0 || cursor2>5);	//Bucle que verifica que el usuario ha seleccionado una opcion valida
				
				switch (cursor2)
				{
            	case 1: 			//Modificar la Definicion
					system("cls");
					printf("Nueva Definicion: ");
					fflush(stdin);
					fgets(m_vehiculos[cursor].definicion,51,stdin);
					fix_string(m_vehiculos[cursor].definicion,51);
					fflush(stdin);
            	    break;
            	case 2:             //Modificar el Numero de Plazas
            	    system("cls");
					do
					{
						printf("Nuevo Numero de plazas: ");
						scanf("%i",&aux);
					}while(aux<2 || aux>8); //Bucle que verifica que el numero de plazas este entre 2 y 8
					m_vehiculos[cursor].plazas=aux;
            	    break;
            	case 3: 			//Lista de Viajes realizados con el vehiculo
            		mostrar_viajes_por_vehiculo(m_vehiculos[cursor].matricula);
            		break;
            	case 4:				//Borrar el vehiculo
					borrar_vehiculo(&m_vehiculos,&l_vehiculos,cursor);
            	    break;
            		}
				}while(cursor2!=4 && cursor2!=3 && cursor2!=5); //Sale del bucle si el usuario ha seleccionada volver, borrar o mostrar la lista de viajes
			}
		}
		
	}while(cursor!=-1); //Sale del bucle si el usuario ha seleccionada volver
}

mostrar_viajes_por_vehiculo(char *matricula)
{
	int i,j;
	system("cls");
	printf("\n\t Viajes de %s\n\n",matricula); //Titulo del submenu
	for(i=0;i<l_viajes;i++) //Bucle que busca los viajes que ha realizado el vehiculo que le corresponde la variable matricula
	{
		if(strcmp(m_viajes[i].matricula,matricula)==0) //Se imprime los atributos de un viaje si matricula coincide con la del viaje
  		{
   			if(m_viajes[i].ida_vuelta==0) printf("vuelta");
   			else printf("ida");
   
  			printf("\n%i/%i/%i\t",m_viajes[i].Fecha_inicio[0],m_viajes[i].Fecha_inicio[1],m_viajes[i].Fecha_inicio[2]);
  			printf("de %i:%i hasta %i:%i\n",m_viajes[i].Hora_inicio[0],m_viajes[i].Hora_inicio[1],m_viajes[i].Hora_final[0],m_viajes[i].Hora_final[1]);
  			for(j=0;j<l_pasos;j++) //Bucle que imprime los lugares que les corresponda el id del viaje actual
  			{
  				if(m_viajes[i].id_viaje==m_pasos[j].id_viaje) printf("%s\n",m_pasos[j].poblacion);
			}
			printf("\n");
		}
	}
 	printf("Escriba un caracter para Volver: ");
 	scanf("%i",&j); //Para visualizar el menu actual se pide al usuario que introduzca cualquier caracter para volver al menu anterior
}
