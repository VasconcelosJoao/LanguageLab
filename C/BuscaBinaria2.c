#include<stdio.h>
#include<stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B.num,A.num)) exch(A,B); }

typedef struct item
{
    long int num;
    int pos;
}item;

void merge(item *V, int l, int m, int r)
{
  item *R=malloc(sizeof(item)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if(lesseq(V[i].num,V[j].num))
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

void mergesort(item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}

void BusB(long int num,item *v,int tam){
    int menor=0,maior=tam,medio;
    while(menor<=maior)
    {
        medio =(maior+menor)/2;
        if(v[medio].num==num)
        {
            printf("%d\n",v[medio].pos);
            return;
        }
        else if(v[medio].num>num)
        {
            maior = medio - 1;
        }
        else
        {
            menor = medio + 1;
        }
    }

    printf("%d\n",-1);
}

int main(int argc, char const *argv[])
{
    int N,M,code=0;
    scanf("%d %d",&N,&M);
    item vN[N];
    long int vM[M];
    
    for(int i=0;i<N;i++)
    {
        scanf("%ld",&vN[i].num);
        vN[i].pos=code;
        code++;
    }

    for(int i=0;i<M;i++)
        scanf("%ld",&vM[i]);

    mergesort(vN,0,N-1);

    for(int i=0;i<M;i++)
        BusB(vM[i],vN,N-1);

    return 0;
}
