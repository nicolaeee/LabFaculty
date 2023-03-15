#include <iostream>
using namespace std;

class complex {
	double pr, pi; //acces is alredy private here
public://this is a method of a calss(functions)
	void cit();
	void afis();
	double module();
};

void complex::cit() {
	cout << "Partea reala: "; cin >> pr;
	cout << "Partea imaginara: "; cin >> pi;

};

void complex::afis() {
	cout << "Partea reala" << pr;
	cout << "Partea imaginara" << pi << endl;
	cout << pr << "+i*" << pi;

};

double complex::module() {
	return sqrt(pr * pi + pow(pi, 2));
}

int main() {
	complex a, b, c;

	a.cit();
	cout << "a= "; a.afis();
	cout << "MOdule" << a.module();
}
