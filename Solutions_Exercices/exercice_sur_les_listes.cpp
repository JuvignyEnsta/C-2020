#include <list>
#include <iostream>
#include <string>

using namespace std::string_literals;

struct fiche_étudiant
{
    std::string prénom, nom;
    int âge, numéro_carte_étudiant, promotion;
};

int main()
{
    std::list classe{ fiche_étudiant{"Robert"s, "Chambier"s, 33, 12234, 2022},
                                    {"Nicolas"s, "Hubert"s, 23, 43245, 2022 },
                                    {"Alexandre"s, "Benoît"s, 25, 23423, 2023},
                                    {"Paul"s, "Pierre"s, 21, 23532, 2022} };
    for ( const auto& eleve : classe )
    {
        std::cout << eleve.prénom << " " << eleve.nom << std::endl;
        std::cout << "\tâge : " << eleve.âge << " \tn° étudiant : " << eleve.numéro_carte_étudiant
                  << " \tPromotion : " << eleve.promotion << std::endl; 
    }
    std::cout << "#####################################################" << std::endl;
    classe.sort([](const fiche_étudiant& fich1, const fiche_étudiant& fich2)
                  { return fich1.nom < fich2.nom; });

    for ( const auto& eleve : classe )
    {
        std::cout << eleve.prénom << " " << eleve.nom << std::endl;
        std::cout << "\tâge : " << eleve.âge << " \tn° étudiant : " << eleve.numéro_carte_étudiant
                  << " \tPromotion : " << eleve.promotion << std::endl; 
    }

    std::cout << "#####################################################" << std::endl;
    classe.remove_if([](const fiche_étudiant& fiche) { return fiche.promotion == 2023; });
    for ( const auto& eleve : classe )
    {
        std::cout << eleve.prénom << " " << eleve.nom << std::endl;
        std::cout << "\tâge : " << eleve.âge << " \tn° étudiant : " << eleve.numéro_carte_étudiant
                  << " \tPromotion : " << eleve.promotion << std::endl; 
    }
    std::cout << "Nombre d'élèves : " << classe.size() << std::endl;
    std::list classe2 = classe;
    return EXIT_SUCCESS;
}