#ifndef _USUARIOS_
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#endif // _USUARIOS_

int tipo_usuario,usuario_actual;               //tipo de usuario 0=usuario, 1=admin.Usuario_actual=indice con datos del usuario.
void login();                   //Procedimiento que Mostrara pantalla de login y comprobara tipo usuario.
int check_user(char *, char *,int *); //Funcion que comprobara si el usuario existe.
int mostrar_menu_usuario();     //Funcion que mostrara el menu de usuario, y devuelve entero con la elección.
int mostrar_menu_admin();       //Idem.

