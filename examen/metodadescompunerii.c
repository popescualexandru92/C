#include <stdio.h>

// metoda descompunerii
int numaraPare(int x[], int ls, int ld)
{
    int nr;
    if (ls == ld)
    {
        if (x[ls] % 2 == 0)
            nr = 1;
        else
            nr = 0;
    }
    else
        nr = numaraPare(x, ls, (ls + ld) / 2) + numaraPare(x, (ls + ld) / 2 + 1, ld);
    return nr;
}

int patratePerfect(int x[], int ls, int ld)
{
    int nr=0;
    if (ls == ld)
    {
        int radacina = 0;
       
        while (radacina * radacina <= x[ls])
        {
            if (radacina * radacina == x[ls])
            {
                nr = 1;
            }
            radacina++;
        }
    }
    else
        nr = patratePerfect(x, ls, (ls + ld) / 2) + patratePerfect(x, (ls + ld) / 2 + 1, ld);
    return nr;
}

void main()
{
    int x[30];
    int n, i;
    printf("n = ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
    }
    int nr = patratePerfect(x, 0, n - 1);
    printf("Numarul de elemente pare este:%d", nr);
}