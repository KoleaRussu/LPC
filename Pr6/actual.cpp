#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include "Gara.h"
void Inscriere()
{
    FILE *ft, *f;
    GaraAuto gara;
    char autobuz[30];
    ft = fopen("GaraAutoDate.txt", "r");
    f = fopen("GaraAutoDate.in", "wb");
    while(fscanf(ft, "%d %s %s %d %d %d %d %d %d",
            &gara.id, &gara.Plecare, &gara.Terminus, &gara.oraplecarii.ora, &gara.oraplecarii.minuta, &gara.Durata.ora, &gara.Durata.minuta , &gara.Locuri, &gara.Pret) !=EOF)
          {
          printf("\n%s", &gara.Plecare);
          fwrite(&gara, sizeof(GaraAuto), 1 ,f);
          }
 printf("\nOK");
 fclose(ft);
 fclose(f);

}
void Linia(int st, int lin, int mij, int dr)
{
    int i;
    printf("\n%c, st");
    for (i = 1; i<=4 ; i++) printf("%c", lin); printf("%c",mij);
    for (i = 1; i<=5 ; i++) printf("%c", lin); printf("%c",mij);
    for (i = 1; i<=20 ; i++) printf("%c", lin); printf("%c",mij);
    for (i = 1; i<=10 ; i++) printf("%c", lin); printf("%c",mij);
    for (i = 1; i<=7 ; i++) printf("%c", lin); printf("%c",mij);
    for (i = 1; i<=3 ; i++) printf("%c", lin); printf("%c",mij);
    for (i = 1; i<=15 ; i++) printf("%c", lin); printf("%c",mij);
    for (i = 1; i<=5 ; i++) printf("%c", lin); printf("%c",mij);
}
void Afisare()
{
    printf("\n Lista Gara de Auto");
    Linia(201, 205, 209, 187);

}
void Adaugare()
{
    GaraAuto gara;
    FILE *f;
    int n = 0;
    f = fopen("GaraAutoDate.in", "rb");
    printf("Lista initiala a Gara de Auto");
    Linia(201,205,209,187);
    printf("\n%c Nr %c ID %2c Statia de plecare %cStatia de Termire.%c Ora de Plecare %cDurata%c %cNr de locuri%c ",
            186,179,179,179,179,179,179,179,186);
    Linia(199,196,197,182);
    while(fread(&gara, sizeof(GaraAuto), 1, f) > 0)
    {
        n++;
        printf("\n%c %2d %c %3d %c %-18.18s %c%02d.%02d.%4d%c %s %c %d %c%2d %2d %2d %2d %2d %c%5.2f%c",
               186, n, 179 gara.id, 179, gara.Plecare, 179, gara.Terminus, 179, gara.oraplecarii.ora, gara.oraplecarii.minuta, 179,
               gara.Durata.ora, gara.Durata.minuta, 179, gara.Locuri, 179, gara.Pret, 186);
    }
    Linia(201,205,209,187);
}
void Modificare()
{

}
