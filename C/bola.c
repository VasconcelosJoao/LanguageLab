#include <stdio.h>
#include <stdlib.h>

void Forj(int *v,int *i,int j,int n){
  int tmp;
if(j<n){
if(v[j]<v[*i]){
  tmp = v[*i];
  v[*i] = v[j];
  v[j] = tmp;
}

j++;
Forj(v,i,j,n);
}
}

void Fori(int *v,int *i,int j,int n){
  j=i;
if(*i<n){
  Forj(v,i,j,n);
  i++;
  Fori(v,i,j,n);
}

}

void ordena (int *v, int n){
int *i=malloc(sizeof(int)),j;
i=0;
Fori(v,i,j,n);
}

int main(){
int n;
 scanf("%d", &n);
 int *N = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    {
        scanf("%d", &N[i]);
    }
ordena(N,n);
printf("\n");
for (int i = 0; i < n; i++)
    {
       printf("%d\t", N[i]);
    }
  return 0;
}
