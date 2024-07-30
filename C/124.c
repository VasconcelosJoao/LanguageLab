#include<stdio.h>
#include<stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;


void insere (celula *le, int x,celula *tatu) {

tatu->dado=x;
tatu->prox=le->prox;
le->prox=tatu;
}

void divide_lista (celula *l, celula *l1, celula *l2){
int impar[1000],i=0;
int par[1000],x=0;
for (l ; l != NULL; l=l->prox)
{
    if(l->dado%2!=0){
        impar[i]=l->dado;
        i++;
    }
     if(l->dado%2==0){
        par[x]=l->dado;
        x++;
    }
}
i--;
x--;

for (i ; i >-1;i --){
   if(i==0) 
      {
         l1->dado=impar[i];
      }  else insere(l1,impar[i],l);
}
for (x ; x >-1;x --){
    printf("%d\n",par[x]);
   if(x==0) 
      {
         l2->dado=par[x];
      }  else insere(l2,par[x],l);
}
}