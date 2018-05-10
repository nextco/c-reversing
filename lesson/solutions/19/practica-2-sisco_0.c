/* Ejercicio 19 Practica 2 */
void main(void)
{
     int tamanho_pir,contador,pos_linea;
     printf("tamaño de la piramide: ");
     scanf("%d",&tamanho_pir);
     for(contador=1;contador<=tamanho_pir;contador++) {
          for(pos_linea=1;(tamanho_pir-contador)>=pos_linea;pos_linea++) {
               printf(" ");
          }
          for(pos_linea=1;(contador*2-1)>=pos_linea;pos_linea++) {
               printf("*");
          }
          printf("\n");                                                                         
     }     
}
