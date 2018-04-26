#include "usuarios.h"

int resp;

void login(){                   //Funcion que comprueba en usuarios.txt usuario y contraseña
int r;
char usuario[15];
char pass[15];

    puts("\n\t ESI-SHARE. BIENVENIDO\n");
    puts("Introduce usuario");
    scanf("%s",&usuario);
    puts("Introduce contraseña");
    scanf("%s",&pass);

    usuario_actual=check_user(usuario,pass,&l_usuarios); //Comprueba si existe usuario y devuelve un entero con el indice de los datos del usuario o -1 si no existe.

if (usuario_actual==-1) {
do{
    system("cls");
    r=0;
    puts("No existe usuario o la contraseña es incorrecta.");
    puts("1. Intentar de nuevo.");
    puts("2. Registrarse");
    scanf("%d",&r);
}while(r<1 || r>2);
if (r==1){
 do{
    system("cls");
    puts("Introduce usuario");
    scanf("%s",&usuario);
    puts("Introduce contraseña");
    scanf("%s",&pass);
    usuario_actual=check_user(usuario,pass,&l_usuarios);
}while(usuario_actual==-1);
}
if(r==2){
    system("cls");
    usuario_actual=registrar_usuario(&m_usuarios,&l_usuarios);
    if(usuario_actual==-1){
        puts("Error al registar usuario, contacte con el administrador");
        system("exit");
    }
    guardar_fich_usuarios();
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
        system("cls");
        puts("1. Perfil");
        puts("2. Vehiculos");
        puts("3. Viajes");
        puts("4. Incidencias");
        puts("5. Salir");
        scanf("%i",&resp);
    } while (resp<=0 || resp>=6);

    return resp;
}
int mostrar_menu_admin(){
    do{
        system("cls");
        puts("1. Usuarios");
        puts("2. Vehiculos");
        puts("3. Viajes");
        puts("4. Incidencias");
        puts("5. Salir");
        scanf("%i",&resp);
    } while (resp<=0 || resp>=6);

    return resp;
}

void modificar_usuario(int indice)
{
int r;
char nombre[21];
char poblacion[21];
char password[9];
do{
        system("cls");
        puts("¿Qué datos quiere modificar?");
        puts("1. Nombre.");
        puts("2. Poblacion");
        puts("3. Contraseña");
        puts("4. Volver");
        scanf("%i",&r);
}while(r<1 && r>4);
if(r==1){

    puts("Introduce nombre:");
    fflush(stdin);
    fgets(m_usuarios[indice].nombre,21,stdin);
    fix_string(m_usuarios[indice].nombre,21);
    //m_usuarios[indice].nombre=nombre;
}
if(r==2){

    puts("Introduce poblacion");
    fflush(stdin);
    fgets(m_usuarios[indice].poblacion,21,stdin);
    fix_string(m_usuarios[indice].poblacion,21);
    //m_usuarios[indice].poblacion=poblacion;
}
if(r==3){

    puts("Introduce contraseña");
    fflush(stdin);
    fgets(m_usuarios[indice].password,9,stdin);
    fix_string(m_usuarios[indice].password,9);
    //m_usuarios[indice].password=password;
}
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

int registrar_usuario(usuarios ** m_usuarios,int * lon){

usuarios u;
int len,aux=-1;
*lon=*lon+1;

            puts("Introduce nombre:");
            fflush(stdin);
            fgets(u.nombre,21,stdin);
            fix_string(u.nombre,21);
            puts("Introduce poblacion");
            fflush(stdin);
            fgets(u.poblacion,21,stdin);
            fix_string(u.poblacion,21);
            do{
            if(aux!=-1) puts("El usuario ya existe");
            puts("Introduce usuario");
            fflush(stdin);
            fgets(u.user,6,stdin);
            fix_string(u.user,21);
            aux=buscar_usuario_user(u.user);
            }while(aux!=-1);

            puts("Introduce contraseña");
            fflush(stdin);
            fgets(u.password,9,stdin);
            fix_string(u.password,21);
            u.estado=1;
            u.perfil=0;
            u.id_Usuario=*lon;

    if(((*m_usuarios)=(usuarios *)realloc((*m_usuarios),(*lon)*sizeof(usuarios)))==NULL)
        {
            puts("No hay espacio suficiente");
            return -1;
    }

        else{
            (*m_usuarios)[*lon-1]=u;
            return *lon-1;
            }
}
int buscar_usuario_user(char * user){
    int i;
    for(i=0;i<l_usuarios;i++)
	{
		if(strcmp(user,m_usuarios[i].user)==0)
		{
			return i;
		}
	}
	return -1;
}
int buscar_usuario_id(int id)
{
	int i;
	for(i=0;i<l_usuarios;i++)
	{
		if(m_usuarios[i].id_Usuario==id)
		{
			return i;
		}
	}
	return -1;
}

