#include<stdio.h>
#include<stdlib.h>

typedef long int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void merge(Item *V, int l, int m, int r)
{
  Item *R=malloc(sizeof(Item)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if(lesseq(V[i],V[j]))
      R[k++]=V[i++];
    else
      R[k++]=V[j++];
  }

  while(i<=m)
      R[k++]=V[i++];
  while(j<=r)
      R[k++]=V[j++];


  k=0;
  for(i=l;i<=r;i++)
    V[i]=R[k++];
  free(R);
}

void mergesort(Item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}

int main(int argc, char const *argv[])
{
    long int N[100001];
    int C;

    scanf("%d",&C);
    
    for(int i=0;i<C;i++)
    scanf("%ld",&N[i]);
    
    mergesort(N,0,C-1);
    
    for(int i=0;i<C;i++)    
    {
        printf("%ld",N[i]);
        if(i!=C-1)printf(" ");
    }
    printf("\n");

    return 0;
}