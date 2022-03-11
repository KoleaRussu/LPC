#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <conio.h>
#include <fstream>


#define NMAX 23

using namespace std;
//interfata programului
int Citire(int n, int a[]);//la intrare n - numarul de elemente; la iesire: a- tabloul de virste; functia intoarce: 1 - ok, 0- error
void Afisare(int n, int a[],char s[]);//la intrare n - numarul de elemente, a- tabloul de virste
int Minimum(int n, int a[]);//la intrare n - numarul de elemente, a- tabloul de virste; la iesire valoarea minima
int Maximum(int n, int a[]);//la intrare n - numarul de elemente, a- tabloul de virste; la iesire valoarea maxima
float Media(int n, int a[]);// la intrare n - numarul de elemente, a- tabloul de virste; la iesire ora medie
int Sortare(int n, int a[]);//la intrare n - numarul de elemente, a- tabloul de virste;  la iesire a- tabloul aranjat functia intoarce: 1 - ok, 0- error
int Rotire(int n, int a[]);//la intrare n - numarul de elemente, a- tabloul de virste;  la iesire a- tabloul rotit functia intoarce: 1 - ok, 0- error
int Adaugare(int &n, int a[], int val); // la intrare n - numarul de elemente, a- tabloul de virste, val - elementul adaugat; la iesire n- se mareste cu 1 a- tablou
int Adaugare(int &n, int a[], int val, char);
int Adaugare(int &n, int a[], int val, int p);//inainte de p- pozitia
int Adaugare(int &n, int a[], int val, int p, char);// dupa p
int Cautare(int n, int a[], int val );//la iesire p- pozitia sau -1
int Stergere(int &n, int a[], int val); // la intrare n - numarul de elemente, a- tabloul de virste, val - elementul adaugat; la iesire n- se scade cu 1 a- tablou
int Clasificare(int n, int a[], int m, int b[] ); // la intrare n - numarul de elemente, a- tabloul de virste, m - nuumarul de clasificari adaugat; la iesire n- mareste cu 1 b- tablou nou
int Generare(int n, int a[]); // la intrare n - numarul de elemente, a- tabloul de virste, val - elementul adaugat; la iesire n- mareste cu 1 a- tablou


int main()
{
    int key, adaugare, valarea, poz;
    int n = 23;
    int ncaut;
    int ora[NMAX]= {10, 19, 13, 21, 15, 14, 7, 5, 4, 12};
    do
    {
         cout << "Introduceti cite ore sunt in tabel: " ;
         cin >> n ;
         Citire (n, ora);
    }while (n <= 0);
    cout << "Tabloul de ora ocupa: " << sizeof(ora) << " Bt" << endl;
    do
    {
        system("cls");
        cout << "Proiect nr.3 elaborat de Russu Nicolai" << endl;
        cout << "Tema: Notele studentilor" << endl;
        cout << "\n1. De determinat intr-un tabel de ora minima si maxima. ";
        cout << "\n2. De determinat intr-un tabel de ora media";
        cout << "\n3. De aranjat un tabel de ora in ordine crescatoare";
        cout << "\n4. De efectuat rotirea la stanga a elementelor tabelului de 7 ori";
        cout << "\n5. De adaugat date in tabelul de Ore";
        cout << "\n6. De sters date din tabelul de Ore";
        cout << "\n7. Clasificare";
        cout << "\n0. Stop";
        cout << "\n\n\t Alegeti de la 0 pana la 8 ->";
        cin >> key;
switch(key)
        {
        case 1:
            Afisare(n, ora, "initial");
            cout << "\nCea mai mica ora este: " << Minimum(n, ora);
            cout << "\nCea mai mare ora este: " << Maximum(n, ora);
            break;
        case 2:
            Afisare(n, ora, "initial");
            cout << "\n ora medie este: " << Media(n, ora);
            break;
        case 3:
            Afisare(n, ora, "inital");
            Sortare(n, ora);
            Afisare(n, ora, "aranjat");
            break;
        case 4:
            Afisare(n, ora, "inital");
            Rotire(n, ora);
            Afisare(n, ora, "rotit");
            break;
       case 5:
            do
            {

                cout << "Care valeare va fi adaugata: ";
                cin >> valarea;
            }   while(valarea < 0 || valarea > 23);
            do
            {
              cout <<"Elemeti va fi adaugati: ";
              cout <<"\n1. La inceput";
              cout <<"\n2. La caut";
              cout <<"\n3. Inainte de pozitia";
              cout <<"\n4. Dupa pozitia";
              cin >> adaugare;
            }while(adaugare > 4 || adaugare < 1);
            Afisare(n, ora, "inital");
            switch(adaugare)
            {
            case 1:
                Adaugare(n, ora, valarea);
            break;
            case 2:
                Adaugare(n, ora, valarea, 'N');
            break;
            case 3:
                do
                {
                    cout << "Scrieti pozitia necesara";
                    cin >> poz;
                } while (poz > n-1);
                Adaugare (n, ora ,valarea, poz);
            break;
            case 4:
                do
                {
                    cout <<"Scrieti pozitia necesara: " ;
                    cin >> poz;
                }while (poz > n-1);
                Adaugare(n, ora, valarea , poz, 'N');
                break;
            }
        case 6:
            cout << "\n Introduceti ce valoare trebuie de sters: ";
            cin >> ncaut;
            /*if ((val = Cautare(n, ora, ncaut)) != -1)
            Stergere(n, ora, Cautare(n, ora, ncaut));
            Afisare(n, ora, "sters");
            break;*/
        }
        getch();
    }
    while(key);
    return 0;
}
int Citire(int n, int a[])
{
    int key;
    int i;
        cout << "\n1. De la trastatura";
        cout << "\n2. De generat aleator";
        cout << "\n3. De generat intr-un mod special";
        cout << "\n4. Din fisier";
        cout << "\n5; Inplicit";
        cout << "\n\n\t Alege ->" ;
        cin >> key;
        switch(key){
    case 1:
    for ( i = 0; i < n; i++)
    do{
        cout << "Ore plecarii" << i+1 << ": " ;
        cin >> a[i];
    }while(a[i] < 0 || a[i] > 23);
    break;
    case 2:
        for ( i = 0; i < n; i++)
            a[i] = rand() % 23 + 0;
        break;
    case 3:
        for ( i = 0; i < n; i++)
            a[i] = i % 3 + 12;
        break;
    case 4:

        break;
        }
    return 1;
    /*if (n == 0)
        return 0;
    for (int i = 0; i < n; i++)
    {
        cout << i << "ora: " ;
        cin >> a[i];
    } */

}
void Afisare(int n, int a[],char s[])
{
    cout << "Tabloul de ora " << s << " \n";
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}
int Minimum(int n, int a[])
{
    int aux = a[0];
    for (int i = 1; 1 < n; i++)
        if (a[i] < aux) aux = a[i];
    return aux;
}
int Maximum(int n, int a[])
{
    int aux = a[0];
    for (int i = 1; 1 < n; i++)
        if (a[i] > aux) aux = a[i];
    return aux;
}
float Media(int n, int a[])
{
    int aux = 0;
    if (n <= 0) return 0;
    for (int i = 1; 1 < n; i++)
        aux += a[i];
    aux /= n;
    return aux;
}
int Sortare(int n, int a[])
{
    int k = 0, aux;
    bool change;
    do
    {
        change = false;
        k++;
        for (int i = 0; i < n-k; i++)
            if(a[i] < a[i+1])
            {
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                change = true;
            }
    }
    while(change);
    return 1;
}
int Rotire(int n, int a[])
{
    //1
    /*for (int j = 0; j < 3; j++)
    {
        int temp = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = temp;
    }*/
    //2
     int i, b[NMAX];
    for ( i = 0; i < 7; i++ )
        b[i] = a[i];
    for( i = 7; i < n; i++)
        a[i-7]=a[i];
    for ( i = n - 7; i < n ; i++)
        a[i]=b[i- n + 7 ];
    return 1;
}
//1 2 3 4 5 6
//4 5 6 1 2 3
int Adaugare(int &n, int a[], int val)//la inceput
{
        for (int i = n; i > 0 ; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = val;
        n++;
}
int Adaugare(int &n, int a[], int val, char)//la capat
{
        a[n++] = val;
}
int Adaugare(int &n, int a[], int val, int p)//la inceput
{
        for (int i = n; i > 0 ; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = val;
        n++;
}
int Adaugare(int &n, int a[], int val, int p, char)//la inceput
{
        for (int i = n; i > 0 ; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = val;
        n++;
}

/*initial: 1 2 3 4 5 6
final: a) 1 2 3 4 5 6 10 la sfirsit
b) 10 1 2 3 4 5 6 la inceput
c) 1 2 10 3 4 5 6 innainte de 3
d) 1 2 3 10 4 5 6 dupa 3*/
int Cautare(int n, int a[], int val )
{
    for ( int i = 0; i <= n; i++)
    {
        if (a[i] == val )
            return i;
    }
    return -1 ;
}
int Stergere(int &n, int a[], int val)
{
    if (val != -1)
    {
        for (int i = val; i <= n; i++)
        {
            a[i] = a[i+1];
        }
    }
    n--;
    return 1;
}
int Clasificare(int n, int a[], int m, int b[] )
{
    int i,j ;
    int limite[] = [3 , 4, ,6 ,12 ,15 ,16];
    char vreame[][23] = ("ziua", "dimeneata", "seara", "noaptea");
    int catagorii[] = [0 , 0, 0, 0];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; i++)
            if(a[i]<= limite[j])
        {
            categorii[j]++;
            break;
        }
    return 1;
}
int Generare(int n, int a[])
{
    return 1;
}

