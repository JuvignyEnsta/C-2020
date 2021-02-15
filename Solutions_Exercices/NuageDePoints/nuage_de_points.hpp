#ifndef _NUAGE_DE_POINTS_HPP_
#define _NUAGE_DE_POINTS_HPP_
#include <array>
#include <cassert>
#include <vector>
#include <iostream>

namespace geometrie
{
    using point = std::array<double,2>;

    class nuage_de_points
    {
    public:
        nuage_de_points() = default;

        nuage_de_points(int nombre_de_points) try
            : ensemble_des_points(nombre_de_points)
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
        catch(std::bad_alloc& err)
        {
            std::cerr << "Erreur lors de l'allocation du nuage de points : " << err.what() << std::endl;
            throw err;
        }

        nuage_de_points( const nuage_de_points& nuage) = default;
        nuage_de_points( nuage_de_points&& nuage ) = default;

        nuage_de_points( int début, int fin, const nuage_de_points& nuage) try
            : ensemble_des_points(nuage.ensemble_des_points.begin()+début, 
                                  nuage.ensemble_des_points.begin()+fin)
        {
            // Pré-conditions
            assert(début >= 0);
            assert(fin < nuage.ensemble_des_points.size());
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            // Post-condition
            assert(this->ensemble_des_points.size() == fin - début);
        }
        catch(std::bad_alloc& err)
        {
            std::cerr << "Erreur lors de l'allocation du nuage de points : " << err.what() << std::endl;
            throw err;
        }

        nuage_de_points( const std::initializer_list<point>& liste_de_points) noexcept
            : ensemble_des_points(liste_de_points)
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;            
        }

        ~nuage_de_points() = default;

    private:
        std::vector<point> ensemble_des_points;
    };
}

#endif