#include<stdio.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int empilha (celula *p, int x){
celula *tatu=malloc(sizeof(celula));
if (tatu==NULL){
  return 0;
}

tatu->dado=x;
tatu->prox=p->prox;
p->prox=tatu;

return 1;

}