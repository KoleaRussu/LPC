#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#define LMAX 180
#define NMAX 20
using namespace std;

int NrCuvinte(char sir[]);
int LungimeaMaxima(char sir[]);
int CuvinteIncep(char sir[]);
int ViewFile(char nume[]);
void CopiaRezerva(char nume[]);
int NrCuvinteFile();
int CuvintePalindromeFile();
int CuvintePalindroame(char sir[]);
int CuvinteDeLungime();
int TransferLungimeaMaxima(char sir[]);
int AdaugareCuvintelorInFisier();

int main()
{
    int key;
    int nr;
    char fraza [81] = "ANA Russu lucreza cu Nicolai ROTARU, iar Maxim CAZAC - nu.";
	cout << "Project Nr.5 elaborat de Russu Nicolai"<< endl;
	cout << "Tema: ŞIRURI DE CARACTERE."<< endl;
	do{
	cout << "\n 1.Numarul de cuvinte dintr-un fraza:";
	cout << "\n 2.Cuvintele -palindrome dintro-fraza.";
	cout << "\n 3.Cuvintele de lungime cel putin 5 litere dintro fraza";
	cout << "\n 4.Numarul de cuvinte dintr-un fisier.";
	cout << "\n 5.Cuvintele - palindrome dintrun fisier";
	cout << "\n 6.Cuvintele de lungime putin 5 litere dint-un fisier";
	cout << "\n 7.De inscris  in alt fisier cuvintele de lungimi > 5 caractere";
	cout << "\n 8.De sters cuvintele de lungime  > 5 litere dentr-un fisier";
	cout << "\n 0.Stop";
	cout << "\n\n\t Alegeti (de la 0 la 8)";
        cin >> key;
        switch(key)
        {
            case 1:
                cout << "Fraza initiala \n";
                puts(fraza);
                nr = NrCuvinte(fraza);
                if (nr > 0) cout << "\nIn total " << nr << " cuvinte in fraza" << endl;
                else cout << "\nNu-s cuvinte in fraza";
            break;
            case 2:
                cout << "Fraza initiala \n";
                puts(fraza);
                nr = CuvintePalindroame(fraza);
                if (nr > 0) cout << "\n In total " << nr << " cuvinte-palindroame in fraza" << endl;
                else cout << "\nNu-s cuvinte-palindroame in fraza";
                //LungimeaMaxima(fraza);
            break;
            case 3:
                cout << "Fraza initiala \n";
                puts(fraza);
                if (NrCuvinte(fraza) != 0)
                    CuvinteIncep(fraza);
                else
                    cout << "Nu-s cuvinte";
            break;
            case 4:
                cout << "Continutul fisierului: \n";
                ViewFile("fraza1.c");
                if (NrCuvinteFile() != 0)
                    cout << "\nIn total " <<  NrCuvinteFile() << " cuvinte" << endl;
                else
                    cout << "Nu-s Cuvinte";
            break;
            case 5:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("fraza1.c");
                cout << "\nCuvinte palindrome din fisier: ";
                CuvintePalindromeFile();
            break;
            case 6:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("fraza1.c");
                cout << "\nCuvinte de lungime mai mult de cit 5 litere: ";
                CuvinteDeLungime();
            break;
            case 7:
                cout << "Fraza initiala din fisier: \n";
                ViewFile("fraza1.c");
                AdaugareCuvintelorInFisier();
            break;
            case 8:

            break;
            case 9:

            break;
        }
        fflush(stdin); // Ochistka bufera
        cout << "Apasa enter: " << getchar();
    } while(key);

    return 0;
}

int NrCuvinte(char sir[])
{
    char copia[81], *cuvint;
    int n = 0;
    strcpy(copia, sir);
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    n = 1;
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
        n++;
    return n;
}
int Palindrome(char slovo[])
{
    char periver[NMAX];
    strcpy(periver, slovo);
    strrev(periver);
    if (strcmp(periver, slovo) == 0) return 1;
    else return 0;
}
int CuvintePalindroame(char sir[])
{
    char copia[81], *cuvint;
    int n = 0;
    strcpy(copia, sir);
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    if (Palindrome(cuvint)){
        cout << setw(16) << cuvint;
        n = 1;
    }
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
       if (Palindrome(cuvint)){
        cout << setw(16) << cuvint;
        n++;
    }
    return n;
}
int LungimeaMaxima(char sir[])
{
    char copia1[81], copia2[81], *cuvint;
    int maxim = 0;
    strcpy(copia1, sir);
    strcpy(copia2, sir);
    if ((cuvint = strtok(copia1, " ,.:\n\t-")) == NULL) return 0;
    maxim = strlen(cuvint);
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
    {
        if (strlen(cuvint) >= maxim)
        {
            maxim = strlen(cuvint);
        }
    }
    cout << "Cuvintul/ele cu lungimea maxima: ";
    if ((cuvint = strtok(copia2, " ,.:\n\t-")) == NULL) return 0;
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
    {
        if(strlen(cuvint) == maxim) cout << cuvint << " ";
    }

    return 1;
}
int CuvinteIncep(char sir[])
{
    char copia[81], *cuvint;
    char litere[NMAX];
    int i = 0, val;
    cout << "Cate litere vor fi: ";
    cin >> val;
    cout << "Introduceti litere necesare:\n";
    for (i = 0; i < val; i++)
    {
        cout << "Litera " << i + 1 << " : ";
        cin >> litere[i];
    }
    strcpy(copia, sir);
    cout << "Cuvintele care incep cu o litera din intervalul dat:\n\t";
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    for (i = 0; i < val; i++)
    {
        if (cuvint[0] == litere[i])
            cout << cuvint << ", ";
    }
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
    for (i = 0; i < val; i++)
    {
        if (cuvint[0] == litere[i])
            cout << cuvint << ", ";
    }
     //cout << cuvint[0] << endl;
    return 1;
}
//-> Fisier
int ViewFile(char nume[])
{
    FILE *f;
    char fraza[LMAX];
    int nr = 0;
    f = fopen(nume, "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
        cout << fraza;
    fclose(f);

}
void CopiaRezerva(/*char nume[]*/)
{

}
int NrCuvinteFile(/*char sir[]*/)
{
    FILE *f;
    char fraza[LMAX];
    int nr = 0;
    f = fopen("fraza1.c", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
        nr += NrCuvinte(fraza);
    fclose(f);
    return nr;
}
int CuvintePalindromeFile()
{
    FILE *f;
    char fraza[LMAX], copia[LMAX], *slovo;
    f = fopen("fraza1.c", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
    {
    strcpy(copia, fraza);
    if ((slovo = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    if (Palindrome(slovo)) cout << slovo << " ";
    while ((slovo = strtok(NULL, " ,.:\n\t-")) != NULL)
    if (Palindrome(slovo)) cout << slovo << " ";
    }

    return 0;
}
int CuvinteDeLungime(/*char sir[]), char litera*/)
{
    FILE *f;
    char fraza[LMAX], copia[LMAX], *slovo;
    f = fopen("fraza1.c", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
    {
    strcpy(copia, fraza);
    if ((slovo = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    if (strlen(slovo) > 5) cout << slovo << " ";
    while ((slovo = strtok(NULL, " ,.:\n\t-")) != NULL)
    if (strlen(slovo) > 5) cout << slovo << " ";
    }
    fclose(f);
    return 0;
}
int AdaugareCuvintelorInFisier(/*char sir[]*/)
{
        FILE *f;
        FILE *s;
    char fraza[LMAX], copia[LMAX], *slovo;
    f = fopen("fraza1.c", "r");
    s = fopen("FurnituriMoldova.c", "w");
    while(fgets(fraza, LMAX-1, f) !=NULL)
    {
    strcpy(copia, fraza);
    if ((slovo = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    if (strlen(slovo) > 5) fputs(slovo, s);
    while ((slovo = strtok(NULL, " ,.:\n\t-")) != NULL) {
            fputs(" ", s);
        if (strlen(slovo) > 5) fputs(slovo, s);
    }
    }
    fclose(f);
    fclose(s);
    return 0;
}
