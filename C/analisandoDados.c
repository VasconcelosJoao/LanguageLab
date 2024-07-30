#include <stdio.h>

typedef struct Item
{
    int qnt;
    char letra;
    int pos;
} Item;

#define lessp(A,B) ((A.pos) < (B.pos))
#define less(A,B) ((A.qnt) > (B.qnt))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
#define cmpexchp(A,B) { if (lessp(B,A)) exch(A,B); }

int separa(Item *V,int l,int r)
{
  Item c=V[r];
  int j=l;
  for(int k=l;k<r;k++)
    if(less(V[k],c))
    {
      exch(V[k],V[j]);
      j++;
    }else
        if (V[k].qnt==c.qnt)
        {
         if(lessp(V[k],c)){
            exch(V[k],V[j]);
            j++;
         } 
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



int main(int argc, char const *argv[])
{

    char input[100001];
    Item EDA[100001];
    int n = 0, j = 0;

    while (scanf("%c", &input[n]) == 1 && input[n]!='\n')
    {
        if(n==0)
        {
            EDA[j].pos=0;
            EDA[j].letra=input[n];
            EDA[j].qnt=1;
        }
        else
            if (input[n]==input[n-1])
                EDA[j].qnt++;
            else
            {
                j++;
                EDA[j].pos=n;
                EDA[j].letra=input[n];
                EDA[j].qnt=1;
            }  
        n++;
    }

    // for (int i = 0; i < j+1; i++)
    //     printf("%d %c %d\n",EDA[i].qnt,EDA[i].letra,EDA[i].pos);
    quicksort(EDA,0,j);
    // printf("\n");
    // printf("--------------------------------------------------\n");
    for (int i = 0; i < j+1; i++)
        printf("%d %c %d\n",EDA[i].qnt,EDA[i].letra,EDA[i].pos);

    return 0;
}
