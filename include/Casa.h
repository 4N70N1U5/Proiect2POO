#ifndef Casa_H
#define Casa_H

#include "Locuinta.h"

class Casa: public Locuinta
{
public:
    Casa();
    Casa(const Casa&);
    ~Casa();
private:
    int suprafataCurte, nrEtaje;
};

#endif
