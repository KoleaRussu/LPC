#include <iostream>
#include <stdlib.h>
#include <math.h>

#define NMAX 1500000

using namespace std;
int Pell(int n);
bool Prim(int n);
int main()

{

    int numar, jos, sus, contor, cit, n;
    cout << "Proiect Nr. 2, elaborat de Russu Nicolai" << endl;
    cout << "Tema: Numere Pell\n";
    cout << "introduceti numarul intreg: ";
    cin >> numar ;
    if (Pell(numar))
        cout << "Numarul " << numar << " este Pell" << endl;
    else
        cout << "Numarul " << numar << " nu este Pell" <<endl;

    cout << "Introduceti limitele de jos si de sus: ";
    cin >> jos >> sus;
    cout << "\n2. Numerele Pell de la " << jos << " la " << sus << endl;
    for(numar = jos, contor = 0; numar <= sus; numar++)
        if (Pell(numar))
        {
            cout << numar << " ";
            contor++;
        }
    if(contor)
        cout << "\nIn total: " << contor << " numere\n";
    else
        cout << "Nu sunt numere Pell pe interval\n";

    //3. De indicat primele n numere, care satisfac proprietatea de bază.
    cout << "Cite numere Pell: ";
    cin >> cit;
    cout << "\n3. Primele "<< cit << " numere Pell " << endl;
    for(numar = 1, contor = 0; contor < cit; numar++)
        if (Pell(numar))
        {
            cout << numar << " ";
            contor++;
        }
    if(contor)
        cout << "\nIn total: " << contor << " numere\n";
    else
        cout << "\nNu sunt numere Pell pe interval\n";

        //4. De indicat toate numerele din intervalul [a; b], care satisfac proprietatea de bază (varianta optimizată) sau care satisfac a doua proprietate.
    cout << "\n4. Numere Pelle sunt:\n";
    for(numar = jos, contor = 0; numar <= sus; numar++)
    if (Prim(numar))
       cout << Pell(numar) << endl;
    /*
        if (Prim(Pell (numar)))
        {
            cout << numar << " ";
            contor++;
        }
    if(contor)
        cout << "\nIn total: " << contor << " numere\n";
    else
                cout << "Nu sunt numere prime pe interval"; */
    //5. De determinat cel mai mare număr, care satisface condiţia indicată.
    cout << "\n5. Cel mai mare numar Pell este: ";
    for (numar = NMAX; numar > 0; numar--)
    {
        if (Pell(numar))
        {
            cout << numar << endl;
            break;
        }
    }

    return 0;
}

int Pell(int n)
{
    int a = 0;
    int b = 1;
    int s;
    s = a + b * 2;
    while(s < n)
    {
        a = b;
        b = s;
        s = a + b * 2;
    }
    return s == n;
}
bool Prim(int n)
{
    for (int i=2; i<=n/2; i++)
        if (n % i == 0) return false;
    return true;
}
