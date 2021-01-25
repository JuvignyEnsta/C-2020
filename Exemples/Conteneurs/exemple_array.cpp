#include <array>
#include <iostream>
#include <iomanip>

int main()
{
    std::array<int,3> arr1;// Création d'un tableau de trois entiers
    arr1[0] = -1; arr1[1] = +2; arr1[2] = -3;
    /*
    arr1[4] = 0; // Bogue ! Si vous avez mis l'option -D_GLIBCXX_DEBUG, l'erreur sera détecté à l'exécution
    */

    std::array darray = {1., 2., 3., 4., 5., 6.};

    std::cout << "arr1 size : " << arr1.size() << std::endl;
    std::cout << "arr 1 : ";
    for ( const auto& val : arr1 ) std::cout << val << " ";
    std::cout << std::endl;

    std::array<std::array<double,3>,3> A = {
                    std::array{1.,2.,3.}, // <- Syntaxe C++ 17
                              {2.,3.,1.},
                              {3.,1.,2.}
                                           };

    std::cout << "Matrice A : " << std::endl;
    for ( const auto& row : A )
    {
        for ( const auto& value : row )
            std::cout << std::setw(4) << value;
        std::cout << std::endl;
    }

    std::array parties_entières = {-1., -2., 3., 6., -4.};
    std::array valeurs_réelles  = {-1.2, -2.3, 3.4, -6.5, -4.1};
    if ( parties_entières > valeurs_réelles )
        std::cout << "La partie entière possède des éléments plus gros !";

    return EXIT_SUCCESS;
}
