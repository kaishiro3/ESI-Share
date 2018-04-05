#include <stdio.h>

int menu_inciusu(){
 int resp=0;
 do{
    printf("1. Crear incidencia \n");
    printf("2. Consultar incidencia \n");
    printf("Introduce un numero para elegir una opcion: \n");
    scanf("%i", &resp);
 }while(resp<1 || resp>2);

return 0;
}
int menu_inciadmin(){
 int resp=0;
 do{
    printf("1. Crear incidencia \n");
    printf("2. Eliminar incidencia \n");
    printf("3. Modificar incidencia \n");
    printf("4. Listar incidencias \n");
    printf("5. Validar incidencias \n");
    printf("6. Bloquear usuarios \n");
    printf("Introduce un numero para elegir una opcion: \n");
    scanf("%i", &resp);
 }while(resp<1 || resp>6);

return 0;
}

