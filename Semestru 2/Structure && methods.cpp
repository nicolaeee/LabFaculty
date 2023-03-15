#include <iostream>
using namespace std;

struct drept
{
	double lung, lat;

	//aici vin metodele structurii(functiile create de programator)
	void cit();
	void afis();
	double perim();
	double arie();


};

void drept::cit(){
	cout << "Lungimea= "; cin >> lung;
	cout << "Latimea= "; cin >> lat;

}

void drept::afis() {
	cout<< "Dreptunghi[ " << lung << ", " << lat << "]\n";
}

double drept::perim() {
	return 2 * (lung + lat);
}

double drept::arie() {
	return lung * lat;
}
int main() {
	drept a, b, c;

	//citirea(asemanator cu tema noastra)

	a.cit();
	//afisarea
	cout << "a = "; a.afis();
	cout << endl;

	cout << "Permetrul lui a = "<<a.perim();
	cout << endl;
	cout << "Arie lui a = "<< a.arie();


}