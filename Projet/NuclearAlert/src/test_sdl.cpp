#include "SDL2/sdl2.hpp"
#include "SDL2/window.hpp"
#include "SDL2/font.hpp"
#include "SDL2/geometry.hpp"

int main(int argc, char* args[])
{
    // Initialisation de la librairie SDL 2 (System Direct Layer 2)
    sdl2::init(argc, args);

    //sdl2::font fonte_titre("./data/roman_font_7.ttf", 28);
    // Pour choisir une fonte courante pour afficher du texte (pas encore mis en oeuvre pour l'affichage du texte)
    sdl2::font fonte_texte("./data/roman_font_7.ttf", 18);

    // Créer une fenêtre avec un titre et la résolution de la fenêtre (ici 800 x 600 pixels )
    sdl2::window fenêtre("Nuclear Alert : Console principale", {800, 600});

    // On utilise des flux pour afficher le graphisme
    // Affichage d'un rectangle plein avec coin
    // 0 - 9 A = 10, B = 11, C= 12, D = 13, E = 14, F = 15 en base 16
    // 0x  => Ecriture hexadécimale (en base 16) 0x3E = 3*16 + 14 = 62 en décimal
    // 0b  => Ecriture binaire 0b100010 => écriture binaire = 2^{1} + 2^{5} = 33 en décimal
    // 
    // Donc 0xAB = 10*16 + 11 = 171 en décimal
    //      0xFF = 15*16 + 15 = 255 en décimal
    fenêtre << sdl2::rectangle({100,100}, {100,50}, {0,0xFF,0xFF,0xFF}, true);
    // Affichage d'un segment de droite
    fenêtre << sdl2::line({10,10}, {50,30}, {0xFF,0x00,0x00,0xFF});
    // Affichage d'un polygone.
    fenêtre << sdl2::polygon({ std::array{200,200}, {250,250}, {200,300}, {150,250} }, {0xFF,0xFF,0x00,0xFF})
            << sdl2::flush;
    SDL_Delay(4000);

    sdl2::finalize();

    return EXIT_SUCCESS;
}