#ifndef _USUARIOS_
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#endif // _USUARIOS_

void modificar_usuario(int);
int tipo_usuario,usuario_actual;               //Muestra el tipo de usuario que es. 1=usuario, 2=admin.
void login();                   //Procedimiento que Mostrara pantalla de login y comprobara tipo usuario.
int check_user(char *, char *,int *); //Funcion que comprobara si el usuario existe.
int mostrar_menu_usuario();     //Funcion que mostrara el menu de usuario, y devuelve entero con la elección.
int mostrar_menu_admin();       //Idem.
int registrar_usuario(usuarios **,int *);
void mostrar_lista_usuarios(usuarios *,int *);
void mostrar_datos_usuario(usuarios *,int *);
int buscar_usuario_id(int);
int buscar_usuario_user(char *);
