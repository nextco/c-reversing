#include <stdio.h>
void intercambio(int *a,int *b);    //Declaraci�n de prototipos de la funci�n
int main (void)
{
    int a=0x05,b=0x0C;      //Declaramos las variables
    intercambio(&a,&b);     //Llamamos a la funci�n
    printf("Ahora a es %d y b es %d\n",a,b);
    getchar();              //Saliendo del programa
    return;   
}
void intercambio(int *a,int *b)
{
     int variable_de_paso;  //Esta ser� nuestra variable local
     variable_de_paso=*a;   //Movemos contenido de 'a'
     *a=*b;                 //Metemos 'b' en 'a'
     *b=variable_de_paso;   /*Y ahora metemos el antiguo
                            valor de 'a' en 'b'*/
     return;
}
