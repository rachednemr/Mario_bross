#include "bullet.h"
#include "SDL_rotozoom.h"
//first  construc
bullet::bullet(SDL_Surface* img,int x,int y,int xVel,int yVel,int ang)
{
box.x=x;
box.y=y;
image=img;
box.w=image->w;
box.h=image->h;
xvel=xVel;
yvel=yVel;
angle=ang;
for(int i=0;i<4;i++)
 {
  clips[i].x=i*20;
  clips[i].y=0;
  clips[i].w=20;
  clips[i].h=20;
 }
frame=0;
}
/*void bullet::setFrame(double fr)
{
    frame=fr;
}
    double bullet::getFrame()
    {
    return frame ;
    }*/
//second construc
bullet::bullet()
{
angle+=10;
}
//move methode
void bullet::move()
{
box.x+=xvel;
box.y+=yvel;
angle+=20;
}
//get the angle
int bullet::getangle()
{
return angle;
}
// set the angle
void bullet::setangle(int agl)
{
angle = (angle + agl) % 360;
}
//methode to show bullet
void bullet::show(const char* filename,SDL_Surface* screen)
{
load_image(filename,screen);
SDL_BlitSurface(load_image(filename,screen),NULL,screen,&box);
}
// methode to get bullet rectangle
/*SDL_Rect* bullet::getRect()
{
return &box ;
}*/
 void bullet::show2(SDL_Surface* screen)
 {
 if (frame>0&& frame<3)
 {
      SDL_Rect tmp={box.x-coord.x,box.y,20,20};
SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);
frame+=0.1;
 }
 }
 void bullet::setY(int Y)
 {
 box.y=Y;
 }
    void bullet::setX(int X)
    {
    box.x=X;
    }
// methode that load the image
 SDL_Surface* bullet::load_image(const char* filename,SDL_Surface* screen)
 {
SDL_Surface* tmp=SDL_LoadBMP(filename);
SDL_Surface* tmp2=SDL_DisplayFormat(tmp);
SDL_SetColorKey(tmp2,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xff,0xff));
SDL_Surface* rotozoomimage=rotozoomSurface(tmp2,getangle(),1.0,0);
SDL_FreeSurface(tmp);
SDL_FreeSurface(tmp2);
return rotozoomimage;
}
