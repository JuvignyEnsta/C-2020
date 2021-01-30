#include <iostream>
#include <vector>
#include <cassert>

std::vector<double> add( const std::vector<double>& u, const std::vector<double>& v )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    assert(u.size() == v.size());
    std::vector<double> w(u.size());
    for ( int i = 0; i < u.size(); ++i )
        w[i] = u[i] + v[i];
    std::cout << "adresse du tableau w local à la fonction : " << (void*)w.data() << std::endl;
    return w; // OK, on effectue un déplacement, aucun coût en mémoire
}

// Pour faire v = v + u : Mauvais, on fait une copie de v en retour de la fonction :-( !
std::vector<double> add_inplace_bad( const std::vector<double>& u, std::vector<double>& v)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    assert(u.size() == v.size());
    for ( int i = 0; i < u.size(); ++i )
        v[i] += u[i];
    std::cout << "adresse du tableau v paramètre de la fonction : " << (void*)v.data() << std::endl;
    return v;
}

{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    assert(u.size() == v.size());
    for ( int i = 0; i < u.size(); ++i )
        v[i] += u[i];
    std::cout << "adresse du tableau v paramètre de la fonction : " << (void*)v.data() << std::endl;
    return v;
}std::vector<double>& add_inplace( const std::vector<double>& u, std::vector<double>& v)



int main()
{
    std::vector u{1.,2.,3.,4.,5.,6.};
    std::vector v{9.,7.,5.,3.,1.,3.};

    {
        auto w = add(u,v);
        std::cout << "adresse du tableau w recevant le résultat de add : " << (void*)w.data() << std::endl;
    }
    {
        auto w = add_inplace_bad(u,v);
        std::cout << "adresse du tableau w recevant le résultat de add_inplace_bad : " << (void*)w.data() << std::endl;
    } 
    {
        auto& w = add_inplace(u,v);
        std::cout << "adresse du tableau w recevant le résultat de add_inplace : " << (void*)w.data() << std::endl;        
    }
}
