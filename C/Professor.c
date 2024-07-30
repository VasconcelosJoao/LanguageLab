#include <stdio.h>
#include <stdlib.h>

void fumn(int *v, int umn, int tam)
{
    int soma = 0, i=0;
    int aux=tam;
    if (tam == 0)
        return;
    while (soma <= umn && i <= tam){
    soma += v[i];
    aux--;
    i++;
    }   
    
    if(soma<=umn)
        return;
    
    fumn(&v[i], umn, aux);
    printf("%d\n", v[i - 1]);

}


int main(void)
{
    int *v = NULL;
    int aux, tam = 0, umn;
   while (scanf("%d", &aux) == 1 && aux != 0)
    {
        tam++;
        v = realloc(v, sizeof(int) * tam);
        v[tam - 1] = aux;
    }
    if (tam==0)
    return 0;
    
    scanf("%d", &umn);
    fumn(v,umn,tam);

    return 0;
}
