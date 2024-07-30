#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    int K=1,N;

    while(scanf("%d",&N)==1){
    int M,aux;
        char nome[25],reprovado[25];
        for(int i=0;i<N;i++){
            scanf("%s %d",nome,&aux);
            if(i==0){
                M=aux;
                strcpy(reprovado,nome);
            }
            if(aux<=M){
                if(aux==M){
                    for(int j=0;j<22;j++){
                        if(nome[j]<reprovado[j]){
                            break;

                        }
                        else{
                            if(nome[j]>reprovado[j]){
                                strcpy(reprovado,nome); 

                            }
                        }  
                        

                    }
                }
                else{
                  M=aux;
                strcpy(reprovado,nome);  
                }
            }

        }
    printf("Instancia %d\n%s\n\n",K,reprovado);    
    K++;
    }


    return 0;
}
