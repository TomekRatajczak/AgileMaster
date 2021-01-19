#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <algorithm>

using namespace std;

string list_name;
string item;
string new_value;
fstream plik;
int row_number;
int ilosc;
int* tab;

char wybor;
bool wyjscie;
bool zmiana;
bool mainMenu;
bool boardMenu;

void welcome() 
{
    cout << endl;
    cout << "#######################################################################################################################" << endl;
    cout << "#######################################################################################################################" << endl;
    cout << "##########      ####     ####  ##  #######      #############   ###    ###      ####     ##        ##      ##      ####" << endl;
    cout << "########  ####  ##  ####  ##  ##  #######  #################  # #  #  ##  ####  ##  #########  #####  ######  ###  ####" << endl;
    cout << "#######  ####  ##  ########  ##  #######     ##############  ##  ##  ##  ####  ##  #########  #####     ###  ###  #####" << endl;
    cout << "######        ##  ##    ##  ##  #######  #################  ######  ##        ###    ######  #####  ######      #######" << endl;
    cout << "#####  ####  ##  ####  ##  ##  #######  #################  ######  ##  ####  ######  #####  #####  ######  ##  ########" << endl;
    cout << "####  ####  ###      ###  ##       ##      #############  ######  ##  ####  ##     ######  #####      ##  ####  #######" << endl;
    cout << "#######################################################################################################################" << endl;
    cout << "############################################################################################  By Tomasz Ratajczak  ####"  << endl;
    cout << endl;
}

void primMenu()
{
    cout << endl << endl << endl;
    cout << "      ------------------------------------------------------------------------------------------------------------" << endl;
    cout << "      ---------------------------------------------   Menu Glowne  -----------------------------------------------" << endl;
    cout << endl;
    cout << "      [1] Dodaj nowy projekt                [3] Czym jest Agile?                      [0] Wyjscie z programu" << endl;
    cout << endl;
    cout << "      [2] Wczytaj istniejacy projekt        [4] Pomoc" << endl;
    cout << endl;
    cout << "      ------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void listMenu()
{
    cout << "      ------------------------------------------------------------------------------------------------------------" << endl;
    cout << "      -------------------------------------------------  Menu  ---------------------------------------------------" << endl;
    cout << endl;
    cout << "      [Edycja listy]                        [Stan zadania]                            [Nawigacja]" << endl;
    cout << endl;
    cout << "      [1] Dodaj nowe zadanie                [5] Przenies do [BACKLOG ]                [9] Powroc do Menu Glownego" << endl;
    cout << "      [2] Usun zadanie                      [6] Przenies do [SPRINT  ]                [0] Wyjscie z programu"      << endl;
    cout << "      [3] Edytuj zadanie                    [7] Przenies do [REVIEW  ]" << endl;
    cout << "      [4] Usun ten projekt                  [8] Przenies do [PRZyROST]" << endl;
    cout << endl;
    cout << "      ------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void aboutAgille() {
    cout << endl;
    cout << "      ------------------------------------------------------------------------------------------------------------" << endl;
    cout << "      ------------------------------------------   Czym jest Agille?  --------------------------------------------" << endl;
    cout << endl;
    cout << "Agile to dynamiczne podejscie do zarzadzania projektami i tworzenia oprogramowania, ktore pomaga" << endl;
    cout << "zespolom szybciej i bez zbednego wysilku dostarczac wartosc swoim klientom. Zamiast stawiac wszystko" << endl;
    cout << "na „wielkie bum”, zespol agile wykonuje pracę w malych, ale wydajnych etapach. Wymagania, plany i" << endl;
    cout << "wyniki sa oceniane w sposób ciagly, dzieki czemu zespoly maja naturalny mechanizm szybkiego" << endl;
    cout << "reagowania na zmiany. " << endl;
    cout << endl;
    cout << "Agile to filozofia podejscia do zarzadzania projektami a nasz projekt oparlismy o metodyke SCRUM..." << endl;
    cout << endl;
    cout << "Scrum to jedna z najpopularniejszych metodyk zwinnych w zarzadzaniu projektami IT, oparta na zasadach " << endl;
    cout << "podejscia zwinnego. To metodyka, ktora daje mozliwosci rozwiazywania zlozonych problemow, adaptacji produktu, " << endl;
    cout << "do wymagań klienta. Scrum umozliwia wydajne i innowacyjne kreowanie produktu, o mozliwie jak najwywszej " << endl;
    cout << "jakosci dla klienta, ze wzgledu na iteracyjny (przyrostowy) proces kontroli." << endl;
    cout << endl;
    cout << "Przebieg zarzadzania projektem w metodyce SCRUM" << endl;
    cout << endl;
    cout << "1.Tworzymy nowy projekt 😉" << endl;
    cout << "2.Nowe zadanie - wszystkie idee, pomysly i funkcjinalnosci laduja w tablicy jako nowe zadania" << endl;
    cout << "3.[BACKLOG ] - to tablica istotnych elementow dla projektu, wybranych z kroku poprzedniego" << endl;
    cout << "4.[SPRINT  ] - to proces wdrazania pojedynczego zadania z listy BACKLOG-ów. Trwa zawsze okreslony okres czasu" << endl;
    cout << "5.[REVIEW  ] - to element wienczacy kazdy sprint. Polega na podsumowaniu i prezentacji wynikow pracy w sprincie" << endl;
    cout << "6.[PRZYROST] - to implementacja noewego produktu zaakceptowanego po procesie REVIEW" << endl;
    cout << "7.Kazdy element wytworzony w pojedynczym SPRINT-cie moze zostac zaakceptowany, oddany do ponownego SPRINTu," << endl;
    cout << "aby go poprawic lub oddany do BACKLOGu aby zajac sie nim pozniej. W ostatecznosci zadanie moze zosac usuniete" << endl;
    cout << "8. Proces wytwarzania projektu konczy sie w momecie w ktorym wszystkie zadania z BACKLOGu znajda sie w PRZYROST-cie" << endl;
    cout << endl;
    cout << "Powodzenia!" << endl;
    cout << "i pozostan zwinny 😉" << endl;
}

void aboutHelp()
{
    cout << endl;
    cout << "      ------------------------------------------------------------------------------------------------------------" << endl;
    cout << "      ------------------------------------------------   Pomoc  --------------------------------------------------" << endl;
    cout << endl;
    cout << "1. Sterowanie programem" << endl;
    cout << endl;
    cout << "Menu Glowne i Menu projektu - wybieramy wszystkie opcje za pomoca przyciskow numerycznych klawiatury 0 - 9." << endl;
    cout << endl;
    cout << "Wprowadzanie tresci - wpisujemy za pomoca klawiatury tresci jakie maja byc przetworzone przez program i nastepnie" << endl;
    cout << "zatwierdzamy je przyciskiem ENTER" << endl;
    cout << endl;
    cout << "+-------------+" << endl;
    cout << "!    UWAGA!   ! aby program nie generowal 'KRZACZKOW' w miejsce liter, wszystkie znaki wprowadzamy bez polskich ogonkow." << endl;
    cout << "+-------------+" << endl;
}

void wait()
{
    Sleep(3000);
}
void waitErr()
{
    Sleep(1000);
}

bool fileExists(string filename)
{
    filename += ".txt";
    bool result = false;
    ifstream ifile(filename);
    if (ifile) {
        result = true;
    }
    ifile.close();
    return result;
}

void showList() {
    cout << endl;
    cout << "Projekt: " << list_name << endl;
    cout << "---------------------------" << endl;
    cout << "lp. Nazwa zadania" << endl;
    cout << "---------------------------" << endl;
    string line;
    int nr = 1;
    ifstream in(list_name + ".txt", ios::in);
    if (in.good() == false)
    {
        cout << "Cos poszlo nie tak" << endl;
        in.close();
        wait();

    }
    while (getline(in, line)) {
        cout << nr << "." << " " << line << endl;
        nr++;
    }
    plik.close();
    cout << "---------------------------" << endl;
    cout << endl;
}

void showText(string path) {
    string line;
    ifstream in(path, ios::in);
    if (plik.good() == false)
    {
        cout << "Cos poszlo nie tak" << endl;
        in.close();
        wait();

    }
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
    cout << endl;
}

int rowNumber() {
    string line;
    int count = 0;
    ifstream f(list_name + ".txt");
    while (getline(f, line))
        count++;
    return count;
}

void deleteRow(size_t row_number)
{
    vector < string > vec;
    ifstream in(list_name + ".txt");
    string tmp;
    while (getline(in, tmp)) vec.push_back(tmp);
    in.close();

    ofstream out(list_name + ".txt");
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i + 1 != row_number) out << vec[i] << endl;
    }
    out.close();
}

void changeRow(string new_value, size_t row_number)
{
    vector < string > vec;
    ifstream in(list_name + ".txt");
    string tmp;
    int index = 1;
    while (getline(in, tmp)) {
        if (index != row_number)
        {
            vec.push_back(tmp);
        }
        else vec.push_back(new_value);
        index++;
    }

    in.close();
    ofstream out(list_name + ".txt");
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i + 1 != row_number) out << vec[i] << endl;
        else out << vec[i] << endl;
    }
    out.close();
}

void changeType(string new_value, size_t row_number)
{
    vector < string > vec;
    ifstream in(list_name + ".txt");
    string tmp;
    while (getline(in, tmp)) vec.push_back(tmp);
    in.close();

    in.close();
    ofstream out(list_name + ".txt");
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i + 1 != row_number) out << vec[i] << endl;
        else
        {
            if (vec[i].compare(0, 1, "[") == 0)
            {
                vec[i].erase(0, 11);
            }
            out << new_value << " " << vec[i] << endl;
        }
    }
    out.close();
}

void secMenu() 
{
    do
    {

        system("cls");

        boardMenu = false;

        listMenu();

        showList();

        wybor = _getch();

        switch (wybor)
        {
        case '1':
            cout << "Wpisz ile chcesz dodac elementow: ";
            cin >> ilosc;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(50, '\n');
                cout << "Nie podales liczby\nWprowadz ponownie liczbe: ";
                cin >> ilosc;
            }
            cin.ignore();

            for (int i = 0; i < ilosc; i++) {
                cout << "Wpisz nazwe zadania: ";
                cin.sync();
                getline(cin, item);
                plik.open(list_name + ".txt", ios::app);
                plik << item << endl;
                plik.close();
            }
            cout << endl;
            cout << "Zapisuje zmiany...";
            wait();
            break;
        case '2':
            zmiana = false;

            if (!ifstream(list_name + ".txt", ios::ate).tellg()) {
                cout << endl;
                cout << "Ten projekt jest pusty wiec nie mozesz wykonac tej operacji" << endl;
                wait();
                ifstream close();
                break;
            }
            else
            {
                do {
                    cout << "Wpisz numer zadania do usuniecia: ";
                    cin >> row_number;
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "Nie podales liczby\nWprowadz ponownie liczbe: ";
                        cin >> row_number;
                    }
                    if (row_number > rowNumber()) {
                        cout << "Twoja lista nie posiada tylu zadan" << endl;
                        cout << "Sprobuj ponownie..." << endl << endl;
                    }
                    else
                        zmiana = true;
                } while (!zmiana);
                cin.ignore();
                deleteRow(row_number);
                cout << endl;
                cout << "Zapisuje zmiany...";
                wait();
                break;
            }
        case '3':
            zmiana = false;
            if (!ifstream(list_name + ".txt", ios::ate).tellg()) {
                cout << endl;
                cout << "Ten projekt jest pusty wiec nie mozesz wykonac tej operacji" << endl;
                wait();
                ifstream close();
                break;
            }
            else
            {
                do {
                    cout << "Wpisz numer zadania do poprawy: ";
                    cin >> row_number;
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "Nie podales liczby\nWprowadz ponownie liczbe: ";
                        cin >> row_number;
                    }
                    if (row_number > rowNumber()) {
                        cout << "Twoja lista nie posiada tylu zadan" << endl;
                        cout << "Sprobuj ponownie..." << endl << endl;
                    }
                    else
                        zmiana = true;
                } while (!zmiana);
                cout << "Wpisz nowa wartosc: ";
                cin.ignore();
                getline(cin, new_value);
                changeRow(new_value, row_number);
                cout << endl;
                cout << "Zapisuje zmiany...";
                wait();
                break;
            }
        case '4':
            cout << "Czy na pewno chcesz usunac ten projekt?" << endl;
            cout << "[1] Tak" << endl;
            cout << "[2] Nie" << endl;
            cout << endl;
            wybor = _getch();
            switch (wybor)
            {
            case '1':
                if (remove((list_name + ".txt").c_str()) == 0)
                {
                    cout << "Usuwam projekt " << list_name << endl << endl;
                    wait();
                    cout << "Usunieto pomyslnie." << endl;
                    wait();
                    boardMenu = true;
                }
                else
                {
                    cout << "Nie udalo sie skasowac pliku." << endl;
                    waitErr();
                    wybor;
                }
                break;
            case '2':
                cout << "Uff... malo brakowalo" << endl;
                wait();
                wybor;
                break;
            default:
                cout << "Bledna wartosc" << endl;
                waitErr();
                break;
            }
            break;
        case '5':
            zmiana = false;
            if (!ifstream(list_name + ".txt", ios::ate).tellg()) {
                cout << endl;
                cout << "Ten projekt jest pusty wiec nie mozesz wykonac tej operacji" << endl;
                wait();
                ifstream close();
                break;
            }
            else
            {
                do {
                    cout << "Wpisz numer zadania do przeniesienia: ";
                    cin >> row_number;
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "Nie podales liczby\nWprowadz ponownie liczbe: ";
                        cin >> row_number;
                    }
                    if (row_number > rowNumber()) {
                        cout << "Twoja lista nie posiada tylu zadan" << endl;
                        cout << "Sprobuj ponownie..." << endl << endl;
                    }
                    else
                        zmiana = true;
                } while (!zmiana);
                changeType("[BACKLOG ]", row_number);
                cout << endl;
                cout << "Zapisuje zmiany...";
                wait();
                break;
            }
        case '6':
            zmiana = false;
            if (!ifstream(list_name + ".txt", ios::ate).tellg()) {
                cout << endl;
                cout << "Ten projekt jest pusty wiec nie mozesz wykonac tej operacji" << endl;
                wait();
                ifstream close();
                break;
            }
            else
            {
                do {
                    cout << "Wpisz numer zadania do przeniesienia: ";
                    cin >> row_number;
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "Nie podales liczby\nWprowadz ponownie liczbe: ";
                        cin >> row_number;
                    }
                    if (row_number > rowNumber()) {
                        cout << "Twoja lista nie posiada tylu zadan" << endl;
                        cout << "Sprobuj ponownie..." << endl << endl;
                    }
                    else
                        zmiana = true;
                } while (!zmiana);
                changeType("[SPRINT  ]", row_number);
                cout << endl;
                cout << "Zapisuje zmiany...";
                wait();
                break;
            }
        case '7':
            zmiana = false;
            if (!ifstream(list_name + ".txt", ios::ate).tellg()) {
                cout << endl;
                cout << "Ten projekt jest pusty wiec nie mozesz wykonac tej operacji" << endl;
                wait();
                ifstream close();
                break;
            }
            else
            {
                do {
                    cout << "Wpisz numer zadania do przeniesienia: ";
                    cin >> row_number;
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "Nie podales liczby\nWprowadz ponownie liczbe: ";
                        cin >> row_number;
                    }
                    if (row_number > rowNumber()) {
                        cout << "Twoja lista nie posiada tylu zadan" << endl;
                        cout << "Sprobuj ponownie..." << endl << endl;
                    }
                    else
                        zmiana = true;
                } while (!zmiana);
                changeType("[REVIEW  ]", row_number);
                cout << endl;
                cout << "Zapisuje zmiany...";
                wait();
                break;
            }
        case '8':
            zmiana = false;
            if (!ifstream(list_name + ".txt", ios::ate).tellg()) {
                cout << endl;
                cout << "Ten projekt jest pusty wiec nie mozesz wykonac tej operacji" << endl;
                wait();
                ifstream close();
                break;
            }
            else
            {
                do {
                    cout << "Wpisz numer zadania do przeniesienia: ";
                    cin >> row_number;
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "Nie podales liczby\nWprowadz ponownie liczbe: ";
                        cin >> row_number;
                    }
                    if (row_number > rowNumber()) {
                        cout << "Twoja lista nie posiada tylu zadan" << endl;
                        cout << "Sprobuj ponownie..." << endl << endl;
                    }
                    else
                        zmiana = true;
                } while (!zmiana);
                changeType("[PRZYROST]", row_number);
                cout << endl;
                cout << "Zapisuje zmiany...";
                wait();
                break;
            }
        case '9':
            boardMenu = true;
            break;
        case '0':
            exit(0);
            break;
        default:
            cout << "Bledna wartosc" << endl;
            waitErr();
            break;
        }
    } while (!boardMenu);
}

int main()
{
    for (;;)
    {
        do {
            system("cls");
            mainMenu = false;

            welcome();
            primMenu();

            wybor = _getch();
            switch (wybor)
            {
            case '1':
                cout << "Podaj nazwe projektu: ";
                getline(cin, list_name);
                cout << endl;
                cout << "Czekaj, sprawdzam..." << endl;
                cout << endl;
                wait();

                if (fileExists(list_name) == true)
                {
                    cout << "Podany projekt juz istnieje! Wczytaj projekt lub wybierz inna nazwe." << endl;
                    Sleep(2000);
                    break;
                }
                else
                {
                    plik.open(list_name + ".txt", ios::out);
                    plik.close();
                    cout << "Tworze nowy projekt...";
                    wait();
                }

                secMenu();

                break;
            case '2':
                cout << "Podaj nazwe projektu: ";
                cin >> list_name;
                cout << endl;

                if (fileExists(list_name) == false)
                {
                    cout << "Wczytuje projekt..." << endl;
                    wait();
                    cout << endl;
                    cout << "Podany projekt nie istnieje!" << endl;
                    waitErr();
                    break;
                }
                else
                {
                    cout << "Wczytuje projekt...";
                    wait();
                }
                
                secMenu();

                break;
            case '3':
                system("cls");
                welcome();
        
                aboutAgille();

                cout << endl;
                cout << "---------------------------------------------" << endl;
                cout << "Nacisnij dowolny klawisz aby powrocic do Menu Glownego" << endl;
                _getch();

                break;
            case '4':
                system("cls");
                welcome();

                aboutHelp();

                cout << endl;
                cout << "---------------------------------------------" << endl;
                cout << "Nacisnij dowolny klawisz aby powrocic do Menu Glownego" << endl;
                _getch();

                break;
            case '0':
                exit(0);
                break;
            default:
                cout << "Bledna wartosc" << endl;
                waitErr();
                break;
            }
        } while (!mainMenu);

    }
    return 0;
}