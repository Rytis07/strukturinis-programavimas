#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const double GBP_Bendras = 0.8729;
    const double GBP_Pirkti = 0.8600;
    const double GBP_Parduoti = 0.9220;

    const double USD_Bendras = 1.1793;
    const double USD_Pirkti = 1.1460;
    const double USD_Parduoti = 1.2340;

    const double INR_Bendras = 104.6918;
    const double INR_Pirkti = 101.3862;
    const double INR_Parduoti = 107.8546;

    int veiksmas, valiuta;
    double suma, kursas, rezultatas;
    string pavadinimas;

    cout << fixed << setprecision(2);

    while (true) {
        cout << "\n1. Valiutos palyginimas\n";
        cout << "2. Pirkti valiuta\n";
        cout << "3. Parduoti valiuta\n";
        cout << "4. Iseiti\n";
        cout << "Pasirinkimas: ";
        cin >> veiksmas;

        if (veiksmas == 4) {
            break;
        }
        if (veiksmas < 1 || veiksmas > 4) {
            cout << "Neteisingas pasirinkimas\n";
            continue;
        }

        cout << "\n1. GBP\n2. USD\n3. INR\n";
        cout << "Pasirinkite valiuta: ";
        cin >> valiuta;


        switch (valiuta) {
            case 1:
                pavadinimas = "GBP";
                if (veiksmas == 1)
                    kursas = GBP_Bendras;
                else if (veiksmas == 2)
                    kursas = GBP_Pirkti;
                else
                    kursas = GBP_Parduoti;
                break;

            case 2:
                pavadinimas = "USD";
                if (veiksmas == 1)
                    kursas = USD_Bendras;
                else if (veiksmas == 2)
                    kursas = USD_Pirkti;
                else
                    kursas = USD_Parduoti;
                break;

            case 3:
                pavadinimas = "INR";
                if (veiksmas == 1)
                    kursas = INR_Bendras;
                else if (veiksmas == 2)
                    kursas = INR_Pirkti;
                else
                    kursas = INR_Parduoti;
                break;

            default:
                cout << "Neteisinga valiuta\n";
                continue;
        }

        if (veiksmas == 1) {
            cout << "1 EUR = " << kursas << " " << pavadinimas << endl;
        }
        else {
            cout << "Iveskite suma: ";
            cin >> suma;

            if (suma <= 0) {
                cout << "Suma turi buti didesne uz nuli\n";
            }
            else if (veiksmas == 2) {
                rezultatas = suma * kursas;
                cout << suma << " EUR = " << rezultatas
                     << " " << pavadinimas << endl;
            }
            else {
                rezultatas = suma / kursas;
                cout << suma << " " << pavadinimas << " = "
                     << rezultatas << " EUR\n";
            }
        }
    }

    return 0;
}