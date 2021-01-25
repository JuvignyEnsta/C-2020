#include <iostream>
#include <memory>

int main()
{
    int i = 3, j = 4;
    int& k = i;
    std::cout << "i = " << i << ", j = " << j << ", k = " << k << std::endl;
    i = 2;
    std::cout << "i = " << i << ", j = " << j << ", k = " << k << std::endl;
    k = 5;    
    std::cout << "i = " << i << ", j = " << j << ", k = " << k << std::endl;
    k = j;
    std::cout << "i = " << i << ", j = " << j << ", k = " << k << std::endl;

    int const& l = i;
    std::cout << " l = " << l << std::endl;
    // l = 3 // Erreur de compilation !
    i = -7;
    std::cout << " l = " << l << std::endl;

    auto pt_x = std::make_unique<double>(0.303);
    auto pt_y = std::make_unique<double>(0.0);
    double& x = *pt_x;

    std::cout << "*pt_x = " << *pt_x << ", *pt_y = " << *pt_y << " et x = " << x << std::endl;
    x = -0.303;
    std::cout << "*pt_x = " << *pt_x << ", *pt_y = " << *pt_y << " et x = " << x << std::endl;
    *pt_x = 0.404;
    std::cout << "*pt_x = " << *pt_x << ", *pt_y = " << *pt_y << " et x = " << x << std::endl;
    *pt_y = -1.;
    std::cout << "*pt_x = " << *pt_x << ", *pt_y = " << *pt_y << " et x = " << x << std::endl;
    std::swap(pt_x,pt_y);
    std::cout << "*pt_x = " << *pt_x << ", *pt_y = " << *pt_y << " et x = " << x << std::endl;
    x = 1.414;
    std::cout << "*pt_x = " << *pt_x << ", *pt_y = " << *pt_y << " et x = " << x << std::endl;
    *pt_x = 2.15;
    std::cout << "*pt_x = " << *pt_x << ", *pt_y = " << *pt_y << " et x = " << x << std::endl;
    *pt_y = 2.28;
    std::cout << "*pt_x = " << *pt_x << ", *pt_y = " << *pt_y << " et x = " << x << std::endl;

    return EXIT_SUCCESS;
}
