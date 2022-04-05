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

// Locuinta::~Locuinta()
// {
//     delete this;
// }

Locuinta& Locuinta::operator=(Locuinta& L)
{
    this->numeClient = L.numeClient;
    this->suprafataUtila = L.suprafataUtila;
    this->discount = L.discount;
    
    return *this;
}

// std::istream& operator>>(std::istream& i, Locuinta& L)
// {
//     i >> L.numeClient;
//     i >> L.suprafataUtila;
//     i >> L.discount;

//     return i;
// }

// std::ostream& operator<<(std::ostream& o, const Locuinta& L)
// {
//     o << L.numeClient << '\n';
//     o << L.suprafataUtila << '\n';
//     o << L.discount << '\n';

//     return o;
// }
