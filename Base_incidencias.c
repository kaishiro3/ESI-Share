
#include <stdio.h>


int main()
{
    int l_Incidencias =1 ; // la cantidad de filas de la matriz, modificable. Es uno por ahora
    
    
    typedef struct {
        
        
        char* id_viaje;
        
        int id_usuario; //el usuario CULPABLE
        
        int id_registra; //el usuario que registra el incidente
        
        char* definicion[100];
        
        int estado; // Abierto, valido, cerrado
        
        
      
        
    }incidencias ; //Esto es una fila de la matriz 
    
    incidencias* m_incidencias = malloc(sizeof(incidencias)*l_incidencias);


    return 0;
}
