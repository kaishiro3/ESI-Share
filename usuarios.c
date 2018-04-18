#include "usuarios.h"

int resp;

int mostrar_menu_usuario();     //Funcion que mostrara el menu de usuario, y devuelve entero con la elección.
int mostrar_menu_admin();       //Idem.
void modificar_usuario(usuarios *,int,int,usuarios);
void mostrar_lista_usuarios(usuarios *,int *);

/*int main(){

mostrar_lista_usuarios(&d_usuarios,&longitud);
//login;

switch (tipo_usuario){

    case 0:
    resp=mostrar_menu_usuario();
    break;
    case 1:
    resp=mostrar_menu_admin();
    break;

    }
switch (resp){  //Switch que comprobara la seleccion del menu y que comprueba tipo de usuario para diferenciar entre una seleccion y otra.
case 1:
    //if (tipo_usuario==1) mostrar_datos_usuarios; //Muestra datos de su perfil.
    //if (tipo_usuario==2) mostrar_lista_usuarios; //Muestra lista de todos usuarios.
    break;
case 2:

    break;
case 3:
    break;
case 4:
    break;
}

return 0;
}*/


void login(){                   //Funcion que comprueba en usuarios.txt usuario y contraseña

char usuario[15];
char pass[15];
    puts("Introduce usuario");
    scanf("%s",&usuario);
    puts("Introduce contraseña");
    scanf("%s",&pass);
usuario_actual=check_user(usuario,pass,&l_usuarios); //Comprueba si existe usuario y devuelve un entero con el indice de los datos del usuario o -1 si no existe.
if (tipo_usuario==-1) {
do{
    puts("No existe usuario. Intentelo de nuevo.");
    puts("Introduce usuario");
    scanf("%s",&usuario);
    puts("Introduce contraseña");
    scanf("%s",&pass);
    usuario_actual=check_user(usuario,pass,&l_usuarios);
}while(tipo_usuario==-1);
}
}

int check_user(char *usu,char *pass, int * lon){
int i;
        for(i=0;i<*lon;i++)
        {
                if(strcmp(m_usuarios[i].user,usu)==0 && strcmp(m_usuarios[i].password,pass)==0){
                tipo_usuario=m_usuarios[i].perfil;
                return i;
                }
        }
return -1;
}

int mostrar_menu_usuario(){
    do{
        puts("1.Perfil");
        puts("2. Vehiculos");
        puts("3. Viajes");
        puts("4. Incidencias");
        scanf("%i",&resp);
    } while (resp<=0 || resp>=5);

    return resp;
}
int mostrar_menu_admin(){
    do{
        puts("1. Usuarios");
        puts("2. Vehiculos");
        puts("3. Viajes");
        puts("4. Incidencias");
        scanf("%i",&resp);
    } while (resp<=0 || resp>=5);

    return resp;
}

void modificar_usuario(usuarios *m_usuarios,int lon,int indice,usuarios modif)
{
    m_usuarios[indice]=modif;
}

void mostrar_lista_usuarios(usuarios *m_usuarios,int *lon){
int i;

for(i=0;i<*lon;i++){
    printf("Id: %d \n Nombre: %s \n Poblacion: %s \n Perfil: %d \n Usuario: %s \n Contraseña: %s \n Estado: %d",m_usuarios[i].id_Usuario,m_usuarios[i].nombre,m_usuarios[i].poblacion,m_usuarios[i].perfil,m_usuarios[i].user,m_usuarios[i].password,m_usuarios[i].estado);
}
}
