#include <string>
#include <cstdint>
#include <iostream>

using namespace std::string_literals;

struct fiche_élève
{
    std::string prénom, nom;
    std::int32_t âge, numéro_étudiant, promotion;
};

int main()
{
    fiche_élève fich1; // Fiche non initialisée
    // Initialisation complète de la fiche
    fiche_élève fich2{"Henry"s, "Chombier"s, 33, 124954L, 2020};
    // Initialisation partielle par désignation des champs
    fiche_élève fich3{.prénom="Paul", .nom="Pierre", .promotion=2020};

    std::cout << "fich1 : " << fich1.prénom << " " << fich1.nom
              << ", âge : " << fich1.âge << ", numéro étudiant : " << fich1.numéro_étudiant
              << ", promotion : " << fich1.promotion << std::endl; 

    std::cout << "fich2 : " << fich2.prénom << " " << fich2.nom
              << ", âge : " << fich2.âge << ", numéro étudiant : " << fich2.numéro_étudiant
              << ", promotion : " << fich2.promotion << std::endl; 

    std::cout << "fich3 : " << fich3.prénom << " " << fich3.nom
              << ", âge : " << fich3.âge << ", numéro étudiant : " << fich3.numéro_étudiant
              << ", promotion : " << fich3.promotion << std::endl; 
    return EXIT_SUCCESS;
}
