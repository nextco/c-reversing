#include <stdio.h>

/* Las variables las declaramos aquí para que sean globales */
int a;
int b;

main(){
        /* suma de a y b */
        printf("Ingrese el valor de a ");
        scanf("%d", &a);
        printf("Ingrese el valor de b ");
        scanf("%d", &b);        
        printf("El valor de la suma es %d:\n\n", a + b);
        /* Fin suma */
        
        /* comparacion_a_b */
       if ( a == b )       
       printf("Son iguales\n\n");  
       
       if ( a < b )
       printf("El valor de b es mayor que el de a\n\n");
             
       if (a > b)
       printf("El valor de a es mayor que el de b\n\n");  
      /* Fin comparacion */
            
    getchar();
    getchar();
    
}

        
        
        

      
    
