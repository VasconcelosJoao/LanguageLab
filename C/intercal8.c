#include<stdio.h>
#include<stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

Item *intercala(Item *a,int la,int ra,Item *b,int lb,int rb)
{
int ta=(ra-la+1);
int tb=(rb-lb+1);
Item *c=malloc(sizeof(Item)*(ta+tb));
int lc=0,rc=ta+tb-1;
int ia=la,ib=lb,ic=0;
while(ia<=ra && ib<=rb)
{
    if(lesseq(a[ia],b[ib]))
        c[ic++]=a[ia++];
    else
        c[ic++]=b[ib++];
}
while(ia<=ra)
    c[ic++]=a[ia++];
while(ib<=rb)
    c[ic++]=b[ib++];
return c;
}



int main(int argc, char const *argv[])
{
Item *v=malloc(sizeof(Item)*800000);
int tamV=0;
for(int i=0;i<8;i++)
{
    int S;
    scanf("%d",&S);
    Item *temp=malloc(sizeof(Item)*S);
    for (int j = 0; j < S; j++)
        scanf("%d",&temp[j]);
    v=intercala(v,0,tamV-1,temp,0,S-1);
    tamV+=S;
    free (temp);
}
for (int i = 0; i < tamV; i++)
{
    if(i==tamV-1)
        printf("%d\n",v[i]);
    else
        printf("%d ",v[i]);
}



    return 0;
}
