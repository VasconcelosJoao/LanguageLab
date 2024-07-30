#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
  char dado[110];
  struct celula *prox;
} celula;

celula *criapilha(){
celula *pilha=malloc(sizeof(celula));
pilha->prox=NULL;
return pilha;
}

celula *criafila(){
celula *fila=malloc(sizeof(celula));
fila->prox=fila;
return fila; 
}

celula *enfileira(celula *le,char x[]){
celula *novo=malloc(sizeof(celula));
novo->prox=le->prox;
(le)->prox=novo;
strcpy((le)->dado,x); 
return novo;
}

int desenfileira(celula *f, char *y){
    if(f->prox == f) return 0;
    celula *trash = f->prox;
    strcpy(y,trash->dado); 
    f->prox = trash->prox;
    free(trash);
    return 1;
}



void empilha (celula *p, char x[]){
celula *tatu=malloc(sizeof(celula));
strcpy(tatu->dado,x); 
tatu->prox=p->prox;
p->prox=tatu;
}

int desempilha (celula *p, char *y){
celula *lixo = p -> prox;
  if (lixo == NULL) return 0;
  strcpy(y,lixo->dado); 
  p -> prox = lixo -> prox;
  free (lixo);
  return 1;

}
void InsereP(char x[],celula *p){
int j=0;
char cha[100]=" ";
for(int i=8;i<strlen(x);i++){
char y;
cha[j]=x[i];
j++;
}
empilha(p,cha);

}


int sele(char func[]){
if(strncmp(func,"desfazer",8)==0)
return 1;
else
return 0;
}


int main(int argc, char const *argv[])
{
char *y=malloc(110*sizeof(char));

    celula *pilha;
    celula *fila;

  pilha=criapilha();
  fila=criafila();

char var[110];

 while(scanf(" %[^\n]s",var) ==1){
  // for (int k=0;k<13;k++){
  fila=enfileira(fila,var);  
}

celula* temp;
int sel,i,T;
for(temp=fila->prox;temp!=fila;temp=temp->prox){
sel=sele(temp->dado);
if (sel==1){
    T=desempilha(pilha,y);
    if(T==0){
        printf("NULL\n");
    }
    else{
      printf("%s\n",y);
    }
}
else{
  InsereP(temp->dado,pilha);
}
}

    return 0;
}