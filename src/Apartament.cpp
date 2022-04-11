#include "../include/Apartament.h"

#include <iostream>
#include <string>

Apartament::Apartament(): Locuinta()
{
    this->etaj = 0;
}

Apartament::Apartament(std::string numeClient, int suprafataUtila, double discount, int etaj): 
Locuinta(numeClient, suprafataUtila, discount)
{
    this->etaj = etaj;
}

Apartament::Apartament(const Apartament& A): Locuinta(A)
{
    this->etaj = A.etaj;
}

// Apartament::~Apartament()
// {
//     
// }

Apartament Apartament::operator=(Apartament A)
{
    Locuinta& L = A;
    this->Locuinta::operator=(L);

    this->etaj = A.etaj;

    return *this;
}

double Apartament::CalculChirie(int X, int Y)
{
    return X * suprafataUtila * (1 - Y * discount / 100.0);
}

void Apartament::CitireLocuinta()
{
    using namespace std;
    {
        cout << "CITIRE APARTAMENT\n\n";

        cout << "Numele clientului: ";
        getline(cin, this->numeClient);
        cout << "Discountul aplicat: ";
        cin >> this->discount;
        cout << "Suprafata utila: ";
        cin >> this->suprafataUtila;
        cout << "Etajul: ";
        cin >> this->etaj;

        cout << "\n";
    } // namespace std
}

void Apartament::AfisareLocuinta()
{
    using namespace std;
    {
        cout << "AFISARE APARTAMENT\n\n";

        cout << "Numele clientului: " << this->numeClient << "\n";
        cout << "Discountul aplicat: " << this->discount << "\n";
        cout << "Suprafata utila: " << this->suprafataUtila << "\n";
        cout << "Etajul: " << this->etaj << "\n";

        cout << "\n";
    } // namespace std
    
}
