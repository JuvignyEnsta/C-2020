/* Faire un programme qui prend en argument trois réels a, b et c et qui résout 
 * ax²+bx+c soit dans les réels si le discriminant est positif, sinon dans les complexes.

Pour choisir a,b, c, on va utiliser nargs et argv :*/
#include <iostream>
#include <cmath>
#include <complex>
#include <string> // Pour utiliser std::stod

int main(int nargs, char* argv[])
{
    double a,b,c;
    if (nargs < 4)
    {
        std::cerr << "Usage : ./equation <a> <b> <c>" << std::endl;
        return EXIT_FAILURE;
    }
    a = std::stod(argv[1]);// std::stod : Transforme une chaîne de caractère en réel double précision
    b = std::stod(argv[2]);
    c = std::stod(argv[3]);

    if ( a == 0.)
    {
        std::cerr << "Le coefficient a doit être positif !" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Résolution de l'équation " << a << "x² + " << b << "x + " << c << " = 0 " 
              << std::endl;

    double Δ = b*b - 4*a*c;
    if (Δ > 0)
    {
        double x1 = (-b -std::sqrt(Δ))/(2*a);
        double x2 = (-b +std::sqrt(Δ))/(2*a);
        std::cout << "Les solutions sont réelles : " << std::endl 
                  << "   x1 = " << x1 << " et x2 = " << x2 << std::endl;
    }
    else if (Δ==0)
    {
        double x1 = -b/(2*a);
        std::cout << "Une solution réelle : " << std::endl 
                  << "    x = " << x1 << std::endl;        
    }
    else
    {
        // Δ < 0
        std::complex<double> sqrt_Δ(0., std::sqrt(-Δ));
        std::complex<double> z1 = (-b-sqrt_Δ)/(2*a);
        std::complex<double> z2 = (-b+sqrt_Δ)/(2*a);
        std::cout << "Les solutions sont complexes conjuguées : " << std::endl
                  << "    z1 = " << z1 << " et z2 = " << z2 << std::endl;
    }

    return EXIT_SUCCESS;
}
