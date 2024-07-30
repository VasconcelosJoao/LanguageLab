#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void insere_inicio (celula *le, int x) {
 celula *tatu=malloc(sizeof(celula));
tatu->dado=x;
tatu->prox=le->prox;
le->prox=tatu;
}

void insere_antes (celula *le, int x, int y){
celula *tatu=malloc(sizeof(celula));
tatu ->dado=x;
// if(le->dado==y){
// tatu->prox=le->prox;
// le->prox=tatu;
//  }
//  else{
celula *elem;
for(elem=le;elem!=NULL;elem=elem->prox){
if(elem->prox==NULL){
  tatu->prox=elem->prox;
  elem->prox=tatu;
  break;
}
if(elem->prox->dado==y){
  tatu->prox=elem->prox;
  elem->prox=tatu;
  break;
}
}
le=elem;
}
// }
