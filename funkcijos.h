#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

typedef struct atsakymai
 {
    char mas[11];
 }atsak;

 struct saugojimas
 {
     char pavad[11];
     char atsakymas[11];
     char spejim[11];
     char spetRaid[23];
     int zodziuK;
     int spejimK;
     float taskuK;
     int buveSpe[3][10];
 }saug;


 void issaugojimas(struct saugojimas saug, FILE *fptrWP);
 void sunkumoLygis(char pav[], FILE **fptrR, char kopij[]);
 void pasikartojimoTikrinimas(char pav[], char diff[], int tikrinimas[3][10], int *r, int sk);
 int spejimoEiga(char raide[], int ilgis, struct saugojimas *saug, FILE *fptrWP);


#endif // FUNKCIJOS_H_INCLUDED
