#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *cria_lista (int dado) {
  celula *le;
  le = malloc (sizeof (celula));
  le -> prox = NULL;
  le -> dado = dado;
  return le; 
}

void insere_lista (celula *c, int x) {
  celula *novo = malloc (sizeof (celula)),*aux=c;
  novo->prox=NULL;
  novo->dado=x;
  if (novo == NULL) return ;
    while (aux->prox!=NULL)
    aux=aux->prox;
aux->prox=novo;


}

void imprime(celula *le,int min){
int soma = 0,aux;
celula *elem;
for (elem = le; elem != NULL && soma<min; elem = elem->prox){
    soma+=elem->dado;
    if (soma>=min)
    aux=elem->dado;
}
if(soma<min)
    return;    
imprime(elem,min);
printf("%d\n",aux);

}

void imprime_lista (celula *le) {
  // Formato: le -> 1 -> 2 -> NULL
  for (celula *elem = le; elem != NULL; elem = elem->prox) 
    printf (" %d ->", elem->dado);
  printf (" NULL\n");
}

int main(void)
{
    celula *le=NULL;
    int aux,min,r=0;


    while (scanf("%d", &aux) == 1 && aux != 0)
    {
      r++;
        if (le==NULL)
         le = cria_lista (aux);
        else
         insere_lista(le,aux);
    }
    if(r!=0){
    scanf("%d", &min);
    imprime(le,min);
    // imprime_lista(le);
    }
    return 0;
}
