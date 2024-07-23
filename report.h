#include <stdio.h>
#include "carte.h"

void report(){
	FILE *f;
	FILE *g;
	CARTE c;
	char numef[20];
	char numeg[20];
	printf("Nume fisier binar: ");
	scanf("%s", numef);
	f = fopen(numef, "rb");
	if (!f)
		printf("Eroare");
	else
	{
		printf("Nume raport: ");
		scanf("%s", numeg);
		g = fopen(numeg, "w");
		fprintf(g, "Cod    Nume produs                    Categorie         Cantitate 		Pret\n");
		fread(&c, sizeof(CARTE), 1, f);
		while (!feof(f))
		{
			fprintf(g, "%-6d %-30s %-20s %6d %10.2f\n", c.cod, c.nume, c.categorie, c.cantitate, c.pret);
			fread(&c, sizeof(CARTE), 1, f);
		}
		fclose(f);
		fclose(g);
	}
}