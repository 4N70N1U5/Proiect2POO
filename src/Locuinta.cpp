#include "../include/Locuinta.h"

#include <iostream>
#include <string>

Locuinta::Locuinta()
{
    this->numeClient = "";
    this->suprafataUtila = 0;
    this->discount = 0.0;
}

Locuinta::Locuinta(std::string numeClient, int suprafataUtila, double discount)
{
    this->numeClient = numeClient;
    this->suprafataUtila = suprafataUtila;
    this->discount = discount;
}

Locuinta::Locuinta(const Locuinta& L)
{
    this->numeClient = L.numeClient;
    this->suprafataUtila = L.suprafataUtila;
    this->discount = L.discount;
}

Locuinta::~Locuinta()
{
    
}

Locuinta& Locuinta::operator=(Locuinta& L)
{
    this->numeClient = L.numeClient;
    this->suprafataUtila = L.suprafataUtila;
    this->discount = L.discount;
    
    return *this;
}

std::istream& operator>>(std::istream& i, Locuinta& L)
{
    std::cout << "Numele clientului: ";
    std::getline(i, L.numeClient);
    std::cout << "Discountul aplicat: ";
    i >> L.discount;
    std::cout << "Suprafata utila: ";
    i >> L.suprafataUtila;

    return i;
}

std::ostream& operator<<(std::ostream& o, const Locuinta& L)
{
    o << "Numele clientului: " << L.numeClient << "\n";
    o << "Discountul aplicat: " << L.discount << "\n";
    o << "Suprafata utila: " << L.suprafataUtila << "\n";

    return o;
}
