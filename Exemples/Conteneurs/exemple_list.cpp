#include <iostream>
#include <list>
#include <cstdint>

int main()
{
    // Les huits premiers nombres premiers supérieurs à trois
    std::list l1{5, 7, 11, 13, 17, 19, 23, 29};

    std::list<std::int32_t> l2{2,3};// Les deux premiers nombres premiers
    // Seuls les nombres de la forme 6i-1 et 6i+1 peuvent être premiers si > 3
    for (int i = 1; i < 100; ++i )
    {
        l2.emplace_back(6*i-1);
        l2.emplace_back(6*i+1);
    }
    // Crible d'eratosthène
    for ( auto val : l1 ) l2.remove_if([val](int n) { return (n>val) && (n%val == 0); });
    std::cout << "Nombres premiers (" << l2.size() << ") : ";
    for ( auto val : l2 ) std::cout << val << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}