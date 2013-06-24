#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "base.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "fleur_ame.h"
#include "fleur_toxique.h"
#include "surprise.h"
#include "Tortue.h"
#include "Champignon.h"
#include "money.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "SDL_rotozoom.h"
class game:public baseclass  {
SDL_Surface *screen,*background,*block,*enem,*sky,*enem2,*pl,*fleur_am1,*fleur_tox1,*Tortues1,*Champignon1,*bull,*bull2,*sur,*mon,*mon2,*mario_head,*text,*text2;
TTF_Font* font,*font2,*font3,*font4;
SDL_Rect camera,rect_mario_head,sky_rect;
player* player1;
bullet * b,*b1;
int time,temps2;
std::vector<std::vector<int> > map1;
std::vector<bullet*> bullets;
std::vector<money*> monies_surp;
bullet * bullet1;
std::vector<enemy*> enemies;
std::vector<Tortue*> Tortues;
std::vector<Champignon*> Champignons;
std::vector<fleur_ame*> fleur_ames;
std::vector<fleur_toxique*> fleur_toxiques;

std::vector<surprise*> surprises;
std::vector<money*> moneis;

//surprise * su;
bool direction[2];
bool running;
static const int screen_width=640;
SDL_Rect finish;
static const int  screen_height=460;
SDL_Surface* load_image(const char* filename);
void loadmap(const char* filename);
int pause(SDL_Surface* screen);
void showmap();
void showmenu();
void   currenttime();
void showmessage(const char* c);
void handelevents();
void relatifdetails(const char * stage );
public :
    game();
    ~game();
    void start();
            };

#endif
 // GAME_H_INCLUDED
