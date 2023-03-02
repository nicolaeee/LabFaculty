#include <iostream>
using namespace std;

int main() {
	struct persoana {
		char nume[25];
		int varsta;
		char stare_civ; //C - casatorit || N - necasatorit
	};

	struct alldat {
		persoana descrip;
		char meniu[25];
	} s[53];

	alldat profesor, student;
	
	profesor.descrip.varsta = 34;
	profesor.descrip.stare_civ = 'C';

	//Afisarea

	cout << profesor.descrip.varsta;
}