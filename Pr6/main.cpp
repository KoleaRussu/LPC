#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Inscriere();
void Afisare();
void Adaugare();
void Modificare();

void AranjareOras();
void AranjareOra();
void AdaugareMedie();

void Lista1();
void Lista2();
void Lista3();
void Lista4();
void Lista5();

int main()
{
    int opt;
    do
        {
        system("cls");
        cout << "Laborator Nr6 Elaborate de Russu Nicolai" << endl;
        cout << "1.  Inscriere" << endl;
        cout << "2.  Afisare" << endl;
        cout << "3.  Adaugare" << endl;
        cout << "4.  Modificare" << endl;
        cout << "5.  AranjareAlfabetica" << endl;
        cout << "6.  AranjareMedie" << endl;
        cout << "7.  AdaugareMedie"<< endl;
        cout << "8.  Lista1" << endl;
        cout << "9.  Lista2" << endl;
        cout << "10. Lista3" << endl;
        cout << "11. Lista4" << endl;
        cout << "12. Lista5" << endl;
        cout << "0.  Stop";
        cout << "\n\n\t Alegeti (de la 0 la 12) -> ";
        cin >> opt;
        switch(opt)
        {
        case 1:
            Inscriere();
            break;
        case 2:
            Afisare();
            break;
        case 3:
            Adaugare();
            break;
        case 4:
            Modificare();
            break;
        case 5:
            AranjareOras();
            break;
        case 6:
            AranjareOra();
            break;
        case 7:
            AdaugareMedie();
            break;
        case 8:
            Lista1();
            break;
        case 9:
            Lista2();
            break;
        case 10:
            Lista3();
            break;
        case 11:
            Lista4();
            break;
        case 12:
            Lista5();
            break;
        }
 getch();
    }while(opt);
return 0;
}
