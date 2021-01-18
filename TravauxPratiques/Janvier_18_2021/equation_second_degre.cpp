/* Faire un programme qui prend en argument trois réels a, b et c et qui résout 
 * ax²+bx+c soit dans les réels si le discriminant est positif, sinon dans les complexes.

Pour choisir a,b, c, on va utiliser argc et argv :*/
#include <iostream>
#include <string> // Pour utiliser std::stod

int main(int nargs, char* argv[])
{
    double a,b,c;
    if (nargs < 4)
    {
        std::cerr << "Usage : ./equation <a> <b> <c>" << std::endl;
        return EXIT_FAILURE;
    }
    a = std::stod(argv[1]);// std::stod : Transforme une chaîne de caractère en réel double précision
    b = std::stod(argv[2]);
    c = std::stod(argv[3]);

    std::cout << "Résolution de l'équation " << a << "x² + " << b << "x + " << c << " = 0 " 
              << std::endl;




    return EXIT_SUCCESS;
}
