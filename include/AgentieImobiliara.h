#ifndef AgentieImobiliara_H
#define AgentieImobiliara_H

#include "Locuinta.h"

#include <vector>

class AgentieImobiliara
{
public:
    AgentieImobiliara();
    AgentieImobiliara(const AgentieImobiliara&);
    ~AgentieImobiliara();
private:
    std::vector<Locuinta*> locuinte;
};

#endif
