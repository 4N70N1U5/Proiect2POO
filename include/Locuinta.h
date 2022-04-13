#ifndef Locuinta_H
#define Locuinta_H

#include <iostream>
#include <string>

class Locuinta
{
public:
    Locuinta();
    Locuinta(std::string, int, double);
    Locuinta(const Locuinta&);
    ~Locuinta();

    Locuinta& operator=(Locuinta&);
    
    friend std::istream& operator>>(std::istream&, Locuinta&);
    friend std::ostream& operator<<(std::ostream&, const Locuinta&);

    virtual double CalculChirie(int, int) = 0;
    // virtual void CitireLocuinta() = 0;
    // virtual void AfisareLocuinta() = 0;
protected:
    std::string numeClient;
    int suprafataUtila;
    double discount;
};

std::istream& operator>>(std::istream&, Locuinta&);
std::ostream& operator<<(std::ostream&, const Locuinta&);

#endif
