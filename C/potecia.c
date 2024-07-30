#include <stdio.h>

long long int soma (long long int nove,int sum){
int x;
if (nove!=0){
x=nove%10;
sum=sum+x;
nove=nove/10;
return soma(nove,sum);
}
else{
    return sum;
}
}

int Grau(long long int numero,int grau){
int sum=0;
if (numero<9){
    return 0;
}
if (numero==9){
    return grau;
}
if (numero>9)
{
    grau=grau+1;
    return Grau(soma(numero, sum),grau);
}

}

void For(){
long long int nove;
int grau=1;
scanf("%lld",&nove);
if (nove!=0){
    grau=Grau(nove,grau);
if (grau==0){
    printf("%lld is not a multiple of 9.\n",nove);
}else{
    printf("%lld is a multiple of 9 and has 9-degree %d.\n",nove,grau);
}
For();    
}else{
    return ;
}
}


int main(int argc, char const *argv[])
{

For();

    return 0;
}
