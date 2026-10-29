
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string vardai[100];
    int pazymiai[100][10];
    int kiekppazymiu[100] = {0};
    int mokiniuskaicius = 0;
    int pasirinkimas;

    do {
        cout << "\n--- DIENYNAS ---\n";
        cout << "1. Ivesti mokini ir jo pazymius\n";
        cout << "2. Perziureti visu mokiniu pazymius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Apskaiciuoti mokinio vidurki\n";
        cout << "6. Pasalinti mokini\n";
        cout << "7. Iseiti\n";
        cout << "Pasirinkite: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {

        case 4: {
            if (mokiniuskaicius == 0) {
                cout << "Mokiniu nera.\n";
                break;
            }

            int m, p, naujas;
            cout << "Mokinio numeris (1-" << mokiniuskaicius << "): ";
            cin >> m;

            while (m < 1 || m > mokiniuskaicius) {
                cout << "Neteisingas numeris. Iveskite nuo 1 iki "
                     << mokiniuskaicius << ": ";
                cin >> m;
            }

            if (kiekppazymiu[m - 1] == 0) {
                cout << "Mokinys neturi pazymiu.\n";
                break;
            }

            cout << "Pazymio numeris (1-" << kiekppazymiu[m - 1] << "): ";
            cin >> p;

            while (p < 1 || p > kiekppazymiu[m - 1]) {
                cout << "Neteisingas numeris. Iveskite nuo 1 iki "
                     << kiekppazymiu[m - 1] << ": ";
                cin >> p;
            }

            cout << "Naujas pazymys (1-10): ";
            cin >> naujas;

            while (naujas < 1 || naujas > 10) {
                cout << "Bandykite dar karta (1-10): ";
                cin >> naujas;
            }

            pazymiai[m - 1][p - 1] = naujas;
            cout << "Pazymys pakeistas!\n";
            break;
        }

        case 1: {
            if (mokiniuskaicius >= 100) {
                cout << "Sarasas pilnas!\n";
                break;
            }

            cout << "Mokinio vardas: ";
            cin >> vardai[mokiniuskaicius];

            int n;
            cout << "Kiek pazymiu (0-10): ";
            cin >> n;

            while (n < 0 || n > 10) {
                cout << "Iveskite skaiciu nuo 0 iki 10: ";
                cin >> n;
            }

            kiekppazymiu[mokiniuskaicius] = n;

            int j = 0;
            while (j < n) {
                cout << "Pazymys " << j + 1 << " (1-10): ";
                cin >> pazymiai[mokiniuskaicius][j];

                while (pazymiai[mokiniuskaicius][j] < 1 ||
                       pazymiai[mokiniuskaicius][j] > 10) {
                    cout << "Blogas pazymys, bandykite dar karta: ";
                    cin >> pazymiai[mokiniuskaicius][j];
                }

                j++;
            }

            mokiniuskaicius++;
            cout << "Mokinys pridetas!\n";
            break;
        }

        case 6: {
            if (mokiniuskaicius == 0) {
                cout << "Sarasas tuscias.\n";
                break;
            }

            int m;
            cout << "Kurio mokinio numeri pasalinti (1-"
                 << mokiniuskaicius << "): ";
            cin >> m;

            while (m < 1 || m > mokiniuskaicius) {
                cout << "Blogas numeris. Iveskite nuo 1 iki "
                     << mokiniuskaicius << ": ";
                cin >> m;
            }

            int i = m - 1;
            while (i < mokiniuskaicius - 1) {
                vardai[i] = vardai[i + 1];
                kiekppazymiu[i] = kiekppazymiu[i + 1];

                int j = 0;
                while (j < 10) {
                    pazymiai[i][j] = pazymiai[i + 1][j];
                    j++;
                }

                i++;
            }

            mokiniuskaicius--;
            cout << "Mokinys pasalintas!\n";
            break;
        }

        case 3: {
            if (mokiniuskaicius == 0) {
                cout << "Sarasas tuscias.\n";
                break;
            }

            int m;
            cout << "Mokinio numeris (1-" << mokiniuskaicius << "): ";
            cin >> m;

            while (m < 1 || m > mokiniuskaicius) {
                cout << "Blogas numeris. Iveskite nuo 1 iki "
                     << mokiniuskaicius << ": ";
                cin >> m;
            }

            cout << vardai[m - 1] << " pazymiai: ";

            int j = 0;
            while (j < kiekppazymiu[m - 1]) {
                cout << pazymiai[m - 1][j] << " ";
                j++;
            }

            if (kiekppazymiu[m - 1] == 0) {
                cout << "Pazymiu nera";
            }

            cout << "\n";
            break;
        }

        case 7:
            cout << "Programa baigta.\n";
            break;

        case 2: {
            if (mokiniuskaicius == 0) {
                cout << "Mokiniu nera.\n";
                break;
            }

            int i = 0;
            while (i < mokiniuskaicius) {
                cout << i + 1 << ". " << vardai[i] << ": ";

                int j = 0;
                while (j < kiekppazymiu[i]) {
                    cout << pazymiai[i][j] << " ";
                    j++;
                }

                if (kiekppazymiu[i] == 0) {
                    cout << "Pazymiu nera";
                }

                cout << "\n";
                i++;
            }
            break;
        }

        case 5: {
            if (mokiniuskaicius == 0) {
                cout << "Mokiniu nera.\n";
                break;
            }

            int m;
            cout << "Mokinio numeris (1-" << mokiniuskaicius << "): ";
            cin >> m;

            while (m < 1 || m > mokiniuskaicius) {
                cout << "Blogas numeris. Iveskite nuo 1 iki "
                     << mokiniuskaicius << ": ";
                cin >> m;
            }

            if (kiekppazymiu[m - 1] == 0) {
                cout << "Mokinys neturi pazymiu.\n";
                break;
            }

            double suma = 0;
            int j = 0;

            while (j < kiekppazymiu[m - 1]) {
                suma = suma + pazymiai[m - 1][j];
                j++;
            }

            double vidurkis = suma / kiekppazymiu[m - 1];

            cout << fixed << setprecision(2);
            cout << "Mokinio " << vardai[m - 1]
                 << " vidurkis: " << vidurkis << "\n";
            break;
        }

        default:
            cout << "Tokio pasirinkimo nera!\n";
        }

    } while (pasirinkimas != 7);

    return 0;
}
