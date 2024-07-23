#include <stdio.h>
#include "carte.h"

void deleteArticle()
{
    FILE *f, *g;
    CARTE c;
    int gasit, cod;
    char nume[20];
    printf("Nume fisier binar: ");
    scanf("%s", nume);
    f = fopen(nume, "rb");
    if (!f)
        printf("Fisierul %s nu a fost gasit", nume);
    else
    {
        printf("Introduceti codul produsului pe care doriti sa il stergeti: ");
        scanf("%d", &cod);
        while (!feof(stdin))
        {
            rewind(f);
            g = fopen("temp.dat", "wb");
            fread(&c, sizeof(CARTE), 1, f);
            gasit = 0;
            while (!feof(f))
            {
                if (cod == c.cod)
                {
                    gasit = 1;
                    printf("Ati sters articolul %s, din categoria %s, pret: %.2f, cantitatea: %d \n", c.nume, c.categorie, c.pret, c.cantitate);
                }
                else
                {
                    fwrite(&c, sizeof(CARTE), 1, g);
                }
                fread(&c, sizeof(CARTE), 1, f);
            }
            if (!gasit)
                printf("Articolul nu a fost gasit! \n");
            printf("Introduceti codul articolului pe care doriti sa il stergeti: ");
            scanf("%d", &cod);
            fclose(g);
        }
        fclose(f);
    }
    remove(nume);
    rename("temp.dat", nume);
}
