#include <stdio.h>

void main()
{   
    int n;
    int a[] = {1, 2, 3, 4, 5};
    FILE *f;
    f = fopen("test.dat","ab");
    if(!f)
    printf("error");
    else{
        while(!feof(stdin)){
            printf("Enter a numer : \n");
            scanf("%d", &n);
            fwrite(&n,sizeof(int),1,f);
        }
    }
    fclose(f);
}