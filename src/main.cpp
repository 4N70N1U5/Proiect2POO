#include "../include/AgentieImobiliara.h"
#include "../include/Locuinta.h"
#include "../include/Apartament.h"
#include "../include/Casa.h"

#include <iostream>

void AfisareOptiuni()
{
    std::cout << std::string(4, '\n');
        
    std::cout << "Va rog alegeti o optiune: \n";
    
    std::cout << "Introduceti o noua locuinta: Optiunea 1\n";
    std::cout << "Stergeti o locuinta: Optiunea 2\n";
    std::cout << "Afisati locuintele inregistrate: Optiunea 3\n";
    std::cout << "Calculati si afisati chiria pentru o locuinta: Optiunea 4\n";
    std::cout << "Opriti programul: Optiunea 5\n";
    
    std::cout << "Optiunea aleasa: ";
}

int main()
{
    bool exit = false;
    std::string input;
    
    AgentieImobiliara AI;

    while (exit == false)
    {
        Intoarcere:
        AfisareOptiuni();

        std::cin >> input;
        
        try
        {
            // switch (input)
            // {
            // case 1:
            //     std::cout << "Ati ales 1\n";
            //     break;

            // case 2:
            //     std::cout << "Ati ales 2\n";
            //     break;

            // case 3:
            //     std::cout << "Ati ales 3\n";
            //     break;

            // case 4:
            //     std::cout << "Ati ales 4\n";
            //     break;

            // case 5:
            //     std::cout << "Programul se inchide.\n";
            //     exit = true;
            //     break;

            // case 0:
            //     goto Intoarcere;
            //     break;

            // default:
            //     throw std::invalid_argument(std::string("Input invalid! Incercati din nou!"));
            //     break;
            // }
        }
        catch (std::invalid_argument& e)
        {
            std::cerr << e.what();
            goto Intoarcere;
        }
    }

    return 0;
}
