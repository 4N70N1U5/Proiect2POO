#include "../include/Casa.h"

#include <iostream>
#include <string>

Casa::Casa(): Locuinta()
{
    this->suprafataCurte = 0;
}

Casa::Casa(std::string numeClient, int suprafataUtila, double discount, int suprafataCurte): 
Locuinta(numeClient, suprafataUtila, discount)
{
    this->suprafataCurte = suprafataCurte;
}

Casa::Casa(const Casa& C): Locuinta(C)
{
    this->suprafataCurte = C.suprafataCurte;
}

// Casa::~Casa()
// {
//     delete this;
// }

Casa Casa::operator=(Casa C)
{
    Locuinta& L = C;
    this->Locuinta::operator=(C);

    this->suprafataCurte = C.suprafataCurte;

    return *this;
}

double Casa::CalculChirie(int X, int Y)
{
    return X * (suprafataUtila + 0.2 * suprafataCurte) * (1 - Y * discount / 100.0);
}

void Casa::CitireLocuinta()
{
    using namespace std;
    {
        cout << "CITIRE CASA\n\n";

        cout << "Numele clientului: ";
        getline(cin, this->numeClient);
        cout << "Discountul aplicat: ";
        cin >> this->discount;
        cout << "Suprafata utila: ";
        cin >> this->suprafataUtila;
        cout << "Suprafata curtii: ";
        cin >> this->suprafataCurte;

        cout << "\n";
    } // namespace std
}

void Casa::AfisareLocuinta()
{
    using namespace std;
    {
        cout << "AFISARE CASA\n\n";

        cout << "Numele clientului: " << this->numeClient << "\n";
        cout << "Discountul aplicat: " << this->discount << "\n";
        cout << "Suprafata utila: " << this->suprafataUtila << "\n";
        cout << "Suprafata curtii: " << this->suprafataCurte << "\n";

        cout << "\n";
    } // namespace std
}
