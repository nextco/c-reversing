# include <stdio.h>
# include <string.h>

main(){
 funcion();  
}

funcion(){
  int eleccion=0;
  int i=0;
  int numero_de_fichas=0;
  char texto_tipeado[40];
  unsigned long cierto_tamanio;
    struct{
       char nombrefich[44];     /* Nombre del fichero */
       unsigned long tamanio;   /* El tamaño en bytes */
    } fichas[1000];
      
  while (eleccion!=5)
  {
    printf("Escoja una opcion:\n");
    printf("1.- Aniadir datos de un nuevo fichero\n");
    printf("2.- Mostrar los nombres de todos los ficheros\n");
    printf("3.- Mostrar ficheros que sean de mas de un cierto tamanio\n");
    printf("4.- Ver datos de un fichero\n");
    printf("5.- Salir\n");

    gets (texto_tipeado);
    sscanf(texto_tipeado, "%d", &eleccion);
    switch(eleccion){
       case 1:

               if (numero_de_fichas < 1000) { 
                 printf("Introduce el nombre del fichero: ");
                 gets(fichas[numero_de_fichas].nombrefich);
	             printf("Introduce el tamanio en KB: ");
	             gets(texto_tipeado);
	             sscanf(texto_tipeado,"%ld",&fichas[numero_de_fichas].tamanio);
	             
                 numero_de_fichas++;
               } else   
                 printf("Maximo de fichas alcanzado (1000)!\n");
               break;
       case 2: 
               for (i=0; i<numero_de_fichas; i++) 
                   printf("Nombre: %s; Tamanio: %ld Kb\n",
                    fichas[i].nombrefich , fichas[i].tamanio); 
               break;
       case 3: 
               printf("¿A partir de que tamanio quieres que te muestre?");
               gets(texto_tipeado);
               sscanf(texto_tipeado, "%ld", &cierto_tamanio);
               if (fichas[i].tamanio >= cierto_tamanio)
                    printf("Nombre: %s; Tamanio: %ld Kb\n",
                    fichas[i].nombrefich , fichas[i].tamanio); 
               break;
       case 4: 
               printf("¿De que fichero quieres ver todos los datos?");
               gets(texto_tipeado);
               for (i=0; i<numero_de_fichas; i++) 
               if (strcmp(fichas[i].nombrefich, texto_tipeado) == 0)
                    printf("Nombre: %s; Tamanio: %ld Kb\n",
                      fichas[i].nombrefich, fichas[i].tamanio); 
               break;
       case 5: 
               printf("Fin del programa\n"); 
               break;
       default: 
               printf("Opcion desconocida!\n");
               break;
       }

  }
}
