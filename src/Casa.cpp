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

Casa::~Casa()
{
    
}

Casa Casa::operator=(Casa C)
{
    Locuinta& L = C;
    this->Locuinta::operator=(C);

    this->suprafataCurte = C.suprafataCurte;

    return *this;
}

std::istream& operator>>(std::istream& i, Casa& C)
{
    Locuinta& L = C;

    i >> L;

    std::cout << "Suprafata curtii: ";
    i >> C.suprafataCurte;

    return i;
}

std::ostream& operator<<(std::ostream& o, const Casa& C)
{
    const Locuinta& L = C;
    
    o << L;
    
    o << "Suprafata curtii: " << C.suprafataCurte << "\n";
    
    return o;
}

double Casa::CalculChirie(int X, int Y)
{
    return X * (suprafataUtila + 0.2 * suprafataCurte) * (1 - Y * discount / 100.0);
}

// void Casa::CitireLocuinta()
// {
//     using namespace std;
//     {
//         // cout << "CITIRE CASA\n\n";

        
//         cout << "Suprafata curtii: ";
//         cin >> this->suprafataCurte;

//         cout << "\n";
//     } // namespace std
// }

// void Casa::AfisareLocuinta()
// {
//     using namespace std;
//     {
//         cout << "AFISARE CASA\n\n";

//         cout << "Numele clientului: " << this->numeClient << "\n";
//         cout << "Discountul aplicat: " << this->discount << "\n";
//         cout << "Suprafata utila: " << this->suprafataUtila << "\n";
//         cout << "Suprafata curtii: " << this->suprafataCurte << "\n";

//         cout << "\n";
//     } // namespace std
// }
