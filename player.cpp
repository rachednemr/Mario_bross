#include "player.h"
player::player(SDL_Surface* img)
{
    money=0;
    image=img;
    box.x=0;
    box.y=0;
    box.w=30;
    box.h=30;
    xvel=0;
    yvel=0;
    for (int i=0;i<10;i++)
    {
       // clip[i].x=i*baseclass::tile_size;
       clips[i].x=i*30;

        clips[i].y=0;
        clips[i].w=30;
        clips[i].h=30;
    }
    ground=jump=0;
    direction='r';
    frame=0.0;
    moving=0;
    health=3;
    power=1;
    gratification=0;
}
player::~player()
      {
      SDL_FreeSurface(image);
      }
/*SDL_Rect* player::getRect()
{
return &box;
}
*/
int player::getpower()
{
return power;
}
void player::setpower(int x)
{
power=x;
}

    int player::getGratification()
    {
    return gratification;
    }
    void player::setGratification(int gr)
    {
    gratification=gr;
    }
/*void player::setFrame(double fr)
{
    player::frame=fr;
}*/
int player::getXvel()
{
    return xvel;
}
void player::setMoving(bool b)
{
 player::moving=b;
}
void player::setDirection(char c)
{
    if((c=='r'||c=='l') &&direction!=c)
direction=c;
if(direction=='r')
    player::frame==1;
else
player::frame==5.6;
}
int  player::getmoney()
{
return money;
}
void player::setmoney(int mny)
{
    if (mny==0)
    {
     money=0;
    }
    money+=mny;
}
void player::setXvel(int vel)
{
     xvel=vel;
}
 void player::setYvel(int Yvel)
 {
 box.y-=Yvel;
 }
 void player::sety(int Y)
 {
 box.y=Y;
 }
char player::getDirection()
{
return direction;
}
void player::showplayer(SDL_Surface* screen)
    {

     SDL_BlitSurface(image,&clips[(int)(frame+0.5)],screen,&box);
     //std::cout<<"je suis le casting de frame"<<(int)(frame+0.5)<<std::endl;
    }
     void player::move(const std::vector< std::vector< int > >& map1)
         {
        // box.x+=xvel;
         //box.y+=yvel;
int start2=(baseclass::coord.x-(baseclass::coord.x%baseclass::tile_size))/baseclass::tile_size;
int end2=(baseclass::coord.x+baseclass::coord.w+(baseclass::tile_size-(baseclass::coord.x+baseclass::coord.w)%baseclass::tile_size))/baseclass::tile_size;
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
         SDL_Rect dest_rect={j*30-baseclass::coord.x,i*30,30,30};
         if(collision(&box,&dest_rect))
           {
           if(dest_rect.y >= box.y+box.h-11)
               {
                   nocollision=1;
                ground=1;
                yvel=0;
               }else if(dest_rect.y+dest_rect.h<=box.y+11)
               {
               box.x++;
               yvel=5;
               }
               if(box.x+box.w>=dest_rect.x-5 && box.y+box.h>=dest_rect.y+6 && box.x+box.w<= dest_rect.x+20)
               {
                   xvel=0;
                   box.x--;
               }
               else if (box.x <= dest_rect.x+dest_rect.w && box.y+box.h >= dest_rect.y+6)
               {
                   xvel=0;
                   box.x++;
               }
           }

         }

         }
          if(! nocollision && ! jump)
         { if(direction=='r'&& (frame!=3.5))
         {
             frame=3.5;
         }else if(direction=='l'&& (frame!=4.5)) { frame=4.5;}
            yvel=5;
         }
         if(jump && yvel<5)
         {
             if(direction=='r'&& (frame!=3.5))
         {
             frame=3.5;
         }else if(direction=='l'&& (frame!=4.5)) { frame=4.5;}
           yvel++;
         }

           else
           jump=0;
         box.x+=xvel;
         box.y+=yvel;
         if(moving)
            {
            if(direction=='r')
         {
              if(frame<=3.4&&frame>=0)
              {
            frame+=0.2;
              }
              else
                {

              frame=1;
              }
         }

        if(direction=='l')
         {
              if(frame<=8.4&&frame>=5.4)
              {
            frame+=0.2;
              }
              else{
              frame=5.6;
              }
         }

         }
         else
            {
                if(!jump && direction=='r')
                {
                    frame=0;
                }
                else if(!jump && direction=='l')
                {
              frame=8.5;

                }
                if(jump && direction=='r')
                {
                 frame=3.5;
                }
                if(jump && direction=='l')
                {
                   frame=4.5;
                }

              }


         }


void player::setJump()
{
    if(ground && ! jump)
    {
    jump=1;
    ground=0;
    yvel=-20;
    box.y-=5;

    }
}
int player::getHealth()
{
    return health;
}
void  player::setHealth(int h)
{
     health+=h;
}
