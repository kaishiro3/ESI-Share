

#ifndef _VIAJES_
#define _VIAJES_
#include <stdio.h>
#include "ficheros.h"
#endif // _VIAJES_

/*Descripcion: lee el fichero "viajes.txt" y devuelve en m_viajes cada uno de los elementos
y en l_viajes la cantidad de elementos*/
	void mostrar_lista_viajes()
    //Precondicion m_viajes inicializado y l_viajes>0
    //Post condicion se mostrará por pantalla la lista de viajes.

    //Descripcion: añadirá un elemento a la matriz de viajes

    void crear_viaje(viajes **m_viajes,int *lon,int id)
    //precondicion, tener la m_viajes inicializado
    //postcondicion, m_viajes será sobreescrito con una matriz en la que se incluirá el elemento añadido


    //descripcion ofrece al usuario la posibilidad de sobreescribir un apartado de un viaje, o borrarlo.
    void editar_viaje(viajes **m_viajes,int *lon, int id)
    //precondicion pedirá que valor quiere cambiar para poder hacerlo y se necesita m_viajes inicializado
    //postcondicion modificará el campo del elemento o lo borrará y sobreescribira m_viajes con el nuevo elemento.

    //descripcion incluirá a un usuario como viajero del viaje.
	void add_viajero (viajes **m_viajes, int id_viaje, int lon)
    //precondicion m_viajes inicializado y un viaje elegido;ç
    //post condicion : se modificará el elemento y se so
