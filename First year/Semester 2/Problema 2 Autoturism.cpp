#include <iostream>
#include <string>
using namespace std;

class Autoturism
{
private:
	const int serieCaroserie = 0;
	string marca;
	string model;
	int putere;
	double pret;
	float* distanteParcurse;
	int nrDrumuri; //nr de elemente al vectorului de mai sus
	static int numarAutoturisme;

public:
	Autoturism()
	{
		marca = "Necunoscuta";
		model = "Necunoscut";
		putere = 0;
		pret = 5000;
		distanteParcurse = nullptr;
		nrDrumuri = 0;
	}


	Autoturism(string marca, string model, int putere)
	{
		this->marca = marca;
		this->model = model;
		this->putere = putere;
		pret = 5000;
		distanteParcurse = nullptr;
		nrDrumuri = 0;
	}


	Autoturism(string marca, string model, float* distante, int nrDrumuri)
	{
		this->marca = marca;
		this->model = model;
		this->putere = 0;
		this->pret = 5000;
		if (nrDrumuri > 0) {
			this->distanteParcurse = new float[nrDrumuri];
			for (int i = 0; i < nrDrumuri; i++) {
				this->distanteParcurse[i] = distante[i];
			}
			this->nrDrumuri = nrDrumuri;
		}
		else {
			this->distanteParcurse = nullptr;
			this->nrDrumuri = 0;
		}
	}

	~Autoturism()
	{
		delete[] distanteParcurse;
		distanteParcurse = nullptr;
		nrDrumuri = 0;
	}

	Autoturism(const Autoturism& other)
	{
		marca = other.marca;
		model = other.model;
		putere = other.putere;
		pret = other.pret;
		nrDrumuri = other.nrDrumuri;
		if (nrDrumuri > 0) {
			distanteParcurse = new float[nrDrumuri];
			for (int i = 0; i < nrDrumuri; i++) {
				distanteParcurse[i] = other.distanteParcurse[i];
			}
		}
		else {
			distanteParcurse = nullptr;
		}
	}





	string getMarca()
	{
		return marca;
	}

	string getModel()
	{
		return model;
	}

	double getPret()
	{
		return pret;
	}

	int getPutere()
	{
		return putere;
	}


	void setMarca(string marca)
	{
		if (marca.length() >= 3) {
			this->marca = marca;
		}
	}

	int getNrDrumuri() const {
		return nrDrumuri;
	}



	float* getDistanteParcurse() const {
		if (nrDrumuri == 0) {
			return nullptr;
		}
		float* copie = new float[nrDrumuri];
		for (int i = 0; i < nrDrumuri; i++) {
			copie[i] = distanteParcurse[i];
		}
		return copie;
	}

	void setDistante(float* distanteParcurse, int nrDrumuri)
	{
		if (distanteParcurse != nullptr && nrDrumuri > 0) {
			if (this->distanteParcurse != nullptr) {
				delete[] this->distanteParcurse;
			}
			this->distanteParcurse = new float[nrDrumuri];
			for (int i = 0; i < nrDrumuri; i++) {
				this->distanteParcurse[i] = distanteParcurse[i];
			}
			this->nrDrumuri = nrDrumuri;
		}
	}


	char* getTaraDeProductie()
	{
		return nullptr;
	}

	void setTaraDeProductie(const char* tara)
	{
	}

	char* AdresaInceputTaraDeProductie()
	{
		return nullptr;
	}

	Autoturism operator=(Autoturism a)
	{
		return *this;
	}

	static double calcul_valoare_flota(Autoturism masini[], int nr_masini)
	{
		return 0;
	}

	void discount(int procent)
	{
	}
};

int Autoturism::numarAutoturisme = 0;

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//Signatura functiilor nu se poate modifica, doar continului lor
//Folosirea valorile din teste, doar pentru a le face sa se execute cu succes este considerata frauda

//1. Modificati constructorul implicit din clasa Autoturism de mai sus
//acesta va initializa marca cu "Necunoscuta", modelul cu "Necunoscut"
//puterea cu 0, pretul cu 5000, vectorul de distante cu NULL si nrDrumuri cu 0

//2. Modificati constructorul cu 3 parametri: marca, model, putere
//acesta va initializa cele 3 atribute cu valorile primite
//restul de atribute nu trebuie sa ramana neinitializate si vor folosi aceleasi valori implicite ca mai sus

//3. Modificati constructorul cu 4 parametri pentru a copia valorile
//primite drept parametri in atributele clasei
//constructorul nu va lasa atribute neinitializate

//4. Adaugati un destructor in clasa care sterge zonele de memorie anterior alocate
//acesta va seta pointerii pe NULL dupa ce face stergerea

//5. Adaugati clasei un constructor de copiere astfel incat
//sa se realizeze o copie in profunzime (deep copy) a obiectelor

//6. Modificati metodele de acces (getteri si setteri) pentru atributul marca
//Setterul va accepta denumiri de marci cu o lungime
//mai mare sau egala de 3 caractere
//in caz contrar marca ramane cea existenta

//7. Modificati getter-ul pentru vectorul de distante parcurse
//Getter-ul va returna o copie a vectorului din clasa
//Modificati getter-ul si pentru numarul de drumuri

//8. Modificati setter-ul pentru vectorul de distante
//acesta va modifica simultan vectorul si numarul de elemente
//si nu va accepta decat vectori nenuli si numar de elemente mai mare decat 0

//9. Adaugati un camp de tip char* in clasa numit taraDeProductie
//modificati getter-ul si setter-ul din clasa pentru a returna,
//respectiv a modifica valoarea acestui camp
//Metoda AdresaInceputTaraDeProductie intoarce adresa primului element din tara de productie
//(da, nu e neaparat safe, dar e necesar pentru test)

//10. Modificati constructorii, destructorul si alte metode necesare
//astfel incat clasa sa gestioneze corect noul camp

//11. Modificati supraincarcarea pentru operator=
//aceasta va realiza o copie in profunzime (deep copy) a obiectelor
//operatorul accepta apeluri in cascada

//12. Modificati constructorii astfel incat serieCaroserie
//sa fie generat unic pe baza campului static
//campul static fiind comun pentru toate obiectele, poate fi incrementat in constructori
//iar valoare lui copiata in campul constant serieCaroserie
//astfel, prima masina va avea serieCaroserie 1, urmatoarea seria 2 s.a.m.d
//constructorul de copiere va copia valoarea ca atare (dintr-un obiect in altul)

//13. Modificati functia statica calcul_valoare_flota
//calculati si returnati valoarea totala a flotei de autoturisme
//prin adunarea preturilor masinilor din flota (vectorul de Autoturisme)

//14. Modificati metoda discount pentru a acorda un discount din pret
//discountul este in procente si poate fi intre 1% si 50% (se face validare)
//functia modifica pretul cu valoarea sa dupa aplicarea discountului

//15. Functia globala de mai jos primeste drept parametri o matrice
//de pointeri la Autoturism impreuna cu numarul de linii si de coloane
//Matricea reprezinta cum sunt dispuse masinile intr-o parcare
//Un element null inseamna ca pe acel loc de parcare nu este nicio masina
//Functia va returna o matrice a locurilor de parcare astfel
//100 90 60
//0 160 75
//0 90 0
//Explicatii: Parcarea are 3 linii si cate 3 locuri de parcare pe fiecare linie (3 coloane)
//Pe prima linie sunt parcate 3 masini cu putere de 100, 90 si respectiv 60 cai putere
//pe a doua linie primul loc este neocupat, iar urmatoarele doua locuri
//sunt ocupate de doua masini cu 160, respectiv 75 de cai putere, s.a.m.d.
int** locuri_libere(Autoturism*** matrice, int nrLinii, int nrColoane)
{
	return nullptr;
}


int main()
{

	//1
	Autoturism masina1;

	cout << "Marca: " << masina1.getMarca() << endl;
	cout << "Model: " << masina1.getModel() << endl;
	cout << "Putere: " << masina1.getPutere() << endl;
	cout << "Pret: " << masina1.getPret() << endl;
	cout << "Distante parcurse: " << masina1.getDistanteParcurse() << endl;
	cout << "Numar drumuri: " << masina1.getNrDrumuri() << endl;
	cout << "\n";

	//2
	Autoturism masina("Ford", "Fiesta", 90);
	cout << "Marca: " << masina.getMarca() << endl;
	cout << "Model: " << masina.getModel() << endl;
	cout << "Putere: " << masina.getPutere() << endl;
	cout << "Pret: " << masina.getPret() << endl;
	cout << "\n";

	//3
	float distante[] = { 100, 200, 300 };
	int nrDrumuri = 3;
	Autoturism autoturism("Audi", "A4", distante, nrDrumuri);
	cout << "Marca: " << autoturism.getMarca() << endl;
	cout << "Model: " << autoturism.getModel() << endl;
	cout << "Putere: " << autoturism.getPutere() << endl;
	cout << "Pret: " << autoturism.getPret() << endl;

	//5
	Autoturism autoturism2 = autoturism;
	autoturism2.setMarca("BMW");
	cout << "Marca autoturismului original: " << autoturism.getMarca() << endl;
	cout << "Marca autoturismului nou: " << autoturism2.getMarca() << endl;
	cout << "\n";

	//6
	Autoturism a;
	a.setMarca("Audi");
	cout << "\n";

	//7
	cout << "Numar drumuri: " << autoturism.getNrDrumuri() << endl;
	cout << "Distante parcurse: ";
	float* distanteParcurse = autoturism.getDistanteParcurse();
	for (int i = 0; i < nrDrumuri; i++) {
		cout << distanteParcurse[i] << " ";
	}
	cout << endl;
	cout << "\n";

	//8
	float distanteNoi[] = { 50, 75, 100 };
	autoturism.setDistante(distanteNoi, 3);
	cout << "Numar drumuri: " << autoturism.getNrDrumuri() << endl;
	cout << "\n";








	return 0;

}