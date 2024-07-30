#include<stdio.h>
#include<stdlib.h>
int *v;
int *t;
int busca(int m, int ini, int fim)
{
    int meio=(ini+fim)/2;
    if (v[meio]==m) return meio;
    if (v[meio]<m) return busca(m,meio+1,fim);
    return busca(m,ini,meio-1);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
   v=malloc(n*sizeof(int)); 
   t=malloc(m*sizeof(int)); 

    for (int i=0;i<n;i++)
        scanf("%d ",&v[i]);
    for (int j=0;j<m;j++)
        scanf("%d ",&t[j]);
    int tempo=0;
    int posicao=0;
    for (int i=0;i<m;i++)
    {
        int proxima_posicao=busca(t[i],0,n-1);
        tempo+=abs(proxima_posicao-posicao);
        posicao=proxima_posicao;
    }
    printf("%d\n",tempo);
    return 0;
}