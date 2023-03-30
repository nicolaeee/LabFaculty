//Aici conectez directivele si bibliotecele pentru execunarea corecta a programului cpp
#include <iostream>
#include <string>
using namespace std;

class Medicam{
//Aici am adaugat/definit 4 variabile/atribute de tip privat
private: 
	string nume;
	int concentr = 0;
	string subsAct;
	double pret = 0.0;
public:
	void setNume(string numeMedicament){
		nume = numeMedicament;
	}

	void setConcentr(int concentratie){
		concentr = concentratie;
	}

	void setSubAct(string substabtaActiva){
		subsAct = substabtaActiva;
	}

	void setPret(double pretMedicament){
		pret = pretMedicament;
	}

	void afiseazaDetalii() const{
		cout << " Nume medicament: " << nume << endl;
		cout << " Concentratie " << concentr << endl;
        cout << "Substanta activa: " << subsAct << endl;
        cout << "Pret: " << pret << end;
	}


}

int main() {
    Medicament medicament1;
    medicament1.setNume("Paraacetamol");
    medicament1.setConcentr(500);
    medicament1.setSubsAct("Paracetamol");
    medicament1.setPret(10.99);
    medicament1.afiseazaDetalii();

    return 0;
}


