#include <string>
#include <iostream>

using namespace std::string_literals;// Indispensable pour utiliser le suffixe s

int main()
{
    char texte_c[] = "Ceci est une chaîne de caractère\n";
    std::cout << texte_c;
    char texte_brut[] = R"LIM(
Un texte brut est un texte où aucun caractère n'est interprété. Ainsi :
    1. Le retour à la ligne fait parti du texte;
    2. On peut utiliser le caractère " sans avoir de soucis qu'on l'interprète comme
       la fin de la chaîne de caractère;
    3. On termine la chaîne de caractère avec le délimiteur donné en début de chaîne
       (mais avec une parenthèse fermante au lieu d'une parenthèse ouvrante).
    )LIM";
    std::cout << texte_brut << std::endl;

    std::string une_première_chaîne = "Une chaîne de caractère basique transformée en std::string";
    std::string une_seconde_chaîne = "Une chaîne de caractère std::string définie directe"s;

    // Remarque : cette ligne ne marche plus en C++ 20 !
    // std::cout << u8"Essai" << std::endl;
#   if (__cplusplus >= 201709)
    std::u8string essai = u8"essai";// Pour stocker une chaîne de caractère u8 en C++ 20
    // On ne peut plus afficher de chaîne de caractère u8 en C++ 20 !
    // std::cout << "essai : " << essai << std::endl;
#   else
    std::string essai = u8"essai";
    // Par contre, avant C++ 20, c'était facile d'afficher une chaîne de caractère u8 !!!
    std::cout << "essai : " << essai << std::endl;
#   endif

    std::string    nom = "Dupont"s;
    std::string prénom = "Albert"s;
    std::string    âge = std::to_string(20);
    std::string identité = nom + " "s + prénom + " : âge "s + âge + " ans\n"s;
    std::cout << identité << std::endl; 

    std::string grosse_chaîne = "Ceci est un essai intéressant. Peut-on trouver une sous-chaîne dans une grosse chaîne ?";
    // On cherche une première occurence de chaîne dans la grosse_chaîne :
    std::size_t pos = grosse_chaîne.find("chaîne"s);
    if (pos != std::string::npos)
        std::cout << "J'ai trouvé une première occurence de chaîne à la position : " << pos << std::endl;
    // Puis on cherche une seconde occurence en commençant juste après la première position
    // de chaîne qu'on vient de trouver :
    pos = grosse_chaîne.find("chaîne"s, pos+1);
    if (pos != std::string::npos)
        std::cout << "J'ai trouvé une seconde occurence de chaîne à la position : " << pos << std::endl;

    std::cout << "Longueur de chaîne : " << "chaîne"s.length() << std::endl;


    return EXIT_SUCCESS;
}