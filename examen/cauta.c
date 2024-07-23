#include <stdio.h>

int cauta(float v[], int n, float val)
{
    int rez;
    if (n == 0)
        rez = -1;
    else if (v[n - 1] == val)
        rez = n - 1;
    else
        rez = cauta(v, n - 1, val);
    return rez;
}

void main()
{
}