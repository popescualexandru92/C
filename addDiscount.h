#include <stdio.h>
#include "carte.h"
#include <string.h>

void addDiscount()
{
    FILE *f;
    int i;
    CARTE c;
    char numef[20];
    float discount = 0;
    char categorie[20];
    printf("Nume fisier binar: ");
    scanf("%s", numef);
    f = fopen(numef, "rb+");
    if (!f)
        printf("Eroare");
    else
    {
        printf("Categorie: ");
        scanf("%s", &categorie);
        printf("\nDiscount: ");
        scanf("%f", &discount);
        fseek(f, 0, 0);
        fread(&c, sizeof(CARTE), 1, f);
        while (!feof(f))
        {
            if (strcmp(categorie, c.categorie) == 0)
            {
                c.pret -= (discount * c.pret / 100);
                fseek(f, ftell(f) - sizeof(CARTE), 0);
                fwrite(&c, sizeof(CARTE), 1, f);
                fseek(f, 0, 1);
                printf("%s din categoria %s cu pretul %.2f si cantitatea %d.\n", c.nume, c.categorie, c.pret, c.cantitate);
            }            
            fread(&c, sizeof(CARTE), 1, f);
        }
        fclose(f);
        printf("Discount aplicat cu succes.\n");
    }
}