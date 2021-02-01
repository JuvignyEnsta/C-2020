#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int main(int nargs, char* argv[])
{
    int N = 100;
    [[maybe_unused]] int compteur = 1;
    if  (nargs > 1) N = std::stoi(argv[1]);

    std::vector<int> entiers(N-1);
    std::generate(entiers.begin(), entiers.end(), [compteur] () mutable {++compteur; return compteur; });

    // 6k-1 et 6k+1 pour les nombres premiers > 2
    std::vector<int> premiers; premiers.reserve(N/3+1);
    for (int i = 0; i <= std::sqrt(N); ++i)
    {
        int number = entiers[i];
        if (number != 0)
        {
            premiers.emplace_back(number);
            int indice_multiple = number*2 - 2; // i commence à zéro, number-2 = indice i
            while (indice_multiple < N-1)
            {
                entiers[indice_multiple] = 0;
                indice_multiple += number;
            }
        }
    }
    for ( int i = std::sqrt(N)+1; i < N; ++i )
    {
        if (entiers[i] != 0)
            premiers.emplace_back(entiers[i]);
    }

    std::cout << "Nombres premiers : ";
    for ( int valeur : premiers )
    {
        std::cout << valeur << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}