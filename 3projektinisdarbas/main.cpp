#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

const int MAX = 100;

// 1. Duomenu nuskaitymas
bool nuskaitytiDuomenis(
    string kategorijos[],
    string pavadinimai[],
    double kainos[],
    int kiekiai[],
    int &n
) {
    ifstream fin("uzsakymas.txt");

    if (!fin.is_open()) {
        cout << "KLAIDA: Nepavyko atidaryti uzsakymas.txt\n";
        return false;
    }

    string eilute;

    if (!getline(fin, eilute)) {
        cout << "KLAIDA: Failas tuscias.\n";
        return false;
    }

    try {
        n = stoi(eilute);
    }
    catch (...) {
        cout << "KLAIDA: Netinkamas irasu skaicius.\n";
        return false;
    }

    if (n < 1 || n > MAX) {
        cout << "KLAIDA: Irasu skaicius turi buti nuo 1 iki 100.\n";
        return false;
    }

    for (int i = 0; i < n; i++) {
        if (!getline(fin, eilute)) {
            cout << "KLAIDA: Nepavyko nuskaityti " << i + 1
                 << " iraso.\n";
            return false;
        }

        stringstream ss(eilute);

        string kategorija, pavadinimas, kainaStr, kiekisStr;

        if (!getline(ss, kategorija, ';') ||
            !getline(ss, pavadinimas, ';') ||
            !getline(ss, kainaStr, ';') ||
            !getline(ss, kiekisStr)) {
            cout << "KLAIDA: Netinkamas " << i + 1
                 << " iraso formatas.\n";
            return false;
        }

        if (kategorija != "Dviraciai" &&
            kategorija != "Dalys" &&
            kategorija != "Aksesuarai") {
            cout << "KLAIDA: Netinkama kategorija " << i + 1
                 << " irase.\n";
            return false;
        }

        try {
            size_t poz1, poz2;

            kainos[i] = stod(kainaStr, &poz1);
            kiekiai[i] = stoi(kiekisStr, &poz2);

            if (poz1 != kainaStr.size() ||
                poz2 != kiekisStr.size()) {
                cout << "KLAIDA: Netinkami skaiciai.\n";
                return false;
            }
        }
        catch (...) {
            cout << "KLAIDA: Netinkama kaina arba kiekis.\n";
            return false;
        }

        if (kainos[i] <= 0 || kiekiai[i] <= 0) {
            cout << "KLAIDA: Kaina ir kiekis turi buti teigiami.\n";
            return false;
        }

        kategorijos[i] = kategorija;
        pavadinimai[i] = pavadinimas;
    }

    fin.close();
    return true;
}

// 2. Vienos prekes eilutes suma pries nuolaida
double eilutesSuma(double kaina, int kiekis) {
    return kaina * kiekis;
}

// 3. Nuolaidos apskaiciavimas
double nuolaida(double suma, int kiekis) {
    if (kiekis >= 10) {
        return suma * 0.10;
    }

    return 0.0;
}

// 4. Vienos prekes galutine suma
double galutineEilutesSuma(double kaina, int kiekis) {
    double suma = eilutesSuma(kaina, kiekis);
    double nuolaidaEur = nuolaida(suma, kiekis);

    return suma - nuolaidaEur;
}

// 5. Kategorijos suma po nuolaidu
double kategorijosSuma(
    string kategorijos[],
    double kainos[],
    int kiekiai[],
    int n,
    string pasirinktaKategorija
) {
    double suma = 0;

    for (int i = 0; i < n; i++) {
        if (kategorijos[i] == pasirinktaKategorija) {
            suma += galutineEilutesSuma(kainos[i], kiekiai[i]);
        }
    }

    return suma;
}

// 6. Visu prekiu perziura
void rodytiPrekes(
    string kategorijos[],
    string pavadinimai[],
    double kainos[],
    int kiekiai[],
    int n
) {
    cout << fixed << setprecision(2);

    cout << "\n"
         << left << setw(15) << "Kategorija"
         << setw(38) << "Pavadinimas"
         << right << setw(12) << "Kaina"
         << setw(8) << "Kiekis"
         << setw(15) << "Pries nuol."
         << setw(12) << "Nuolaida"
         << setw(15) << "Moketina" << "\n";

    cout << string(115, '-') << "\n";

    for (int i = 0; i < n; i++) {
        double suma = eilutesSuma(kainos[i], kiekiai[i]);
        double nuol = nuolaida(suma, kiekiai[i]);
        double moketina = suma - nuol;

        cout << left << setw(15) << kategorijos[i]
             << setw(38) << pavadinimai[i]
             << right << setw(12) << kainos[i]
             << setw(8) << kiekiai[i]
             << setw(15) << suma
             << setw(12) << nuol
             << setw(15) << moketina << "\n";
    }
}

// 7. Pasirinktos kategorijos prekiu perziura
void rodytiKategorija(
    string kategorijos[],
    string pavadinimai[],
    double kainos[],
    int kiekiai[],
    int n,
    string kategorija
) {
    bool rasta = false;

    cout << fixed << setprecision(2);

    cout << "\nKategorija: " << kategorija << "\n";

    cout << left << setw(38) << "Pavadinimas"
         << right << setw(12) << "Kaina"
         << setw(8) << "Kiekis"
         << setw(15) << "Pries nuol."
         << setw(12) << "Nuolaida"
         << setw(15) << "Moketina" << "\n";

    cout << string(100, '-') << "\n";

    for (int i = 0; i < n; i++) {
        if (kategorijos[i] == kategorija) {
            rasta = true;

            double suma = eilutesSuma(kainos[i], kiekiai[i]);
            double nuol = nuolaida(suma, kiekiai[i]);

            cout << left << setw(38) << pavadinimai[i]
                 << right << setw(12) << kainos[i]
                 << setw(8) << kiekiai[i]
                 << setw(15) << suma
                 << setw(12) << nuol
                 << setw(15) << suma - nuol << "\n";
        }
    }

    if (!rasta) {
        cout << "Sioje kategorijoje prekiu nera.\n";
    }
    else {
        cout << "\nKategorijos moketina suma: "
             << kategorijosSuma(
                    kategorijos, kainos, kiekiai, n, kategorija
                )
             << " Eur\n";
    }
}

// 8. Viso uzsakymo sumu apskaiciavimas
void apskaiciuotiUzsakymoSumas(
    double kainos[],
    int kiekiai[],
    int n,
    double &priesNuolaidas,
    double &nuolaiduSuma,
    double &galutineSuma
) {
    priesNuolaidas = 0;
    nuolaiduSuma = 0;
    galutineSuma = 0;

    for (int i = 0; i < n; i++) {
        double suma = eilutesSuma(kainos[i], kiekiai[i]);
        double nuol = nuolaida(suma, kiekiai[i]);

        priesNuolaidas += suma;
        nuolaiduSuma += nuol;
        galutineSuma += suma - nuol;
    }
}

// 9. Uzsakymo sumu perziura
void rodytiUzsakymoSumas(
    double kainos[],
    int kiekiai[],
    int n
) {
    double pries, nuol, galutine;

    apskaiciuotiUzsakymoSumas(
        kainos, kiekiai, n, pries, nuol, galutine
    );

    cout << fixed << setprecision(2);

    cout << "\n--- UZSAKYMO SUMOS ---\n";
    cout << "Suma pries nuolaidas: " << pries << " Eur\n";
    cout << "Nuolaidu suma:        " << nuol << " Eur\n";
    cout << "Galutine suma:        " << galutine << " Eur\n";
}

// 10. Kategoriju suvestine
void rodytiKategorijuSumas(
    string kategorijos[],
    double kainos[],
    int kiekiai[],
    int n
) {
    string kategorijuPavadinimai[3] = {
        "Dviraciai", "Dalys", "Aksesuarai"
    };

    cout << fixed << setprecision(2);

    cout << "\n--- KATEGORIJU SUVESTINE ---\n";

    for (int i = 0; i < 3; i++) {
        double suma = kategorijosSuma(
            kategorijos,
            kainos,
            kiekiai,
            n,
            kategorijuPavadinimai[i]
        );

        cout << kategorijuPavadinimai[i]
             << ": " << suma << " Eur\n";
    }
}

// 11. Visa ataskaita
void ataskaita(
    ostream &out,
    string kategorijos[],
    string pavadinimai[],
    double kainos[],
    int kiekiai[],
    int n
) {
    out << fixed << setprecision(2);

    out << "\n========== UZSAKYMO ATASKAITA ==========\n\n";

    out << left << setw(15) << "Kategorija"
        << setw(38) << "Pavadinimas"
        << right << setw(12) << "Kaina"
        << setw(8) << "Kiekis"
        << setw(15) << "Pries nuol."
        << setw(12) << "Nuolaida"
        << setw(15) << "Moketina" << "\n";

    out << string(115, '-') << "\n";

    for (int i = 0; i < n; i++) {
        double suma = eilutesSuma(kainos[i], kiekiai[i]);
        double nuol = nuolaida(suma, kiekiai[i]);

        out << left << setw(15) << kategorijos[i]
            << setw(38) << pavadinimai[i]
            << right << setw(12) << kainos[i]
            << setw(8) << kiekiai[i]
            << setw(15) << suma
            << setw(12) << nuol
            << setw(15) << suma - nuol << "\n";
    }

    double pries, nuol, galutine;

    apskaiciuotiUzsakymoSumas(
        kainos, kiekiai, n, pries, nuol, galutine
    );

    out << "\n--- VISO UZSAKYMO SUMOS ---\n";
    out << "Suma pries nuolaidas: " << pries << " Eur\n";
    out << "Nuolaidu suma:        " << nuol << " Eur\n";
    out << "Galutine suma:        " << galutine << " Eur\n";

    out << "\n--- KATEGORIJU SUVESTINE ---\n";

    string kategorijuPavadinimai[3] = {
        "Dviraciai", "Dalys", "Aksesuarai"
    };

    for (int i = 0; i < 3; i++) {
        out << kategorijuPavadinimai[i] << ": "
            << kategorijosSuma(
                   kategorijos,
                   kainos,
                   kiekiai,
                   n,
                   kategorijuPavadinimai[i]
               )
            << " Eur\n";
    }

    out << "\n========================================\n";
}

// 12. Ataskaitos issaugojimas
bool issaugotiAtaskaita(
    string kategorijos[],
    string pavadinimai[],
    double kainos[],
    int kiekiai[],
    int n
) {
    ofstream fout("ataskaita.txt");

    if (!fout.is_open()) {
        cout << "KLAIDA: Nepavyko sukurti ataskaita.txt\n";
        return false;
    }

    ataskaita(
        fout,
        kategorijos,
        pavadinimai,
        kainos,
        kiekiai,
        n
    );

    if (!fout.good()) {
        cout << "KLAIDA: Nepavyko pilnai irasyti ataskaitos.\n";
        fout.close();
        return false;
    }

    fout.close();

    if (fout.fail()) {
        cout << "KLAIDA: Nepavyko uzdaryti ataskaitos failo.\n";
        return false;
    }

    cout << "Ataskaita sekmingai issaugota i ataskaita.txt\n";
    return true;
}

// MAIN
int main() {
    string kategorijos[MAX];
    string pavadinimai[MAX];
    double kainos[MAX];
    int kiekiai[MAX];

    int n;

    if (!nuskaitytiDuomenis(
        kategorijos, pavadinimai, kainos, kiekiai, n
    )) {
        return 1;
    }

    cout << "Duomenys sekmingai nuskaityti.\n";
    cout << "Prekiu irasu skaicius: " << n << "\n";

    int pasirinkimas;

    do {
        cout << "\n========== MENIU ==========\n";
        cout << "1. Perziureti visas uzsakymo prekes\n";
        cout << "2. Perziureti pasirinktos kategorijos prekes\n";
        cout << "3. Perziureti viso uzsakymo sumas\n";
        cout << "4. Perziureti sumas pagal kategorijas\n";
        cout << "5. Parodyti visa uzsakymo ataskaita\n";
        cout << "6. Issaugoti ataskaita i faila\n";
        cout << "7. Iseiti\n";
        cout << "Pasirinkite: ";

        if (!(cin >> pasirinkimas)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Netinkamas pasirinkimas. Bandykite dar karta.\n";
            pasirinkimas = 0;
            continue;
        }

        switch (pasirinkimas) {
            case 1:
                rodytiPrekes(
                    kategorijos, pavadinimai, kainos, kiekiai, n
                );
                break;

            case 2: {
                int katPasirinkimas;

                cout << "\nPasirinkite kategorija:\n";
                cout << "1. Dviraciai\n";
                cout << "2. Dalys\n";
                cout << "3. Aksesuarai\n";
                cout << "Pasirinkite: ";

                if (!(cin >> katPasirinkimas)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Netinkamas pasirinkimas.\n";
                    break;
                }

                string kategorija;

                if (katPasirinkimas == 1) {
                    kategorija = "Dviraciai";
                }
                else if (katPasirinkimas == 2) {
                    kategorija = "Dalys";
                }
                else if (katPasirinkimas == 3) {
                    kategorija = "Aksesuarai";
                }
                else {
                    cout << "Netinkamas kategorijos pasirinkimas.\n";
                    break;
                }

                rodytiKategorija(
                    kategorijos,
                    pavadinimai,
                    kainos,
                    kiekiai,
                    n,
                    kategorija
                );

                break;
            }

            case 3:
                rodytiUzsakymoSumas(kainos, kiekiai, n);
                break;

            case 4:
                rodytiKategorijuSumas(
                    kategorijos, kainos, kiekiai, n
                );
                break;

            case 5:
                ataskaita(
                    cout,
                    kategorijos,
                    pavadinimai,
                    kainos,
                    kiekiai,
                    n
                );
                break;

            case 6:
                issaugotiAtaskaita(
                    kategorijos, pavadinimai, kainos, kiekiai, n
                );
                break;

            case 7:
                cout << "Programa baigta.\n";
                break;

            default:
                cout << "Tokio pasirinkimo nera. Bandykite dar karta.\n";
        }

    } while (pasirinkimas != 7);

    return 0;
}