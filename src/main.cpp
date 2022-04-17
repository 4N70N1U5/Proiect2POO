#include "../include/AgentieImobiliara.h"
#include "../include/Locuinta.h"
#include "../include/Apartament.h"
#include "../include/Casa.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void AfisareOptiuni()
{        
    std::cout << "Te rog alege o optiune: \n";
    
    
    
    std::cout << "Optiunea aleasa: ";
}

void Clear()
{
    #if defined _WIN32
        system("cls");
    #else
        system("clear");
    #endif
} // Multumim, Stack Overflow

int main()
{
    bool exit = false;
    std::string input;
    
    // std::vector<Apartament> A;
    // std::vector<Casa> C;
    // std::vector<AgentieImobiliara> AI;

    AgentieImobiliara AI;

    while (exit == false)
    {
        SkipSleep:
        Clear();
        AfisareOptiuni();

        try
        {
            std::cin >> input;
            std::cin.get();

            if (input == "1")
            {
                std::cout << "Ai ales 1.\n";
                std::cin >> AI;
            }
            else if (input == "2")
            {
                std::cout << "Ai ales 2.\n";
                std::cout << AI;
                std::cout << "Apasa enter pentru a continua.\n";
                std::cin.get();
                goto SkipSleep;
            }
            else if (input == "3")
            {
                std::cout << "Ai ales 3.\n";
                AI.AfisareApartamente();
                std::cout << "Apasa enter pentru a continua.\n";
                std::cin.get();
                goto SkipSleep;
            }
            else if (input == "4")
            {
                std::cout << "Ai ales 4.\n";
                AI.AfisareCase();
                std::cout << "Apasa enter pentru a continua.\n";
                std::cin.get();
                goto SkipSleep;
            }
            else if (input == "0")
            {
                std::cout << "Ai ales 0.\nProgramul se va inchide.\n";
                exit = true;
            }
            else
            {
                throw "Te rog incearca din nou!\n";
            }
        }
        catch (const char* err)
        {
            std::cout << err;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(2048));
    }

    Clear();

    return 0;
}
