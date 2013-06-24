#ifndef SURPRISE_H_INCLUDED
#define SURPRISE_H_INCLUDED
#include <SDL/SDL.h>
#include <vector>
#include "base.h"
class surprise:public virtual baseclass
{
//SDL_Rect box;
//int xvel,yvel;
//SDL_Surface* image;
//bool ground;
bool movement;
//double frame;
//SDL_Rect clips[6];
int bonus;
public:
    surprise(SDL_Surface*,int x,int y,int xvel,int yvel);
    void show(SDL_Surface*);
   // void setFrame(double);
   // double getFrame();
  //  SDL_Rect* getRect();
    int getY();
    void setY(int Yvel);
    bool getmovement();
    int getBonus();
    void setmovement(bool x);
};
#endif // SURPRISE_H_INCLUDED
