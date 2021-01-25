#include <iostream>

int main()
{
    int i = 3;
    std::cout << "i = " << i << std::endl;

    int&j = i;
    j = 4;

    std::cout << "i = " << i << ", j = " << j << std::endl;

    auto& k = i;
    k = 5;

    std::cout << "i = " << i << ", j = " << j << ", k = " << k << std::endl;

    decltype(i) l = i;// Attention, ce n'est pas une référence !
    l = 6;

    std::cout << "i = " << i << ", j = " << j << ", k = " << k 
              << ", l = " << l << std::endl;

    decltype((i)) m = i;// Ici, c'est une référence ! Notez les parenthèses en plus
    m = 7;

    std::cout << "i = " << i << ", j = " << j << ", k = " << k 
              << ", l = " << l << ", m = " << m << std::endl;

    return EXIT_SUCCESS;
}