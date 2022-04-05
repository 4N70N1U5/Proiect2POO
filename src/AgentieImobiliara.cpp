#include "../include/AgentieImobiliara.h"
#include "../include/Locuinta.h"
#include "../include/Apartament.h"
#include "../include/Casa.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

AgentieImobiliara::AgentieImobiliara()
{

}

AgentieImobiliara::AgentieImobiliara(std::vector<Locuinta*> locuinte)
{
    this->locuinte = locuinte;
}

AgentieImobiliara::AgentieImobiliara(const AgentieImobiliara& AI)
{
    this->locuinte = AI.locuinte;
}

AgentieImobiliara AgentieImobiliara::operator=(AgentieImobiliara AI)
{
    this->locuinte = AI.locuinte;
    return *this;
}

std::istream& operator>>(std::istream& i, AgentieImobiliara& AI)
{
    using namespace std;
    {
        string tip;

        CitireTip:
        cout << "Tip locuinta (Apartament sau Casa): ";
        getline(i, tip);
        transform(tip.begin(), tip.end(), tip.begin(), ::tolower);
        
        if (tip == "apartament")
        {
            cout << "A fost selectat apartament.\n";
            AI.locuinte.push_back(new Apartament());
            AI.locuinte[AI.locuinte.size() - 1]->CitireLocuinta();
        }
        else if (tip == "casa")
        {
            cout << "A fost selectata casa.\n";
            AI.locuinte.push_back(new Casa());
            AI.locuinte[AI.locuinte.size() - 1]->CitireLocuinta();
        }
        else
        {
            cout << "Va rog repetati selectia.\n";
            goto CitireTip;
        }
    } // namespace std
    
    return i;
}

std::ostream& operator<<(std::ostream& o, const AgentieImobiliara& AI)
{
    for (int i = 0; i < AI.locuinte.size(); i++)
    {
        AI.locuinte[i]->AfisareLocuinta();
    }

    return o;
}
