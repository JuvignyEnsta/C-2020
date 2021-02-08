#include <vector>
#include <cmath>
#include <stdexcept>
#include <cassert>
#include <iostream>

auto dot(const std::vector<double>& u, const std::vector<double>& v)
{
    double somme = 0;
    for ( int i = 0; i < u.size(); ++i )
        somme += u[i]*v[i];
    return somme;
}

auto homothetie(double alpha, const std::vector<double>& u)
{
    std::vector<double> v(u.size());
    for ( int i = 0; i < u.size(); ++i )
        v[i] = alpha * u[i];
    return v;
}

auto normL2(const std::vector<double>& u)
{
    return std::sqrt(dot(u,u));
}

auto axpy(double alpha, const std::vector<double>& u, std::vector<double>& v )
{
    assert(u.size() == v.size());
    for ( int i = 0; i < u.size(); ++i )
        v[i] += alpha*u[i];
    return v;
}

auto orthonormalisation( const std::vector<std::vector<double>>& famille)
{
    std::vector<std::vector<double>> base; base.reserve(famille.size());
    double nrmu = normL2(famille[0]);
    if (nrmu < 1.E-14)
    {
        throw std::runtime_error("Vecteur nul !");
    }
    base.emplace_back(homothetie(1./nrmu, famille[0]));
    for ( int i = 1; i < famille.size(); ++i )
    {
        base.emplace_back(famille[i]);
        // u_i = u_i - (u_i|u_j).u_j
        for ( int j = 0; j < i; ++j )
          axpy(-1., homothetie(dot(base[j],base[i]), base[j]), base[i]);
        nrmu = normL2(base[i]);
        if (nrmu < 1.E-14)
        {
            throw std::runtime_error("Famille liée !");
        }
        base[i] = homothetie(1./nrmu, base[i]);
    }
}

int main()
{
    std::vector<std::vector<double>> famille{
        {1.,1.,1.}, {1.,1.,0.}, {1.,1.,0.}
    };
    try
    {
        orthonormalisation(famille);
    }
    catch(std::runtime_error& err)
    {
        std::cerr << "Impossible d'othormalisé : " << err.what() << std::endl;
    }
    return EXIT_SUCCESS;
}