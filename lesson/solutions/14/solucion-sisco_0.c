#include <stdio.h>
#include <string.h>
//Definimos nuestra estructura
typedef struct {
       char nombre[300];
       int edad;
       char email[252];
} miestructura;
int main(void)
{
    //Definimos Juan sin puntero:
    miestructura juan;
    strcpy(juan.nombre,"Juan el Viejo\n");
    strcpy(juan.email,"juan@chiste.com :-)\n");
    juan.edad=200;
    //Definimos Pedrito con puntero:
    miestructura *pedrito;
    pedrito=(miestructura *)malloc(0x22C);     //Reservamos espacio
    strcpy((*pedrito).nombre,"Pedrito\n");
    strcpy((*pedrito).email,"pedrito@gmail.com\n");
    (*pedrito).edad=21;
    //Imprimimos datos de Juan
    printf("Primera persona: %s,%s, con edad %d\n",juan.nombre,juan.email,juan.edad);
    //Imprimimos datos de Pedrito
    printf("Segunda persona: %s,%s, con edad %d\n",(*pedrito).nombre,(*pedrito).email,(*pedrito).edad);
    
    //Finalizando
    free(pedrito);
    getchar();
    return;
}
