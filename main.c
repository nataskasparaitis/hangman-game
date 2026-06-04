#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funkcijos.h"


int main()
{
    char pav[100];
    char raide[2];
    char pakar[2] = {'t'};
    FILE *fptrR;
    FILE *fptrWP;


    fptrWP = fopen("progresas.txt", "r");


    if((fscanf(fptrWP, "%s", saug.pavad)) != EOF)
    {
        fscanf(fptrWP, "%s", saug.atsakymas);
        fscanf(fptrWP, "%s", saug.spejim);
        fscanf(fptrWP, "%s", saug.spetRaid);
        fscanf(fptrWP, "%d", &saug.zodziuK);
        fscanf(fptrWP, "%d", &saug.spejimK);
        fscanf(fptrWP, "%f", &saug.taskuK);
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<10; j++)
            {
                fscanf(fptrWP, "%d ", &saug.buveSpe[i][j]);
            }
        }
        fclose(fptrWP);

        int ilgis = strlen(saug.atsakymas);

        float taskaiP = 23;
        issaugojimas(saug, fptrWP);


        saug.spejimK = spejimoEiga(raide, ilgis, &saug, fptrWP);


        taskaiP = ((taskaiP - (float)saug.spejimK) / (taskaiP - (float)ilgis)) * 100;
        saug.taskuK +=  taskaiP;
        saug.zodziuK++;


        printf("Tavo surinkti taskai - %.2f%%\n", taskaiP);

        fptrWP = fopen("progresas.txt", "w");
        fclose(fptrWP);

        issaugojimas(saug, fptrWP);

        do
        {
            printf("\nAr norite zaisti is naujo? (t/n): ");
            scanf("%s", pakar);
        }
        while((strlen(pakar) != 1) || ((pakar[0] != 't') && (pakar[0] != 'n')));

    }
    else
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<10; j++)
            {
                saug.buveSpe[i][j] = 0;
            }
        }
    }
    fclose(fptrWP);



while(pakar[0] == 't')
    {

    sunkumoLygis(pav, &fptrR, saug.pavad);

    issaugojimas(saug, fptrWP);


    if(fptrR == NULL)
    {
        printf("\nError: failas \"%s\" nerastas\n", pav);
        return -1;
    }


    atsak *ats;
    ats = (atsak *) calloc(10, sizeof(atsak));

    for(int i=0; i<10; i++)
    {
        fscanf(fptrR, "%s", ats[i].mas);
    }

    int ilgis = 0;
    int r;

    pasikartojimoTikrinimas(saug.pavad, "easy.txt", saug.buveSpe, &r, 0);
    pasikartojimoTikrinimas(saug.pavad, "medium.txt", saug.buveSpe, &r, 1);
    pasikartojimoTikrinimas(saug.pavad, "hard.txt", saug.buveSpe, &r, 2);


    ilgis = strlen(ats[r].mas);

    char* zodis = (char *) calloc(ilgis,sizeof(char));
    char* spejimas = (char *) calloc(ilgis,sizeof(char));

    strcpy(zodis, ats[r].mas);
    strcpy(saug.atsakymas, zodis);



    for(int i=0; i<ilgis; i++)
    {
       spejimas[i] = '_';
    }
    spejimas[ilgis]=0;
    strcpy(saug.spejim, spejimas);

    for(int i=0; i<23; i++)
    {
        saug.spetRaid[i] = 0;
    }



    saug.spejimK=0;
    float taskaiP = 23;

    issaugojimas(saug, fptrWP);


    saug.spejimK = spejimoEiga(raide, ilgis, &saug, fptrWP);


    taskaiP = ((taskaiP - (float)saug.spejimK) / (taskaiP - (float)ilgis)) * 100;
    saug.taskuK +=  taskaiP;
    saug.zodziuK++;


    printf("Tavo surinkti taskai - %.2f%%\n", taskaiP);
    issaugojimas(saug, fptrWP);


    fptrWP = fopen("progresas.txt", "w");
    fclose(fptrWP);

    do
    {
        printf("\nAr norite zaisti is naujo? (t/n): ");
        scanf("%s", pakar);
    }
    while((strlen(pakar) != 1) || ((pakar[0] != 't') && (pakar[0] != 'n')));

    fclose(fptrR);
    free(zodis);
    free(ats);
    free(spejimas);
    }

    printf("\n\nTavo surinktu tasku vidurkis yra: %.2f%%\n\n", saug.taskuK / (float)saug.zodziuK);

    fptrWP = fopen("progresas.txt", "w");
    fclose(fptrWP);

return 0;
}
