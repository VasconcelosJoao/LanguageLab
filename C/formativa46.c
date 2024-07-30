#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
int chave=0,conchete=0,paranteses=0;
char Entrada[500];    
scanf(" %[^\n]s",Entrada);
int i;
for(i=0;i<strlen(Entrada);i++){
    if(Entrada[i]=='{'){
        chave++;
    }
    if(Entrada[i]=='['){
        conchete++;
    }
    if(Entrada[i]=='('){
        paranteses++;
    }
    if(Entrada[i]=='}'){
        chave--;
    }
    if(Entrada[i]==']'){
        conchete--;
    }
    if(Entrada[i]==')'){
        paranteses--;
    }
    if(chave<0 || paranteses<0 || conchete<0){
        break;
    }
}
if(paranteses==0 && conchete==0 && chave==0){
    printf("sim");
}else{
    printf("nao");
}
printf("\n");


    return 0;
}
