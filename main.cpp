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
    int id = 0, idUzytkownika = 0;
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
	cout << endl;
	cout << "Konto zalozone" << endl << endl;
	system("pause");

    dodajUzytkownikaDoPliku(uzytkownik);
	return iloscUzytkownikow+1;
}

int logowanie (vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
	Uzytkownik uzytkownik;
	string login = "", haslo = "";
	cout << "Podaj login: ";
	login = wczytajLinie();


	int i = 0;
	while ( i < iloscUzytkownikow )
	{
	    for (Uzytkownik uzytkownik: uzytkownicy)
        {
           if (uzytkownik.nazwa == login)
    	{

        	for (int proby = 0; proby < 3; proby++)
        	{
            	cout << "Podaj haslo. Pozostalo prob " << 3-proby << ": ";
            	haslo = wczytajLinie();
            	if (uzytkownik.haslo == haslo)
            	{
                	cout << "Zalogowales sie." << endl;
                	Sleep(1000);
                	return uzytkownik.id;
            	}
        	}
        	cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba" << endl;
        	Sleep(3000);
        	return 0;
    	}
    	i++;
        }


	}
	cout << "Nie ma uzytkownika z takim loginem" << endl;
	Sleep(1500);
	return 0;
}

int wczytajAdresatowZPliku (vector <Adresat> &adresaci, vector <Uzytkownik> &uzytkownicy)
{
    Adresat adresat;
    Uzytkownik uzytkownik;
    string linia = "", wyraz = "";
    int nrKreski = 0, ostatniNumerId = 0;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::in);

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
                    adresat.id = stoi(wyraz);
                    wyraz = "";
                    break;
                case 2:
                    adresat.idUzytkownika = stoi(wyraz);
                    wyraz = "";
                    break;
                case 3:
                    adresat.imie = wyraz;
                    wyraz = "";
                    break;
                case 4:
                    adresat.nazwisko = wyraz;
                    wyraz = "";
                    break;
                case 5:
                    adresat.numerTelefonu = wyraz;
                    wyraz = "";
                    break;
                case 6:
                    adresat.email= wyraz;
                    wyraz = "";
                    break;
                case 7:
                    adresat.adres = wyraz;
                    wyraz = "";
                    adresaci.push_back(adresat);
                    nrKreski = 0;
                    break;
                }
            }
        }
    }
    plik.close();

    return ostatniNumerId = adresat.id;
}








void dodajAdresataDoPliku (Adresat adresat)
{
    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << adresat.id << "|";
        plik << adresat.idUzytkownika << "|";
        plik << adresat.imie << "|";
        plik << adresat.nazwisko << "|";
        plik << adresat.numerTelefonu << "|";
        plik << adresat.email << "|";
        plik << adresat.adres << "|" <<endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
    plik.close();
}



int dodajAdresata (vector <Adresat> &adresaci, int numerKolejnegoId, int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    Uzytkownik uzytkownik;

    adresat.id = numerKolejnegoId + 1;
    adresat.idUzytkownika = idZalogowanegoUzytkownika;

    cout << "Wpisujesz adresatow dla uzytkownika o id:";
    cout << adresat.idUzytkownika << endl;

    cout <<"Podaj imie: ";
    adresat.imie = wczytajLinie();

    cout <<"Podaj nazwisko: ";
    adresat.nazwisko = wczytajLinie();

    cout <<"Podaj numer telefonu: ";
    adresat.numerTelefonu = wczytajLinie();

    cout <<"Podaj email: ";
    adresat.email = wczytajLinie();

    cout <<"Podaj adres: ";
    adresat.adres = wczytajLinie();

    cout << endl;
    cout << "Osoba zostala dodana" << endl;

    numerKolejnegoId++;

    adresaci.push_back(adresat);

    system("pause");

    dodajAdresataDoPliku(adresat);

    return numerKolejnegoId;
}


void wyswietlWszystkichAdresatow(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    for (Adresat adresat : adresaci)
    {
       if ( idZalogowanegoUzytkownika == adresat.idUzytkownika)
       {
        cout << setw(25)<< left <<"Id: "              << adresat.id<< endl;
        cout << setw(25)<< left <<"Imie: "            << adresat.imie<< endl;
        cout << setw(25)<< left <<"Nazwisko: "        << adresat.nazwisko << endl;
        cout << setw(25)<< left <<"Numer telefonu: "  << adresat.numerTelefonu<< endl;
        cout << setw(25)<< left <<"Email:"            << adresat.email<< endl;
        cout << setw(25)<< left <<"Adres:"            << adresat.adres<< endl << endl;

    }


    if (adresaci.size() == 0)
    {
        cout << "Plik nie zostal jeszcze stworzony" << endl << endl;
    }
    }
    system("pause");
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
                idZalogowanegoUzytkownika = logowanie (uzytkownicy, iloscUzytkownikow);
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
            cout << "---------------------" << endl;
            cout << "Twoj wybor: ";

            numerKolejnegoId = wczytajAdresatowZPliku(adresaci, uzytkownicy);


            cin >> wybor;
            if (wybor == '1')
            {
                numerKolejnegoId= dodajAdresata(adresaci, numerKolejnegoId, idZalogowanegoUzytkownika);
            }
            else if (wybor == '2')
            {
                //
            }
            else if (wybor == '3')
            {
                //
            }
            else if (wybor == '4')
            {
                wyswietlWszystkichAdresatow(adresaci, idZalogowanegoUzytkownika);
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
                idZalogowanegoUzytkownika = 0;
            }
        }

    }


}

