#ifndef Apartament_H
#define Apartament_H

#include "Locuinta.h"

class Apartament: public Locuinta
{
public:
    Apartament();
    Apartament(const Apartament&);
    ~Apartament();
    void CalculChirie(int, int);
private:
    int numarBloc, etaj;
    std::string scaraBloc;
};

#endif
