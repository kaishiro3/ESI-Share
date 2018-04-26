#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include"viajes.h"

void mostrar_lista_viajes(int mod)
{
	int id;
	for(id=0;id<l_viajes;id++)
	{
		if(mod==1){
			printf("\n\tIdentificador de usuario %i\n",m_viajes[id].id_usuario);		
		}
		printf("Identificacion %i:\n",id);
		mostrar_pasos(m_viajes[id].id_viaje);
		printf("Matricula: %s\n",m_viajes[id].matricula);
		printf("Fecha de inicio: %i\n",m_viajes[id].Fecha_inicio);
		printf("Hora de inicio: %i \n",m_viajes[id].Hora_inicio);
		printf("Hora de llegada: %i \n",m_viajes[id].Hora_final);
		printf("Plazas libres: %i \n",m_viajes[id].Plazas_libres);
		if(m_viajes[id].ida_vuelta==0) printf("Viaje de vuelta \n");
		else{
			printf("Viaje de ida \n");
		}
		printf("Precio: %i \n", m_viajes[id].precio);
		switch (m_viajes[id].estado)
		{
			case 0:
				printf("Abierto\n");
				break;
			case 1:
				printf("Cerrado\n");
				break;
			case 2:
				printf("Finalizado\n");
				break;
			case 3:
				printf("Cancelado\n");
				break;
			case 4:
				printf("Iniciado\n");
				break;
		}	
	}
}

static void mostrar_pasos(int id)
{
	
	int cursor=0;
	printf("Pasos: ")
	for(cursor=0,cursor<l_pasos,cursor++){
		
		if(m_pasos[cursor].id_viaje == id) 
		printf("%s",m_pasos[cursor].poblacion);
	}
}

void menu_usuario_viajes(int id, int lon, viajes **m_viajes)
{
	int caso=0
	int id_v=00;
	int encontrado=0
	
	printf("\nQue desea hacer:\n1-mostrar viajes\n2-crear viaje\n3-entrar a un viaje\n4-editar un viaje suyo\n5-mostrar sus viajes");
	scanf("%i",&caso);
	switch (caso){
		case 1:
			mostrar_lista_viajes(0);
			break;
		case 2:
			crear_viaje(**m_viajes, l_viajes);
			break;
		case 3:
			
			printf("indique la id del viaje");
			scanf("%i",&id_v);
			for (counter=0,counter<=lon,counter++){
				if(id_v==m_viajes[counter].id_viaje);
				encontrado=1;
				break;
			}
			if(encontrado==0)printf("viaje no encontrado");
			else{			
				add_viajero(**m_viajes, id_v,id);
			}
			break;
		case 4:
			printf("indique la id del viaje");
			scanf("%i",&id_v);
			for (counter=0,counter<=lon,counter++){
				if(id_v==m_viajes[counter].id_viaje){
				encontrado=1;
				break;
				}
			}
			if(encontrado==0)printf("viaje no encontrado");
			else{		
				if(m_viajes[counter].id_usuario==id)	
				editar_viaje(**m_viajes, *lon, id_v);
				encontrado=0;
				else{
					printf("Este viaje no es suyo");
				}
			}
		case 5:
			for (counter=0,counter<=lon,counter++){
				if(id==m_viajes[counter].id_usuario){
							id_v==m_viajes[counter].id_viaje;
				
							printf("Identificacion %i:\n",id_v);
							mostrar_pasos(m_viajes[id_v].id_viaje);
							printf("Matricula: %s\n",m_viajes[id_v].matricula);
							printf("Fecha de inicio: %i\n",m_viajes[id_v].Fecha_inicio);
							printf("Hora de inicio: %i \n",m_viajes[id_V].Hora_inicio);
							printf("Hora de llegada: %i \n",m_viajes[id_v].Hora_final);
							printf("Plazas libres: %i \n",m_viajes[id_v].Plazas_libres);
							if(m_viajes[id].ida_vuelta==0) printf("Viaje de vuelta \n");
							else{
								printf("Viaje de ida \n");
							}
							printf("Precio: %i \n", m_viajes[id_v].precio);
							switch (m_viajes[id_v].estado)
							{
								case 0:
									printf("Abierto\n");
									break;
								case 1:
									printf("Cerrado\n");
									break;
								case 2:
									printf("Finalizado\n");
									break;
								case 3:
									printf("Cancelado\n");
									break;
								case 4:
									printf("Iniciado\n");
									break;
							}	
						}
			}
			break;

	}		
}

void crear_viaje(viajes **m_viajes,int *lon,int id)
{
	viajes x;
	int i,aux;

	*lon=*lon+1;
	if(((*m_viajes) = (viajes *)realloc((*m_viajes),(*lon)*sizeof(viajes)))==NULL) puts("No hay espacio suficiente");
	else
	{
		
		system("cls");
		printf("\n\t Crear un Viaje\n\n");
		printf("\nMatricula del vehiculo: ");
		fflush(stdin);
		fgets(x.matricula,8,stdin);
		fflush(stdin);
		printf("\nFecha de inicio:");
		scanf("%i",&x.Fecha_inicio);
		printf("\nHora de inicio:");
		scanf("%i",&x.Hora_inicio);
		printf("\nHora de llegada aproximada:");
		scanf("%i",&x.Hora_final);
		printf("\nPlazas libres:");
		scanf("%i",&x.Plazas_libres);
		printf("\nPrecio:");
		scanf("%i",&x.precio);
		printf("\nIda - 1\nVuelta - 0");
		scanf("%i",&x.ida_vuelta);
		x.estado=0;
		x.id_usuario=obtener_usuario_mat();
		**m_viajes[*lon]=x;
		
	}
}

static void borrar_viaje (viajes **m_viajes,int *l,int indice)
{
    int i;
    for(i=indice;i<*l;i++){
        (*m_viajes)[i]=(*m_viajes)[i+1]; 
    }
    *l=*l--;
    if(((*m_viajes)=(viajes *)realloc((*m_viajes),*l*sizeof(viajes)))==NULL) puts("Error al eliminar el viaje");
}

void add_viajero (viajes **m_viajes, int id_viaje, int lon)
{
	
	
	int i=0;
	for(i=0,i<lon,i++){
		if(*m_viajes[i].id_viaje=id&&m_viajes[i].Plazas_libres>0) {
		m_viajes[i].Plazas_libres= m_viajes[i].Plazas_libres-1;
		if(m_viajes[i].Plazas_libres=0) m_viajes[i].estado=2;
		}
		else{printf("\nerror al añadir usuario\n");
		}
	}
	
}

void editar_viaje(viajes **m_viajes,int *lon, int id)
{
	int i=0;
	char answer = 'n';
	do{
	printf("\n\tQue desea cambiar?:\n");
	printf("\n1-Matricula\n2-Fecha de Inicio\n3-Hora de Inicio\n4-Hora de llegada\n5-Plazas\n6-Precio\n7-Cancelar viaje\n");
	scanf("%i",&i);
	
	switch (i){
		
		case 1:
			printf("Introduzca la matricula");
			fflush(stdin);
			fgets(m_viajes[id].matricula,8,stdin);
			fflush(stdin);
			break;
		case 2:
			printf("\nFecha de inicio:");
			scanf("%i",&m_viajes[id].Fecha_inicio);
			break;
		case 3:
			printf("\nHora de Inicio");
			scanf("%i",&m_viajes[jd].Hora_inicio);
			break;
		case 4:
			printf("\nHora de Llegada");
			scanf("%i",&m_viajes[id].Hora_final);
			break;
		case 5:
			printf("\nPlazas");
			scanf("%i",&m_viajes[id].Plazas_libres);
			break;
		case 6:
			printf("\nPrecio:");
			scanf("%i",&m_viajes[id].precio);
			break;
		case 7:
			*m_viajes[id].estado=3;
			break;
		}
		
		printf("Desea cambiar algo más del viaje? \nSi - s       \nNo - cualquier otra tecla");
		scanf("%c",)
				
	}while(answer=='s');
		
	
	
}

void menu_admin_viajes(int id, int lon, viajes **m_viajes)
{
	int caso=0
	int id_v=00;
	int encontrado=0
	
	printf("\nQue desea hacer:\n1-mostrar viajes\n2-crear viaje\n3-entrar a un viaje\n4-editar un viaje\n5-mostrar sus viajes");
	scanf("%i",&caso);
	switch (caso){
		case 1:
			mostrar_lista_viajes(1);
			break;
		case 2:
			crear_viaje(**m_viajes, l_viajes);
			break;
		case 3:
			
			printf("indique la id del viaje");
			scanf("%i",&id_v);
			for (counter=0,counter<=lon,counter++){
				if(id_v==m_viajes[counter].id_viaje);
				encontrado=1;
				break;
			}
			if(encontrado==0)printf("viaje no encontrado");
			else{			
				add_viajero(**m_viajes, id_v,id);
			}
			break;
		case 4:
			printf("indique la id del viaje");
			scanf("%i",&id_v);
			for (counter=0,counter<=lon,counter++){
				if(id_v==m_viajes[counter].id_viaje){
				encontrado=1;
				break;
				}
			}
			if(encontrado==0)printf("viaje no encontrado");
			else{	
				editar_viaje(**m_viajes, *lon, id_v);
				encontrado=0;

				}
			
		case 5:
			for (counter=0,counter<=lon,counter++){
				if(id==m_viajes[counter].id_usuario){
							id_v==m_viajes[counter].id_viaje;
				
							printf("Identificacion %i:\n",id_v);
							mostrar_pasos(m_viajes[id_v].id_viaje);
							printf("Matricula: %s\n",m_viajes[id_v].matricula);
							printf("Fecha de inicio: %i\n",m_viajes[id_v].Fecha_inicio);
							printf("Hora de inicio: %i \n",m_viajes[id_V].Hora_inicio);
							printf("Hora de llegada: %i \n",m_viajes[id_v].Hora_final);
							printf("Plazas libres: %i \n",m_viajes[id_v].Plazas_libres);
							if(m_viajes[id].ida_vuelta==0) printf("Viaje de vuelta \n");
							else{
								printf("Viaje de ida \n");
							}
							printf("Precio: %i \n", m_viajes[id_v].precio);
							switch (m_viajes[id_v].estado)
							{
								case 0:
									printf("Abierto\n");
									break;
								case 1:
									printf("Cerrado\n");
									break;
								case 2:
									printf("Finalizado\n");
									break;
								case 3:
									printf("Cancelado\n");
									break;
								case 4:
									printf("Iniciado\n");
									break;
							}	
						}
			}
			break;
			        
			  }

	}	
