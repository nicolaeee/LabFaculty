#include <iostream>
#include <string>
using namespace std;

class Cartus
{
private:
	string producator;
	int nrTotalPagini;
};

class Imprimanta
{
private:
	const int serialNumber = 0;
	char* producator;
	int nrPaginiPrintate;
	static string tipImprimanta;

public:
	Imprimanta()
	{
	}

	Imprimanta(int serialNumber, char* producator, int nrPaginiPrintate)
	{
	}

	Imprimanta operator=(Imprimanta i)
	{
		return *this;
	}

	bool operator<(Imprimanta t)
	{
		return false;
	}

	static string getTipImprimanta()
	{
		return "";
	}

	static void setTipImprimanta(string tipImprimanta)
	{
	}

	static long getTotalPaginiPerProducator(Imprimanta* imprimante, int nrImprimante, char* producator)
	{
		return 0;
	}

	void setCartus(Cartus c)
	{
	}

	Cartus getCartus()
	{
		Cartus c;
		return c;
	}

	int getNumarPaginiRamase()
	{
		return 0;
	}

	void serialize(string fileName)
	{

	}

	void deserialize(string fileName)
	{

	}
	
	
friend ostream& operator<<(ostream& out, Imprimanta)
{
	return out;
}

friend istream& operator>>(istream& in, Imprimanta)
{
	return in;
}
};

string Imprimanta::tipImprimanta = "";

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
	//Se vor testa in  main TOATE FUNCTIILE IMPLEMENTATE!!!!!
	//Veti incarca pe TEAMS o arhiva care va contine solutia MS-VisualStudio 2019!
}

//Teste 
#include "CppUnitTest.h"
#include<math.h>
#include <fstream>
#define private public
#include "..//Tema3_ID/Source.cpp"
#undef private

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TesteUnitare)
	{
	public:
		
		TEST_METHOD(_01TestareConstructorImplicit)
		{
			Imprimanta imprimanta;
			Assert::IsTrue(strlen(imprimanta.producator)==0,
				L"Constructorul nu initializeaza corect numele producatorului");
			Assert::IsTrue(imprimanta.nrPaginiPrintate == 0,
				L"Constructorul nu initializeaza corect numarul de pagini");
		}

		TEST_METHOD(_02TestareConstructorCu3Parametri)
		{
			char* producator = "Canon";
			Imprimanta x(12345, producator, 250);
			Assert::IsTrue(x.serialNumber == 12345,
				L"Constructorul nu initializeaza corect serialNumber");
			Assert::IsTrue(strcmp(x.producator, producator)==0,
				L"Constructorul nu initializeaza corect producatorul");
			Assert::IsTrue(x.producator != producator,
				L"Constructorul nu initializeaza corect producatorul");
			Assert::IsTrue(x.nrPaginiPrintate == 250,
				L"Constructorul nu initializeaza corect numarul de pagini printate");
			Imprimanta y;
			Assert::IsTrue(y.serialNumber == 1,
				L"Constructorul implicit nu initializeaza corect serialNumber");
		}

		TEST_METHOD(_03TestareDestructor)
		{
			Imprimanta* pi = new Imprimanta(456, "Test", 1200);
			char* pointer = pi->producator;
			delete pi;
			Assert::IsTrue(pointer != pi->producator,
				L"Destructorul nu sterge zona de memorie alocata dinamic");
		}

		TEST_METHOD(_04TestareConstructorDeCopiere)
		{
			Imprimanta x(45678, "Dell", 1500);
			Imprimanta y = x;
			Assert::IsTrue(x.serialNumber == y.serialNumber,
				L"Constructorul nu copiaza corect serialNumber");
			Assert::IsTrue(x.nrPaginiPrintate == y.nrPaginiPrintate,
				L"Constructorul nu copiaza corect nrPaginiPrintate");
			Assert::IsTrue(strcmp(x.producator, y.producator) == 0,
				L"Constructorul nu copiaza corect producatorul");
			Assert::IsTrue(x.producator != y.producator,
				L"Constructorul nu copiaza corect producatorul");
		}


		TEST_METHOD(_05TestareOperatorAtribuire)
		{
			char* producator1 = "Dell";
			char* producator2 = "HP";
			Imprimanta x(45678, producator1, 1500);
			Imprimanta y(12345, producator2, 1200);
			Imprimanta z;
			z = y = x;
			Assert::IsTrue(y.producator != producator2,
				L"Operatorul nu dezaloca spatiul de memorie");
			Assert::IsTrue(x.nrPaginiPrintate == y.nrPaginiPrintate,
				L"Operatorul nu copiaza corect nrPaginiPrintate");
			Assert::IsTrue(strcmp(x.producator, y.producator) == 0,
				L"Operatorul nu copiaza corect producatorul");
			Assert::IsTrue(x.producator != y.producator,
				L"Operatorul nu copiaza corect producatorul");
		}

		TEST_METHOD(_06TestareAtributStatic)
		{
			Assert::IsTrue(Imprimanta::tipImprimanta == "Cerneala",
				L"Campul static nu este initializat corect");
		}

		TEST_METHOD(_07TestareMetodeAccesStatice)
		{
			Imprimanta::tipImprimanta = "Laser";
			Assert::IsTrue(Imprimanta::getTipImprimanta() == "Laser",
				L"Getter-ul pentru campul static nu returneaza corect valoarea");
			Imprimanta::setTipImprimanta("Imprimanta 3D");
			Assert::IsTrue(Imprimanta::tipImprimanta == "Imprimanta 3D",
				L"Setter-ul pentru campul static nu seteaza corect valoarea");
		}

		TEST_METHOD(_08TestareMetodeStaticaDeCalcul)
		{
			long result = Imprimanta::getTotalPaginiPerProducator(NULL, 0, NULL);
			Assert::IsTrue(result == 0,
				L"Metoda statica nu valideaza vectorul primit ca parametru");
			Imprimanta i1(1, "Dell", 120);
			Imprimanta i2(2, "HP", 250);
			Imprimanta i3(3, "Dell", 240);
			Imprimanta i4(4, "HP", 190);
			Imprimanta i5(5, "Canon", 100);
			Imprimanta v[] = { i1, i2, i3, i4, i5 };
			result = Imprimanta::getTotalPaginiPerProducator(v, 0, "Dell");
			Assert::IsTrue(result == 0,
				L"Metoda statica nu valideaza numarul de elemente");
			result = Imprimanta::getTotalPaginiPerProducator(v, 5, "Delly");
			Assert::IsTrue(result == 0,
				L"Metoda statica nu returneaza rezultatul corect");
			result = Imprimanta::getTotalPaginiPerProducator(v, 5, "Dell");
			Assert::IsTrue(result == 360,
				L"Metoda statica nu returneaza rezultatul corect");
			result = Imprimanta::getTotalPaginiPerProducator(v, 5, "HP");
			Assert::IsTrue(result == 440,
				L"Metoda statica nu returneaza rezultatul corect");
			result = Imprimanta::getTotalPaginiPerProducator(v, 5, "Canon");
			Assert::IsTrue(result == 100,
				L"Metoda statica nu returneaza rezultatul corect");
		}

		TEST_METHOD(_09TestareRelatieCompunere)
		{
			Cartus c;
			c.producator = "Auchan";
			c.nrTotalPagini = 500;
			Imprimanta x;
			x.setCartus(c);
			Cartus d = x.getCartus();
			Assert::IsTrue(d.producator == "Auchan",
				L"Metoda setCartus nu functioneaza corect");
			Assert::IsTrue(d.nrTotalPagini == 500,
				L"Metoda setCartus nu functioneaza corect");
		}

		TEST_METHOD(_10TestareGetNumarPaginiRamase)
		{
			Cartus c;
			c.producator = "Auchan";
			c.nrTotalPagini = 500;
			Imprimanta x(123, "Dell", 150);
			x.setCartus(c);
			int result = x.getNumarPaginiRamase();
			Assert::IsTrue(result == 350,
				L"Metoda setCartus nu functioneaza corect");
			Imprimanta y(456, "HP", 600);
			y.setCartus(c);
			result = y.getNumarPaginiRamase();
			Assert::IsTrue(result == 0,
				L"Metoda setCartus nu functioneaza corect");
		}

		TEST_METHOD(_11TestareOperatorMaiMic)
		{
			Imprimanta i1(1, "Dell", 120);
			Imprimanta i2(2, "HP", 250);

			bool result = i1 < i2;

			Assert::IsTrue(result,
				L"Operatorul < nu functioneaza corect");
			result = i2 < i1;
			Assert::IsFalse(result,
				L"Operatorul < nu functioneaza corect");
		}

		TEST_METHOD(_12TestareAfisareConsola)
		{
			Imprimanta imp(1, "Dell", 120);

			stringstream out;
			out << imp;
			string result = out.str();
			Assert::IsTrue(result.find("Serial number: 1") != string::npos,
				L"Operatorul de afisare nu afiseaza corect serial number");
			Assert::IsTrue(result.find("Producator: Dell") != string::npos,
				L"Operatorul de afisare nu afiseaza corect producatorul");
			Assert::IsTrue(result.find("Numar pagini printate: 120") != string::npos,
				L"Operatorul de afisare nu afiseaza corect numarul de pagini printate");
		}

		TEST_METHOD(_13TestareCitireConsola)
		{
			string value = "Hewlett Packard\n543";
			stringstream in;
			in << value;
			Imprimanta imp;
			
			Assert::IsTrue(strcmp(imp.producator, "Hewlett Packard") == 0,
				L"Operatorul de citire nu citeste corect producatorul");
			Assert::IsTrue(imp.nrPaginiPrintate == 543,
				L"Operatorul de citire nu citeste corect numarul de pagini printate");
		}

		TEST_METHOD(_14TestareScriereCitireText)
		{
			Imprimanta imp(1, "Dell", 120);
			ofstream f("fisier.txt");
			f << imp;
			f.close();

			ifstream g("fisier.txt");
			Imprimanta x;
		
			g.close();

			Assert::IsTrue(strcmp(imp.producator, x.producator) == 0,
				L"Eroare citire/scriere producator");
			Assert::IsTrue(imp.producator != x.producator,
				L"Eroare citire/scriere producator");
			Assert::IsTrue(imp.nrPaginiPrintate == x.nrPaginiPrintate,
				L"Eroare citire/scriere numar de pagini printate");
		}

		TEST_METHOD(_15TestareScriereCitireBinara)
		{
			Imprimanta imp(1, "Dell", 120);
			imp.serialize("imprimanta.dat");

			Imprimanta x;
			x.deserialize("imprimanta.dat");

			Assert::IsTrue(strcmp(imp.producator, x.producator) == 0,
				L"Eroare citire/scriere producator");
			Assert::IsTrue(imp.producator != x.producator,
				L"Eroare citire/scriere producator");
			Assert::IsTrue(imp.nrPaginiPrintate == x.nrPaginiPrintate,
				L"Eroare citire/scriere numar de pagini printate");
		}
	};
}
