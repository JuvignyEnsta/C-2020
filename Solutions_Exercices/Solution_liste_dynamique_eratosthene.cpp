#include <iostream>
#include <memory>
#include <cstdint>
#include <cmath>

struct liste_entier
{
    std::int32_t valeur;
    std::shared_ptr<liste_entier> prochain;
};

std::shared_ptr<liste_entier> initialisation(int valeur)
{
    return std::make_shared<liste_entier>(valeur, nullptr);
}

void rajouter(std::shared_ptr<liste_entier> lst, int valeur)
{
    std::shared_ptr<liste_entier> dernier = lst;
    while (dernier->prochain != nullptr)
    {
        dernier = dernier->prochain;
    }
    dernier->prochain = std::make_shared<liste_entier>(valeur,nullptr);
}

void afficher_liste(std::shared_ptr<liste_entier> lst)
{
    std::shared_ptr<liste_entier> current = lst;
    while (current != nullptr)
    {
        std::cout << current->valeur << " ";
        current = current->prochain;
    }
}


void supprimer_multiple_de(std::shared_ptr<liste_entier> lst, int valeur)
{
    std::shared_ptr<liste_entier> current = lst;
    while (current->prochain != nullptr)
    {
        if ( (current->prochain->valeur % valeur == 0) && (current->prochain->valeur > valeur) )
            current->prochain = current->prochain->prochain;
        else
            current = current->prochain;
    }
}

int main()
{
    const int N = 100;
    auto liste_premier = initialisation(2);
    for ( int i = 3; i < N; i += 2) rajouter(liste_premier, i);
    auto current = liste_premier;
    while (current->valeur < std::sqrt(N))
    {
        supprimer_multiple_de(liste_premier, current->valeur);
        current = current->prochain;
    }
    afficher_liste(liste_premier);
}