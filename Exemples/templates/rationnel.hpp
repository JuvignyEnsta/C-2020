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
    template<typename Int>
    class rationnel
    {
    public:
        //# Constructeur et destructeurs
        //@{
        rationnel()
            : m_numérateur(0), m_dénominateur(1)
        {}
        rationnel( Int num, Int dénom = 1LL);
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
        // Opérateur spatial (spaceship operator) pour les comparaisons (C++ 20)
        decltype(Int(1)<=>Int(2)) operator <=> ( const rationnel& ) const;
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
        std::pair<Int, Int> valeurs() const 
        { 
            return {this->m_numérateur, this->m_dénominateur};
        }
        Int numérateur() const { return this->m_numérateur; }
        Int dénominateur() const { return this->m_dénominateur; }
        //@}

    private:
        Int m_numérateur, m_dénominateur;
    };
}

template<typename Int> inline
arithmetic::rationnel<Int> operator + ( Int val, const arithmetic::rationnel<Int>& p)
{
    return p + val;
}

template<typename Int> inline
arithmetic::rationnel<Int> operator - ( Int val, const arithmetic::rationnel<Int>& p)
{
    return -(p - val);
}

template<typename Int> inline
arithmetic::rationnel<Int> operator * ( Int val, const arithmetic::rationnel<Int>& p)
{
    return p * val;
}

template<typename Int> inline
arithmetic::rationnel<Int> operator / ( Int val, const arithmetic::rationnel<Int>& p)
{
    return arithmetic::rationnel<Int>(val)/p;
}

template<typename Int> inline
std::ostream& operator << ( std::ostream& out, const arithmetic::rationnel<Int>& p)
{
    auto [pn,pd] = p.valeurs();
    out << pn << " " << pd;
    return out;
}
#endif