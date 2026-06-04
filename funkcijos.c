#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funkcijos.h"


void issaugojimas(struct saugojimas saug, FILE *fptrWP)
{
    fptrWP = fopen("progresas.txt", "w+");
    fprintf(fptrWP, "%s\n", saug.pavad);
    fprintf(fptrWP, "%s\n", saug.atsakymas);
    fprintf(fptrWP, "%s\n", saug.spejim);
    fprintf(fptrWP, "%s\n", saug.spetRaid);
    fprintf(fptrWP, "%d\n", saug.zodziuK);
    fprintf(fptrWP, "%d\n", saug.spejimK);
    fprintf(fptrWP, "%f\n", saug.taskuK);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<10; j++)
        {
            fprintf(fptrWP, "%d ", saug.buveSpe[i][j]);
        }
        fprintf(fptrWP, "\n");
    }
    fclose(fptrWP);
}


void sunkumoLygis(char pav[], FILE **fptrR, char kopij[])
{
    printf("\n////////////////////////////\n");
    printf("\neasy - iki 5 raidziu\n");
    printf("medium - nuo 6 iki 8 raidziu\n");
    printf("hard - 8 raides ir daugiau\n");
    printf("\n////////////////////////////\n");
    printf("\nPasirinkite zaidimo sunkumo lygi (easy,medium,hard): ");
    scanf("%s", pav);

    strcpy(kopij, pav);
    strcat(kopij, ".txt");

    *fptrR = fopen(kopij, "r");
}


void pasikartojimoTikrinimas(char pav[], char diff[], int tikrinimas[3][10], int *r, int sk)
{
    if(strcmp(pav, diff) == 0)
    {
    do
        {
            srand(time(NULL));
            *r = rand()%10;
        }
    while(tikrinimas[sk][*r] != 0);
    tikrinimas[sk][*r] = 1;
    }
}


int spejimoEiga(char raide[], int ilgis, struct saugojimas *saug, FILE *fptrWP)
{
    while(strcmp(saug->spejim, saug->atsakymas) != 0)
    {
        int t = saug->spejimK;
        printf("\n%s\n", saug->spejim);
        printf("spek raide: ");
        scanf("%s", raide);

        while(strlen(raide) != 1)
        {
            printf("irasykite 1 raide: ");
            scanf("\n%s", raide);
        }


        while(strchr(saug->spetRaid, raide[0]) != NULL)
        {
            printf("\njau spejote sia raide: %c\n", raide[0]);
            printf("spekite is naujo: ");
            scanf("\n%s", raide);

            while(strlen(raide) != 1)
            {
                printf("irasykite 1 raide: ");
                scanf("\n%s", raide);
            }
        }

        saug->spetRaid[t] = raide[0];

        for(int i=0; i<ilgis; i++)
        {
            if(raide[0] == saug->atsakymas[i])
            {
                saug->spejim[i] = raide[0];
            }
        }
        saug->spejimK++;
        issaugojimas(*saug, fptrWP);
    }
    printf("\n%s\n\n", saug->spejim);

    return saug->spejimK;
}
