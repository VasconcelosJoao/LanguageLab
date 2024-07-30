#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
  int dado;
  struct celula *prox;
} celula;

void insere(celula *le, int x)
{
  celula *tatu = malloc(sizeof(celula));
  tatu->dado = x;
  tatu->prox = le->prox;
  le->prox = tatu;
}

void imprime(celula *le)
{
  for (celula *elem = le->prox; elem != NULL; elem = elem->prox)
    printf("%d -> ", elem->dado);
  printf("NULL\n");
}

celula *cria_listal()
{
  celula *le;
  le = malloc(sizeof(celula));
  le->prox = NULL; // Definicao de lista vazia
  return le;
}
celula *cria_lista()
{
  celula *le;
  le = malloc(sizeof(celula));
  le->prox = NULL; // Definicao de lista vazia
  return le;
}

// void divide_lista (celula *l, celula *l1, celula *l2){
// if(l->prox==NULL)
// {
// return;
// }
//   if(l->prox->dado%2!=0)
//     {
//       l1->prox=l->prox;
//       l->prox=l->prox->prox;
//       l1->prox->prox=NULL;
//       divide_lista(l,l1->prox,l2);
//     }
//   else{
//       l2->prox=l->prox;
//       l->prox=l->prox->prox;
//       l2->prox->prox=NULL;
//     divide_lista(l,l1,l2->prox);
//     }
// }
// int remove_depois (celula *p){
// if(p->prox==NULL){
//    return 1;
// }
// else{
// celula *pont;
// pont=p->prox->prox;
//    p->prox=pont;
// }
// }

void remove_todos_elementos(celula *le, int x)
{
  if (le->prox != NULL)
  {
    if (le->prox->dado != x)
    {
      remove_todos_elementos(le->prox, x);
    }
    else
    {
      remove_todos_elementos(le->prox, x);
      le->prox = le->prox->prox;
    }
  }
}

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
  if (l2->prox == NULL && l1->prox == NULL)
  {
    return;
  }

  if (l1->prox == NULL)
  {
    l3->prox = l2->prox;
    l2->prox = l2->prox->prox;
    l3->prox->prox = NULL;
    mescla_listas(l1, l2, l3->prox);
    return;
  }

  if (l2->prox == NULL)
  {
    l3->prox = l1->prox;
    l1->prox = l1->prox->prox;
    l3->prox->prox = NULL;
    mescla_listas(l1, l2, l3->prox);
    return;
  }

  if (l1->prox->dado < l2->prox->dado)
  {
    l3->prox = l1->prox;
    l1->prox = l1->prox->prox;
    l3->prox->prox = NULL;
    mescla_listas(l1, l2, l3->prox);
  }
  else
  {
    l3->prox = l2->prox;
    l2->prox = l2->prox->prox;
    l3->prox->prox = NULL;
    mescla_listas(l1, l2, l3->prox);
  }
}

int main()
{

  celula *l;

  l = cria_listal();

  insere(l, 10);
  insere(l, 8);
  insere(l, 5);
  insere(l, 4);
  insere(l, 1);

  celula *l1, *l2;
  l1 = cria_lista();
  l2 = cria_lista();

  insere(l1, 11);
  insere(l1, 9);
  insere(l1, 7);
  insere(l1, 6);
  insere(l1, 3);
  insere(l1, 2);

  printf("l1 -> ");
  imprime(l);

  printf("l2 -> ");
  imprime(l1);

  mescla_listas(l, l1, l2);

  printf("l1 -> ");
  imprime(l);

  printf("l2 -> ");
  imprime(l1);

  printf("l3 -> ");
  imprime(l2);

  return 0;
}