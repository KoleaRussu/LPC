int Clasificare(int n, int a[], int m, int b[]); // La intrare: n - numarul de elemente, a - tabloul de note, m - numarul de clasificari; La iesire: b - tabloul nou
int Generare(int n, int a[]); // La intrare: n - numarul de elemente; La iesire: a - tabloul de note; Functia intoarce: 1 - OK; 0 - Eroare
int main()
{
    int key;
    int n = 10;
    int note[NMAX] = { 8, 1, 10, 7, 4, 5, 3, 2, 6, 9 };

    //Citire(n, note);
    cout << "Tabloul de note ocupa: " << sizeof(note) << " Bt" << endl;
    do
    {
        system("cls");
        cout << "Proiect nr.3 elaborat de Russu Nicolai" << endl;
        cout << "Tema: Notele studentilor" << endl;
        cout << "\n1. De determinat intr-un tabel de ora minima si maxima. ";
        cout << "\n2. De determinat intr-un tabel de ora media";
        cout << "\n3. De aranjat un tabel de ore in ordine crescatoare";
        cout << "\n4. De efectuat rotirea la stanga a elementelor tabelului de 7 ori";
        cout << "\n5. De adaugat date in tabelul de Ore";
        cout << "\n6. De sters date din tabelul de Ore";
        cout << "\n7. Clasificare";
        cout << "\n0. Stop";
        cout << "\n\n\t Alegeti de la 0 pana la 23 ->";
        cin >> key;
        switch(key)
        {
            case 1:
                Afisare(n, note, "initial");
                cout << "\nCea mai mica nota este: " << Minimum(n, note);
                cout << "\nCea mai mare nota este: " << Maximum(n, note);
            break;
            case 2:
                Afisare(n, note, "inital");
                cout << "\nNota medie este: " << Media(n, note);
            break;
            case 3:
                Afisare(n, note, "inital");
                Sortare(n, note);
                Afisare(n, note, "aranjat");
            break;
        }
        getch();
    } while(key);

    return 0;
}
int Citire(int n, int a[])
{
   return 1;
}
void Afisare(int n, int a[], char s[])
{
    cout << "\nTabloul de note " << s << " \n";
    for (int i = 0; i < n; i++)
        cout << setw(12) << a[i];
    cout << endl;
}
int Minimum(int n, int a[])
{
    int aux = a[0];
    if(n <= 0) return 0;
    for (int i = 1; i < n; i++)
        if(a[i] < aux) aux = a[i];
    return aux;
}
int Maximum(int n, int a[])
{
    int aux = a[0];
    if(n <= 0) return 0;
    for (int i = 1; i < n; i++)
        if(a[i] > aux) aux = a[i];
    return aux;
}
float Media(int n, int a[])
{
    int aux = 0;
    if(n <= 0) return 0;
    for (int i = 1; i < n; i++)
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
        change = false; k++;
        for (int i = 0; i < n-k; i++)
            if(a[i] < a[i+1])
            {
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                change = true;
            }
    } while(change);
    return 1;
}
int Rotire(int n, int a[])
{
    return 1;
}
int Adaugare(int *n, int a[], int val)
{
    return 1;
}
int Cautare(int n, int a[], int val)
{
    return 1;
}
int Stergere(int &n, int a[], int val)
{
    return 1;
}
int Clasificare(int n, int a[], int m, int b[])
{
    return 1;
}
int Generare(int n, int a[])
{
    return 1;
}
/*
k = 0: 5 10 8 7 6 1
k = 1: 5 8 7 6 1 10
k = 2: 5 7 6 1 8
k = 3: 5 6 1 7
k = 4: 5 1 6
k = 5: 1 5
*/
