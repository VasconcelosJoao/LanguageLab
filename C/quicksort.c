#include<stdio.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }


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

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    Item v[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&v[i]);
    
    quicksort(v,0,n-1);
    for (int i = 0; i < n-1; i++)
        printf("%d ", v[i]);
    printf("%d\n",v[n-1]);
    return 0;
}
