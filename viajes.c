
#include <stdio.h>


int main()
{
    int l_Viajes =1 ; // la cantidad de filas de la matriz, modificable. Es uno por ahora
    
    typedef char* localizacion[]; //el nombre del lugar al que ir
    
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
        
        

        
        
      
        
    }viajes ; //Esto es una fila de la matriz 
    
    viajes* m_viajes = malloc(sizeof(viajes)*l_Viajes);


    return 0;
}
