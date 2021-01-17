#include <iostream>
#include <iomanip>

int main()
{
    bool f1 = true;
    bool f2 = (4 < 3); // Vaut false

    std::cout << "f1 <-- " << f1 << std::endl
              << "f2 <-- " << f2 << std::endl;

    std::cout << std::boolalpha << "f1 <-- " << f1 << std::endl
              << "f2 <-- " << f2 << std::endl;

    bool f3 = f1 || f2; // f1 or  f2
    bool f4 = f1 && f2; // f1 and f2
    bool f5 = !f2;     // not f2
    bool f6 = f1 ^ f2; // f1 xor f2

    std::cout << std::boolalpha << "f1 = " << f1 << ", f2 = " << f2 << ", f3 = " << f3
              << ", f4 = " << f4 << ", f5 = " << f5 << ", f6 = " << f6 << std::endl;

    bool f7 = 0; // f7 vaut false
    bool f8 = 1; // f8 vaut true

    std::cout << std::boolalpha << "f7 <- " << f7 << " et f8 <- " << f8 << std::endl;
    std::cout << "f7 <- " << f7 << " et f8 <- " << f8 << std::endl;

    return EXIT_SUCCESS;
}