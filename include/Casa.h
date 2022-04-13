#ifndef Casa_H
#define Casa_H

#include "Locuinta.h"

class Casa: public Locuinta
{
public:
    Casa();
    Casa(std::string, int, double, int);
    Casa(const Casa&);
    ~Casa();

    Casa operator=(Casa);

    friend std::istream& operator>>(std::istream&, Casa&);
    friend std::ostream& operator<<(std::ostream&, const Casa&);

    double CalculChirie(int, int);
    // void CitireLocuinta();
    // void AfisareLocuinta();
private:
    int suprafataCurte;
};

std::istream& operator>>(std::istream&, Casa&);
std::ostream& operator<<(std::ostream&, const Casa&);

#endif
