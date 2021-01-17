#include <iostream>
#include <iomanip>
#include <cstdint>

int main()
{
    std::int32_t value1 = -32;
    std::int32_t value2 =   3;

    std::cout << "value1 = "  << value1 << std::endl;
    std::cout << " et value2 = " << value2 << std::endl;

    std::cout << "123456789ABCDEF" << std::endl;

    std::cout << std::setw(15) << "value1 = " << std::setw(4) << value1 << std::endl;
    std::cout << std::setw(15) << " et value2 = " << std::setw(4)  << std::setfill('0') << value2 << std::endl;

    return EXIT_SUCCESS;
}