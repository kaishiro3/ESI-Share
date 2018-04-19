

#ifndef _VIAJES_
#define _VIAJES_
#include <stdio.h>


 typedef char* localizacion[]; //el nombre del lugar al que ir
//Estructura de datos de viajes
 typedef struct {
        int id_viaje[6];
        char* matricula;
        int Fecha_inicio[3];
        int Hora_inicio[2];
        int Hora_final[2];
        int Plazas_libres;
        int ida_vuelta; //booleano de si es ida o vuelta
        int precio;
        int estado; //si es abierto, cerrado, finalizado, cancelado, iniciado;
        localizacion* pasos[]; //las localizaciones por las que pasa;
    }viajes ;

    int l_Viajes =1 ; // la cantidad de filas de la matriz, modificable. Es uno por ahora
    viajes* m_viajes;


#endif // _VIAJES_

/*Descripcion: lee el fichero "viajes.txt" y devuelve en m_viajes cada uno de los elementos
y en l_viajes la cantidad de elementos*/

    void cargar_fich_viajes(viajes **m_viajes, int* l_Viajes);
    //Precondicion: m_viajes inicializado y en l_viajes>1
    //Postcondicion: sobreescribe el actual m_viajes con el archivo en txt
    //en caso de no haber un archivo llamado "viajes.txt" lo creará con el actual m_viajes actualizado

    //Descripcion: Guarda un archivo "viajes.txt" con los datos especificados
    //en  m_viajes
    void guardar_fich_viajes(viajes **m_viajes, int* l_Viajes);
    //Precondicion: m_viajes debe estar inicializado
    //Postcondicion: sobreescribe el fichero "viajes.txt" por otro con los datos del actual
    // m_viajes.

/*Descripcion: Muestra por pantalla una lista de todos los viajes en formato de matriz de viajes**/
    void mostrar_lista();
    //Precondicion m_viajes inicializado y l_viajes>0
    //Post condicion se mostrará por pantalla la lista de viajes.

    //Descripcion: añadirá un elemento a la matriz de viajes

    void crear_viaje(int id_viaje, int id_usuario);
    //precondicion, tener la m_viajes inicializado
    //postcondicion, m_viajes será sobreescrito con una matriz en la que se incluirá el elemento añadido


    //descripcion ofrece al usuario la posibilidad de sobreescribir un apartado de un viaje, o borrarlo.
    void modificar_viaje(int id_viaje, int id_usuario);
    //precondicion pedirá que valor quiere cambiar para poder hacerlo y se necesita m_viajes inicializado
    //postcondicion modificará el campo del elemento o lo borrará y sobreescribira m_viajes con el nuevo elemento.

    //descripcion incluirá a un usuario como viajero del viaje.
    void incluir_usuario_viaje(int id_viaje, int id_usuario);
    //precondicion m_viajes inicializado y un viaje elegido;ç
    //post condicion : se modificará el elemento y se sobreescribira el elemento al sobreescribir m_viqajes
