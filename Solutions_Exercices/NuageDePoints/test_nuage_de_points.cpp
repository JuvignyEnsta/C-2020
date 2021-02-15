#include <cstdlib>
#include "nuage_de_points.hpp"
using geometrie::nuage_de_points;
//using namespace geometrie;

int main()
{
    nuage_de_points nuage1(10); 
    nuage_de_points nuage2(nuage1);
    nuage_de_points nuage3;
    nuage_de_points nuage4(2,5, nuage1);
    nuage_de_points nuage5{geometrie::point{1.,0.}, {1.,1.}, {1.,-1.}};

    nuage1[2] = geometrie::point{1.,-1.};
    std::cout << nuage5[1][0] << ", " << nuage5[1][1] << std::endl;

    std::cout << "nuage 5 : " << nuage5 << std::endl;
    // std::cout.operator<<("nuage 5 : ").operator<< (nuage5);
    std::cout << "nuage 5 : " << std::string(nuage5) << std::endl;

    for ( const auto& pt : nuage5 )
    {
        std::cout << "<" << pt[0] << ", " << pt[1] << "> ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}