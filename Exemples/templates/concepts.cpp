#include <cstdlib>
#include <concepts>
#include <iostream>
#include <complex>
using namespace std::complex_literals;

template<typename Int> Int fact(Int n) requires std::integral<Int>
{ if (n==0) return Int(0); else return n * fact(n-1); }

auto factorial(std::integral auto n)
{
    if (n == 0) return decltype(n)(0); else return n * factorial(n-1);
}


// Vérifie que K est sans doute un corps (au sens algébrique)
template<typename K>
concept field_partial = requires(K x, K y)
{
    {x+y} -> std::same_as<K>; // x+y reste bien dans K
    {x*y} -> std::same_as<K>; // x*y reste bien dans K
    {1} -> std::convertible_to<K>; // 1 est bien défini pour K (convertible en K)
    {-x} -> std::same_as<K>; // On a le droit d'avoir un opposé
    {K(1)/x} -> std::same_as<K>; // On peut inverser une valeur x
};

// L'ensemble des entiers n'est pas un corps, mais il existe une division euclidienne...
template<typename K>
concept field = field_partial<K> && !std::integral<K>;

// Résoud a.x + b = 0 dans le group
auto linear_solve( field auto a, field auto b )
{
    return -b/a;
}

int main()
{
    auto fl = fact(5L);
    auto fi = fact(5);
    //auto fx = fact(5.);
    auto fl2 = factorial(5L);

    auto x1 = linear_solve( 2., -4.);
    auto z1 = linear_solve( 2.+3.i, -4.+5.i);
    int i1 = 0;
    //i1 = linear_solve( 2, 3); // Aïe, erreur de compilation !
    std::cout << "x1 : " << x1 << " i1 : " << i1 << " z1 : " << z1.real() << "+" << z1.imag() << "i" << std::endl << std::flush;
    return EXIT_SUCCESS;
}