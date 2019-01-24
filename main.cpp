#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;

string produkty[10] = {"Kajzerka        ", "Bulka z boczkiem", "Paluch z serem  ", "Pizzerka         ", "Chipsy          ", "Pepsi           ", "Kawa            ", "Woda            ", "Mirinda         ", "Riviva          "};
double cena[10] = {0.49, 1.10, 1.10, 2.20, 4.29, 1.80, 2.50, 0.69, 1.80, 2.49};
int ilosc[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
int wybor, wybor2, i, k, wybor4, produkt, dodaj, j, kup, usun;
double mamona, pln, eur, dol, zaplata;
string haslo;

int main()
{
    do
    {
        cout << fixed << setprecision(2);
        system("cls");
        cout << "Konto: " << mamona << " PLN" << endl;
        cout << "1. Dodaj pieniadze" << endl;
        cout << "2. Sprawdz produkty" << endl;
        cout << "3. Kupno" << endl;
        cout << "4. Wyjdz" << endl;
        cin >> wybor;
        if(wybor==1)
        {
            do
            {
                system("cls");
                cout << "1. PLN" << endl;
                cout << "2. EUR" << endl;
                cout << "3. $$$" << endl;
                cout << "4. Wyjdz" << endl;
                cin >> wybor2;
                if(wybor2==1)
                {
                    system("cls");
                    cout << "PLN: ";
                    cin >> pln;
                    mamona += pln;
                    system("cls");
                }
                else if(wybor2==2)
                {
                    system("cls");
                    cout << "EUR: ";
                    cin >> eur;
                    mamona += (eur * 4.29);
                    system("cls");
                }
                else if(wybor2==3)
                {
                    system("cls");
                    cout << "$$$: ";
                    cin >> dol;
                    mamona += (dol * 3.76);
                    system("cls");
                }
            }
            while(wybor2==1 || wybor2==2 || wybor2==3);
        }
        else if(wybor==2)
        {
            system("cls");
            cout << "Produkt: \t \tCena: \tIlosc: " << endl;
            for(i=0; i<10; i++)
            {
                cout << produkty[i] << "\t" << cena[i] << "\t" << ilosc[i] << endl;
            }
            getch();
        }
        else if(wybor==3)
        {
            system("cls");
            cout << "Lp. \t Ilosc: \t Produkt: " << endl;
            for(j=0; j<10; j++)
            {
                cout << j+1 << "\t " << ilosc[j] << "\t \t " << produkty[j] << endl;
            }
            cout << "Co chcesz kupic?" << endl;
            cin >> kup;
            system("cls");
            cout << "Wybrales " << produkty[kup-1] << endl;
            cout << "Ile chcesz kupic?" << endl;
            cin >> ilosc[10];
            if(ilosc[10]<=ilosc[kup-1])
            {
                zaplata = cena[kup-1] * ilosc[10];
                system("cls");
                cout << "Konto: " << mamona << endl;
                cout << "Do zaplaty: " << zaplata << endl;
                cout << "Nacisnij dowolny klawisz, aby zaplacic..." << endl;
                getch();
                system("cls");
                if(zaplata<mamona)
                {
                    cout << "Dziekujemy za zakup!";
                    mamona -= zaplata;
                    ilosc[kup-1] -= ilosc[10];
                    getch();
                }
                else
                {
                    cout << "Brak pieniedzy";
                    getch();
                }
            }
            else
            {
                system("cls");
                cout << "Brak produktu lub za duza ilosc kupna" << endl;
                getch();
            }
    }
        else if(wybor==77687)
        {
            system("cls");
            cout << "Haslo: ";
            cin >> haslo;
            if(haslo=="kajzerka")
            {
                system("cls");
                do
                {
                    cout << "1. Dodaj produkt" << endl;
                    cout << "2. Usun produkt" << endl;
                    cout << "3. Wyjdz" << endl;
                    cin >> wybor4;
                    if(wybor4==1)
                    {
                        system("cls");
                        cout << "Lp. \t Ilosc: \t Produkt: " << endl;
                        for(k=0; k<10; k++)
                        {
                            cout << k+1 << "\t " << ilosc[k] << "\t \t " << produkty[k] << endl;
                        }
                        cout << "Dodaj: ";
                        cin >> produkt;
                        system("cls");
                        cout << produkty[produkt-1] << endl;
                        cout << "Ile chcesz dodac?" << endl;
                        cin >> dodaj;
                        ilosc[produkt-1] += dodaj;
                        system("cls");
                    }
                    else if(wybor4==2)
                    {
                        system("cls");
                        cout << "Lp. \t Ilosc: \t Produkt: " << endl;
                        for(k=0; k<10; k++)
                        {
                            cout << k+1 << "\t " << ilosc[k] << "\t \t " << produkty[k] << endl;
                        }
                        cout << "Usun: ";
                        cin >> produkt;
                        system("cls");
                        cout << produkty[produkt-1] << endl;
                        cout << "Ile chcesz usunac?" << endl;
                        cin >> usun;
                        ilosc[produkt-1] -= usun;
                        system("cls");
                    }
                }
                while(wybor4!=3);
            }
        }
    }
    while(wybor!=4);
    system("cls");
}
