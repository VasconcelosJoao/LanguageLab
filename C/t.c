#include <stdio.h>
#include <string.h>
#define TAM 501
struct Pilha{
        int topo;
        int pilha[TAM];
};
void push(struct Pilha *p, int item){
        if(p->topo == TAM){                
        }else p->pilha[p->topo++] = item;
}
int empty(struct Pilha *p){
        if(p->topo == 0) return -1;
        else return 0;
}
int pop(struct Pilha *p){
        if(empty(p)){              
        }else return p->pilha[--p->topo];
}
int top(struct Pilha *p){
        if(empty(p)){
        }else return p->pilha[p->topo-1];
}
void main(){
        struct Pilha celula;
        int abre, fecha, id, i;
        char entrada[TAM];
        i = abre = fecha = celula.topo = 0;
        fgets(entrada, TAM, stdin);
        for(i; entrada[i] != '\n'; i++){
                if((entrada[i] == '(') || (entrada[i] == '[') || (entrada[i] == '{')){
                        abre++;
                        if(entrada[i] == '(') id = 1;
                        else if(entrada[i] == '[') id = 2;
                        else id = 3;
                        push(&celula, id);
                }else if((entrada[i] == ')') || (entrada[i] == ']') || (entrada[i] == '}')){
                        fecha++;
                        if(entrada[i] == ')') id = 1;
                        else if(entrada[i] == ']') id = 2;
                        else id = 3;
                        if(id == top(&celula)) pop(&celula);
        }       }
        if(empty(&celula)){
                if(abre == fecha) printf("sim\n");
                
        }else{
                printf("nao\n");
                
        }
}
