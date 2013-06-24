#include"fleur_ame.h"
#include <SDL/SDL.h>
#include <iostream>
fleur_ame::fleur_ame(SDL_Surface* img ,int x,int y,int xVel,int yVel)
{
image=img;
box.x=x;
box.y=y;
box.w=image->w/2;
box.h=image->h;
xvel=xVel;
yvel=yVel;
ground=0;
for(int i=0;i<2;i++)
 {
  clips[i].x=i*30;
  clips[i].y=0;
  clips[i].w=30;
  clips[i].h=30;
 }
frame=0.0;
movement=false;
}
double  fleur_ame::getFrame()
{
return frame;
}
void fleur_ame::setFrame(double fr)
{
frame=fr;
}
void fleur_ame::show(SDL_Surface* screen)
{ if (frame>=0.0)
{
    if (frame>1)
    {
        frame=0.0;
    }
SDL_Rect tmp={box.x-coord.x,box.y,30,30};
SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);
frame+=0.1;
}}
SDL_Rect* fleur_ame::getRect()
{
return &box;
}
void  fleur_ame::setX(int X)
{
box.x=X;
}
void fleur_ame::setY(int Yval)
{
    box.y=Yval;
}
 bool fleur_ame::getmovement()
 {
 return movement;
 }
    void fleur_ame::setmovement(bool mvt)
    {
    movement=mvt;
    }
    /*fleur_ame::~fleur_ame()
      {
      SDL_FreeSurface(image);
      }*/


