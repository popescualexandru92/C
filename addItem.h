#include <stdio.h>
#include <string.h>
#include "carte.h"

void addFile()
{
	FILE *f;
	CARTE c;
	char nume[20];
	printf("Nume fisier binar cu produse: ");
	scanf("%s", nume);
	f = fopen(nume, "rb+");
	if (!f)
		printf("Eroare");
	else
	{	
		fseek(f, 0, 2);
		printf("Cod: ");
		scanf("%d", &c.cod);
		while (!feof(stdin))
		{
			printf("Nume: ");
			getchar();
			fgets(c.nume, sizeof(c.nume), stdin);
			size_t ln = strlen(c.nume) - 1;
			if (*c.nume && c.nume[ln] == '\n')
				c.nume[ln] = '\0';
			printf("Categorie: ");
			scanf("%s", &c.categorie);
			printf("Cantitate: ");
			scanf("%d", &c.cantitate);
			printf("Pret: ");
			scanf("%f", &c.pret);
			fwrite(&c, sizeof(CARTE), 1, f);
			printf("\nCod: ");
			scanf("%d", &c.cod);
		}
		fclose(f);
	}
}