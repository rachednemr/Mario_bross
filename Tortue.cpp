#include"Tortue.h"
#include "enemy.h"
#include <SDL/SDL.h>
Tortue::Tortue(SDL_Surface* img,int x,int y,int xVel,int yVel):enemy(img, x, y,xvel, yvel)
{
        //set the variables, nothing new
        image=img;
        box.x=x;
        box.y=y;
        box.w=30;
        box.h=30;
        xvel=xVel;
        yvel=yVel;
        ground=0;
        arme=false;
        etat=2;
        sauter=false;
        direction='l';
        for(int i=0;i<5;i++)
        {
                clips[i].x=i*30;
                clips[i].y=0;
                clips[i].w=clips[i].h=30;
        }
        frame=0.0;      //initialize frame is 0
}
/*void Tortue::show(SDL_Surface* screen)
{
 SDL_Rect tmp={box.x-coord.x,box.y,30,30};
    if (frame>=6)
    {
        for(int i=0;i<7000;i++)
        {
    SDL_BlitSurface(image,&clips[(int)(2)],screen,&tmp);
        }
  }
    else
  {
      SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);
  }
  }*/
/*int  Tortue::getxvel()
{
return xvel;
}
void Tortue::setxvel(int Xvel)
{
xvel=Xvel;
}*/

void Tortue::setdirection(char c )
{
if( direction=='l')
    Tortue::frame==0.0;
else
Tortue::frame==1.5;
}
int Tortue::getetat()
{
    return etat;
}
char Tortue::getDirection()
{
return direction;
}
bool Tortue::getSauter()
{
return sauter;
}
void Tortue::setetat(int ETT)
{
     etat=ETT;
     if (etat==1)
     setFrame(4);
        xvel=5;
}

/*SDL_Rect* Tortue::getRect()
{
        return &box;
}*/
/*void Tortue::setFrame(double Fr)
{
frame=Fr;
}*/
/*void Tortue::move(const std::vector<std::vector<int > >& map)
{
        //calculate the start and the end coordinate (see game.cpp)
        int start=(baseclass::coord.x-(baseclass::coord.x%baseclass::tile_size))/baseclass::tile_size-2;
        int end=(baseclass::coord.x+baseclass::coord.w+(baseclass::tile_size-(baseclass::coord.x+baseclass::coord.w)%baseclass::tile_size))/30+2;
        if(start<0)
                start=0;
        if(end>map[0].size())
                end=map[0].size();
        bool nc=0;      //if this remains 0 until the end of the loops, than we fall (no ground under the enemy)
        for(int i=0;i<map.size();i++)//go through the map
                for(int j=start;j<end;j++)
                {
                        if(map[i][j]==0)
                                continue;
                        SDL_Rect destrect={j*30,i*30,30,30};
                        if(collision(&box,&destrect))   //if there was a collision
                        {
                                if(destrect.y>=box.y+box.h-11)//and it'a the ground (so the tile is under the enemy)
                                {
                                        ground=1;       //then we don't fall any more and we are on the ground
                                        yvel=0;
                                        nc=1;
                                }else
                                        xvel=-xvel;     //else change the direction in the x axis
                        }
                }
        if(!nc) //if there is no ground under the enemy
        {
            yvel=5; //than fall
        if((getxvel()==-1)&&(frame!=1.5))
         {
             frame=0.0;
        }
        }
        box.x+=xvel;    //just move
        box.y+=yvel;
       if (getxvel()==-1&&frame>1)
        {
        frame=0.0;
         }else if (getxvel()==1&&frame<2||getxvel()==1&&frame>3)
         {
             frame=2;
          }
       frame+=0.05;    //set back
}*/
