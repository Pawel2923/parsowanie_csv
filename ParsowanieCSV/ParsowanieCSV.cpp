#include <iostream>

using namespace std;

int main()
{
    int choice;

    do {
        cout << "--------Parsowanie CSV--------" << endl;
        cout << "1. Wczytaj plik CSV" << endl;
        cout << "2. Zapisz do pliku binarnego" << endl;
        cout << "3. Wczytaj z pliku binarnego" << endl;
        cout << "0. Wyjdz z programu" << endl;
        cout << "Podaj numer opcji: " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Wczytaj plik CSV" << endl;
			break;
        case 2:
			cout << "Zapisz do pliku binarnego" << endl;
            break;
        case 3:
            cout << "Wczytaj z pliku binarnego" << endl;
			break;
        case 0:
			cout << "Wychodzenie z programu..." << endl;
            break;
        default:
            cout << "Nie ma takiej opcji" << endl;
			break;
        }
    } while (choice != 0);

    return 0;
}
