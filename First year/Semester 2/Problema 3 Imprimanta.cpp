#include <iostream>
#include <string>
using namespace std;

class Cartus
{
private:
	string producator;
	int nrTotalPagini;
public:
	int getNrTotalPagini() {
		return nrTotalPagini;
	}
};

class Imprimanta
{
private:
	const int serialNumber = 0;
	char* producator = nullptr;
	int nrPaginiPrintate;
	static string tipImprimanta;
	Cartus cartus;
public:
	Imprimanta() : serialNumber(1), nrPaginiPrintate(0)
	{
		producator = new char[1];
		producator[0] = '\0';
	}

	Imprimanta(int serialNumber, const char* producator, int nrPaginiPrintate)
		: serialNumber(serialNumber) {
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
		this->nrPaginiPrintate = nrPaginiPrintate;
	}


	~Imprimanta() {
		delete[] producator;
	}

	Imprimanta(const Imprimanta& i) : serialNumber(i.serialNumber) {
		nrPaginiPrintate = i.nrPaginiPrintate;
		producator = new char[strlen(i.producator) + 1];
		strcpy_s(producator, strlen(i.producator) + 1, i.producator);
	}

	Imprimanta& operator=(const Imprimanta& i) {
		if (this == &i) {
			return *this;
		}
		nrPaginiPrintate = i.nrPaginiPrintate;
		delete[] producator;
		producator = new char[strlen(i.producator) + 1];
		strcpy_s(producator, strlen(i.producator) + 1, i.producator);
		return *this;
	}

	bool operator<(Imprimanta t)
	{
		return this->nrPaginiPrintate < t.nrPaginiPrintate;
	}

	static string getTipImprimanta() {
		return tipImprimanta;
	}

	static void setTipImprimanta(string tipImprimanta) {
		Imprimanta::tipImprimanta = tipImprimanta;
	}

	static long getTotalPaginiPerProducator(Imprimanta* imprimante, int nrImprimante, const char* searchProducator) {
		long totalPagini = 0;
		for (int i = 0; i < nrImprimante; i++) {
			if (strcmp(imprimante[i].producator, const_cast<char*>(searchProducator)) == 0) {
				totalPagini += imprimante[i].nrPaginiPrintate;
			}
		}
		return totalPagini;
	}






	void setCartus(Cartus c)
	{
		cartus = c;
	}

	Cartus getCartus()
	{
		return cartus;
	}

	int getNrPaginiPrintate() {
		return nrPaginiPrintate;
	}

	int getNumarPaginiRamase()
	{
		int nrmax = cartus.getNrTotalPagini();
		int nrprint = getNrPaginiPrintate();
		int pagramase = nrmax - nrprint;
		if (pagramase < 0) {
			return 0;
		}
		return pagramase;
	}

	void serialize(string fileName)
	{

	}

	void deserialize(string fileName)
	{

	}


	friend ostream& operator<<(ostream& out, Imprimanta i)
	{
		out << "Serial number: " << i.serialNumber << endl;
		out << "Producator: " << i.producator << endl;
		out << "Numar pagini printate: " << i.nrPaginiPrintate << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Imprimanta& i)
	{

		return in;
	}
};

string Imprimanta::tipImprimanta = "Cerneala";

//ATENTIE!!!
//Sunt punctate doar solutiile originale si individuale
//Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//!!! Signatura anumitor operatori poate fi modificata pentru a permite functionarea lor conform specificatiilor

//1. Modificati constructorul implicit din clasa Imprimanta de mai sus
//acesta va initializa producatorul cu un sir de caractere vid ("")
//si numarul de pagini printate cu 0

//2. Modificati constructorul cu 3 parametri: serialNumber, producator, nrPaginiPrintate
//acesta va initializa cele 3 atribute cu valorile primite
//atributul constant nu va mai fi initializat la definire
//constructorul implicit va initializa acest atribut cu 1

//3. Adaugati un destructor in clasa pentru a dezaloca
//campul(urile) alocate dinamic

//4. Adaugati clasei un constructor de copiere astfel incat
//sa se realizeze o copie in profunzime (deep copy) a obiectelor
//se va realiza si copierea campului constant

//5. Modificati supraincarcarea pentru operator=
//aceasta va realiza o copie in profunzime (deep copy) a obiectelor
//operatorul accepta apeluri in cascada

//6. Initializati membrul static tipImprimanta cu valoarea "Cerneala"

//7. Modificati metodele de acces pentru campul static
//astfel incat acestea sa permita modificarea si obtinerea valorii acestui camp

//8. Modificati metoda getTotalPaginiPerProducator pentru a returna numarul total de pagini
//printate de toate imprimantele din vectorul de imprimante primit ca parametru
//care sunt produse de producatorul primit drept parametru
//De ex daca avem 3 imprimante: "Dell" - 120 de pagini, "HP" - 150 de pagini, "Dell" - 170 de pagini
//functia va returna 290 de pagini daca primeste ca parametru producatorul "Dell"
//si 150 de pagini daca primeste ca parametru producatorul "HP"
//pentru orice alt producator functia va returna 0

//9. Modelati o relatie de compunere intre clasa Cartus si clasa Imprimanta
//astfel incat sa reiasa faptul ca Imprimanta are (foloseste) un Cartus
//Modificati metoda setCartus astfel incat sa puteti schimba cartusul curent al imprimantei
//cu cel primit drept parametru si metoda getCartus pentru a returna cartusul curent

//10. Modificati metoda getNumarPaginiRamase astfel incat sa returneze numarul de pagini
//pe care imprimanta respectiva la mai poate printa avand in vedere ca stim
//cate pagini se pot printa maxim cu cartusul curent si cate pagini au fost printate pana acum
//functia nu poate returna o valoare negativa, asa ca daca numarul curent de pagini il
//depaseste pe cel maxim, va returna 0

//11. Modificati supraincarcarea operatorului <
//acesta va compara numarul de pagini al celor doi operanzi de tip Imprimanta

//12. Modificati operatorul de scriere la consola pentru a afisa informatiile despre Imprimanta
//se pot folosi functii friend sau getteri
//afisarea va fi de forma:
//Serial number: serialNumber
//Producator: producator
//Numar pagini printate: nrPaginiPrintate

//13. Modificati operatorul de citire de la consola pentru a citi informatii despre Imprimanta
//se vor citi in ordine urmatoarele informatii (fiecare pe o linie noua)
//producator
//nrPaginiPrintate
//se pot folosi setteri sau functii friend
//operatorul trebuie sa poata citi siruri de caractere ce contin spatii

//14. Supraincarcati operatorii de scriere si citire din fisiere text
//operatorii functioneaza pe fisiere text deschise deja

//15. Modificati metodele serialize si deserialize pentru a scrie
//si a citi obiectul curent de clasa Imprimanta intr-un/dintr-un fisier binar
//se vor serializa toate campurile (ordinea nu conteaza)
//cu exceptia celor constante si statice
//numele fisierului este primit drept parametru
//metodele deschid si inchid fisierele specificate

int main()
{
	//1
	Imprimanta myImprimanta;
	cout << myImprimanta << endl;
	cout << myImprimanta.getNrPaginiPrintate() << '\n ';
	cout << myImprimanta.getTipImprimanta << '\n';


	//2
	int serialNumber = 12345;
	const char* producator = "Panasonic";
	int nrPaginiPrintate = 100;
	Imprimanta myImprimantaTwo(serialNumber, producator, nrPaginiPrintate);
	cout << myImprimantaTwo << endl;
	cout << myImprimantaTwo.getNrPaginiPrintate() << '\n';
	cout << myImprimantaTwo.getTipImprimanta << '\n';


	//3
	//Destructorul este descris in clasa dar functioneaza conform testului

	//4
	Imprimanta myImprimantaThree(2121, "HP", 150);
	myImprimantaTwo = myImprimantaThree;
	cout << myImprimantaThree << endl;
	cout << myImprimantaThree.getNrPaginiPrintate() << '\n';
	cout << myImprimantaThree.getTipImprimanta << '\n';

	//5
	Imprimanta myImprimantaFourth;
	myImprimantaFourth = myImprimantaThree;
	cout << myImprimantaFourth << endl;
	cout << myImprimantaFourth.getNrPaginiPrintate() << '\n';
	cout << myImprimantaFourth.getTipImprimanta << '\n';

	//6
	//Acest membru este inaccesibil pentru a fi utilizat in main() dar functioneaza conform testului

	//7
	//Am modificat acest membru si am creat o functie publica de acces
	Imprimanta myImprimantaFifth(212122, "Sony", 250);
	cout << myImprimantaFifth.getTipImprimanta() << '\n';

	//8
	Imprimanta Imprimante[] = {
	  Imprimanta(1, "HP", 100),
	  Imprimanta(2, "Canon", 50),
	  Imprimanta(3, "HP", 200),
	  Imprimanta(4, "Epson", 75)
	};
	cout << Imprimante->getNumarPaginiRamase();

	//9
	Cartus c1;
	Imprimanta i1;
	i1.setCartus(c1);
	Cartus c2 = i1.getCartus();
	int nrTotalPagini = c2.getNrTotalPagini();
	cout << "Numar total de pagini in cartusul asociat imprimantei: " << nrTotalPagini << endl;

	//10
	Imprimanta myImprimantaSix(222121, "Canon", 250);
	cout << myImprimantaSix.getNumarPaginiRamase();

	//11
	cout << myImprimantaFifth.getNumarPaginiRamase() << endl;
	cout << myImprimantaSix << endl;

	//12
	cout << myImprimantaSix;


	return 0;
}