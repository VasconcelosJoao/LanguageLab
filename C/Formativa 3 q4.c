#include<stdio.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){
for(l;l!=NULL;l=l->prox){
if(l->dado%2==0){
l2->dado=l->dado;
l2->prox=l->prox;
l2->prox->prox=NULL;
}else{
l1->dado=l->dado;
l1->prox=l->prox;
l1->prox->prox=NULL;
}
}
}