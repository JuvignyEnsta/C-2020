#include "rationnel.hpp"
#include <assert.h>
#include <stdexcept>

using arithmetic::rationnel;

namespace
{
// Calcul du pgcd par algorithme d'Euclide
std::int64_t pgcd( std::int64_t p, std::int64_t q)
{
    if (p == 0LL) return q;
    if (q == 0LL) return p;
    if (p<0) p = -p;
    if (q<0) q = -q;
    if (p < q) std::swap(p,q);
    // On utilise l'algorithme d'Euclide pour calculer le pgcd :
    while (q != 0LL)
    {
        std::int64_t t = q;
        q = p%q;
        p = t;
    }
    assert(p>0);
    return p;
}

rationnel 
approximation_rationnelle(double x, const rationnel& pn, const rationnel& qn, double tol )
{
    auto [pnum, pdénom] = pn.valeurs();
    auto [qnum, qdénom] = qn.valeurs();
    rationnel median{ pnum + qnum, pdénom + qdénom};
    double y = double(median);
    if (std::abs(x-y) < tol) return median;
    if (y < x) return approximation_rationnelle(x, median, qn, tol);
    else return approximation_rationnelle(x, pn, median, tol);
}

}// Fin espace de nommage anonyme

arithmetic::rationnel::rationnel( std::int64_t num, std::int64_t dénom)
    :   m_numérateur(num), m_dénominateur(dénom)
{
    if (dénom <= 0LL) throw std::runtime_error("Le dénominateur doit être strictement positif");
    if (dénom != 1LL)
    {
        auto p = pgcd(num, dénom);
        this->m_numérateur /= p; this->m_dénominateur /= p;
    }
    assert(this->m_dénominateur > 0);
}

// On explore l'arbre de Stern-Brocot pour trouver une approximation de x par un rationnel
// irréductible dont le quotien reste relativement petit. 
arithmetic::rationnel::rationnel( double real, double epsilon)
    :   m_numérateur(0LL), m_dénominateur(1LL)
{
    double x = std::abs(real);
    rationnel p0{std::int64_t(x)};
    rationnel q0{std::int64_t(x+1)};

    rationnel p = ::approximation_rationnelle(x, p0, q0, epsilon);
    this->m_numérateur = p.numérateur();
    this->m_dénominateur = p.dénominateur();
}

rationnel& 
arithmetic::rationnel::operator += ( const rationnel& p)
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);
    rationnel q(*this);
    this->m_numérateur = q.m_numérateur*p.m_dénominateur + q.m_dénominateur*p.m_numérateur;
    this->m_dénominateur = q.m_dénominateur*p.m_dénominateur;
    std::int64_t gcd = pgcd(this->m_numérateur, this->m_dénominateur);
    this->m_numérateur /= gcd; this->m_dénominateur /= gcd;
    assert(this->m_dénominateur > 0);
    return *this;
}

rationnel& 
arithmetic::rationnel::operator -= ( const rationnel& p)
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);
    rationnel q(*this);
    this->m_numérateur = q.m_numérateur*p.m_dénominateur - q.m_dénominateur*p.m_numérateur;
    this->m_dénominateur = q.m_dénominateur*p.m_dénominateur;
    std::int64_t gcd = pgcd(this->m_numérateur, this->m_dénominateur);
    this->m_numérateur /= gcd; this->m_dénominateur /= gcd;
    assert(this->m_dénominateur > 0);
    return *this;
}

rationnel& 
arithmetic::rationnel::operator *= ( const rationnel& p)
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);
    if ( (p.m_numérateur == 0LL) || (this->m_numérateur == 0LL) )
        *this = {0LL,1LL};
    else
    {
        rationnel q(*this);
        std::int64_t p1 = pgcd(p.m_numérateur, this->m_dénominateur);
        std::int64_t p2 = pgcd(this->m_numérateur, p.m_dénominateur);
        this->m_numérateur /= p2;
        this->m_numérateur *= (p.m_numérateur/p1);
        this->m_dénominateur /= p1;
        this->m_dénominateur *= (p.m_dénominateur/p2);
    }
    assert(this->m_dénominateur > 0);
    return *this;
}

rationnel& 
arithmetic::rationnel::operator /= ( const rationnel& p)
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);
    if (p.m_numérateur == 0LL)
    {
        throw std::runtime_error("Division par zéro !");
    }
    if ( this->m_numérateur == 0LL )
        *this = {0LL,1LL};
    else
    {
        rationnel q(*this);
        std::int64_t p1 = pgcd(p.m_dénominateur, this->m_dénominateur);
        std::int64_t p2 = pgcd(this->m_numérateur, p.m_numérateur);
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

rationnel 
arithmetic::rationnel::operator + ( const rationnel& p) const
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);

    rationnel s{this->m_numérateur*p.m_dénominateur + this->m_dénominateur*p.m_numérateur, 
                this->m_dénominateur*p.m_dénominateur
               };
    std::int64_t gcd = pgcd(s.m_numérateur, s.m_dénominateur);
    s.m_numérateur /= gcd; s.m_dénominateur /= gcd;

    assert(s.m_dénominateur > 0);
    return s;
}

rationnel 
arithmetic::rationnel::operator - ( const rationnel& p) const
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);

    rationnel s{this->m_numérateur*p.m_dénominateur - this->m_dénominateur*p.m_numérateur, 
                this->m_dénominateur*p.m_dénominateur
               };
    std::int64_t gcd = pgcd(s.m_numérateur, s.m_dénominateur);
    s.m_numérateur /= gcd; s.m_dénominateur /= gcd;

    assert(s.m_dénominateur > 0);
    return s;    
}

rationnel 
arithmetic::rationnel::operator * ( const rationnel& p ) const
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);
    if ( (p.m_numérateur == 0LL) || (this->m_numérateur == 0LL) )
        return {0LL,1LL};
    std::int64_t p1 = pgcd(p.m_numérateur, this->m_dénominateur);
    std::int64_t p2 = pgcd(this->m_numérateur, p.m_dénominateur);

    assert((this->m_dénominateur/p1)*(p.m_dénominateur/p2) > 0);
    return { (this->m_numérateur/p2)*(p.m_numérateur/p1), 
             (this->m_dénominateur/p1)*(p.m_dénominateur/p2) };
}

rationnel 
arithmetic::rationnel::operator / ( const rationnel& p) const
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);
    if (p.m_numérateur == 0LL)
    {
        throw std::runtime_error("Division par zéro !");
    }
    if ( this->m_numérateur == 0LL )
        return {0LL,1LL};
    std::int64_t p1 = pgcd(p.m_dénominateur, this->m_dénominateur);
    std::int64_t p2 = pgcd(this->m_numérateur, p.m_numérateur);
    std::int64_t num   = (this->m_numérateur/p2) * (p.m_dénominateur/p1);
    std::int64_t dénom = (this->m_dénominateur/p1) * (p.m_numérateur/p2);
    if (dénom < 0) 
    {
        num   = -num;
        dénom = -dénom;
    }

    assert(dénom > 0);
    return { num, dénom };
}

rationnel 
arithmetic::rationnel::operator  - () const
{
    return {-this->m_numérateur, this->m_dénominateur};
}

decltype(1LL<=>2LL) 
arithmetic::rationnel::operator <=> ( const rationnel& p) const
{
    assert(this->m_dénominateur != 0LL);
    assert(p.m_dénominateur     != 0LL);

    if ( (this->m_numérateur == p.m_numérateur) && (this->m_dénominateur == p.m_dénominateur) ) 
        return std::strong_ordering::equal;
    if (this->m_numérateur * p.m_dénominateur <  p.m_numérateur * this->m_dénominateur) 
        return std::strong_ordering::less;
    assert(this->m_numérateur * p.m_dénominateur >  p.m_numérateur * this->m_dénominateur);
    return std::strong_ordering::greater;

}
