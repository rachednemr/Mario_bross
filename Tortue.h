#ifndef TORTUE_H_INCLUDED
#define TORTUE_H_INCLUDED
#include "enemy.h"
class Tortue:public enemy
{
bool sauter;// il ya des tortues qui sauter les autres ne sautent pas
bool arme;// il ya des tortues qui ont des armes les autres n'ont plus
int etat;
char direction;
// si le player a creuser la tortue alors on change l'etat "marcher ou glisser"
public :
//SDL_Rect box;
//int xvel,yvel;
//SDL_Surface* image;
//bool ground;
//double frame;
//SDL_Rect clips[5];
public:
    Tortue(SDL_Surface*img,int x,int y,int xvel,int yvel);
   //void move(const std::vector< std::vector< int > >& map);
//void show(SDL_Surface*);
  //  void setFrame(double);
    //double getFrame();
   // SDL_Rect* getRect();
    //int getxvel();
int getetat();
void setetat(int etat);
//void  setxvel(int xvel);
void setdirection(char c);
char getDirection();
bool getArme();
bool getSauter();
};



#endif // TORTUE_H_INCLUDED
