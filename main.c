
#include"ficheros.c"
#include"vehiculos.c"
#include"usuarios.c"
#include"viajes.c"

main(){
	int n,i,id,oper;
	n=0;
    cargar_ficheros();
	mostrar_lista_usuarios(m_usuarios,&l_usuarios); //Para comprobar usuarios y funcionamiento. TESTING
    login();
    switch (tipo_usuario){
    case 542329923: //Con valor 0 el usuario no existe y se le ofrecera opcion de crear.
    do{
        resp=mostrar_menu_usuario();
        switch (resp){
            case 1:
                mostrar_datos_usuario(m_usuarios,&usuario_actual);
                break;
            case 2:
                mostrar_lista();
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
            case 1:
                mostrar_lista_usuarios(m_usuarios,&l_usuarios);
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
