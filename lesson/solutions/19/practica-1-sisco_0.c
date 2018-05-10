/* Ejercicio 19 Practica 1 */
#include <stdio.h>
void main(void)
{
     char si_o_no;
     int coef_mul1=35,coef_mul2=12,coef_mul3=22;
     int horas_trab,salario_cal;
     
     do {
          //Caja violeta
          printf("Horas trabajadas: ");
          scanf("%d",&horas_trab);
          if (horas_trab<=35)
          {
               //Caja verde
               salario_cal=horas_trab*coef_mul2;
          }
          else {
               //Caja amarilla
               salario_cal=coef_mul1*coef_mul2+(horas_trab-coef_mul1)*coef_mul3;  
          }
          //Caja rosa
          printf("Salario = %d euros\n\n",salario_cal);
          fflush(stdin);
          printf("+Desea calcular otro salario (s/n)?\n");
          scanf("%c",&si_o_no);
          if(si_o_no=='S' || si_o_no=='s') break;
     } while(1);
}

