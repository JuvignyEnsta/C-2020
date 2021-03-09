#include "rationnel.hpp"
#include <assert.h>
#include <stdexcept>

using arithmetic::rationnel;

namespace
{
// Calcul du pgcd par algorithme d'Euclide
template<typename Int> Int pgcd( Int p, Int q)
{
    if (p == 0LL) return q;
    if (q == 0LL) return p;
    if (p<0) p = -p;
    if (q<0) q = -q;
    if (p < q) std::swap(p,q);
    // On utilise l'algorithme d'Euclide pour calculer le pgcd :
    while (q != 0LL)
    {
        Int t = q;
        q = p%q;
        p = t;
    }
    assert(p>0);
    return p;
}

template<typename Int> rationnel<Int> 
approximation_rationnelle(double x, const rationnel<Int>& pn, const rationnel<Int>& qn, double tol )
{
    auto [pnum, pdénom] = pn.valeurs();
    auto [qnum, qdénom] = qn.valeurs();
    rationnel<Int> median{ Int(pnum + qnum), Int(pdénom + qdénom)};
    double y = double(median);
    if (std::abs(x-y) < tol) return median;
    if (y < x) return approximation_rationnelle(x, median, qn, tol);
    else return approximation_rationnelle(x, pn, median, tol);
}

}// Fin espace de nommage anonyme

template<typename Int>
arithmetic::rationnel<Int>::rationnel( Int num, Int dénom)
    :   m_numérateur(num), m_dénominateur(dénom)
{
    if (dénom <= 0) throw std::runtime_error("Le dénominateur doit être strictement positif");
    if (dénom != 1)
    {
        auto p = pgcd(num, dénom);
        this->m_numérateur /= p; this->m_dénominateur /= p;
    }
    assert(this->m_dénominateur > 0);
}

// On explore l'arbre de Stern-Brocot pour trouver une approximation de x par un rationnel
// irréductible dont le quotien reste relativement petit. 
template<typename Int>
arithmetic::rationnel<Int>::rationnel( double real, double epsilon)
    :   m_numérateur(0), m_dénominateur(1)
{
    double x = std::abs(real);
    rationnel p0{Int(x)};
    rationnel q0{Int(x+1)};

    rationnel p = ::approximation_rationnelle(x, p0, q0, epsilon);
    this->m_numérateur = p.numérateur();
    this->m_dénominateur = p.dénominateur();
}

template<typename Int> rationnel<Int>& 
arithmetic::rationnel<Int>::operator += ( const rationnel<Int>& p)
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);
    rationnel<Int> q(*this);
    this->m_numérateur = q.m_numérateur*p.m_dénominateur + q.m_dénominateur*p.m_numérateur;
    this->m_dénominateur = q.m_dénominateur*p.m_dénominateur;
    auto gcd = pgcd(this->m_numérateur, this->m_dénominateur);
    this->m_numérateur /= gcd; this->m_dénominateur /= gcd;
    assert(this->m_dénominateur > 0);
    return *this;
}

template<typename Int> rationnel<Int>& 
arithmetic::rationnel<Int>::operator -= ( const rationnel& p)
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);
    rationnel q(*this);
    this->m_numérateur = q.m_numérateur*p.m_dénominateur - q.m_dénominateur*p.m_numérateur;
    this->m_dénominateur = q.m_dénominateur*p.m_dénominateur;
    Int gcd = pgcd(this->m_numérateur, this->m_dénominateur);
    this->m_numérateur /= gcd; this->m_dénominateur /= gcd;
    assert(this->m_dénominateur > 0);
    return *this;
}

template<typename Int> rationnel<Int>& 
arithmetic::rationnel<Int>::operator *= ( const rationnel& p)
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);
    if ( (p.m_numérateur == 0LL) || (this->m_numérateur == 0LL) )
        *this = {Int(0),Int(1)};
    else
    {
        rationnel q(*this);
        auto p1 = pgcd(p.m_numérateur, this->m_dénominateur);
        auto p2 = pgcd(this->m_numérateur, p.m_dénominateur);
        this->m_numérateur /= p2;
        this->m_numérateur *= (p.m_numérateur/p1);
        this->m_dénominateur /= p1;
        this->m_dénominateur *= (p.m_dénominateur/p2);
    }
    assert(this->m_dénominateur > 0);
    return *this;
}

template<typename Int> rationnel<Int>& 
arithmetic::rationnel<Int>::operator /= ( const rationnel& p)
{
    assert(this->m_dénominateur != 0);
    assert(p.m_dénominateur     != 0);
    if (p.m_numérateur == 0)
    {
        throw std::runtime_error("Division par zéro !");
    }
    if ( this->m_numérateur == 0 )
        *this = {Int(0),Int(1)};
    else
    {
        rationnel q(*this);
        auto p1 = pgcd(p.m_dénominateur, this->m_dénominateur);
        auto p2 = pgcd(this->m_numérateur, p.m_numérateur);
        this->m_numérateur /= p2;
        this->m_numérateur *= (p.m_dénominateur/p1);
        this->m_dénominateur /= p1;
        this->m_dénominateur *= (p.m_numérateur/p2);
    }
    if (this->m_dénominateur < 0)
    {
        this->m_numérateur = -this->m_numérateur;
        this->m_dénominateur = -this->m_dénominateur;
    }
    return *this;
}

template<typename Int> rationnel<Int> 
arithmetic::rationnel<Int>::operator + ( const rationnel& p) const
{
    assert(this->m_dénominateur != 0);
    assert(p.m_dénominateur     != 0);

    rationnel<Int> s(Int(this->m_numérateur*p.m_dénominateur + this->m_dénominateur*p.m_numérateur), 
                     Int(this->m_dénominateur*p.m_dénominateur)
               );
    auto gcd = pgcd(s.m_numérateur, s.m_dénominateur);
    s.m_numérateur /= gcd; s.m_dénominateur /= gcd;

    assert(s.m_dénominateur > 0);
    return s;
}

template<typename Int> rationnel<Int>
arithmetic::rationnel<Int>::operator - ( const rationnel& p) const
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);

    rationnel s{Int(this->m_numérateur*p.m_dénominateur - this->m_dénominateur*p.m_numérateur), 
                Int(this->m_dénominateur*p.m_dénominateur)
               };
    auto gcd = pgcd(s.m_numérateur, s.m_dénominateur);
    s.m_numérateur /= gcd; s.m_dénominateur /= gcd;

    assert(s.m_dénominateur > 0);
    return s;    
}

template<typename Int> rationnel<Int>
arithmetic::rationnel<Int>::operator * ( const rationnel& p ) const
{
    assert(this->m_dénominateur != 0);
    assert(p.m_dénominateur     != 0);
    if ( (p.m_numérateur == 0) || (this->m_numérateur == 0) )
        return {Int(0),Int(1)};
    auto p1 = pgcd(p.m_numérateur, this->m_dénominateur);
    auto p2 = pgcd(this->m_numérateur, p.m_dénominateur);

    assert((this->m_dénominateur/p1)*(p.m_dénominateur/p2) > 0);
    return rationnel<Int>(Int((this->m_numérateur/p2)*(p.m_numérateur/p1)), 
                          Int((this->m_dénominateur/p1)*(p.m_dénominateur/p2)) );
}

template<typename Int>  rationnel<Int> 
arithmetic::rationnel<Int>::operator / ( const rationnel& p) const
{
    assert(this->m_dénominateur != 0);
    assert(p.m_dénominateur     != 0);
    if (p.m_numérateur == 0)
    {
        throw std::runtime_error("Division par zéro !");
    }
    if ( this->m_numérateur == 0 )
        return {Int(0),Int(1)};
    auto p1 = pgcd(p.m_dénominateur, this->m_dénominateur);
    auto p2 = pgcd(this->m_numérateur, p.m_numérateur);
    auto num   = (this->m_numérateur/p2) * (p.m_dénominateur/p1);
    auto dénom = (this->m_dénominateur/p1) * (p.m_numérateur/p2);
    if (dénom < 0) 
    {
        num   = -num;
        dénom = -dénom;
    }

    assert(dénom > 0);
    return { Int(num), Int(dénom) };
}

template<typename Int>  rationnel<Int>
arithmetic::rationnel<Int>::operator  - () const
{
    return {Int(-this->m_numérateur), Int(this->m_dénominateur)};
}

template<typename Int>  decltype(Int(1)<=>Int(2)) 
arithmetic::rationnel<Int>::operator <=> ( const rationnel& p) const
{
    assert(this->m_dénominateur != 0);
    assert(p.m_dénominateur     != 0);

    if ( (this->m_numérateur == p.m_numérateur) && (this->m_dénominateur == p.m_dénominateur) ) 
        return std::strong_ordering::equal;
    if (this->m_numérateur * p.m_dénominateur <  p.m_numérateur * this->m_dénominateur) 
        return std::strong_ordering::less;
    assert(this->m_numérateur * p.m_dénominateur >  p.m_numérateur * this->m_dénominateur);
    return std::strong_ordering::greater;

}
