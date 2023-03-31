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
    //In public avem 5 metode publice pentru setarea datelor in obiectul medicament 1 prin metoda 1
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

    //Aici am o metoda care imi afiseaza aceste date de la obiectul pe care am sa l selectez prin .metoda
    void afiseazaDetalii()  {
        cout << "Nume medicament: " << nume << endl;
        cout << "Connncentratie: " << concentr << endl;
        cout << "Substanta activa: " << subsAct << endl;
        cout << "Pret: " << pret << endl;
    }

    void setTot(string numeMedicament, int concentratie, string substantaActiva, double pretMedicament) {
        nume = numeMedicament;
        concentr = concentratie;
        subsAct = substantaActiva;
        pret = pretMedicament;
    }

};



int main() {
/*O clasa este un tip de date definite de utilizator care contin date si
metode(datele sunt private si metodele sunt publice), 
mai precis o metoda este o functie care poate face ceva anumit cu obiectul dat*/

        Medicament medicament1, medicament2;
        medicament1.setNume("Paracetamol");
        medicament1.setConcentr(500);
        medicament1.setSubsAct("Pasracetamol");
        medicament1.setPret(10.99);
        medicament1.afiseazaDetalii();
        medicament2.setTot("Nurofen", 500, "Amidon:(", 10.99);
        medicament2.afiseazaDetalii();


        return 0;

	
}
