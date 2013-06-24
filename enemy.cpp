#include"enemy.h"
#include <SDL/SDL.h>
enemy::enemy(SDL_Surface* img,int x,int y,int xVel,int yVel)
{
        //set the variables, nothing new
        image=img;
        box.x=x;
        box.y=y;
        box.w=30;
        box.h=30;
        xvel=xVel;
        yvel=yVel;
        ground=0;       //is the enemy on the ground?
        //we set the clips for the image, so we can do animation, by blittin first one part of the image, than the other one
        for(int i=0;i<5;i++)
        {
                clips[i].x=i*30;
                clips[i].y=0;
                clips[i].w=clips[i].h=30;
        }
        frame=0.0;      //initialize frame is 0
}

void enemy::show(SDL_Surface* screen)
{
 SDL_Rect tmp={box.x-coord.x,box.y,30,30};
    if (frame==4)
    {
    SDL_BlitSurface(image,&clips[(int)(4)],screen,&tmp);
        }
    else
  {
      SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&tmp);
  }
}
int  enemy::getxvel()
{
return xvel;
}
void enemy::setxvel(int Xvel)
{
xvel=Xvel;
}

/*void enemy::setdirection(int direction)
{
if( direction==-1)
    enemy::frame==0.0;
else
enemy::frame==1.5;
}*/

/*SDL_Rect* enemy::getRect()
{
        return &box;
}
void enemy::setFrame(double Fr)
{
frame=Fr;
}
double enemy::getFrame()
{
return frame;
}*/
void enemy::move(const std::vector<std::vector<int > >& map)
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
        if (frame<4)
        {
       if (getxvel()==-1&&frame>1)
        {
        frame=0.0;
         }
          if (getxvel()==1&&frame<2||getxvel()==1&&frame>3)
         {
             frame=2;
          }
       frame+=0.05;
       }    //set back
}
