#include <iostream>
#include <vector>
#include <string>

class Medicam {
private:
    char* nume;
    int concentr;
    std::string subsAct;
    double pret;

public:
    Medicam() {
        nume = nullptr;
        concentr = 0;
        subsAct = "";
        pret = 0.0;
    }

    Medicam(const char* numeMedicament, int concentratie, const std::string& substantaActiva, double pretMedicament) {
        nume = new char[strlen(numeMedicament) + 1];
        strcpy_s(nume, strlen(numeMedicament) + 1, numeMedicament);
        concentr = concentratie;
        subsAct = substantaActiva;
        pret = pretMedicament;
    }

    ~Medicam() {
        delete[] nume;
    }

    friend std::ostream& operator<<(std::ostream& os, const Medicam& m) {
        os << m.nume << " - " << m.concentr << " - " << m.subsAct << " - " << m.pret;
        return os;
    }
};

class Reteta {
private:
    std::vector<Medicam>* medicam;
    int nrMed;

public:
    Reteta(Medicam* m, int n) {
        medicam = new std::vector<Medicam>(m, m + n);
        nrMed = n;
    }

    ~Reteta() {
        delete medicam;
    }

    friend std::ostream& operator<<(std::ostream& os, const Reteta& r) {
        os << "Reteta contine " << r.nrMed << " medicamente:\n";
        for (int i = 0; i < r.nrMed; i++) {
            os << r.medicam->at(i) << "\n";
        }
        return os;
    }
};

int main() {
    Medicam A[] = {Medicam("Medicament 1", 10, "Substanta activa 1", 5.0),
                   Medicam("Medicament 2", 20, "Substanta activa 2", 10.0),
                   Medicam("Medicament 3", 30, "Substanta activa 3", 15.0),
                   Medicam("Medicament 4", 40, "Substanta activa 4", 20.0)};
    Reteta r1(A, 4);
    std::cout << r1;
    return 0;
}
