#ifndef FLEUR_UTILE_H_INCLUDED
#define FLEUR_UTILE_H_INCLUDED
#include <SDL/SDL.h>
#include <vector>
#include "base.h"
#include "surprise.h"
class Fleur_Utile: public surprise
{
int chance_vie;
//SDL_Rect box;
int xvel,yvel;
SDL_Surface* image;
bool ground;
//bool movement;
//double frame;
//SDL_Rect clips[2];
public:
    Fleur_Utile(SDL_Surface*,int x,int y,int xvel,int yvel);
    void show(SDL_Surface*);
//    void setFrame(double);
 //   double getFrame();
  //  SDL_Rect* getRect();

//    void setY(int Yval);
    int getChance_vie();
};



#endif // FLEUR_UTILE_H_INCLUDED
