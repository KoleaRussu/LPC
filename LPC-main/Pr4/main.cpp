#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <conio.h>

#define NMAX 100

using namespace std;


int main ()
{
    int key;
	cout << "Project Nr.4 elaborat de Russu Nicolai"<< endl;
	cout << "Tema: Orele de sosire sau plecare a n autobuse pe m rute."<< endl;
	do{
	cout << "\n 1.De determinat intr-o matrice ora de sosire sau pleca minima si maxima si pozitiile lor.:";
	cout << "\n 2.De interschimbat 2 linii sau 2 coloane .";
	cout << "\n 3.De adaugat o linie si / sau coloana, Autobusele ce pleaca cel mai devreme";
	cout << "\n 4.De aranjat o matrice dupa linia sau coloana adaugata.";
	cout << "\n 5.De generat o matrice conform variantei.";
	cout << "\n 0.Stop";
	cout << "\n\n\t Alegeti (de la 0 la 5)";
    cin >> key;
    switch(key)
{
case 1:
cout << "Fraza initiala \n";
break;
}

}while(key);
return 0;
}


