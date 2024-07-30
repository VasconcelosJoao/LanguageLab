#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct pilha {
  int *dados;
  int N, topo;
} pilha;

pilha *criapilha(){
pilha *p=malloc(sizeof(pilha));
p->N=501;
p->dados=malloc(p->N*sizeof(int));
p->topo=0;
return p;
}

int empilha (pilha *p, int x){
    if(p->topo==p->N){
        if(p->dados==NULL) return 1;
    }
    p->dados[p->topo]=x;
    p->topo++;
    return 0;
}

int desempilha (pilha *p, int y){
if (p->topo==0){
return 1;
}
else{
    if(p->dados[p->topo-1]!=y) return 1; 
    p->topo--;
    return 0;
}
}

int main()
{
pilha *p;
p=criapilha();

char Entrada[500];    
scanf(" %[^\n]s",Entrada);
int i,code;
for(i=0;i<strlen(Entrada);i++){
    
    if(Entrada[i]=='{'){
    code=empilha(p,1);   
    }
    if(Entrada[i]=='['){
    code=empilha(p,2);   
    }
    if(Entrada[i]=='('){
    code=empilha(p,3);   
    }
    if(Entrada[i]=='}'){
    code=desempilha(p,1);
    }
    if(Entrada[i]==']'){
    code=desempilha(p,2);
    }
    if(Entrada[i]==')'){
    code=desempilha(p,3);
    }

    if(code==1){
        break;
    }

}
if(p->dados[p->topo-1]==1 ||p->dados[p->topo-1]==2||p->dados[p->topo-1]==3){
    code=1;
}


if (code==1){
    printf("nao\n");
}else{
    printf("sim\n");
}

    return 0;
}
