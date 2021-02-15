#if defined(_WIN32)
#  include <SDL2/SDL_image.h>
#else
#  include <SDL_image.h>
#endif
#include <stdexcept>
#include <string>
#include "image.hpp"

sdl2::image::image(const std::string &file, window& win)
    : pt_texture(nullptr),
      position_and_stretching(),
      centerx(-1), centery(-1),
      angle(0.f), posx(0), posy(0)
{
    // On charge l'image d'abord dans une surface temporaire
    SDL_Surface* loadedSurface = IMG_Load( file.c_str() );
    if( loadedSurface == nullptr )
    {
        std::string errmsg = "Incapable de charger le fichier " + file + " : " +
                             std::string(IMG_GetError());
        throw std::runtime_error(errmsg);
    }
    //Create texture from surface pixels
    this->pt_texture = SDL_CreateTextureFromSurface( win.get_native_renderer(), loadedSurface );
    if( this->pt_texture == nullptr )
    {
        std::string errmsg = "Incapable de créer une texture de " + file + " : "
                           + std::string(SDL_GetError());
        throw std::runtime_error(errmsg);
    }
    // Initialisation du rectangle d'affichage :
    this->position_and_stretching.x = 0; this->position_and_stretching.y = 0;
    this->position_and_stretching.w = loadedSurface->w;
    this->position_and_stretching.h = loadedSurface->h;
    // Destrution de la surface temporaire
    SDL_FreeSurface( loadedSurface );
}
// =================================================================================================
sdl2::image::at(int x, int y)
{

}