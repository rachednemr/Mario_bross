#ifndef MONEY_H_INCLUDED
#define MONEY_H_INCLUDED
#include <SDL/SDL.h>
#include <vector>
#include "base.h"
class money:public baseclass
{
SDL_Rect box;
int xvel,yvel;
SDL_Surface* image;
bool ground;
double frame;
SDL_Rect clips[4];
SDL_Rect clips2[2];
public:
    money(SDL_Surface*,int x,int y,int xvel,int yvel);
    void show(SDL_Surface*);
    void show2(SDL_Surface* );
    void setFrame(double);
    void setX(int x);
    void setY(int Y);
    double getFrame();
    SDL_Rect* getRect();
};

#endif // MONEY_H_INCLUDED
