#include <limits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <numbers>

int main()
{
    std::cout << "Caractéristique d'un réel simple précision : " << std::endl;
    std::cout << "\t Nombre de bits : " << 8*sizeof(float) << std::endl;
    std::cout << std::boolalpha << "\t Peut avoir une valeur infinie ? " 
              << std::numeric_limits<float>::has_infinity << std::endl;
    std::cout << "\t Peut avoir un NaN silencieux ? " 
              << std::numeric_limits<float>::has_quiet_NaN << std::endl;
    std::cout << "\t Peut avoir un NaN levant une erreur ? "
              << std::numeric_limits<float>::has_signaling_NaN << std::endl;
    std::cout << "\t Nombre de bits contenus dans la mantisse : "
              << std::numeric_limits<float>::digits-1 << std::endl;
    std::cout << "\t Erreur relative d'un réel simple précision : 10^-"
              << std::numeric_limits<float>::digits10 << std::endl;
    std::cout << "\t Valeur minimale acceptable : " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "\t Valeur maximale acceptable : " << std::numeric_limits<float>::max() << std::endl;

    std::cout << "Caractéristique d'un réel double précision : " << std::endl;
    std::cout << "\t Nombre de bits : " << 8*sizeof(double) << std::endl;
    std::cout << std::boolalpha << "\t Peut avoir une valeur infinie ? " 
              << std::numeric_limits<double>::has_infinity << std::endl;
    std::cout << "\t Peut avoir un NaN silencieux ? " 
              << std::numeric_limits<double>::has_quiet_NaN << std::endl;
    std::cout << "\t Peut avoir un NaN levant une erreur ? "
              << std::numeric_limits<double>::has_signaling_NaN << std::endl;
    std::cout << "\t Nombre de bits contenus dans la mantisse : "
              << std::numeric_limits<double>::digits-1 << std::endl;
    std::cout << "\t Erreur relative d'un réel double précision : 10^-"
              << std::numeric_limits<double>::digits10 << std::endl;
    std::cout << "\t Valeur minimale acceptable : " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "\t Valeur maximale acceptable : " << std::numeric_limits<double>::max() << std::endl;

    std::cout << "Caractéristique d'un réel long double precision : " << std::endl;
    std::cout << "\t Nombre de bits : " << 8*sizeof(long double) << std::endl;
    std::cout << std::boolalpha << "\t Peut avoir une valeur infinie ? " 
              << std::numeric_limits<long double>::has_infinity << std::endl;
    std::cout << "\t Peut avoir un NaN silencieux ? " 
              << std::numeric_limits<long double>::has_quiet_NaN << std::endl;
    std::cout << "\t Peut avoir un NaN levant une erreur ? "
              << std::numeric_limits<long double>::has_signaling_NaN << std::endl;
    std::cout << "\t Nombre de bits contenus dans la mantisse : "
              << std::numeric_limits<long double>::digits-1 << std::endl;
    std::cout << "\t Erreur relative d'un réel long double precision : 10^-"
              << std::numeric_limits<long double>::digits10 << std::endl;
    std::cout << "\t Valeur minimale acceptable : " << std::numeric_limits<long double>::min() << std::endl;
    std::cout << "\t Valeur maximale acceptable : " << std::numeric_limits<long double>::max() << std::endl;

    float π_f = std::acos(-1.f);
    double π = std::acos(-1.);
    long double π_lf = std::acos(-1.l);
    double π⁻¹ = 1./π;

    std::cout << "Calcul de π et ses variantes avec arccos : " << std::endl;
    std::cout << "π_f  = " << std::setprecision(std::numeric_limits<float>::digits10+1) << π_f << std::endl;
    std::cout << "π    = " << std::setprecision(std::numeric_limits<double>::digits10+1) << π << std::endl;
    std::cout << "π_lf = " << std::setprecision(std::numeric_limits<long double>::digits10+1) << π_lf << std::endl;
    std::cout << "π⁻¹  = " << std::setprecision(std::numeric_limits<double>::digits10+1) << π⁻¹ << std::endl;
#   if (__cplusplus >= 201709L) // Devrait être 202000L mais g++ avec -std=c++20 met __cplusplus à 201709L !
    π_f = std::numbers::pi_v<float>;
    π = std::numbers::pi;
    π_lf = std::numbers::pi_v<long double>;
    π⁻¹ = std::numbers::inv_pi;

    std::cout << "π et ses variantes définies par C++ 2020 : " << std::endl;
    std::cout << "π_f  = " << std::setprecision(std::numeric_limits<float>::digits10+1) << π_f << std::endl;
    std::cout << "π    = " << std::setprecision(std::numeric_limits<double>::digits10+1) << π << std::endl;
    std::cout << "π_lf = " << std::setprecision(std::numeric_limits<long double>::digits10+1) << π_lf << std::endl;
    std::cout << "π⁻¹  = " << std::setprecision(std::numeric_limits<double>::digits10+1) << π⁻¹ << std::endl;
#   endif

    std::cout << "zeta(-1) = " << std::riemann_zeta(-1.) << std::endl;
    return EXIT_SUCCESS;
}   