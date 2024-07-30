#include <stdio.h>
#include <stdlib.h>


struct valor{
  int numero;
  int posicao;
};
typedef struct valor VAL;

struct node{
  VAL valor;
  struct node *left;
  struct node *right;
};
typedef struct node NODE;

NODE *treeinitialize()  
{
  return NULL;
}

NODE *treeinsert(NODE *root, VAL x)           
{
  if(root == NULL)              
  {
    NODE *aux = (NODE *)malloc(sizeof(NODE)); 
    aux->valor = x;
    aux->left = NULL;               
    aux -> right = NULL;            
    return aux;
  } 
  else 
  {
    if(x.numero > root ->valor.numero)  
    {
      root->right = treeinsert(root->right,x);
    }
    else if(x.numero < root->valor.numero)  
    {
      root->left = treeinsert(root->left,x);
    }
  }
  return root;
}

VAL valorC(int numero,int posicao) //cria umas struct de musica para cada nó.
{
  VAL val;
  val.numero=numero;
  val.posicao=posicao;
  return val;
}


NODE *CreateV(NODE *root,int N)    
{
int i,numero;
root=NULL;                    
for(i=0;i<N;i++)             
{
  scanf("%d",&numero);
  root = treeinsert(root, valorC(numero,i)); 
}
return root;
}

int buscaNode(NODE *root,int num){
if(root==NULL){
  return -1;
}
if(root->valor.numero==num){

  return root->valor.posicao;
}
if(root->valor.numero>num){
  

  
  return buscaNode(root->left,num);
}
else
{

  return buscaNode(root->right,num);
}

}


void PrintaJ(NODE *root,int *m,int M){
int i;
for(i=0;i<M;i++){
printf("%d\n",buscaNode(root,m[i]));
}
}





int main(void) {
NODE *root  = treeinitialize();
  int N,M;
  scanf("%d %d",&N,&M);
  int *m=malloc(M*sizeof(int));
root=CreateV(root,N);

for(int j=0;j<M;j++){
scanf("%d",&m[j]);
}
PrintaJ(root,m,M);

  return 0;
}