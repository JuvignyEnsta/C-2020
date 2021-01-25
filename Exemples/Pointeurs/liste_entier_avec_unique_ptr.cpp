#include <iostream>
#include <memory>

struct liste_entier
{
    int valeur;
    std::unique_ptr<liste_entier> prochain;
};

void ajoute_valeur(std::unique_ptr<liste_entier>& liste, int valeur)
{
    if (liste->prochain != nullptr)
    {
        ajoute_valeur(liste->prochain, valeur);
    }
    else
    {
        liste->prochain = std::make_unique<liste_entier>(valeur, nullptr);
    }
}

// Supprime toutes les occurences de valeur :
std::unique_ptr<liste_entier>& supprime_valeur(std::unique_ptr<liste_entier>& liste, int valeur)
{
    // A CONTINUER
//}