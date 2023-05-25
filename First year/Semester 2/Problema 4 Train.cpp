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