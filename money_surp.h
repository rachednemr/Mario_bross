#ifndef MONEY_SURP_H_INCLUDED
#define MONEY_SURP_H_INCLUDED
#include <SDL/SDL.h>
#include <vector>
#include "base.h"
#include "surprise.h"
class money_surp:public baseclass,public surprise
//class money_surp:public baseclass

{
SDL_Rect box;
int xvel,yvel;
SDL_Surface* image;
bool ground;
int valeur;
bool movement;
double frame;
SDL_Rect clips[2];
public:
    money_surp(SDL_Surface* img ,int x,int y,int xvel,int yvel);
    void show(SDL_Surface*);
    void setFrame(double);
    double getFrame();
    SDL_Rect* getRect();
    void setX(int X);
    void setY(int Yval);
    bool getmovement();
    int getValeur();
    void setmovement(bool x);
};


#endif // MONEY_SURP_H_INCLUDED
