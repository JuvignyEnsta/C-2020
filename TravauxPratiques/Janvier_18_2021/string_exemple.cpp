#include <iostream>
#include <string>

using namespace std::string_literals;

int main()
{
    // char* toto = "C'est est un " + " exemple.";
    std::string toto = "C'est un "s + "exemple"s;

    double x = 3.14;
    int    n = 11;

    std::string snumbers = "x a pour valeur "s + std::to_string(x) + 
                           " et n est un nombre premier valant : "s + std::to_string(n);
    std::cout << snumbers << std::endl;
    return EXIT_SUCCESS;
}