#include <iostream>
#include <memory>
#include <cassert>

struct liste_entier
{
    int valeur;
    std::shared_ptr<liste_entier> prochain;
};

liste_entier init_liste_entier(int valeur)
{
    return {valeur, nullptr};
}

void ajoute_valeur(std::shared_ptr<liste_entier> liste, int valeur)
{
    assert(liste != nullptr);
    if (liste->prochain != nullptr)
    {
        ajoute_valeur(liste->prochain, valeur);
    }
    else
    {
        liste->prochain = std::make_shared<liste_entier>(valeur, nullptr);
    }
}

std::shared_ptr<liste_entier> supprime_valeur(std::shared_ptr<liste_entier> liste, int valeur)
{
    assert(liste != nullptr);
    if (liste->valeur == valeur)
        return supprime_valeur(liste->prochain, valeur);

    liste->prochain = supprime_valeur(liste->prochain, valeur);
    return liste;
}

