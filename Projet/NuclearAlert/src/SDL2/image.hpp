#ifndef _SDL2_IMAGE_HPP_
#define _SDL2_IMAGE_HPP_
#if defined(_WIN32)
#  include <SDL2/SDL.h>
#else
#  include <SDL.h>
#endif
#include <array>
#include <string>
#include "window.hpp"
#include "color.hpp"

namespace sdl2
{
    class image
    {
    public:
        image(const std::string& file, window& win);
        ~image();

        void at( int x, int y );
        void stretch_in( const std::array<int,2>& pos, const std::array<int,2>& dimension);
        void rotate( const std::array<int,2>& center, float angle);
        void color_filter(const color& col);

        virtual void render(window& win) const;
    private:
        SDL_Texture *pt_texture;
        SDL_Rect    position_and_stretching;
        int   centerx, centery;
        float angle;
        int   posx, posy;
    };
}

#endif