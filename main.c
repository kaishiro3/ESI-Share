
#include"ficheros.c"
#include"vehiculos.c"
#include"usuarios.c"
#include"viajes.c"

main(){
	int n,i,id,oper;
	n=0;
    cargar_ficheros();
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
