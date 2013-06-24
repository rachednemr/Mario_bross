#ifndef FLEUR_TOXIQUE_H_INCLUDED
#define FLEUR_TOXIQUE_H_INCLUDED
#include <SDL/SDL.h>
#include <vector>
#include "base.h"
#include "enemy.h"
//#include "person.h"
class fleur_toxique:  public enemy
//class fleur_toxique:  public baseclass,public person
{
//SDL_Rect box;
bool arme;
//int xvel,yvel;
//SDL_Surface* image;
//bool ground;
bool mouvement; //si elle est en mouvement elle peut tuer si elle est en repos le joueur peut passer
//double frame;
SDL_Rect clips[44];
public:
    //fleur_toxique(SDL_Surface*,int x,int y,int xvel,int yvel,int age,int nbr_fils);
    fleur_toxique(SDL_Surface*,int x,int y,int xvel,int yvel);
    void show(SDL_Surface*);
   /* void setFrame(double);
    double getFrame();*/
   // SDL_Rect* getRect();
    /*void setX(int X);
    void setY(int Yval);*/
    bool getmouvement();
    bool getarme();
};
#endif // FLEUR_TOXIQUE_H_INCLUDED
