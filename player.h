#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include<SDL/SDL.h>
#include<iostream>
#include<vector>
#include "base.h"
class player: public baseclass
{
//SDL_Rect box;
//SDL_Surface* image;
int xvel,yvel, money,life;
bool ground,jump;
//SDL_Rect clip[10];
char direction;
//double frame;
bool moving;
int power;
int gratification;
public:
    player(SDL_Surface* img);
    ~player();
    int getXvel();
    int getGratification();
    void setGratification(int gr);
    int health;
  //  SDL_Rect*  getRect();
    void setMoving(bool );
    void setDirection(char );
    void setXvel(int );
    void setYvel(int );
void sety(int Y);
    void setHealth(int x);
    int  getHealth();
char getDirection();
   void move(const std::vector< std::vector< int > >& map1);
void showplayer(SDL_Surface* screen);
void setJump();
void setmoney(int money);
int getmoney();
int getpower();
void setpower(int power);
//void setFrame(double frame);
};



#endif // PLAYER_H_INCLUDED
