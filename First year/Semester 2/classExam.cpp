//Aici conectez directivele si bibliotecele pentru execunarea corecta a programului cpp
#include <iostream>
#include <string>
using namespace std;


class Medicament {

private://Avem 4 variabile membre private
    string nume;
    int concentr;
    string subsAct;
    double pret;

public:
    //In public avem 5 metode publice
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

};



int main() {
/*O clasa este un tip de date definite de utilizator care contin date si
metode(datele sunt private si metodele sunt publice), 
mai precis o metoda este o functie care poate face ceva anumit cu obiectul dat*/

        Medicament medicament1;
        medicament1.setNume("Paracetamol");
        medicament1.setConcentr(500);
        medicament1.setSubsAct("Paracetamol");
        medicament1.setPret(10.99);
        medicament1.afiseazaDetalii();

        return 0;

	
}

