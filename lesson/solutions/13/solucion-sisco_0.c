#include <stdio.h>
void intercambio(int *a,int *b);    //Declaración de prototipos de la función
int main (void)
{
    int a=0x05,b=0x0C;      //Declaramos las variables
    intercambio(&a,&b);     //Llamamos a la función
    printf("Ahora a es %d y b es %d\n",a,b);
    getchar();              //Saliendo del programa
    return;   
}
void intercambio(int *a,int *b)
{
     int variable_de_paso;  //Esta será nuestra variable local
     variable_de_paso=*a;   //Movemos contenido de 'a'
     *a=*b;                 //Metemos 'b' en 'a'
     *b=variable_de_paso;   /*Y ahora metemos el antiguo
                            valor de 'a' en 'b'*/
     return;
}
