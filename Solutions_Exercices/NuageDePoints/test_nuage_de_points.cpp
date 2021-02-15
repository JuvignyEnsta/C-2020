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

    return EXIT_SUCCESS;
}