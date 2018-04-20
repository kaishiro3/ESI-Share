#include "usuarios.h"

int resp;

void modificar_usuario(usuarios *,int,int,usuarios);

void login(){                   //Funcion que comprueba en usuarios.txt usuario y contraseña
int r;
char usuario[15];
char pass[15];
	puts("\n\t Inicio de sesion.");
    puts("Introduce usuario");
    scanf("%s",&usuario);
    puts("Introduce contraseña");
    scanf("%s",&pass);
usuario_actual=check_user(usuario,pass,&l_usuarios); //Comprueba si existe usuario y devuelve un entero con el indice de los datos del usuario o -1 si no existe.
if (usuario_actual==-1) {
do{
    system("cls");
    r=0;
    puts("No existe usuario.");
    puts("1. Intentar de nuevo.");
    puts("2. Registrarse");
    scanf("%d",&r);
}while(r<1 || r>2);
if (r==1){
 do{   puts("Introduce usuario");
    scanf("%s",&usuario);
    puts("Introduce contraseña");
    scanf("%s",&pass);
    usuario_actual=check_user(usuario,pass,&l_usuarios);
}while(usuario_actual==-1);
}
if(r==2){
    registrar_usuario();
}
}
}

int check_user(char *usu,char *pass, int * lon){
int i;
        for(i=0;i<*lon;i++)
        {
                if(strcmp(m_usuarios[i].user,usu)==0 && strcmp(m_usuarios[i].password,pass)==0){
                    tipo_usuario=m_usuarios[i].perfil;
                    if(m_usuarios[i].estado==0) {
                            puts("El usuario esta bloqueado. Contacte con el administrador.");
                            system("pause");
                            exit(0);
                    }else return i;
                }
        }
return -1;
}

int mostrar_menu_usuario(){
    do{
        puts("1. Perfil");
        puts("2. Vehiculos");
        puts("3. Viajes");
        puts("4. Incidencias");
        scanf("%i",&resp);
    } while (resp<=0 || resp>=6);

    return resp;
}
int mostrar_menu_admin(){
    do{
        puts("1. Usuarios");
        puts("2. Vehiculos");
        puts("3. Viajes");
        puts("4. Incidencias");
        scanf("%i",&resp);
    } while (resp<=0 || resp>=6);

    return resp;
}

void modificar_usuario(usuarios *m_usuarios,int lon,int indice,usuarios modif)
{
    m_usuarios[indice]=modif;
}

void mostrar_lista_usuarios(usuarios *m_usuarios,int *lon){
int i;

for(i=0;i<*lon;i++){
    printf("Id: %d \n Nombre: %s \n Poblacion: %s \n Perfil: %d \n Usuario: %s \n Contraseña: %s \n Estado: %d\n",m_usuarios[i].id_Usuario,m_usuarios[i].nombre,m_usuarios[i].poblacion,m_usuarios[i].perfil,m_usuarios[i].user,m_usuarios[i].password,m_usuarios[i].estado);
}
}

void mostrar_datos_usuario(usuarios *m_usuarios,int *indice){
printf("Id: %d \n Nombre: %s \n Poblacion: %s \n Perfil: %d \n Usuario: %s \n Contraseña: %s \n Estado: %d \n",m_usuarios[*indice].id_Usuario,m_usuarios[*indice].nombre,m_usuarios[*indice].poblacion,m_usuarios[*indice].perfil,m_usuarios[*indice].user,m_usuarios[*indice].password,m_usuarios[*indice].estado);
}


//Arreglar comprobacion tamaño cadena.
void registrar_usuario(){
int len;
char *nombre;
char *poblacion;
char *usuario;
char *password;
puts("Introduce nombre:");
fflush(stdin);
fgets(nombre,20,stdin);
len=strlen(nombre);
if(len>20){
    do{
        puts("Introduce como maximo 20 caracteres");
        fflush(stdin);
        fgets(nombre,20,stdin);
    } while(len>20);
}
puts("Introduce poblacion");
fflush(stdin);
fgets(poblacion,20,stdin);
if(strlen(poblacion)>20){
    do{
        puts("Introduce como maximo 20 caracteres");
        fflush(stdin);
        fgets(poblacion,20,stdin);
    } while(strlen(poblacion)>20);
}
puts("Introduce usuario");
fflush(stdin);
fgets(usuario,5,stdin);
if((strlen(usuario))>5){
    do{
        puts("Introduce como maximo 5 caracteres");
        fflush(stdin);
        fgets(usuario,5,stdin);
    } while((strlen(usuario))>5);
}
puts("Introduce contraseña");
fflush(stdin);
fgets(password,8,stdin);
if(strlen(password)>8){
    do{
        puts("Introduce como maximo 8 caracteres");
        fflush(stdin);
        fgets(password,8,stdin);
    } while(strlen(password)>8);
}
printf("Nombre: %s Poblacion: %s Usuario: %s Contraseña: %s",nombre,poblacion,usuario,password);
system("pause");
}
