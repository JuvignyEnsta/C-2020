#include <thread>
#include <chrono>
#include <random>
#include <functional>
#include <iostream>
#include <utility>
//#include "centrale.hpp"
//#include "console.hpp"
//#include "radioprotection.hpp"

// Pour pouvoir utiliser les unités de temps (3h, 1s, 10ms, 1000ns, etc.)
using namespace std::chrono_literals;

int main()
{
    // Création d'un générateur de nombre au hasard entre 0. et 1.
    // Le moteur de création de nombre stochastique
    std::random_device hgenerator; // Permet à chaque run du programme d'avoir un entier différent
    // hgenerator() va servir la graine aléatoire (seed)
    std::default_random_engine generator(hgenerator()); // Equivalent au générateur du rand du langage C
    std::uniform_real_distribution<double> genrand(0.,1.);
    std::uniform_int_distribution<int> igenran(0, 90);

    double x = genrand(generator);
    // Création d'une fonction rnd qui permet d'avoir un nombre entre 0 et 1
    auto drnd = std::bind(genrand, generator);
    auto irnd = std::bind(igenran, generator);

    for ( int i = 0; i < 10; ++i )
    {
        double y = drnd();
        double a = irnd();
        std::cout << "max(x,y) = " << std::max(x,y)  << ", a = " << a << std::endl;
        std::this_thread::sleep_for(750ms);
    }

    bool quit = false;
    bool console_state = true;
    //console cons(...);
    //radioprotection prot(...);
    /*do
    {
        if (console_state)
            cons.display_and_run();
        else
            radioprotection.display_and_run();
        // Met le processus en veille pendant une seconde.
        std::this_thread::sleep_for(1s);
    }
    while(quit == false);*/
    return EXIT_SUCCESS;
}