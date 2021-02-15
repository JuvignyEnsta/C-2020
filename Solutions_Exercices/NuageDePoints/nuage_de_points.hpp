#ifndef _NUAGE_DE_POINTS_HPP_
#define _NUAGE_DE_POINTS_HPP_
#include <array>
#include <cassert>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

namespace geometrie
{
    using point = std::array<double,2>;

    class nuage_de_points
    {
    public:
        using iterator = std::vector<point>::iterator;
        using const_iterator = std::vector<point>::const_iterator;

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

        nuage_de_points& operator = ( const nuage_de_points& ) = default;
        nuage_de_points& operator = ( nuage_de_points&& ) = default;

        std::size_t size() const
        {
            return this->ensemble_des_points.size();
        }

        point& operator [] ( std::size_t i )
        {
            assert(i < this->ensemble_des_points.size());
            return this->ensemble_des_points[i];
        }

        const point& operator [] ( std::size_t i ) const
        {
            assert(i < this->ensemble_des_points.size());
            return this->ensemble_des_points[i];
        }

        nuage_de_points operator + ( const nuage_de_points& nuage ) const
        {
            nuage_de_points nuage_union;
            nuage_union.ensemble_des_points.reserve(this->size() + nuage.size());
            for ( const auto& pt : this->ensemble_des_points )
            {
                nuage_union.ensemble_des_points.emplace_back(pt);
            }
            for ( const auto& pt : nuage.ensemble_des_points )
            {
                nuage_union.ensemble_des_points.emplace_back(pt);
            }
            return nuage_union;
        }

        nuage_de_points& operator += ( const point& tr )
        {
            for ( auto& pt : this->ensemble_des_points )
            {
                pt[0] += tr[0];
                pt[1] += tr[1];
            }
            return *this;
        }

        explicit operator std::string() const
        {
            std::string out("{");
            for ( int i = 0; (i < 5) && (i < this->size()); ++i)
            {
                out += "(" + std::to_string(this->ensemble_des_points[i][0]) + ", " 
                           + std::to_string(this->ensemble_des_points[i][1]) + ")";
            }
            if ( this->size() > 10) out += "...";
            if (this->size() > 5)
                for ( int i = std::max(this->size()-5, 5ULL); i < this->size(); ++i )
                    out += "(" + std::to_string(this->ensemble_des_points[i][0]) + ", " 
                               + std::to_string(this->ensemble_des_points[i][1]) + ")";
            out += "}";
            return out;
        }

        std::ostream& save(std::ostream& out ) const
        {
            out << this->size() << " ";
            for ( const auto& pt : this->ensemble_des_points )
                out << pt[0] << " " << pt[1] << " ";
            return out;
        }

        iterator begin()
        {
            return this->ensemble_des_points.begin();
        }

        const_iterator begin() const
        {
            return this->ensemble_des_points.begin();
        }

        iterator end()
        {
            return this->ensemble_des_points.end();
        }

        const_iterator end() const
        {
            return this->ensemble_des_points.end();
        }

    private:
        std::vector<point> ensemble_des_points;
    };
}

inline std::ostream& operator << (std::ostream& out, const geometrie::nuage_de_points& nuage )
{
    return nuage.save(out);
}

#endif