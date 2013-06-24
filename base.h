#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <SDL/SDL.h>
class baseclass
{
public:
    static  SDL_Rect coord;
    static const int tile_size=30;
    protected : bool collision(SDL_Rect* rect1,SDL_Rect* rect2);
SDL_Rect box;
SDL_Surface* image;
double frame;
SDL_Rect clips[50];
public : SDL_Rect* getRect();
public : void setFrame(double Fr);
public : double getFrame();
};
#endif
// BASE_H_INCLUDED

