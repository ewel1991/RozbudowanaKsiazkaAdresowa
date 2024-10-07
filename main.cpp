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

struct Adresat
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

string wczytajLinie()
{
    string wejscie ="";

    cin.sync();
    getline(cin, wejscie);
    return wejscie;
}

int wczytajOsobyZPlikuUzytkownicy (vector <Uzytkownik> &uzytkownicy)
{
    Uzytkownik uzytkownik;
    string linia = "", wyraz = "";
    int nrKreski = 0, ostatniNumerUzytkownika = 0;

    fstream plik;
    plik.open("Uzytkownicy.txt", ios::in);

    if (plik.good() == false)
    {
        return 0;
    }
    while (getline(plik, linia))
    {

        for (int i = 0; i < linia.length(); i++)
        {

            if (linia[i] != '|')
            {
                wyraz += linia [i];
            }

            else
            {
                nrKreski ++;


                switch (nrKreski)
                {
                case 1:
                    uzytkownik.id = stoi(wyraz);
                    wyraz = "";
                    break;
                case 2:
                    uzytkownik.nazwa = wyraz;
                    wyraz = "";
                    break;
                case 3:
                    uzytkownik.haslo = wyraz;
                    wyraz = "";
                    uzytkownicy.push_back(uzytkownik);
                    nrKreski = 0;
                    break;
                }
            }
        }
    }
    plik.close();

    return ostatniNumerUzytkownika = uzytkownik.id;
}






void dodajUzytkownikaDoPliku (Uzytkownik uzytkownik)
{
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << uzytkownik.id << "|";
        plik << uzytkownik.nazwa << "|";
        plik << uzytkownik.haslo << "|" << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
    plik.close();
}


int rejestracja (vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    string nazwa;
	Uzytkownik uzytkownik;
	cout <<"Podaj nazwe uzytkownika: ";
	nazwa = wczytajLinie();

	int i = 0;
	while ( i < iloscUzytkownikow )
	{
	    for (Uzytkownik uzytkownik: uzytkownicy)
        {
            if (uzytkownik.nazwa == nazwa)
    	{
        	cout << "Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
        	nazwa = wczytajLinie();
        	i = 0;
    	}
    	else
    	{
        	i++;
    	}
        }

	}
	uzytkownik.nazwa = nazwa;

	cout << "Podaj haslo:";
	uzytkownik.haslo = wczytajLinie();

	uzytkownik.id = iloscUzytkownikow+1;

	uzytkownicy.push_back(uzytkownik);
	cout << "Konto zalozone" << endl;
	Sleep(1000);

    dodajUzytkownikaDoPliku(uzytkownik);
	return iloscUzytkownikow+1;
}


int main()
{
    vector <Adresat> adresaci;
    vector <Uzytkownik> uzytkownicy;
    Adresat adresat;
    Uzytkownik uzytkownik;
    char wybor;
    int numerKolejnegoId = 0, iloscUzytkownikow = 0;
    int idZalogowanegoUzytkownika = 0;

    iloscUzytkownikow = wczytajOsobyZPlikuUzytkownicy(uzytkownicy);


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
                iloscUzytkownikow = rejestracja(uzytkownicy, iloscUzytkownikow);
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

