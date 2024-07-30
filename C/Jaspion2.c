#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Item
{
    char jp[82], br[82];
}Item;

typedef struct list
{
    char br[82];
}list;


#define less(A,B) (strcmp(A.jp, B.jp) < 0)
#define exch(A,B) {Item T; T=A;A=B;B=T; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

#define lesK(A, K) (strcmp(A.jp, K) < 0)
#define equaK(A, K) (strcmp(A.jp, K) == 0)

int separa(Item *V,int l,int r)
{
  Item c=V[r];
  int j=l;
  for(int k=l;k<r;k++)
    if(less(V[k],c))
    {
      exch(V[k],V[j]);
      j++;
    }
  exch(V[j],V[r]);
  return j;
}


void quicksort(Item *V,int l, int r)
{
  if (r<=l) return;

  cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
      cmpexch(V[r],V[(l+r)/2]);

  int j=separa(V,l,r);
  quicksort(V,l,j-1);
  quicksort(V,j+1,r);
}

int buscaBinaria(Item *v, int l, int r, char *x)
{
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (equaK(v[m], x))
            return m;
        else
            if (lesK(v[m], x))
                l = m + 1;
            else
                r = m - 1;
    }
    return -1;
}

void strcatC(char texto[], char letra){
    size_t tamanho = strlen(texto);
    texto[tamanho] = letra;
    texto[tamanho + 1] = '\0';
}


void principal(){
    Item *v=malloc(sizeof(Item)*100001);
    int M,N;
    scanf("%d %d",&M,&N);

    for (int i = 0; i < M; i++)
    {
        scanf(" %s",v[i].jp);
        scanf(" %[^\n]",v[i].br);
    }

    quicksort(v,0,M-1);

    list *Verso=malloc(sizeof(list)*N);
    int count=0;
    for (int i = 0; i < N; i++)
    {   
        char str[82];
        scanf(" %[^\n]",str);
        char *token;
        token= strtok(str," ");
            while(token != NULL)
            {

                int idx = buscaBinaria(v, 0, M - 1, token);
            printf("%s", (idx != -1 ? v[idx].br : token));
            token = strtok(NULL, " ");
            printf("%c", " \n"[token == NULL]);
            }
                count++;
    }
        for (int i = 0; i < count; i++)
            printf("%s\n",Verso[i].br);

}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d",&T);

    while (T--)
        principal();    
 
    return 0;
}

