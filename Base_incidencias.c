
#include <stdio.h>


int main()
{
    int l_incidencias =1 ; // la cantidad de filas de la matriz, modificable. Es uno por ahora
    
    
    typedef struct {
        
        
        char* id_viaje;
        
        int id_usuario; //el usuario CULPABLE
        
        int id_registra; //el usuario que registra el incidente
        
        char* definicion[100];
        
        int estado; // Abierto, valido, cerrado
        
        
      
        
    }usuarios ; //Esto es una fila de la matriz 
    
    usuarios* m_usuarios = malloc(sizeof(usuarios)*l_usuarios);


    return 0;
}