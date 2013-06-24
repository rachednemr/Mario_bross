#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include <SDL/SDL.h>
#include <iostream>
#include "base.h"
class bullet: public baseclass
{
//SDL_Rect box;
int xvel,yvel,angle;
SDL_Surface *image,*bull;
//SDL_Rect  clips[4];
//double frame;
public:
    void show2(SDL_Surface*);
    bullet ();
    bullet(SDL_Surface* img,int x,int y,int xvel,int yvel,int angle);
    void move();
    void show(const char* filename,SDL_Surface* screen);
   // SDL_Rect* getRect();
    SDL_Surface* load_image(const char* filename,SDL_Surface* screen);
    int getangle();
     void show(SDL_Surface*);
   // void setFrame(double);
    void setY(int Y);
    void setX(int X);
    //double getFrame();
    void setangle(int angle);
};
#endif // BULLET_H_INCLUDED
