#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a < b ? a : b)

#define less(a, b) (a < b)
#define exch(A,B) { Item T; T=A;A=B;B=T; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

typedef long int Item;

int separa(Item *v, int l, int r)
{
    Item c = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], c))
        {
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}

void quicksortM3(Item *v, int l, int r)
{
    if (r - l <= 32)
        return;

    exch(v[(l + r) / 2], v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int m = separa(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Item t = v[i];
        for (j = i; j > 0 && less(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

void quicksort(Item *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

void quickselect(Item *v, int l, int r, int i)
{
    if (i < l || i > r)
        return;

    cmpexch(v[(l + r) / 2], v[r]);
    cmpexch(v[l], v[(l + r) / 2]);
    cmpexch(v[r], v[(l + r) / 2]);

    int m = separa(v, l, r);
    if (m > i)
        quickselect(v, l, m - 1, i);
    else if (m < i)
        quickselect(v, m + 1, r, i);
}

int main()
{
    int N, P, X;
    scanf(" %d %d %d", &N, &P, &X);
    Item *V = malloc(N * sizeof(Item));
    for (int i = 0; i < N; i++)
        scanf("%ld", V + i);

    quickselect(V, 0, N-1, min(N-1, P*X));
    quickselect(V, 0, N-1, min(N-1, (P+1)*X-1));
    quicksort(V, min(N-1, P*X), min(N-1, (P+1)*X-1));

    for (int i = P*X; i < min(N, (P+1)*X); i++)
        printf("%ld\n", V[i]);

    return 0;
}