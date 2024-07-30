#include <stdio.h>
#include <stdlib.h>

int v[1010];

void resp(){
    int N;
    scanf(" %d", &N);

    int R = 0, M = 0;
    for (int i = 0; i < N; i++)
    {
        int X;
        scanf(" %d",&X);
        if (++v[X] > M)
        {
            M = v[X];
            R = X;
        }
        else if (v[X] == M && R < X)
            R = X;
    }
    printf("%d\n", R);
}

int main()
{
    // for(int i=0;i<4;i++)
    resp();

    return 0;
}