#include <stdio.h>
#include <vehiculos.c>

/*Descripcion: Lee el fichero "Vehiculos.txt" y devuelve en m_vehiculos
cada uno de los elementos y en lon la cantidad de elementos*/
void cargar_fich_vehiculos(vehiculos **m_vehiculos,int *lon);

//Precondicion: m_vehiculos inicializado y en lon la longitud de vm_vehiculos
//Descripcion: Sobrescribe "Vehiculos.txt" con los datos de m_vehiculos
void guardar_fich_vehiculos(vehiculos *m_vehiculos,int lon);

//Precondicion: m_vehiculos inicializado y en lon la longitud de vm_vehiculos
//Descripcion: Imprime en pantalla cada uno de los datos de m_vehiculos
void mostrar_lista(vehiculos *m_vehiculos,int lon);

//Precondicion: m_vehiculos y id inicializados y en lon la longitud del m_vehiculos
/*Descripcion: Imprime en pantalla un menu con los vehiculos pertenecientes a id.
Devuelve el indice del vehiculo elegido en m_vehiculos, -2 si desea agregar un vehiculo y -1 si desea salir */
int mostrar_vehiculos_de_usuario(vehiculos *m_vehiculos,int lon,int id);

//Precondicion: m_vehiculos y id inicializados y en lon la longitud de m_vehiculos
/*Descripcion: Imprime en pantalla un formulario para agregar un nuevo vehiculos a m_vehiculos a id.
Devuelve m_vehiculos y lon actualizados*/
void agregar_vehiculo(vehiculos **m_vehiculos,int *lon,int id);

//Precondicion: m_vehiculos y matricula inicializados y en lon la longitud de m_vehiculos
/*Descripcion: Elimina de m_vehiculos el elemento al que le pertenezca el valor en matricula*/
void borrar_vehiculo(vehiculos **m_vehiculos,int *lon,char *matricula);

//Precondicion: m_vehiculos y modif inicializados, en lon la longitud de m_vehiculos e -1<indice<longitud
/*Descripcion: Reemplaza m_vehiculos[indice] con modif*/
void modificar_vehiculo(vehiculos *m_vehiculos,int lon,int indice,vehiculos modif);
