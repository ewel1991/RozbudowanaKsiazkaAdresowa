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



int main()
{
    vector <Osoba> osoby;
    vector <Uzytkownik> uzytkownicy;
    Osoba osoba;
    Uzytkownik uzytkownik;
    char wybor;
    int numerKolejnegoId = 0;




}

