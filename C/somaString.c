#include<stdio.h>
#include<stdlib.h>

int cl(char *St){
int T=0;
for(int i=0;St[i]!='\0';i++){
if(St[i]>'0'&&St[i]<='9'){
T=T+(St[i]-'0');    
}
}
return T;

}

int main(int argc, char const *argv[])
{
int N;
scanf("%d",&N);
int Sm[N];
char St[105];
for(int i=0;i<N;i++){
scanf("%s",St);
Sm[i]=cl(St);
}

for(int i=0;i<N;i++){
printf("%d\n",Sm[i]);
}

    return 0;
}
