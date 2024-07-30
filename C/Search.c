#include<stdio.h>
#include<stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B.code,A.code)) exch(A,B); }

typedef struct item
{
    int code;
    char func[16];
}item;

void insertionsort(item *v,int l,int r)
{
  for(int i=r;i>l;i--)
    cmpexch(v[i-1],v[i]);

  for(int i=l+2;i<=r;i++)
  {
    int j=i; item tmp=v[j];
    while(less(tmp.code,v[j-1].code))
    {
      v[j]=v[j-1];
      j--;
    }
    v[j]=tmp;
  }
}

void printFunc(item *v,int code,int N){
    int menor=0,maior=N-1,medio;
        while(menor<=maior){
            medio =(maior+menor)/2;
            if(v[medio].code==code)
            {
                printf("%s\n",v[medio].func);
                return;
            }
            else if(v[medio].code>code)
            {
                maior = medio - 1;
            }
            else
            {
                menor = medio + 1;
            }
        }
        printf("undefined\n");
}


int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    item itens[N];
    for(int i=0;i<N;i++)
        scanf("%d %s",&itens[i].code,itens[i].func);
    insertionsort(itens,0,N-1);

    int I[100000],c=0;
    while(scanf("%d",&I[c])==1)
        c++;

    for (int i = 0; i < c; i++)
    {
        printFunc(itens,I[i],N);
    }
    
    return 0;
}
