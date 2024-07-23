#include <stdio.h>
#include "carte.h"

void searchArticle()
{
	FILE *f;
	CARTE c;
	char nume[20];
	printf("Nume fisier binar: ");
	scanf("%s", nume);
	int cod;
	f = fopen(nume, "rb");
	if (!f)
		printf("Eroare");
	else
	{
		printf("Cod: ");
		scanf("%d", &cod);
		while (!feof(stdin))
		{
			fseek(f, 0, 0);
			int gasit = 0;
			fread(&c, sizeof(CARTE), 1, f);
			while (!feof(f) && gasit == 0)
			{
				if (cod == c.cod)
				{
					gasit = 1;
					printf("%s din catergoria %s cu pretul %f si cantitatea %d \n", c.nume, c.categorie, c.pret, c.cantitate);
				}
				fread(&c, sizeof(CARTE), 1, f);
			}
			if (gasit == 0)
				printf("Produsul nu a fost gasit\n");
			printf("Cod: ");
			scanf("%d", &cod);
		}
		fclose(f);
	}
}