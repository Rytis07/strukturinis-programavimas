#include <iostream>
#include <string>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    string komanda = "Manchester city";
    string zaidejas = "Erling Haaland";
    int marskineniunumeris 9;
    int ivarciai = 22;
    int rungtynes = 17;
    const auto lang = "C++";

    double ugis = 195;
    double svoris = 88.7
    double svorisKonv = static_cast<double>(svoris);
    double Ivarciuvidurkis = static_cast<double>(ivarciai/rungtynes);
    cout << "Komanda" << komanda << endl;
    cout << "Zaidejas" << zaidejas << endl;
    cout << "Numeris" <<marskineniunumeris<<endl;
    cout <<
        cout <<
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}