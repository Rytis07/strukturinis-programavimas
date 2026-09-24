#include <iostream>
#include <string>

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    string komanda = "Manchester city";
    string zaidejas = "Erling Haaland";
    int marskineniunumeris = 9;
    int ivarciai = 22;
    int rungtynes = 17;
    const auto lang = "C++";

    double ugis = 195;
    double svoris = 88.7;
    double svorisKonv = static_cast<double>(svoris);
    double Ivarciuvidurkis = static_cast<double>(ivarciai/rungtynes);
    cout << "Komanda" << komanda << endl;
    cout << "Zaidejas" << zaidejas << endl;
    cout << "Numeris" <<marskineniunumeris<<endl;
    cout << "Ugis" << ugis << endl;
    cout << "Svoris " << svoris<<endl;
    cout << "Svoris (int): <<svorisKonv << endl;"
    
        cout <<


    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}