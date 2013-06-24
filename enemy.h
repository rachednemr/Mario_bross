#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <SDL/SDL.h>
#include <vector>
#include "base.h"

class enemy: public virtual baseclass
{
public :
//SDL_Rect box;
int xvel,yvel;
//SDL_Surface* image;
bool ground;
//double frame;
//SDL_Rect clips[5];
public:
    enemy(SDL_Surface*img,int x,int y,int xvel,int yvel);
   void move(const std::vector< std::vector< int > >& map);
    void show(SDL_Surface*);
   //void setFrame(double);
   // double getFrame();
 //   SDL_Rect* getRect();
    int getxvel();
void  setxvel(int xvel);
//void setdirection(int xvel);
};


#endif // ENEMY_H_INCLUDED
