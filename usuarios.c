#include <stdio.h>

int resp;

void login();                   //Procedimiento que Mostrara pantalla de login y comprobara que existe.
int check_user(char *, char *); //Funcion que comprobara si el usuario existe y devolvera entero.
int mostrar();                  //Funcion que mostrara el menu de usuario, y devuelve entero con la elección.



void login(){                   //Funcion que comprueba en usuarios.txt usuario y contraseña
char user[15];
char password[15];
do{
    puts("Introduce usuario");
    scanf("%s",&user);
    puts("Introduce contraseña");
    scanf("%s",&password);
}while(check_user(user,password)!=0); //Corregir numero que devuelve check_user

}


int mostrar_menu_admin(){
    do{
        puts("1. Crear");
        puts("2. Buscar");
        puts("3. Comprobar");
        puts("4. ");
        scanf("%i",&resp);
    } while (resp<=0 && resp>=5);

    return resp;
}
