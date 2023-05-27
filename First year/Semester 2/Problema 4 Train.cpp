#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstring> 
#include <map>
using namespace std;

template <typename T>
T concatenate(T first, T second)
{
	// Concatenate the wagon vectors of the two objects
	first.setWeigth(first.nbOfWagons + second.nbOfWagons,
		concatenateArrays(first.weigthPerWagon, second.weigthPerWagon,
			first.nbOfWagons, second.nbOfWagons));

	return first;
}


template <typename T>
T* concatenateArrays(const T* first, const T* second, int sizeFirst, int sizeSecond)
{
	T* concatenated = new T[sizeFirst + sizeSecond];

	for (int i = 0; i < sizeFirst; i++)
	{
		concatenated[i] = first[i];
	}

	for (int i = 0; i < sizeSecond; i++)
	{
		concatenated[sizeFirst + i] = second[i];
	}

	return concatenated;
}


class Comparable
{
public:
	virtual int compare(Comparable& c) = 0;
};

class TrainRoute
{
private:
	string departure;
	string destination;
	char* trainCode;

public:
	TrainRoute(string departure, string destination, const char* trainCode)
		: departure(departure), destination(destination), trainCode(new char[strlen(trainCode) + 1])
	{
		strcpy_s(this->trainCode, strlen(trainCode) + 1, trainCode);
	}
	// Constructorul de copiere
	TrainRoute(const TrainRoute& other)
		: departure(other.departure), destination(other.destination), trainCode(new char[strlen(other.trainCode) + 1])
	{
		strcpy_s(trainCode, strlen(other.trainCode) + 1, other.trainCode);
	}

	// Operatorul de atribuire
	TrainRoute& operator=(const TrainRoute& other)
	{
		if (this != &other)
		{
			delete[] trainCode;

			departure = other.departure;
			destination = other.destination;
			trainCode = new char[strlen(other.trainCode) + 1];
			strcpy_s(trainCode, strlen(other.trainCode) + 1, other.trainCode);
		}

		return *this;
	}

	virtual int totalWeight()
	{
		return 100;
	}

	string getDeparture() const
	{
		return departure;
	}

	string getDestination() const
	{
		return destination;
	}

	const char* getTrainCode() const
	{
		return trainCode;
	}

	char* getTrainCode()
	{
		return trainCode;
	}

	void setTrainCode(const char* code)
	{
		if (trainCode == code) {
			return; // Avoid self-assignment
		}

		delete[] trainCode;
		trainCode = nullptr;

		if (code != nullptr) {
			trainCode = new char[strlen(code) + 1];
			strcpy_s(trainCode, strlen(code) + 1, code);
		}
	}


	// Destructorul
	virtual ~TrainRoute() {
		delete[] trainCode;
	}


};




class FreightTrainRoute : public TrainRoute, public Comparable
{
protected:
	int nbOfWagons;
	float* weigthPerWagon;

public:
	FreightTrainRoute() : TrainRoute("", "", "Necunoscut"), nbOfWagons(0), weigthPerWagon(nullptr)
	{
	}

	FreightTrainRoute(string departure, string destination, const char* trainCode) :
		TrainRoute(departure, destination, trainCode), nbOfWagons(0), weigthPerWagon(nullptr)
	{
	}

	void setWeigth(int nbOfWagons, float* weightPerWagon)
	{

		delete[] this->weigthPerWagon;
		this->weigthPerWagon = new float[nbOfWagons];

		for (int i = 0; i < nbOfWagons; i++)
		{
			this->weigthPerWagon[i] = weightPerWagon[i];
		}

		this->nbOfWagons = nbOfWagons;
	}

	int totalWeight() override
	{
		float total = 0.0;
		for (int i = 0; i < nbOfWagons; i++)
		{
			total += weigthPerWagon[i];
		}

		return static_cast<int>(total);
	}

	// Constructorul de copiere
	FreightTrainRoute(const FreightTrainRoute& other)
		: TrainRoute(other), nbOfWagons(other.nbOfWagons), weigthPerWagon(nullptr)
	{
		if (other.weigthPerWagon != nullptr)
		{
			weigthPerWagon = new float[nbOfWagons];
			for (int i = 0; i < nbOfWagons; i++)
			{
				weigthPerWagon[i] = other.weigthPerWagon[i];
			}
		}
	}

	// Operatorul de atribuire
	FreightTrainRoute& operator=(const FreightTrainRoute& other)
	{
		if (this != &other)
		{
			TrainRoute::operator=(other);

			nbOfWagons = other.nbOfWagons;

			delete[] weigthPerWagon;
			weigthPerWagon = nullptr;

			if (other.weigthPerWagon != nullptr)
			{
				weigthPerWagon = new float[nbOfWagons];
				for (int i = 0; i < nbOfWagons; i++)
				{
					weigthPerWagon[i] = other.weigthPerWagon[i];
				}
			}
		}

		return *this;
	}



	~FreightTrainRoute()
	{
		delete[] weigthPerWagon;
	}

	int compare(Comparable& c) override
	{
		FreightTrainRoute* other = dynamic_cast<FreightTrainRoute*>(&c);
		if (other)
		{
			int thisWeight = totalWeight();
			int otherWeight = other->totalWeight();

			if (thisWeight < otherWeight)
				return -1;
			else if (thisWeight > otherWeight)
				return 1;
			else
				return 0;
		}
		else
		{
			// Handle the case when 'c' is not of type FreightTrainRoute
			// You can choose an appropriate return value or throw an exception
		}
	}

	int getNbOfWagons() const
	{
		return nbOfWagons;
	}

	const float* getWeightPerWagon() const
	{
		return weigthPerWagon;
	}

};


ostream& operator<<(ostream& o, const TrainRoute& t)
{
	o << "Departure: " << t.getDeparture() << endl;
	o << "Destination: " << t.getDestination() << endl;
	o << "Train code: " << t.getTrainCode() << endl;

	return o;
}


istream& operator>>(istream& i, TrainRoute& t)
{
	string departure;
	cout << "Enter departure: ";
	getline(i, departure);
	t.getDeparture() = departure;

	string destination;
	cout << "Enter destination: ";
	getline(i, destination);
	t.getDestination() = destination;

	cout << "Enter train code: ";
	char trainCode[100];
	i.getline(trainCode, 100);

	delete[] t.getTrainCode();
	t.setTrainCode(trainCode);
	t.getTrainCode();

	return i;
}





bool operator<(const FreightTrainRoute& f1, const FreightTrainRoute& f2)
{
	return false;
}

vector<float> ArrayToVector(const FreightTrainRoute& v)
{
	vector<float> weightVector(v.getNbOfWagons());

	for (int i = 0; i < v.getNbOfWagons(); i++)
	{
		weightVector[i] = v.getWeightPerWagon()[i];
	}

	return weightVector;
}


map<char*, FreightTrainRoute> ObjectsToMap(FreightTrainRoute* trains, int nbOfTrains)
{
	return map<char*, FreightTrainRoute>();
}

set<FreightTrainRoute>::iterator FindMyTrain(set<FreightTrainRoute> s, char* trainCode)
{
	return set<FreightTrainRoute>::iterator();
}

//ATENTIE!!!
//* Sunt punctate doar solutiile originale si individuale
//* Orice incercare de frauda va duce la pierderea intregului punctaj de la seminar
//* Signatura functiilor se poate modifica doar pentru a realiza supradefinirea
//* Utilizarea valorilor din teste pentru a obtine rezultate fals pozitive este considerata frauda

//1. Modificati constructorul cu parametri din clasa TrainRoute pentru a initializa
//statia de plecare, statia de sosire si codul trenului

//2. Respectati "regula celor 3" in cadrul clasei TrainRoute

//3. Modificati operatorul de scriere la consola pentru a afisa informatiile despre ruta
//se pot folosi functii friend sau getteri
//afisarea va fi de forma:
//Departure: departure
//Destination: destination
//Train code: trainCode

//Modificati operatorul de citire de la consola pentru a citi informatii despre ruta
//se vor citi in ordine urmatoarele informatii (fiecare pe o linie noua)
//Departure
//Destination
//Train code
//se pot folosi setteri sau functii friend
//operatorul trebuie sa poata citi siruri de caractere ce contin spatii

//4. Modificati constructorul implicit al clasei FreightTrainRoute
//acesta va initializa numarul de vagoane cu 0 si vectorul de greutati cu nullptr
//statia de plecare si destinatia vor fi initializate cu un sir vid
//codul trenului va fi "Necunoscut"

//5. Modificati constructorului cu parametri al clasei FreightTrainRoute
//astfel incat sa initializeze corect statia de plecare, destinatia si codul trenului
//numarul de vagoane si vectorul de greutati vor ramane 0, respectiv nullptr
//clasa TrainCode nu se poate modifica pentru a contine constructor implicit

//6. Modificati metoda setWeigth astfel incat sa se poata modifica
//vectorul de greutati si numarul de vagoane

//7. Aplicati "regula celor 3" si in clasa derivata

//8. Supraincarcati operatorii de citire si afisare pentru clasa derivata
//cel de afisarea arata in plus urmatoarele linii la consola
//Nb of wagons: nbOfWagons
//Weigth per wagon: weigth1 weigth2 etc.
//se va afisa doar partea intreaga a greutatilor (fara zecimale)
//cel de citire va citi in continuare numarul de vagoane de pe o linie noua
//si greutatile separate prin spatii

//9. Supradefiniti metoda totalWeight in clasa FreightTrainRoute
//astfel incat sa returneze greutatea totala a trenului ca intreg
//prin trunchiere (se ignora zecimalele rezultatului final)

//10. Evitati memory leaks generate odata cu virtualizarea

//11. Derivati clasa FreightTrainRoute din interfata Comparable
//si supradefiniti metoda pur virtuala compare
//functia va compara greutatile totale a doua trenuri si va returna
//-1 daca primul tren este mai usor decat al doilea
//0 daca au greutati egale
//1 daca primul tren este mai greu decat al doilea

//12. Modificati functia template (sablon) concatenate
//astfel incat sa functioneze pentru obiecte de tip FreightTrainRoute
//dar si pentru orice clasa derivata din FreightTrainRoute
//functia va concatena cei doi vectori de vagoane din cele doua obiecte
//si va returna un obiect cu detaliile primului tren si vectorul concatenat

//13. Modificati functia globala ArrayToVector
//astfel incat sa returneze vectorul alocat dinamic de greutati
//din obiectul de tip FreightTrainRoute ca vector STL

//14. Modificati functia globala ObjectsToMap
//astfel incat sa returneze o colectie STL de tip map
//ce are drept chei codurile trenurilor din vectorul primit drept parametru
//si drept valori obiectele de tip FreightTrainRoute corespunzatoare elementelor din vector

//15. Modificati functia globala FindMyTrain astfel incat sa returneze un iterator
//ce pointeaza catre elementul din set-ul primit drept parametru ce are codul trenului
//egal cu valoarea trainCode primita drept parametru, sau set.end() daca nu exista
//acel cod de tren in set-ul primit drept parametru

int main(){
	return 0;
}