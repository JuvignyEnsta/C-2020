#include <memory>
#include <iostream>
#include <string>
#include <cstdint>

struct ficheEtudiant
{
    std::string prénom, nom;
    std::int32_t âge, numéro_carte_étudiant, promotion;
};

void affiche_edudiant( std::shared_ptr<ficheEtudiant> pt_fiche )
{
    std::cout << "Fiche de " << pt_fiche->prénom << " " << pt_fiche->nom << std::endl
              << "    âge : " << pt_fiche->âge << "\t numéro carte étudiant : " 
              << pt_fiche->numéro_carte_étudiant << std::endl
              << "    Promotion : " << pt_fiche->promotion << std::endl;    
    std::cout << "Nombre de référence à cette fiche : " << pt_fiche.use_count() << std::endl;
}

int main()
{
    auto pt_i1 = std::make_shared<int>(-4);
    std::cout << "Nombre de référence à -4 : " << pt_i1.use_count() << std::endl;
    {
        auto pt = pt_i1;
        std::cout << "Nombre de référence à -4 : " << pt_i1.use_count() << std::endl;
        {
            auto pt2 = pt;
            std::cout << "Nombre de référence à -4 : " << pt_i1.use_count() << std::endl;
        }
        std::cout << "Nombre de référence à -4 : " << pt_i1.use_count() << std::endl;
    }
    std::cout << "Nombre de référence à -4 : " << pt_i1.use_count() << std::endl;
    auto pt_fiche  = std::make_shared<ficheEtudiant>("Gérard","Chambier", 32, 132493, 2022);
    std::cout << "Nombre de référence à Chambier : " << pt_fiche.use_count() << std::endl;
    affiche_edudiant(pt_fiche);
    std::cout << "Nombre de référence à Chambier : " << pt_fiche.use_count() << std::endl;

    // Bien que ce ne soit pas conseillé, on peut accéder au pointeur natif :
    // Cela peut être nécessaire pour passer la valeur à une routine C demandant un pointeur natif.
    ficheEtudiant* pt_natif = pt_fiche.get();


    return EXIT_SUCCESS;
}