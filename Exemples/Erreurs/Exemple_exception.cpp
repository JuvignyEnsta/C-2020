#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <type_traits>

using namespace std::string_literals;

double normeL2(std::vector<double> const& u)
{
    double dot = 0.;
    for (const auto& val : u)
    {
        dot += val*val;
    }
    return std::sqrt(dot);
}

auto scal(double alpha, std::vector<double> const&u )
{
    std::vector<double> u_normalisé;
    u_normalisé.reserve(u.size());
    for ( const auto& val : u )
        u_normalisé.emplace_back(alpha*val);
    return u_normalisé;
}

auto normalise( std::vector<double> const &  u )
{
    double norme_u = normeL2(u);
    if (norme_u < std::numeric_limits<double>::epsilon())
    {
        std::string message_d_erreur = "Erreur, vecteur nul. norme L2 = "s + std::to_string(norme_u) + "\n";
        throw std::runtime_error(message_d_erreur);
    }
    return scal(1./norme_u, u);
}

int main()
{
    std::vector u{1.,1.,0.}, v{0.,0.,0.};

    try
    {
        auto u_nrm = normalise(u);
        std::cout << "u normalisé : ";
        for (const auto& val : u_nrm)
            std::cout << val << " ";
        std::cout << std::endl;
        auto v_nrm = normalise(v);
        std::cout << "v normalisé : ";
        for (const auto& val : v_nrm)
            std::cout << val << " ";
        std::cout << std::endl;
    } catch(std::runtime_error& err)
    {
        std::cout << "Un des deux vecteurs était nul..." << std::endl;
    }
    return EXIT_SUCCESS;
}