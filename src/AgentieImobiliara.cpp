#include "../include/AgentieImobiliara.h"
#include "../include/Locuinta.h"
#include "../include/Apartament.h"
#include "../include/Casa.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

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
            Apartament* A = new Apartament();
            i >> *A;
            AI.locuinte.push_back(A);
        }
        else if (tip == "casa")
        {
            cout << "A fost selectata casa.\n";
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
    o << '\n';
    for (int i = 0; i < AI.locuinte.size(); i++)
    {
        o << "Locuinta " << i + 1 << ":\n";
        if (dynamic_cast<Apartament*>(AI.locuinte[i]))
        {
            Apartament* A = dynamic_cast<Apartament*>(AI.locuinte[i]);
            o << *A << '\n';
        }
        else if (dynamic_cast<Casa*>(AI.locuinte[i]))
        {
            Casa* C = dynamic_cast<Casa*>(AI.locuinte[i]);
            o << *C << '\n';
        }
    }

    return o;
}

void AgentieImobiliara::AfisareApartamente()
{
    int indice = 1;

    std::cout << '\n';

    for (int i = 0; i < this->locuinte.size(); i++)
    {
        Apartament* A = dynamic_cast<Apartament*>(this->locuinte[i]);
        if (A != NULL)
        {
            std::cout << "Apartamentul " << indice << ":\n";
            std::cout << *A << '\n';
            indice++;
        }
    }
}

void AgentieImobiliara::AfisareCase()
{
    int indice = 1;

    std::cout << '\n';

    for (int i = 0; i < this->locuinte.size(); i++)
    {
        Casa* C = dynamic_cast<Casa*>(this->locuinte[i]);
        if (C != NULL)
        {
            std::cout << "Casa " << indice << ":\n";
            std::cout << *C << '\n';
            indice++;
        }
    }
}

void AgentieImobiliara::ModificareLocuinta()
{
    std::cout << *this;
    std::cout << "\nAlege o locuinta pe care sa o modifici: ";

    int i;

    std::cin >> i;

    i--;

    try
    {
        this->locuinte.at(i); 
        // Pentru a arunca exceptia de tip out_of_range in caz ca indicele citit nu este ok.

        if (dynamic_cast<Apartament*>(this->locuinte[i]))
        {
            std::cout << "Modifici apartamentul de pe pozitia " << i + 1 << ".\n";

            std::cin.get();

            Apartament A;
            std::cin >> A;

            Apartament* aux = dynamic_cast<Apartament*>(this->locuinte[i]);

            *aux = A;
        }
        else if (dynamic_cast<Casa*>(this->locuinte[i]))
        {
            std::cout << "Modifici casa de pe pozitia " << i + 1 << ".\n";

            std::cin.get();

            Casa C;
            std::cin >> C;

            Casa* aux = dynamic_cast<Casa*>(this->locuinte[i]);

            *aux = C;
        }

        std::cout << "Locuinta a fost modificata.\n";
    }
    catch(const std::out_of_range& err)
    {
        
        std::cout << "Locuinta aleasa nu exista. Incearca din nou!\n";
    }
}

void AgentieImobiliara::CalculChirie()
{
    std::cout << *this;
    std::cout << "\nAlege locuinta pentru care vrei sa calculezi chiria: ";

    int i, aplicareDiscount;

    std::cin >> i;
    std::cin.get();

    i--;

    CitireDiscount:
    std::cout << "Doresti sa aplici discountul? (DA / NU)\n";

    std::string raspuns;

    std::getline(std::cin, raspuns);

    std::transform(raspuns.begin(), raspuns.end(), raspuns.begin(), ::tolower);

    if (raspuns == "da")
    {
        aplicareDiscount = 1;
    }
    else if (raspuns == "nu")
    {
        aplicareDiscount = 0;
    }
    else
    {
        std::cout << "Raspuns invalid.\n";
        goto CitireDiscount;
    }

    try
    {
        this->locuinte.at(i);

        if (dynamic_cast<Apartament*>(this->locuinte[i]))
        {
            std::cout << "Chiria pentru apartamentul de pe pozitia " << i + 1 << ": ";

            Apartament* A = dynamic_cast<Apartament*>(this->locuinte[i]);

            std::cout << A->CalculChirie(aplicareDiscount);
        }
        else if (dynamic_cast<Casa*>(this->locuinte[i]))
        {
            std::cout << "Chiria pentru casa de pe pozitia " << i + 1 << ": ";

            Casa* C = dynamic_cast<Casa*>(this->locuinte[i]);

            std::cout << C->CalculChirie(aplicareDiscount);
        }
    }
    catch(const std::out_of_range& err)
    {
        
        std::cout << "Locuinta aleasa nu exista. Incearca din nou!\n";
    }
}
