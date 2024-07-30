#include<stdio.h>

int q7s(long E){
int C=0;
if((E-7)%10==0||E-7==0){
    C++;
    E=E/10;
    }
    else{
    E=E/10; 
    }
    if(E>0){
    C=C+q7s(E);
    }
    return C;
}

int main(int argc, char const *argv[])
{
    long E;
    scanf("%ld",&E);
 
    printf("%d\n",q7s(E));
    return 0;
}
