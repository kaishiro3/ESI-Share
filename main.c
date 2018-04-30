#include"ficheros.c"
#include"usuarios.c"
#include"vehiculos.c"
#include"viajes.c"
#include"incidencias.c"

void main(){
	int n,i,id,oper,r,comp,aux; //comp=comprobacion de alta de usuario.;
	n=0;
    cargar_ficheros();
	//mostrar_lista_usuarios(m_usuarios,&l_usuarios); //Para comprobar usuarios y funcionamiento. TESTING
    login();
    switch (tipo_usuario){
    case 0:
    do{
        resp=mostrar_menu_usuario();
        system("cls");
        switch (resp){
            case 1:         //Perfil
                mostrar_datos_usuario(m_usuarios,&usuario_actual);
                r=0;
                do{
                    puts("1. Editar");
                    puts("2. Volver");
                    scanf("%d",&r);
                }while(r!=1 && r!=2);
                if(r==1){             //Editar datos usuario.
                    modificar_usuario(usuario_actual);
                }
                break;
            case 2:         //Vehiculos
            	printf("este es: %i",m_usuarios[usuario_actual].id_Usuario);
                menu_usuario_vehiculos(m_usuarios[usuario_actual].id_Usuario);

                break;
            case 3:         //Viajes
                r=0;
                break;
            case 4:         //Incidencias
                r=0;
                break;
        }
    } while (resp!=5);
    guardar_ficheros();
    puts("Hasta luego");
    exit(0);
    //break;
    case 1:
    do{
    resp=mostrar_menu_admin();
    system("cls");
        switch (resp){
            case 1:             //Usuarios
                r=0;
                do{
                    puts("1. Dar de alta");
                    puts("2. Dar de baja");
                    puts("3. Modificar");
                    puts("4. Listar usuarios");
                    puts("5. Volver");
                    scanf("%d",&r);
                } while(r<=0 || r>=6);
                    if(r==1){
                        comp=registrar_usuario(&m_usuarios,&l_usuarios);
                        if(comp==-1) puts("El usuario no se ha podido dar de alta");
                        else {
                            puts("Usuario creado con exito");
                            guardar_fich_usuarios();
                        }
                        system("pause");
                    }
                    if(r==3){
                        mostrar_lista_usuarios(m_usuarios,&l_usuarios);
                        puts("Seleccione id del usuario");
                        scanf("%i",&aux);
                        modificar_usuario_admin(aux-1);
                        system("pause");
                    }
                    if(r==4) {
                        mostrar_lista_usuarios(m_usuarios,&l_usuarios);
                        system("pause");
                    }
                break;
            case 2:             //Vehiculos
                    menu_admin_vehiculos(m_usuarios[usuario_actual].id_Usuario);
                break;
            case 3:             //Viajes

                break;
            case 4:             //Incidencias

                break;
        }
    }while(resp!=5);
    guardar_ficheros();
    system("cls");
    puts("Hasta luego");
    exit(0);
    //break;
    }
}
