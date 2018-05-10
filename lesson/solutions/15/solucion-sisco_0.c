#include <stdio.h>
#include <malloc.h>
typedef struct {
    int cifra;
    int *siguiente;
} ficha;
ficha * crear_ficha(int cifra_in);
void anyadir_ficha(ficha **pficha,int cifra_in);
void imprime_lista(ficha *pficha);
int main(void)
{
    ficha *mi_ficha;
    mi_ficha=crear_ficha(5);
    anyadir_ficha(&mi_ficha,3);
    anyadir_ficha(&mi_ficha,2);
    anyadir_ficha(&mi_ficha,6);
    imprime_lista(mi_ficha);
    getchar();
    getchar();
    return 0;
}
ficha * crear_ficha(int cifra_in)
{
      ficha *ficha_out;
      ficha_out=(ficha *)malloc(8);
      (*ficha_out).cifra=cifra_in;
      (*ficha_out).siguiente=0x0;
      return ficha_out;
}
void anyadir_ficha(ficha **pficha,int cifra_in)
{
    ficha *estruct2;
    ficha *estruct1;
    estruct1=*pficha;
    if ((estruct1)!=0)
    {
        if (cifra_in>(*estruct1).cifra)
        {
            anyadir_ficha((ficha **)(estruct1)+1,cifra_in);
            //Utilizamos +1 para que separe el add
        }
        else
        {
            estruct2=crear_ficha(cifra_in);
            (*estruct2).siguiente=(int *)estruct1;
            *pficha=estruct2;
        }
    }
    else
    {
         estruct2=crear_ficha(cifra_in);
         *pficha=estruct2;
    }       
}
void imprime_lista(ficha *pficha)
{
     if (pficha!=0)
     {
        printf("%d\n",(*pficha).cifra);     
        imprime_lista((ficha *)(*pficha).siguiente);         
     }    
}
