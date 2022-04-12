#include <iostream>
#include <string.h>
#include <cstdlib>
#include <iomanip>


int nrCuvinte (char sin[]);
int CuvintePalindrome (char sin[]);
int CuvinteLungLin (char sin[]);
int NrCuvinte();
int CuvintelePalindrome();
int CuvinteleLungLin ( char sir[]);
int TransferCuvintuluiLungLin (char sir[]);
int ElimenaCuvintuluiLungLin(char sir[]);
void ViewFile(char nume[]);
void CoplaRezerva(char nume[]);




using namespace std;

int main ()
{
int opt;
char fraza [81] = "Ana Virlan  prieteneste cu Ana CABAC, iar Colea CAZAC - nu.";
cout << "Project Nr.5 elaborat de Russu Nicolai"<< endl;
cout << "Tema: ŞIRURI DE CARACTERE."<< endl;
do{
cout << "\n 1.Numarul de cuvinte dintr-un fraza:";
cout << "\n 2.Cuvintele -palindrome dintro-fraza.";
cout << "\n 3.Cuvintele de lungime cel putin 5 litere dintro fraza";
cout << "\n 4.Numarul de cuvinte dintr-un fisier.";
cout << "\n 5.Cuvintele - palindrome dintrun fisier";
cout << "\n 6.Cuvintele de lungime putin 5 linetere dint-un fisier";
cout << "\n 7.De inscris  in alt fisier cuvintele de lungimi > 5 caractere";
cout << "\n 8.De sters cuvintele de lungime  >5 litere dentr-un fisier";
cout << "\n 9.Stop";
cout << "\n\n\t Alegeti (de la 0 la 9)";
cin >> opt;
switch(opt)
{
 case 1:
 puts("Fraza intitiala \n");
 puts(fraza);
 if (int n = nrCuvinte(fraza)) cout << "In total " << n << " cuvinte\n";
 else cout << "Nus cuvinte\n";
 break;
 case 2:
 puts("Fraza intitiala \n");
 puts(fraza);
 if (int n = CuvintePalindrome(fraza)) cout << "In total " << n << " cuvinte\n";
 else cout << "Nus cuvinte\n";
 break;
 }
 cout << " Apasa - ma"; getchar();
 fflush(stdin);
}while(opt);
return 0;
}

int nrCuvinte (char sir[])
{
char copia[81], *cuvint;
int n = 0;
strcpy(copia, sir);
if((cuvint = strtok(copia, " ,.:\n\t")) == NULL) return 0;
n = 1;
while((cuvint = strtok(NULL, " ,.:\n\t")) != NULL);
n++;

return n;
}
int CuvintePalindrome (char sir[])
{
char copia[81], *cuvint;
int n = 0;
strcpy(copia, sir);
if((cuvint = strtok(copia, " ,.:\n\t")) == NULL) return 0;
if(cuvint[0] == cuvint[strlen(cuvint)-1]) {
n++;
cout << setw(12) << cuvint;
}

while((cuvint = strtok(NULL, " ,.:\n\t")) != NULL);
if(cuvint[0] == cuvint[strlen(cuvint)-1]) {
n++;
cout << setw(12) << cuvint;
}
return n;
}
int CuvinteLungLin (char sin[])
{
return 0;
}
int NrCuvinte()
{
return 0;
}
int CuvintelePalindrome()
{
return 0;
}
int CuvinteleLungLin ( char sir[])
{
return 0;
}
int TransferCuvintuluiLungLin (char sir[])
{
return 0;
}
int ElimenaCuvintuluiLungLin(char sir[])
{
return 0;
}
void ViewFile(char nume[])
{
}
void CoplaRezerva(char nume[])
{
}
