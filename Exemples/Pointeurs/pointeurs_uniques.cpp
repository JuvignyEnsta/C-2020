#include <memory>
#include <iostream>
#include <cstdint>
#include <complex>
#include <string>
using namespace std::string_literals;// Indispensable pour utiliser le suffixe s

int main()
{
    struct ficheEtudiant
    {
        std::string prénom, nom;
        std::int32_t âge, numéro_carte_étudiant, promotion;
    };

    std::unique_ptr<double> pt_x = nullptr;
    auto pt_z = std::make_unique<std::complex<double>>(-1,3.14);

    auto pt_fiche1 = std::make_unique<ficheEtudiant>("Robert"s, "Chambier"s, 33, 23923, 2022);
    std::cout << "pt_fiche1 pointe sur une fiche étudiant à l'adresse : " << (void*)pt_fiche1.get() << std::endl;
    auto pt_fiche2 = std::move(pt_fiche1);
    std::cout << "pt_fiche1 pointe sur une fiche étudiant à l'adresse : " << (void*)pt_fiche1.get() << std::endl;
    std::cout << "pt_fiche2 pointe sur une fiche étudiant à l'adresse : " << (void*)pt_fiche2.get() << std::endl;

    return EXIT_SUCCESS;
}