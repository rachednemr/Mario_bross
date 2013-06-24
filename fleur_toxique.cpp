#include"fleur_toxique.h"
#include"enemy.h"
#include <SDL/SDL.h>
#include <iostream>
fleur_toxique::fleur_toxique( SDL_Surface * img,int x,int y,int xvel,int yvel):enemy(img, x, y,xvel, yvel)
{
image=img;
box.x=x;
box.y=y;
box.w=image->w/2;
box.h=image->h;
xvel=xvel;
yvel=yvel;
ground=0;
arme=false;
for(int i=0;i<44;i++)
 {
  clips[i].x=i*30;
  clips[i].y=0;
  clips[i].w=30;
  clips[i].h=30;
 }
frame=20;
mouvement=true;
}
/*double  fleur_toxique::getFrame()
{
return frame;
}
void fleur_toxique::setFrame(double fr)
{
frame=fr;
}*/
void fleur_toxique::show(SDL_Surface* screen)
{ if (frame<44)
{
SDL_Rect tmp={box.x-coord.x,box.y,30,30};
SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);
frame+=0.1;
}
else
    {
   frame=0.0;
   SDL_Rect tmp={box.x-coord.x,box.y,30,30};
SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);

    }
    if (frame<=7)
        {
        mouvement=false;
        }
        else mouvement=true;
}
/*SDL_Rect* fleur_toxique::getRect()
{
return &box;

void  fleur_toxique::setX(int X)
{
box.x=X;
}
void fleur_toxique::setY(int Yval)
{
    box.y=Yval;
}*/
 bool fleur_toxique::getmouvement()
 {
 return mouvement;
 }
 bool fleur_toxique::getarme()
 {
     return arme;
 }


