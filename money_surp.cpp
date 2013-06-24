#include"money_surp.h"
#include"surprise.h"
#include <SDL/SDL.h>
#include <iostream>
money_surp::money_surp(SDL_Surface* img ,int x,int y,int xVel,int yVel):surprise(img, x, y,xvel, yvel)
{
image=img;
box.x=x;
box.y=y;
box.w=image->w/2;
box.h=image->h;
//xvel=xVel;
//yvel=yVel;
ground=0;
valeur=1;
for(int i=0;i<5;i++)
 {
  clips[i].x=i*30;
  clips[i].y=0;
  clips[i].w=30;
  clips[i].h=30;
 }
frame=0.0;
movement=false;
}
/*double  money_surp::getFrame()
{
return frame;
}
void money_surp::setFrame(double fr)
{
frame=fr;
}*/
void money_surp::show(SDL_Surface* screen)
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
SDL_Rect* money_surp::getRect()
{
return &box;
}
void  money_surp::setX(int X)
{
box.x=X;
}
void money_surp::setY(int Yval)
{
    box.y=Yval;
}
int money_surp::getValeur()
{
return valeur;
}
 bool money_surp::getmovement()
 {
 return movement;
 }
    void money_surp::setmovement(bool mvt)
    {
    movement=mvt;
    }



