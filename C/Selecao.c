#include<stdio.h>
#include<stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void selecSort(int *v,int l,int r)
    {
        if(l==r)return;
        int min=l;
        for(int j=l+1;j<=r;j++){
            if(less(v[j],v[min]))
                min=j;
        }
        exch(v[min],v[l]);
        selecSort(v,l+1,r);
    }

int main(int argc, char const *argv[])
{
    int I[1000],c=0;
    while(scanf("%d",&I[c])==1)
    c++;

    selecSort(I,0,c-1);

    for(int i=0;i<c;i++)    
    {
        printf("%d",I[i]);
        if(i!=c-1)printf(" ");
    }
    printf("\n");
    return 0;
}
