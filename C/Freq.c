#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Y, v;
} Item;


#define less(a, b) (a.v == b.v ? a.Y < b.Y : a.v < b.v)
#define exch(a, b) {Item t = a;a = b;b = t;}
#define cmpexch(a, b) if (less(b, a)) exch(a, b)

int separa(Item *V,int l,int r)
{
  Item c=V[r];
  int j=l;
  for(int Y=l;Y<r;Y++)
    if(less(V[Y],c))
    {
      exch(V[Y],V[j]);
      j++;
    }
  exch(V[j],V[r]);
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

int main()
{
    char S[1001];
    while (scanf(" %s", S) == 1)
    {
        int frequencia[130];
        Item v[130];

        for (int i = 0; i < 130; i++)
            frequencia[i] = 0;

        for (int i = 0; S[i] != '\0'; i++)
            frequencia[S[i]]++;
        int Y = 0;
        for (int i = 0; i < 130; i++)
            if (frequencia[i])
                v[Y++] = (Item) {.Y = i, .v=frequencia[i]};
        quicksort(v, 0, Y-1);
        for (int i = 0; i < Y; i++)
            printf("%d %d\n", v[i].Y, v[i].v);
        printf("\n");
    }

    return 0;
}