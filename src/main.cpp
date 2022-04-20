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
    std::cout << "Te rog alege o optiune:\n";
    
    std::cout << "Optiunea 1: Adauga o locuinta.\n";
    std::cout << "Optiunea 2: Afiseaza locuintele.\n";
    std::cout << "Optiunea 3: Afiseaza apartamentele.\n";
    std::cout << "Optiunea 4: Afiseaza casele.\n";
    std::cout << "Optiunea 5: Modifica o locuinta.\n";
    std::cout << "Optiunea 6: Sterge o locuinta.\n";
    std::cout << "Optiunea 7: Calculeaza si afiseaza chiria pentru o locuinta.\n";
    std::cout << "Optiunea 0: Inchide programul.\n";
    
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
    Clear();
    Locuinta::setValStandard();

    bool exit = false;
    std::string input;

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
                Clear();
                std::cout << "Ai ales 1: Adauga o locuinta.\n\n";
                
                std::cin >> AI;
            }
            else if (input == "2")
            {
                Clear();
                std::cout << "Ai ales 2: Afiseaza locuintele.\n\n";
                
                std::cout << AI;
                
                std::cout << "Apasa enter pentru a continua.\n";
                std::cin.get();
                goto SkipSleep;
            }
            else if (input == "3")
            {
                Clear();
                std::cout << "Ai ales 3: Afiseaza apartamentele.\n\n";
                
                AI.AfisareApartamente();
                
                std::cout << "Apasa enter pentru a continua.\n";
                std::cin.get();
                goto SkipSleep;
            }
            else if (input == "4")
            {
                Clear();
                std::cout << "Ai ales 4: Afiseaza casele.\n\n";
                
                AI.AfisareCase();
                
                std::cout << "Apasa enter pentru a continua.\n";
                std::cin.get();
                goto SkipSleep;
            }
            else if (input == "5")
            {
                Clear();
                std::cout << "Ai ales 5: Modifica o locuinta.\n\n";
                
                AI.ModificareLocuinta();
            }
            else if (input == "6")
            {
                Clear();
                std::cout << "Ai ales 6: Sterge o locuinta.\n\n";

                AI.StergereLocuinta();
            }
            else if (input == "7")
            {
                Clear();
                std::cout << "Ai ales 7: Calculeaza si afiseaza chiria pentru o locuinta.\n\n";
                
                AI.CalculChirie();
            }
            else if (input == "0")
            {
                Clear();
                std::cout << "Ai ales 0: Inchide programul.\n\n";
                std::cout << "Programul se va inchide.\n";
                
                exit = true;
            }
            else
            {
                throw "Optiune invalida. Te rog incearca din nou!\n";
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
