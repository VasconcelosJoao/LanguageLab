#include <stdio.h>
#include <stdlib.h>

void Forj(int *v,int i,int j,int n){
  int tmp;
if(j<n){
if(v[j]<v[i]){
  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

j++;
Forj(v,i,j,n);
}
}

void Fori(int *v,int i,int j,int n){
  j=i;
if(i<n){
  Forj(v,i,j,n);
  i++;
  Fori(v,i,j,n);
}

}

void ordena (int *v, int n){
int i,j;
i=0;
Fori(v,i,j,n);
}
