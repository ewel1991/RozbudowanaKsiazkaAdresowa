#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>


using namespace std;

struct Uzytkownik
{
    int id;
    string nazwa = "", haslo = "";
};

struct Osoba
{
    int id = 0;
    string imie = "", nazwisko = "", numerTelefonu ="", email ="", adres ="";
};

char wczytajZnak()
{
    string wejscie = "";
    char znak = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}









int main()
{
    vector <Osoba> osoby;
    vector <Uzytkownik> uzytkownicy;
    Osoba osoba;
    Uzytkownik uzytkownik;
    char wybor;
    int numerKolejnegoId = 0;
    int idZalogowanegoUzytkownika = 0;

    while(1)
    {
        if(idZalogowanegoUzytkownika == 0)
        {
            system ("cls");
            cout << " >>> MENU GLOWNE <<<" << endl;
            cout << "---------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            cout << "---------------------" << endl;
            cout << "Twoj wybor: ";

            wybor = wczytajZnak();

            if (wybor == '1')
            {
                //iloscUzytkownikow = rejestracja(uzytkownicy, iloscUzytkownikow);
            }
            else if (wybor == '2')
            {
                //idZalogowanegoUzytkownika = logowanie (uzytkownicy, iloscUzytkownikow );
            }
            else if (wybor == '9')
            {
                exit(0);
            }
        }
        else
        {
            system ("cls");
            cout << ">>> KSIAZKA ADRESOWA <<<" << endl << endl;
            cout << "---------------------" << endl;
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl wszystkich adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "---------------------" << endl;
            cout << "7. Zmian haslo" << endl;
            cout << "8. Wyloguj sie" << endl;

            cin >> wybor;
            if (wybor == '1')
            {
                //zmianaHasla(uzytkownicy, iloscUzytkownikow, idZalogowanegoUzytkownika);
            }
            else if (wybor == '2')
            {
                //idZalogowanegoUzytkownika = 0;
            }
            else if (wybor == '3')
            {
                //
            }
            else if (wybor == '4')
            {
                //
            }
            else if (wybor == '5')
            {
                //
            }
            else if (wybor == '6')
            {
                //
            }
            else if (wybor == '7')
            {
                //
            }
            else if (wybor == '8')
            {
                exit(0);
            }
        }

    }


}

