#include <stdio.h>
#include <stdlib.h>
main() { /* Declaracion de constantes y punteros */
        float primero; 
        float *segundo, *suma; 
        primero = 5.0; 
        segundo = (float *) malloc (sizeof(float)); 
        *segundo = 6.7;
        suma = (float *) malloc (sizeof(float)); 
        *suma = primero + *segundo;
         /* Fin Declaracion */
          
        printf("El valor prefijado para la suma era: %4.2f\n", *suma);
        
        printf("Ahora es tu turno: Introduce el primer numero ");
        scanf("%f",&primero); 
        printf("Introduce el segundo numero ");
                              /* como es un puntero, esto daria error */ 
        scanf("%f", segundo); /* scanf("%f", &segundo); */
        *suma = primero + *segundo; 
        printf("Ahora la suma es %4.2f\n", *suma);
        free(segundo); 
        free(suma);
        getchar();
        getchar();
}
