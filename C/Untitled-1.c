#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

celula *cria_lista () {
  celula *le;
  le = malloc (sizeof (celula));
  le -> prox = NULL; // Definicao de lista vazia
  return le;
}

int insere_lista (celula *c, int x) {
  // Insere uma nova celula depois de c.
  // Valor de retorno:
  //   0: bem sucedido
  //   1: deu ruim a alocacao
  celula *novo = malloc (sizeof (celula));
  celula *elem=c;
  if (novo == NULL) return 1;
  novo -> dado = x;
  novo -> prox = elem -> prox;
  elem -> prox = novo;
  c=elem;
  return 0;
}

int remove_lista (celula *c, int *y) {
  // Remove a celula depois de c e retorna o valor em y.
  // Valor de retorno:
  //   0: bem sucedido
  //   1: nao ha celula depois de c
  celula *lixo = c -> prox;
  if (lixo == NULL) return 1;
  *y = lixo -> dado;
  c -> prox = lixo -> prox;
  free (lixo);
  return 0;
}

void imprime_lista (celula *le) {
  // Formato: le -> 1 -> 2 -> NULL
  printf ("\nle ->");
  for (celula *elem = le->prox; elem != NULL; elem = elem->prox) 
    printf (" %d ->", elem->dado);
  printf (" NULL\n");
}

int menu () {
  int opcao;
  printf ("\n1 - Inserir um elemento no inicio da lista.\n");
  printf ("2 - Remover o primeiro elemento da lista.\n");
  printf ("3 - Imprime a lista.\n");
  printf ("0 - Sair.\n");
  printf ("ESCOLHA UMA OPCAO: ");
  scanf ("%d", &opcao);
  return opcao;
}

int main () {
  int op, y, ret;
  celula *le;

  // Criacao da lista
  le = cria_lista ();

  op = menu ();
  while (op != 0) {
    switch (op) {
    case 1:
      printf ("\nDigite o elemento a ser inserido: ");
      scanf ("%d", &y);
      ret = insere_lista (le, y);
      if (ret != 0) printf ("\nA insercao falhou. Codigo de retorno: %d\n", ret);
      else printf ("\nElemento inserido com sucesso.\n");
      break;

    case 2:
      if (remove_lista (le, &y) == 1) printf ("\nLista vazia\n");
      else printf ("\nElemento removido: %d\n", y);
      break;

    case 3:
      imprime_lista (le);
      break;

    default:
      printf ("\nOpcao invalida!\n");

    }

    op = menu ();
  }

  // Remocao da lista
  while (remove_lista (le, &y) == 0);
  free (le);

  return 0;
}