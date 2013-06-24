#ifndef CHAMPIGNON_H_INCLUDED
#define CHAMPIGNON_H_INCLUDED
#include "enemy.h"
class Champignon:public enemy
{
    int puissance;
char direction;
//SDL_Rect box;
//int xvel,yvel;
//SDL_Surface* image;
//bool ground;
//double frame;
//SDL_Rect clips[5];
public:
    Champignon(SDL_Surface*img,int x,int y,int xvel,int yvel);
  // void move(const std::vector< std::vector< int > >& map);
  // void show(SDL_Surface*);
   // void setFrame(double);
   // double getFrame();
    //SDL_Rect* getRect();
  //  int getxvel();
void setdirection(char  c);
char getdirection();
//void  setxvel(int xvel);
int getPuissance();
void setpuissance(int puiss);
};



#endif // TORTUE_H_INCLUDED


