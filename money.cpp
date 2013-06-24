#include"money.h"
#include <SDL/SDL.h>
money::money(SDL_Surface* img ,int x,int y,int xVel,int yVel)
{
image=img;
box.x=x;
box.y=y;
box.w=image->w/2;
box.h=image->h;
xvel=xVel;
yvel=yVel;
ground=0;
for(int i=0;i<4;i++)
{
   clips[i].x=i*30;
   clips[i].y=0;
   clips[i].w=30;
   clips[i].h=30;
}
for(int i=0;i<2;i++)
{
   clips2[i].x=i*30;
   clips2[i].y=0;
   clips2[i].w=30;
   clips2[i].h=30;
}
frame=0.0;
}
double  money::getFrame()
{
    return frame;
}
void money::setFrame(double fr)
{
    frame=fr;
}
void money::show(SDL_Surface* screen)
{
      SDL_Rect tmp={box.x-coord.x,box.y,30,30};
    if (frame>=2 && frame<=2.5)
    {
        //for(int i=0;i<3000;i++)
      //  {
    //SDL_BlitSurface(image,&clips[(int)(2)],screen,&tmp);
        //}
        frame=0.1;
        SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);

  }
    else
  {
      SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);
  }
   frame+=0.1;

if (frame>2.5 && frame<=3.5)
{
       SDL_BlitSurface(image,&clips[(int)(frame-0.5)],screen,&tmp);
}
}
void money::show2(SDL_Surface* screen)
{
    if (frame<1.5)
        {
      SDL_Rect tmp={box.x-coord.x,box.y,30,30};
      SDL_BlitSurface(image,&clips2[(int)(frame+0.5)],screen,&tmp);
      frame+=0.1;

    }
}
SDL_Rect* money::getRect()
{
return &box;
}
/*void surprise::move(const std::vector<std::vector<int > >& map1)
{
int start2=(baseclass::coord.x-(baseclass::coord.x%baseclass::tile_size))/baseclass::tile_size-2;
int end2=(baseclass::coord.x+baseclass::coord.w+(baseclass::tile_size-(baseclass::coord.x+baseclass::coord.w)%baseclass::tile_size))/baseclass::tile_size+2;
if(start2<0)
    start2=0;
if(end2>map1[0].size())
    end2=map1[0].size();
bool    nocollision=0;
for (int i=0;i<map1.size();i++)
    {
      for (int j=start2;j<end2;j++)
      {
         if( map1[i][j]==0)
            continue;
         SDL_Rect dest_rect={j*50,i*50,50,50};
         if(collision(&box,&dest_rect))
           {
            // show your surprise
            frame=2.5;
            box.y-=3;
           }
         }
         }
  //        frame+=0.1;
//

}*/


//--------  cuurent time
/*
   void game::currenttime()
{
    SDL_Color color={255,255,255};
    SDL_Surface* text=TTF_RenderText_Solid(font,time,color);
    SDL_Rect tmprect={30,20};
    SDL_BlitSurface(text,NULL,screen,&tmprect);
    SDL_FreeSurface(screen);
    SDL_Flip(screen);

}*/
