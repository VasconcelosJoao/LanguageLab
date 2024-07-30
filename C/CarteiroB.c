#include <stdio.h>
#include <stdlib.h>

int busca(int *n,int*m,int N,int M){
int posi=n[0];
int pace=0;
int Pi=0,Pf=0;
int j;
for(int i=0;i<M;i++){
if(m[i]==posi){

}else{
for(j=0;j<N;j++){
if(posi==n[j]){
Pi=j;
}
if(n[j]==m[i]){
Pf=j;  
}
}
posi=m[i];

if(Pi<Pf){
pace=pace+Pf-Pi;
}
if(Pf<Pi){
pace=pace-Pf+Pi;
}
}
}
  return pace;
}


int main(void) {
int N,M;
scanf("%d%d",&N,&M);
int *n=malloc(N*sizeof(int)),*m=malloc(M*sizeof(int));
for(int i=0;i<N;i++){
  scanf("%d",&n[i]);
}
for(int i=0;i<M;i++){
  scanf("%d",&m[i]);
}
int tamanho=busca(n,m,N,M);

printf("%d\n",tamanho);
  return 0;
}