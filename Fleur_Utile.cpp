#include"Fleur_Utile.h"
#include"surprise.h"
#include <SDL/SDL.h>
#include <iostream>
Fleur_Utile::Fleur_Utile(SDL_Surface* img ,int x,int y,int xVel,int yVel):surprise(img, x, y,xvel, yvel)
{
image=img;
box.x=x;
box.y=y;
box.w=image->w/2;
box.h=image->h;
//xvel=xVel;
//yvel=yVel;
ground=0;
for(int i=0;i<5;i++)
 {
  clips[i].x=i*30;
  clips[i].y=0;
  clips[i].w=30;
  clips[i].h=30;
 }
frame=0.0;
//movement=false;
chance_vie=1;
}
/*double  Fleur_Utile::getFrame()
{
return frame;
}*/
int Fleur_Utile::getChance_vie()
{
    return chance_vie;
}
/*void Fleur_Utile::setFrame(double fr)
{
frame=fr;
}*/
void Fleur_Utile::show(SDL_Surface* screen)
{ if (frame>=0.0)
{
    if (frame>1)
    {
        frame=0.0;
    }
SDL_Rect tmp={box.x-coord.x,box.y,30,30};
SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);
frame+=0.1;
}
}
/*SDL_Rect* Fleur_Utile::getRect()
{
return &box;
}*/
/*void Fleur_Utile::setY(int Yval)
{
    box.y=Yval;
}*/
 /*bool Fleur_Utile::getmovement()
 {
 return movement;
 }
    void Fleur_Utile::setmovement(bool mvt)
    {
    movement=mvt;
    }*/



