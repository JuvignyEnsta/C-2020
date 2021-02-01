#include <unordered_map>
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
    std::pair<int, double> p;
    p.first = 3; p.second = 3.14;

    std::unordered_map<std::string, fiche_étudiant> classe;
    classe["Chambier"s] = fiche_étudiant{"Robert"s, "Chambier"s, 33, 32423, 2022};

    std::unordered_map classe2{ 
        std::pair{"Chambier"s, fiche_étudiant{"Robert"s, "Chambier"s, 33, 32423, 2022}},
                 {"Laplace"s, fiche_étudiant{"Simon"s, "Laplace"s, 37, 11897, 2022}} };

    std::cout << classe2["Laplace"s].prénom << std::endl;

    for (const auto& valeur : classe2 )
    {
        std::cout << "clef : " << valeur.first << " contient pour étudiant : "
                  << valeur.second.prénom << " " << valeur.second.nom << std::endl;
    }


}