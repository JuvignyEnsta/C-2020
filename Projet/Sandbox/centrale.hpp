#ifndef _NUCLEARALERT_CENTRALE_HPP_
#define _NUCLEARALERT_CENTRALE_HPP_
#include <memory>
#include "circuit.hpp"
#include "centrale_base.hpp"

class centrale : public centrale_base
{
public:
    // Design pattern : Singleton
    static centrale& get();

    /**
     * @brief      Retourne l'état général de la centrale
     *
     * @return     { description_of_the_return_value }
     */
    double etat() const
    {
        double etat_primaire = primaire.etat();
    }

    /**
     * @brief      Production en MW actuelle de la centrale
     *
     * @return     { description_of_the_return_value }
     */
    virtual double lire_production() const override;


private:
    centrale();
    static centrale* la_centrale;
    std::unique_ptr<circuit> primaire, secondaire;
};


#endif