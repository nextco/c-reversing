#include <stdio.h>
int main(void)
{
    float numero=5.0;
    float *puntero1=malloc(4);
    *puntero1=6.7;
    float *puntero2=malloc(4);
    *puntero2=*puntero1+numero;
    printf("El valor prefijado para la suma era %4.2f\n",*puntero2);
    
    printf("Ahora es tu turno: Introduce el primer número ");
    scanf("%f",&numero);
    printf("Introduce el segundo numero ");
    scanf("%f",puntero1);
    *puntero2=*puntero1+numero;
    printf("Ahora la suma es %4.2f\n",*puntero2);
    
    free(puntero1);
    free(puntero2);
    getchar();
    getchar();
    getchar();
    return;   
}
