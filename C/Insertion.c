#include<stdio.h>
#include<stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertionsort(int *v,int l,int r)
{
  for(int i=r;i>l;i--)
    cmpexch(v[i-1],v[i]);

  for(int i=l+2;i<=r;i++)
  {
    int j=i; int tmp=v[j];
    while(less(tmp,v[j-1]))
    {
      v[j]=v[j-1];
      j--;
    }
    v[j]=tmp;
  }
}

int main(int argc, char const *argv[])
{
    int I[50000],c=0;
    while(scanf("%d",&I[c])==1)
    c++;

    insertionsort(I,0,c-1);

    for(int i=0;i<c;i++)    
    {
        printf("%d",I[i]);
        if(i!=c-1)printf(" ");
    }
    printf("\n");
    return 0;
}
