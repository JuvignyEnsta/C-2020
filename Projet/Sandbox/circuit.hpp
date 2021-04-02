#ifndef _NUCLEARALERTE_CIRCUIT_HPP_
#define _NUCLEARALERTE_CIRCUIT_HPP_
#include "pompe.hpp"
#include "centrale_base.hpp"

class circuit
{
public:

    virtual double radioactivité( const centrale_base& c ) const = 0;
private:
    double etat;
    double debit;
    // Calcul de l'inertie 
    pompe pmp;
};

#endif