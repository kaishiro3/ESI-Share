
#include <stdio.h>


int main()
{
    int l_usuarios =1 ; // la cantidad de filas de la matriz, modificable. Es uno por ahora
    
    
    typedef struct {
        
        
        int id_Usuario;
        
        char* nombre;
        
        char* poblacion;
        
        int perfil; //si es admin o usuario normal
        
        int plazas;
        
        char* user;
        
        char* password;
        
        int estado; //activo o bloqueado
        
        
      
        
    }usuarios ; //Esto es una fila de la matriz 
    
    usuarios* m_usuarios = malloc(sizeof(usuarios)*l_usuarios);


    return 0;
}