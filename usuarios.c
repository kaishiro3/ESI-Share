#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
        
    int id_Usuario;
    char nombre[20]; 
    char poblacion[20];
    int perfil; //si es admin o usuario normal Usuario=0
    int plazas;
    char user[5]; 
    char password[8];
    int estado; //activo=1 o bloqueado=0
    
}usuarios;

int resp;

void login();                   //Procedimiento que Mostrara pantalla de login y comprobara que existe.
int check_user(char *, char *); //Funcion que comprobara si el usuario existe y devolvera entero.
int mostrar();                  //Funcion que mostrara el menu de usuario, y devuelve entero con la elección.
void modificar_usuario(usuarios *,int,int,usuarios);


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

int check_user(char *user, char *password){
int i;
        for(i=0;i<longitud;i++)
        {
                if(strcmp(m_usuarios[i].user,user ==0 && strcmp(m_usuarios[i].password,password)==0)
                   return i;
        }
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

void modificar_usuario(usuarios *m_usuarios,int lon,int indice,usuarios modif)
{
    m_usuarios[indice]=modif;
}
