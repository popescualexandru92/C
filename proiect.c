#include <stdio.h>
#include "createFile.h"
#include "searchArticle.h"
#include "addItem.h"
#include "modifyArticle.h"
#include "deleteArticle.h"
#include "report.h"
#include "partialReport.h"
#include "addDiscount.h"

void main()
{
    int optiune;
    do
    {
        printf("Introduceti o optiune \n");
        printf("1. Creaza fisier; \n");
        printf("2. Adauga carte; \n");
        printf("3. Cautare carte; \n");
        printf("4. Modificare carte; \n");
        printf("5. Stergere carte; \n");
        printf("6. Generare raport; \n");
        printf("7. Generare raport partial; \n");
        printf("8. Oferta reducere; \n");
        printf("0. Iesire.\n");
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 0:
            printf("Programul a fost incheiat\n");
            break;
        case 1:
            createFile();
            break;
        case 2:
            addFile();
            break;
        case 3:
            searchArticle();
            break;
        case 4:
            modifyArticle();
            break;
        case 5:
            deleteArticle();
            break;
        case 6:
            report();
            break;
        case 7:
            partialReport();
            break;
        case 8:
            addDiscount();
            break;
        default:
            printf("introduceti o optiune valida\n");
            break;
        }
    } while (optiune != 0);
}