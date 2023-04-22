#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Medicament {
public:
    Medicament() {
        nume = "";
        concentr = 0;
        subsAct = "";
        pret = 0.0;
    }

    Medicament(string numeMedicament, int concentratie, string substantaActiva, double pretMedicament) {
        nume = numeMedicament;
        concentr = concentratie;
        subsAct = substantaActiva;
        pret = pretMedicament;
    }

    void setNume(string numeMedicament) {
        nume = numeMedicament;
    }

    void setConcentr(int concentratie) {
        concentr = concentratie;
    }

    void setSubsAct(string substantaActiva) {
        subsAct = substantaActiva;
    }

    void setPret(double pretMedicament) {
        pret = pretMedicament;
    }

    void afiseazaDetalii() const {
        cout << "Nume medicament: " << nume << endl;
        cout << "Concentratie: " << concentr << endl;
        cout << "Substanta activa: " << subsAct << endl;
        cout << "Pret: " << pret << endl;
    }

private:
    string nume;
    int concentr;
    string subsAct;
    double pret;
};

int main() {
    Medicament a1("Aspirina", 500, "acetisalicilc", 10.5);
    a1.afiseazaDetalii();

    cout << "\n";
    Medicament a2 = a1;
    a2.afiseazaDetalii();
    return 0;
}
