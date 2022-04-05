#ifndef AgentieImobiliara_H
#define AgentieImobiliara_H

#include "Locuinta.h"

#include <iostream>
#include <vector>

class AgentieImobiliara
{
public:
    AgentieImobiliara();
    AgentieImobiliara(std::vector<Locuinta*>);
    AgentieImobiliara(const AgentieImobiliara&);
    // ~AgentieImobiliara();

    AgentieImobiliara operator=(AgentieImobiliara);

    friend std::istream& operator>>(std::istream&, AgentieImobiliara&);
    friend std::ostream& operator<<(std::ostream&, const AgentieImobiliara&);
private:
    std::vector<Locuinta*> locuinte;
};

std::istream& operator>>(std::istream&, AgentieImobiliara&);
std::ostream& operator<<(std::ostream&, const AgentieImobiliara&);

#endif
