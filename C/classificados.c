#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define less(a, b) (a.value == b.value ? a.key < b.key : a.value < b.value)

#define less2(a, b) (a.key == b.key ? a.value < b.value : a.key < b.key)

#define exch(A,B) { Item T; T=A;A=B;B=T; }

#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

#define cmpexch2(A,B) { if (less2(B,A)) exch(A,B); }

typedef struct
{
    long long key;
    int value;
} Item;

Item v[10000001];

int separa2(Item *v, int l, int r)
{
    Item c = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less2(v[k], c))
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
    cmpexch2(v[l], v[r - 1]);
    cmpexch2(v[l], v[r]);
    cmpexch2(v[r - 1], v[r]);

    int m = separa2(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Item t = v[i];
        for (j = i; j > 0 && less2(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

void quicksort2(Item *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

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

void quickselect(Item *v, int l, int r, int i)
{
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
    int k;
    scanf(" %d", &k);
    int n;
    for (n = 0; scanf(" %lld %d", &v[n].key, &v[n].value) == 2; n++)
        ;

    quickselect(v, 0, n - 1, k - 1);
    quicksort2(v, 0, k - 1);

    for (int i = 0; i < k; i++)
        printf("%lld %d\n", v[i].key, v[i].value);

    return 0;
}