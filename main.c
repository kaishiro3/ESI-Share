
#include"ficheros.c"
#include"vehiculos.c"
#include"usuarios.c"
#include"viajes.c"
#include"incidencias.c"

main(){
	int n,i,id,oper;
	n=0;
    cargar_ficheros();
	mostrar_lista_usuarios(m_usuarios,&l_usuarios); //Para comprobar usuarios y funcionamiento. TESTING
    login();
    switch (tipo_usuario){
    case 0:
    do{
        resp=mostrar_menu_usuario();
        switch (resp){
            case 1:         //Perfil
                mostrar_datos_usuario(m_usuarios,&usuario_actual);
                r=0;
                do{
                    puts("1. Editar");
                    puts("2. Volver");
                    scanf("%d",&r);
                }while(r!=1 && r!=2);
                /*if(r==1){             //Editar datos usuario.

                }*/
                break;
            case 2:         //Vehiculos
                mostrar_vehiculos_de_usuario(m_usuarios[usuario_actual].id_Usuario);

                break;
            case 3:         //Viajes
                r=0;
                break;
            case 4:         //Incidencias
                r=0;
                break;
        }
    } while (resp!=5);
    puts("Hasta luego");
    exit(0);
    //break;
    case 1:
    do{
    resp=mostrar_menu_admin();
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
                    if(r==4) mostrar_lista_usuarios(m_usuarios,&l_usuarios);

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
    puts("Hasta luego");
    exit(0);
    //break;
    }
		do
		{
			printf("ID de Usuario: ");
			scanf("%i",&id);
		}while(id<1);
		for(i=0;i<l_usuarios;i++)
		{
			//if(m_usuarios[i].id_Usuario==id)
			printf("%s ",m_usuarios[i].nombre);
		}
		oper=mostrar_vehiculos_de_usuario(id);
		if(oper!=-1)
		{
			if(oper=-2)
			{
				agregar_vehiculo(&m_vehiculos,&l_vehiculos,id);
			}
		}
	guardar_fich_vehiculos(m_vehiculos,l_vehiculos);
}
