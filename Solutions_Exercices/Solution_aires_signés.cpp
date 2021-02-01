#include <iostream>
#include <array>

using vecteur = std::array<double,2>;
using point   = std::array<double,2>;

using triangle = std::array<point,3>;

int main()
{
    point p{0.,0.};
    triangle T{ point{-1.,-1.}, point{+1.,-1.}, point{0.,1.}};

    vecteur pp1{T[0][0]-p[0], T[0][1]-p[1]};
    vecteur pp2{T[1][0]-p[0], T[1][1]-p[1]};
    vecteur pp3{T[2][0]-p[0], T[2][1]-p[1]};

    double aire1 = pp1[0]*pp2[1]-pp1[1]*pp2[0];
    double aire2 = pp2[0]*pp3[1]-pp2[1]*pp3[0];
    double aire3 = pp3[0]*pp1[1]-pp3[1]*pp1[0];

    if ( (aire1*aire2>0) && (aire1*aire3>0) )
    {
        std::cout << "p est dans le triangle !" << std::endl;
    } 
    else
    {
        std::cout << "p n'est pas dans le triangle !" << std::endl;
    }
    return EXIT_SUCCESS;
}