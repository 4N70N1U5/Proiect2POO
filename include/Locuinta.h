#ifndef Locuinta_H
#define Locuinta_H

#include <string>

class Locuinta
{
public:
    Locuinta();
    Locuinta(const Locuinta&);
    ~Locuinta();
    virtual void CalculChirie(int, int) = 0;
protected:
    int chirie, discount, suprafataUtila, nrCamere;
    std::string strada, numar, oras, judet, tara; 
    // am ales declararea numarului stradal ca string pentru cazurile precum 22A
};

#endif
