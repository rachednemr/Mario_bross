#ifndef FLEUR_AME_H_INCLUDED
#define FLEUR_AME_H_INCLUDED
#include <SDL/SDL.h>
#include <vector>
#include "base.h"
class fleur_ame:public baseclass
{
SDL_Rect box;
int xvel,yvel;
SDL_Surface* image;
bool ground;
bool movement;
double frame;
SDL_Rect clips[2];
public:
    fleur_ame(SDL_Surface*,int x,int y,int xvel,int yvel);
    void show(SDL_Surface*);
    void setFrame(double);
    double getFrame();
    SDL_Rect* getRect();
    void setX(int X);
    void setY(int Yval);
    bool getmovement();
    void setmovement(bool x);
};
#endif // FLEUR_AME_H_INCLUDED
