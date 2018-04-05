
#include <stdio.h>


int main()
{
    int l_vehiculos =1 ; // la cantidad de filas de la matriz, modificable. Es uno por ahora
    
    
    typedef struct {
        
        char* matricula;
        
        int id_Usuario;
        
        int plazas;
        
        char *definicion[50];
        
      
        
    }vehiculos ; //Esto es una fila de la matriz 
    
    vehiculos* m_vehiculo = malloc(sizeof(vehiculos)*l_vehiculos);


    return 0;
}
