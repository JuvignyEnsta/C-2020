#include <iostream>
#include <string>
#include <cwchar>

int main()
{
    char ascii = 'p';
    // char ascii = 'é'; Erreur de compilation car é codé sur plus d'un octet avec un éditeur unicode
    char utf8 = u8'p'; // Ok car p codé sur un seul octet.
    //char utf8 = u8'é'; Erreur compilation car C++ attend dans ce cas des caractères de taille constant...
    wchar_t utf16 = u'é';// OK, code sur deux octets, contient le caractère é
    char32_t utf32 = u'é'; // ok, code sur quatre octets

    std::cout << "ascii : " << ascii << ", utf8 : " << utf8 << std::endl;
    // Pour afficher des caractères codés sur 16 bits, on utilise wcout, mais l'affichage est bizarre : 
    std::wcout << "utf16 : " << utf16 << std::endl;
    // Pour afficher un caracère codé sur 32 bits ????
    return EXIT_SUCCESS;
}