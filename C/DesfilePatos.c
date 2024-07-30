#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(scanf("%d", &n)==1 && n!=0){
        int z = 0, C = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf(" %d",&x);
            if (C == 0)
            {
                z = x;
                C++;
            }
            else
                C += (z == x ? 1 : -1);
        }
    printf("%d\n", z);
    }

    return 0;
}