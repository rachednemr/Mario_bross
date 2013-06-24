#include"surprise.h"
#include <SDL/SDL.h>
#include <iostream>
surprise::surprise(SDL_Surface* img ,int x,int y,int xVel,int yVel)
{
image=img;
box.x=x;
box.y=y;
box.w=image->w/2;
box.h=image->h;
//xvel=xVel;
//yvel=yVel;
//ground=0;
for(int i=0;i<4;i++)
 {
  clips[i].x=i*30;
  clips[i].y=0;
  clips[i].w=30;
  clips[i].h=30;
 }
frame=0.0;
//movement=false;
bonus=10;
}
/*double  surprise::getFrame()
{
return frame;
}
void surprise::setFrame(double fr)
{
frame=fr;
}*/
void surprise::show(SDL_Surface* screen)
{
SDL_Rect tmp={box.x-coord.x,box.y,30,30};
if (frame>2.5 && frame<3 )
   {
   frame=0.1;
   SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);

  }
else if (frame<3 )
  {
    SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);
  }
  if(frame>=3.0)
    //if(frame>=2.7.0) si 3.0 sa marche pas
    { SDL_BlitSurface(image,&clips[(int)(3)],screen,&tmp);
  }

frame+=0.1;
}
/*SDL_Rect* surprise::getRect()
{
return &box;
}*/
int  surprise::getY()
{
return box.y;
}
void surprise::setY(int Y)
{
   box.y+=Y;
}
 bool surprise::getmovement()
 {
 return movement;
 }
 int surprise::getBonus()
 {
 return bonus;
 }
    void surprise::setmovement(bool mvt)
    {
    movement=mvt;
    }


