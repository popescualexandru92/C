#include <stdio.h>

void printVector(int vector[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int no_of_negatives(int vector[], int n)
{
    int nr;
    if (n == 0)
    {
        nr = 0;
    }
    else
    {
        nr = no_of_negatives(vector, n - 1);
        nr += (vector[n - 1] < 0) ? 1 : 0;
    }
    return nr;
}

int scalar(int v1[], int v2[], int size)
{
    int nr;
    if (size == 0)
    {
        nr = 0;
    }
    else
    {
        nr = scalar(v1, v2, size - 1);
        nr = nr + (v1[size - 1] * v2[size - 1]);
    }
    return nr;
}

int cmmmdc(int a, int b)
{
    int c;
    if (a % b == 0)
        return b;
    else
        return cmmmdc(b, a % b);
}

int main()
{

    int vector[] = {-1, 2, 2};

    int size = sizeof(vector) / sizeof(vector[0]);
    int rez = scalar(vector, vector, size);
    printf("%d", cmmmdc(40, 25));

    return 0;
}
