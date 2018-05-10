#include <stdio.h>
#include <string.h>

void funcion_investigada() {
                      struct mia {
                             char nombre[44];
                             unsigned int tamanio;
                      } ficha[1000];
                      int indice;
                      int contador_recorre;
                      int opcion;
                      char guardado_stdin[40];
                      int tamanio_comparacion;
                      
                      indice = 0;
                      do {
                               printf("Escoja una opcion:\n");
                               printf("1.- Añadir datos de un nuevo fichero\n");
                               printf("2.- Mostrar los nombres de todos los ficheros\n");
                               printf("3.- Mostrar ficheros que sean de mas de un cierto tamaño\n");
                               printf("4.- Ver datos de un fichero\n");
                               printf("5.- Salir\n");
                               
                               gets(guardado_stdin);
                               sscanf(guardado_stdin, "%d", &opcion);
                               switch(opcion) {
                                              case 1:
                                                   if(indice <= 999) {
                                                             printf("Introduce el nombre del fichero: ");
                                                             gets(ficha[indice].nombre);
                                                             printf("Introduce el tamaño: ");
                                                             gets(guardado_stdin);
                                                             sscanf(guardado_stdin, "%ld", &ficha[indice].tamanio);
                                                             indice++;
                                                   }else {
                                                         printf("Maximo de fichas alcanzado (1000)!\n");
                                                   }
                                                   break;
                                              case 2:
                                                   for(contador_recorre = 0; contador_recorre < indice; contador_recorre++) {
                                                                        printf("Nombre: %s; Tamaño: %d\n", ficha[contador_recorre].nombre, ficha[contador_recorre].tamanio);
                                                   }
                                                   break;
                                              case 3:
                                                   printf("A partir de que tamaño quieres que te muestre: ");
                                                   gets(guardado_stdin);
                                                   sscanf(guardado_stdin, "%ld", &tamanio_comparacion);
                                                   
                                                   for(contador_recorre = 0; contador_recorre < indice; contador_recorre++) {
                                                                        if(ficha[contador_recorre].tamanio >= tamanio_comparacion) printf("Nombre: %s; Tamaño: %d\n", ficha[contador_recorre].nombre, ficha[contador_recorre].tamanio);
                                                   }
                                                   break;
                                              case 4:
                                                   printf("De que ficheros quiere ver todos los datos?");
                                                   gets(guardado_stdin);
                                                   for(contador_recorre = 0; contador_recorre < indice; contador_recorre++) {
                                                                        if(strcmp(ficha[contador_recorre].nombre, guardado_stdin) == 0) {
                                                                                                                  printf("Nombre: %s; Tamaño: %d\n", ficha[contador_recorre].nombre, ficha[contador_recorre].tamanio);
                                                                        }
                                                   }
                                                   break;
                                              case 5:
                                                   printf("Fin del programa\n");
                                                   break;
                                              default:
                                                      printf("Opcion desconocida\n");
                                                      break;   
                               }
                      } while(opcion != 5);
                      return;

}

main() {
       funcion_investigada();
}                 
