#include<stdio.h>

void BusB(long int num,long int *v,int tam){
    int menor=0,maior=tam,medio;
    while(menor<=maior)
    {
        medio =(maior+menor)/2;
        if(v[medio]==num)
        {
                printf("%d\n",medio);
                return;
        }
        else if(v[medio]>num)
        {
                maior = medio - 1;
        }
        else
        {
            menor = medio + 1;
        }
    }

    if(num<v[medio])
        printf("%d\n",medio);
    else 
        printf("%d\n",medio+1);
    return;
}

int main(int argc, char const *argv[])
{
    int N,M;
    scanf("%d %d",&N,&M);
    long int vN[N],vM[M];
    
    for(int i=0;i<N;i++)
        scanf("%ld",&vN[i]);
    
    for(int i=0;i<M;i++)
        scanf("%ld",&vM[i]);

    for(int i=0;i<M;i++)
        BusB(vM[i],vN,N-1);

    return 0;
}
