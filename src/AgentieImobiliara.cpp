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

AgentieImobiliara::~AgentieImobiliara()
{
    
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
            // AI.locuinte.push_back(new Apartament());
            // AI.locuinte[AI.locuinte.size() - 1]->CitireLocuinta();
            Apartament* A = new Apartament();
            i >> *A;
            AI.locuinte.push_back(A);
        }
        else if (tip == "casa")
        {
            cout << "A fost selectata casa.\n";
            // AI.locuinte.push_back(new Casa());
            // AI.locuinte[AI.locuinte.size() - 1]->CitireLocuinta();
            // i >> *AI.locuinte[AI.locuinte.size() - 1];
            Casa* C = new Casa();
            i >> *C;
            AI.locuinte.push_back(C);
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
        // AI.locuinte[i]->AfisareLocuinta();
        // o << *AI.locuinte[i];
        if (dynamic_cast<Apartament*>(AI.locuinte[i]))
        {
            Apartament* A = dynamic_cast<Apartament*>(AI.locuinte[i]);
            o << *A;
        }
        else if (dynamic_cast<Casa*>(AI.locuinte[i]))
        {
            Casa* C = dynamic_cast<Casa*>(AI.locuinte[i]);
            o << *C;
        }
    }

    return o;
}

void AgentieImobiliara::AfisareApartamente()
{
    for (int i = 0; i < this->locuinte.size(); i++)
    {
        Apartament* A = dynamic_cast<Apartament*>(this->locuinte[i]);
        if (A != NULL)
        {
            // A->AfisareLocuinta();
            std::cout << *A;
        }
    }
}

void AgentieImobiliara::AfisareCase()
{
    for (int i = 0; i < this->locuinte.size(); i++)
    {
        Casa* C = dynamic_cast<Casa*>(this->locuinte[i]);
        if (C != NULL)
        {
            // C->AfisareLocuinta();
            std::cout << *C;
        }
    }
}
