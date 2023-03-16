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

void Discipline(student studenti[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "Disciplinele pentru studentul " << i + 1 << ": ";
        for (int j = 0; j < 3; j++)
            cin >> studenti[i].note[j].disciplina;
    }
}

void DateStudent(student studenti[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Introduceti numele studentului: ";
        cin >> studenti[i].nume;
        cout << "Introduceti prenumele studentului (foloti '_' pentru a desparti prenumele): ";
        cin >> studenti[i].prenume;
        cout << "Introduceti facultatea studentului: ";
        cin >> studenti[i].facultate;
        cout << "Introduceti notele pentru cele 3 discipline: " << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Nota pentru disciplina " << studenti[i].note[j].disciplina << ": ";
            cin >> studenti[i].note[j].valoare;
        }
    }
}

void AfisareStudenti(student studenti[], int n)
{
    cout << "Lista studentilor: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Studentul " << i + 1 << ": " << studenti[i].nume << " " << studenti[i].prenume << " din facultatea " << studenti[i].facultate << endl;
        for (int j = 0; j < 3; j++)
            cout << "Disciplina " << studenti[i].note[j].disciplina << ": " << studenti[i].note[j].valoare << endl;
    }
}

float CalculMedie(student s)
{
    float suma = 0;
    for (int i = 0; i < 3; i++)
        suma += s.note[i].valoare;
    return suma / 3;
}

void ListaMedii(student studenti[], int n)
{
    cout << "Lista mediilor studentilor: " << endl;
    for (int i = 0; i < n; i++)
    {
        float medie = CalculMedie(studenti[i]);
        cout << studenti[i].nume << " " << studenti[i].prenume << ": " << medie << endl;
    }
}

void ListaStudentiMedieDescrescatoare(student studenti[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            float medie1 = CalculMedie(studenti[j]);
            float medie2 = CalculMedie(studenti[j + 1]);
            if (medie1 < medie2)
            {
                student aux = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = aux;
            }
        }
    }
    cout << "Lista studentilor in ordine descrescatoare a mediilor celor 3 discipline: " << endl;
    for (int i = 0; i < n; i++)
        cout << studenti[i].nume << " " << studenti[i].prenume << " - Medie: " << CalculMedie(studenti[i]) << endl;
}

void CautareStudent(student studenti[], int n)
{
    char NumeCautat[20];
    cout << "Introduceti numele studentului cautat: ";
    cin >> NumeCautat;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(studenti[i].nume,NumeCautat) == 0)
        {
            cout << "Studentul " << studenti[i].nume << " " << studenti[i].prenume << " din faculatea " << studenti[i].facultate << endl;
            for (int j = 0; j < 3; j++)
                cout << "Disciplina " << studenti[i].note[j].disciplina << ": " << studenti[i].note[j].valoare << endl;
            return;
        }
    }
    cout << "Studentul " << NumeCautat << " nu a fost gasit." << endl;
}

void AfisareMedii(student studenti[], int n)
{
    float SumaMedii = 0;
    float MedieMaxima = 0;
    float MedieMinima = 10;
    for (int i = 0; i < n; i++)
    {
        float medie = CalculMedie(studenti[i]);
        SumaMedii += medie;
        if (medie > MedieMaxima)
            MedieMaxima = medie;
        if (medie < MedieMinima)
            MedieMinima = medie;
    }
    float MedieGenerala = SumaMedii / n;
    cout << "Media maxima: " << MedieMaxima << endl;
    cout << "Media minima: " << MedieMinima << endl;
    cout << "Medie mediilor: " << MedieGenerala << endl;
}

void Meniu(student studenti[], int n)
{
    int optiune;
    do {
        cout << endl << endl;
        cout << "========== Bun venit in meniu! ==========" << endl;
        cout << "|1) Introducere 3 discipline pentru 5 studenti" << endl;
        cout << "|2) Introducere date student, cu notele pentru cele 3 discipline" << endl;
        cout << "|3) Afisare datele studentilor" << endl;
        cout << "|4) Lista mediilor tuturor studentilor" << endl;
        cout << "|5) Lista studentilor in ordine descrescatoare a mediilor celor 3 discipline" << endl;
        cout << "|6) Cautare un student" << endl;
        cout << "|7) Afisarea mediei maxime, minime si a mediei mediilor pentru studentii din evidenta introdusa" << endl;
        cout << "|0) Iesire" << endl;
        cout << "=========================================" << endl << endl;
        cout << "Introduceti optiunea: ";
        cin >> optiune;
        cout << endl;
        switch (optiune)
        {
        case 1:
            Discipline(studenti, n);
            break;
        case 2:
            DateStudent(studenti, n);
            break;
        case 3:
            AfisareStudenti(studenti, n);
            break;
        case 4:
            ListaMedii(studenti, n);
            break;
        case 5:
            ListaStudentiMedieDescrescatoare(studenti, n);
            break;
        case 6:
            CautareStudent(studenti, n);
            break;
        case 7:
            AfisareMedii(studenti, n);
        case 0:
            cout << "La revedere!";
            break;
        default:
            cout << "Optiune invalida!" << endl;
        }

    } while (optiune != 0);
}

int main()
{
    const int n = 5;
    student studenti[n];
    Meniu(studenti, n);
    return 0;
}