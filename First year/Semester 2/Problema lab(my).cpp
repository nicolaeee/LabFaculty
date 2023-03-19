
///*Sa se defineasca tipul de date note cu datele:
//Disciplina - char
//nota - int
//Sa se defineasca tipul de date student cu datele:
//Nume - char
//Prenume -char
//Facultate - string
//note notele[3]
//Sa se creeze un meniu de selectare a urmatoarelor functii:
//- introducere 3 discipline pentru 5 studenti
//- introducere date student, cu notele pentru cele 3 discipline
//- afisare datele studentilor
//- lista mediilor tuturor studentilor
//- lista studentilor in ordine descrescatoare a mediilor celor 3 discipline
//- cautare un student, prin selectare? numelui acestuia din vectorul cu studenti
//- afisarea mediiei maxime, minime si a mediei mediilor pentru studentii din evidenta introdusa*/

#include <iostream>
using namespace std;
struct note {
    char disciplina[20];
    int valoare;
};


struct student {
    char nume[20];
    char prenume[20];
    string facultate;
    note note[3];
};

//- introducere 3 discipline pentru 5 studenti
void discip(student s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Disciplinele pentru studentul " << i + 1 << ": ";
        for (int j = 0; j < 3; j++) {
            cin >> s[i].note[j].disciplina;
        }

    }
}

//- introducere date student, cu notele pentru cele 3 discipline
void dateStudent(student s[], int n) {
    cout << "Introdu datele(numele si prenumele)\n";
    for (int i = 0; i < n; i++) {
        cout << "Numele\n"; cin >> s[i].nume;
        cout << "Prenumele\n "; cin >> s[i].prenume;
        cout << "Introduceti notele pentru cele 3 discipline: \n" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Nota pentru disciplina " << s[i].note[j].disciplina << ": ";
            cin >> s[i].note[j].valoare;
        }
    }
}
//- afisare datele studentilor
void afisStudent(student s[], int n) {
    cout << "Lista studentilor: " << endl;
    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "Student " << i + 1 << ": " << s[i].nume << " " << s[i].prenume << endl;
        for (int j = 0; j < 3; j++)
            cout << "Disciplina " << s[i].note[j].disciplina << ": " << s[i].note[j].valoare << endl;
    }
}

float calcMedie(student s) {
    float sum = 0;
    for (int i = 0; i < 3; i++)
        sum += s.note[i].valoare;
    return sum / 3;
}
//- lista mediilor tuturor studentilor
void listMedie(student s[], int n) {
    cout << "Lista mediilor studentilor: " << endl;
    for (int i = 0; i < n; i++) {
        float med = calcMedie(s[i]);
        cout << s[i].nume << "   " << s[i].prenume << ": " << med << endl;
    }
}


void menu(student s[], int n) {
    cout << "Meniul de intorducerea si afisarea datelor intorduse:\n ";
    for (int i = 0; i < n; i++) {
        cout << "Astept 3 discipline pentru fiecare studnet\n";
        discip(s, n);
        cout << "Afisare dateStudent:\n";
        dateStudent(s, n);
        cout << "Afisare student\n";
        afisStudent(s, n);
        cout << "Lista de medii\n";
        listMedie(s, n);
    };
}

int main() {
    cout << "Datele cerute:\n";
    const int n = 5;
    student s[n];
    menu(s, n);
}