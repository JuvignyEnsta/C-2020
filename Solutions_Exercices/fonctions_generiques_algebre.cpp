#include <vector>
#include <cmath>
#include <complex>
#include <iostream>

using namespace std::complex_literals;

auto produit_scalaire(int dim, const auto* u, const auto* v, int incu = 1, int incv=1)
{
    decltype(u[0]+v[0]) somme = 0;
    for ( decltype(dim) i = 0; i < dim; ++i )
        somme += u[i*incu]*v[i*incv];
    return somme;
}

/*auto produit_scalaire(auto iteru_begin, auto iteru_end, auto iterv_begin)
{
    decltype(*iteru_begin) somme = 0;
    auto iteru = iteru_begin;
    auto iterv = iterv_begin;
    for ( ; iteru != iteru_end; iteru++, iterv++)
        somme += (*iteru)*(*iterv);
    return somme;
}*/

auto homothetie( auto alpha, const auto& u, int incu = 1)
{
    auto dim = u.size();
    auto dimloc = dim/incu;
    decltype(u) v(dimloc);
    for ( decltype(dim) i = 0; i < dimloc; ++i)
        v[i]= alpha * u[i*incu];
    return v;
}

auto normL2( int dim, const auto* u, int incu = 1)
{
    return std::sqrt(produit_scalaire(dim, u, u, incu, incu));
}

int main()
{
    std::vector x{1.,-1.,1.};
    std::vector y{3.,2.,1.};
    std::cout << "(x|y) = " << produit_scalaire(x.size(), x.data(), y.data(), 1, 1);

    std::vector z1{ 1.+2.i, 2.-1.i, 3.+5.i};
    std::cout << "||z1|| = " << normL2(z1.size(), z1.data()) << std::endl;
    return EXIT_SUCCESS;
}