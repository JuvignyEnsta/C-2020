#ifndef _ARITHMETIC_RATIONNEL_HPP_
#define _ARITHMETIC_RATIONNEL_HPP_
#include <cstdint>
#include <iostream>
#include <string>

namespace arithmetic
{
    /***********************************************************************************************
     * @brief      Classe représentant des nombres rationnels                                      *
     **********************************************************************************************/
    class rationnel
    {
    public:
        //# Constructeur et destructeurs
        //@{
        rationnel()
            : m_numérateur(0LL), m_dénominateur(1LL)
        {}
        rationnel( std::int64_t num, std::int64_t dénom = 1LL);
        // Approche un réel par une fraction à epsilon près
        explicit rationnel( double real, double epsilon = 1.E-14 );
        rationnel( const rationnel& ) = default;
        rationnel(      rationnel&& ) = default;
        ~rationnel() = default;
        //@}

        //# Opérateurs
        //@{        
        rationnel& operator = ( const rationnel& ) = default;
        rationnel& operator = (      rationnel&& ) = default;
        rationnel& operator += ( const rationnel& );
        rationnel& operator -= ( const rationnel& );
        rationnel& operator *= ( const rationnel& );
        rationnel& operator /= ( const rationnel& );
        rationnel operator + ( const rationnel& ) const;
        rationnel operator - ( const rationnel& ) const;
        rationnel operator * ( const rationnel& ) const;
        rationnel operator / ( const rationnel& ) const;
        rationnel operator -() const;
        // Opérateur spatial (spaceship operator) pour les comparaisons
        decltype(1LL<=>2LL) operator <=> ( const rationnel& ) const;
        bool operator == ( const rationnel& ) const = default;// Pour dire qu'on utilise l'opérateur <=> sinon faut le redéfinir

        // Opérateur convertissant le rationnel en un réel flottant
        explicit operator double() const { return double(m_numérateur)/m_dénominateur; }
        explicit operator std::string() const 
        { 
            return "(" + std::to_string(this->m_numérateur) + "/" + std::to_string(this->m_dénominateur) + ")"; 
        }
        //@}

        //# Accesseurs et modifieurs
        //@{
        std::pair<std::int64_t, std::int64_t> valeurs() const 
        { 
            return {this->m_numérateur, this->m_dénominateur};
        }
        std::int64_t numérateur() const { return this->m_numérateur; }
        std::int64_t dénominateur() const { return this->m_dénominateur; }
        //@}

    private:
        std::int64_t m_numérateur, m_dénominateur;
    };
}

inline
arithmetic::rationnel operator + ( std::int64_t val, const arithmetic::rationnel& p)
{
    return p + val;
}

inline
arithmetic::rationnel operator - ( std::int64_t val, const arithmetic::rationnel& p)
{
    return -(p - val);
}

inline
arithmetic::rationnel operator * ( std::int64_t val, const arithmetic::rationnel& p)
{
    return p * val;
}

inline
arithmetic::rationnel operator / ( std::int64_t val, const arithmetic::rationnel& p)
{
    return arithmetic::rationnel(val)/p;
}

inline
std::ostream& operator << ( std::ostream& out, const arithmetic::rationnel& p)
{
    auto [pn,pd] = p.valeurs();
    out << pn << " " << pd;
    return out;
}
#endif