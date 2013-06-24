#include "game.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cstdio>
SDL_Rect baseclass::coord;
game::game()
{
    time=0;
    temps2=398;
  SDL_Init(SDL_INIT_EVERYTHING);
  screen=SDL_SetVideoMode(screen_width,screen_height,32,SDL_SWSURFACE);
  SDL_WM_SetCaption("Mario For Ever 3", NULL);
  mario_head=SDL_DisplayFormat(SDL_LoadBMP("mario_head.bmp"));
SDL_SetColorKey(mario_head,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xFF,0xFF));
  SDL_WM_SetIcon(mario_head, NULL);
  block=load_image("block2.bmp");
  background=load_image("background4.bmp");
  enem=load_image("chompions_arigi.bmp");
  Champignon1=load_image("chompions_arigi.bmp");
  fleur_am1=load_image("fleur_ame.bmp");
  fleur_tox1=load_image("fleur_toxique.bmp");
 enem2=load_image("tortues2.bmp");
 Tortues1=load_image("tortues2.bmp");
 mon=load_image("money2.bmp");
 sky=SDL_DisplayFormat(SDL_LoadBMP("sky2.bmp"));
 SDL_SetColorKey(sky,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xFF,0xFF));
 mon2=load_image("money_explosion.bmp");
//surp=load_image("surprise3.bmp");
  sur=load_image("surprise3.bmp");
  b=new bullet();
  bull=b->load_image("bullet2.bmp",screen);
  bull2=load_image("bullet3.bmp");
  baseclass::coord.x=camera.x=0;
  baseclass::coord.y=camera.y=0;
  baseclass::coord.w=camera.w=screen_width;
  baseclass::coord.h=camera.h=screen_height;
  direction[0]=direction[1]=0;
  running=true;
  TTF_Init();
  font=TTF_OpenFont("air.ttf",20);
  font2=TTF_OpenFont("smbfont.ttf",20);
  font3=TTF_OpenFont("air.ttf",20);
  font4=TTF_OpenFont("air.ttf",20);
  player1=new player(load_image("mar8.bmp"));
b1=new bullet(bull2,200,150,20,20,0);
  //enemies.push_back(new enemy(enem,100,40,1,0));
  finish.x=finish.y=0;
  finish.w=finish.h=30;
  finish.w=finish.h=30;
 sky_rect.x=0;
sky_rect.y=0;
sky_rect.w=640;
sky_rect.h=35;
  /*for (int i=0;enemies.size();i++)
   {
     enemies[i]->setFrame(0.0);
   }*/
  for (int i=0;Tortues.size();i++)
   {
     Tortues[i]->setFrame(0.0);
   }
for (int i=0;Champignons.size();i++)
   {
     Champignons[i]->setFrame(0.0);
   }
   for (int i=0;monies_surp.size();i++)
   {
     monies_surp[i]->setFrame(0.0);
   }
   for (int i=0;fleur_ames.size();i++)
   {
     fleur_ames[i]->setFrame(0.0);
   }
   for (int i=0;fleur_toxiques.size();i++)
   {
     fleur_toxiques[i]->setFrame(0.0);
   }
  for (int i=0;surprises.size();i++)
   {
     surprises[i]->setFrame(0.0);
   }

   for (int i=0;moneis.size();i++)
   {
     moneis[i]->setFrame(0.0);
   }
   for (int i=0;monies_surp.size();i++)
   {
     monies_surp[i]->setFrame(0.0);
   }
//   SDL_FreeSurface(text);
    /*rect_mario_head.x=10;
    rect_mario_head.y=20;
    rect_mario_head.w=30;
    rect_mario_head.h=27;*/
}
game::~game()
       {
       SDL_FreeSurface(background);
       SDL_FreeSurface(block);
       SDL_FreeSurface(bull);
       for (int i=0;i<bullets.size();i++)
       {
           delete bullets[i];
       }
       for (int i=0;i<monies_surp.size();i++)
       {
           delete monies_surp[i];
       }
        /*for (int i=0;i<enemies.size();i++)
       {
           delete enemies[i];
       }*/
        for (int i=0;i<Tortues.size();i++)
       {
           delete Tortues[i];
       }
for (int i=0;i<Champignons.size();i++)
       {
           delete Champignons[i];
       }
       for (int i=0;i<surprises.size();i++)
       {
           delete surprises[i];
       }
       for (int i=0;i<moneis.size();i++)
       {
           delete moneis[i];
       }
       for (int i=0;i<monies_surp.size();i++)
       {
           delete monies_surp[i];
       }

       for (int i=0;i<fleur_ames.size();i++)
       {
           delete fleur_ames[i];
       }
       for (int i=0;i<fleur_toxiques.size();i++)
       {
           delete fleur_toxiques[i];
       }
      TTF_CloseFont(font);
       SDL_Quit();
//       SDL_FreeSurface(surp);
       SDL_FreeSurface(mario_head);
       }
       void game::relatifdetails(const char* c)
{

        SDL_BlitSurface(mario_head,NULL,screen,&rect_mario_head);
    rect_mario_head.x=10;
    rect_mario_head.y=40;
    rect_mario_head.w=30;
    rect_mario_head.h=27;
     mario_head=SDL_DisplayFormat(SDL_LoadBMP("mario_head.bmp"));
     SDL_SetColorKey(mario_head,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xFF,0xFF));
    SDL_Color color={255,255,255};
    SDL_Surface* text=TTF_RenderText_Solid(font,c,color);
    SDL_Rect tmprect={50,40};
    SDL_BlitSurface(text,NULL,screen,&tmprect);
     SDL_BlitSurface(mario_head,NULL,screen,&rect_mario_head);
     // afficher sky qui move

}
  void game::currenttime()
{
SDL_Color color={255,255,255};
int  life=0;
int temps,moneyvalue=0;
temps=this->temps2;
life=player1->getHealth();
moneyvalue=player1->getmoney();
char *s,*mny="";
char * t="";
s= (char*)&life;
mny=(char*)&moneyvalue;
t=(char*)&temps;
itoa (life,s,10);
itoa (temps,t,10);
itoa (moneyvalue,mny,10);
 SDL_Rect tmprect={320,50};
//rectangle life
SDL_Surface* text_life=TTF_RenderText_Solid(font2,"LIFE :",color);
SDL_Rect tmprect_life={280,50};
SDL_BlitSurface(text_life,NULL,screen,&tmprect_life);
// rectangle life value
SDL_Surface* text_life_value=TTF_RenderText_Solid(font2,s,color);
SDL_Rect tmprect_life_value={320,50};
SDL_BlitSurface(text_life_value,NULL,screen,&tmprect_life_value);
//rectangle money
SDL_Surface* text_money=TTF_RenderText_Solid(font2,"MONEY :",color);
SDL_Rect tmprect_money={350,50};
SDL_BlitSurface(text_money,NULL,screen,&tmprect_money);
//money value
SDL_Surface* text_money_value=TTF_RenderText_Solid(font2,mny,color);
SDL_Rect tmprect_money_value={400,50};
SDL_BlitSurface(text_money_value,NULL,screen,&tmprect_money_value);

//rectangle motivation
SDL_Surface* text_motivation=TTF_RenderText_Solid(font2,"BONUS :",color);
SDL_Rect tmprect_motivation={430,50};
SDL_BlitSurface(text_motivation,NULL,screen,&tmprect_motivation);
//motivation value
SDL_Surface* text_motivation_value=TTF_RenderText_Solid(font2,mny,color);
SDL_Rect tmprect_motivation_value={480,50};
SDL_BlitSurface(text_motivation_value,NULL,screen,&tmprect_motivation_value);

//rectangle time
SDL_Surface* text_time=TTF_RenderText_Solid(font2,"TIME :",color);
SDL_Rect tmprect_time={550,50};
SDL_BlitSurface(text_time,NULL,screen,&tmprect_time);
//rectangle time value
SDL_Surface* text_time_value=TTF_RenderText_Solid(font2,t,color);
SDL_Rect tmprect_time_value={600,50};
SDL_BlitSurface(text_time_value,NULL,screen,&tmprect_time_value);

//rebnder the sky rectangle
sky_rect.x+=20;
   if(sky_rect.x>6400-640)
    {
           sky_rect.x=20;
   }
  SDL_BlitSurface(sky,&sky_rect,screen,NULL);
}
     void game::showmessage(const char* c)
{
    SDL_Color color={255,255,255};
    SDL_Surface* text_stage=TTF_RenderText_Solid(font,"Game Over ",color);
    SDL_Rect tmprect_stage={150,200};
    SDL_BlitSurface(text_stage,NULL,screen,&tmprect_stage);
SDL_Flip(screen);
}


       SDL_Surface* game::load_image(const char* filename)
       {
           SDL_Surface* tmp=SDL_LoadBMP(filename);
           SDL_Surface* tmp2=SDL_DisplayFormat(tmp);
          SDL_SetColorKey(tmp2,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xff,0xff));
           SDL_FreeSurface(tmp);
           return tmp2;
       }
    int game::pause(SDL_Surface* screen) //shows he menu
{
        int x,y;
        bool run=true;  //bool variable for the menu's for loop
        const int NUMMENU=2;//we have 2 menu item
        const char* array[NUMMENU] = {"Continue","Exit"}; //the label of these are these
        SDL_Surface* menu[NUMMENU];//we need surface for them
        bool selected[NUMMENU] = {0,0};//a boolean array for each menu item, true if it is selected
        SDL_Color colors[2] = {{255,255,255},{255,0,0}};        //white and red color

        for(int i=0;i<NUMMENU;i++)
                menu[i]=TTF_RenderText_Solid(font,array[i],colors[0]); //make all of the white menus

        SDL_Rect pos[NUMMENU];  //we store the position in here
        for(int i=0;i<NUMMENU;i++)
        {
                pos[i].x=screen->clip_rect.w/2-menu[i]->clip_rect.w/2;  //put it approxemately to the center of the screen
                pos[i].y=screen->clip_rect.h/2+i*(menu[i]->clip_rect.h);
        }
        SDL_Event menuevent;    //event
        SDL_Surface* alpha=SDL_CreateRGBSurface(SDL_SWSURFACE|SDL_SRCALPHA,screen->w,screen->h,32,screen->format->Rmask,screen->format->Gmask,screen->format->Bmask,screen->format->Amask);     //create a new layer
        SDL_FillRect(alpha,&screen->clip_rect,SDL_MapRGB(screen->format,0x00,0x00,0x00)); //which we fill with black
        SDL_SetAlpha(alpha,SDL_SRCALPHA,129);   //and use it for alpha blending, because it's a cool effect
        SDL_BlitSurface(alpha,NULL,screen,NULL);        //then show it
        SDL_FreeSurface(alpha); //we don't need it anymore
        while(run)
        {
                SDL_WaitEvent(&menuevent); //OK, I think, that's new, we'll wait until an event happened, if there is no event
                                                                                                                         //the program will sleep in this function, so less CPU power is needed, we don't need
                                                                                                                         //to regulate the FPS
                        switch(menuevent.type)
                        {
                                case SDL_QUIT:  //if we're exiting, than free the surfaces and exit
                                        for(int i=0;i<NUMMENU;i++)
                                                SDL_FreeSurface(menu[i]);
                                        return 1;
                                case SDL_MOUSEMOTION:   //if the mouse is moved
                                        x=menuevent.motion.x;   //then get the coordinates
                                        y=menuevent.motion.y;
                                        for(int i=0;i<NUMMENU;i++)      //we go throught all of the element
                                        {       //and check if we are inside one of them
                                                if(x>=pos[i].x && x <= (pos[i].x + menu[i]->clip_rect.w) && y>=pos[i].y && y <= (pos[i].y + menu[i]->clip_rect.h))
                                                {
                                                        if(!selected[i]) //if so, then we check that is it already selected
                                                        {
                                                                SDL_FreeSurface(menu[i]);       //if not, then free the surface and make a red one
                                                                menu[i]=TTF_RenderText_Solid(font,array[i],colors[1]);
                                                                selected[i]=1; //and select the surface
                                                        }
                                                }else{  //if we're not selecting one
                                                        if(selected[i]) //we check, that is it selected
                                                        {
                                                                SDL_FreeSurface(menu[i]); //if so, then we delete and create a white one.
                                                                menu[i]=TTF_RenderText_Solid(font,array[i],colors[0]);
                                                                selected[i]=0;  //and unselect it
                                                        }
                                                }
                                }
                                break;
                                case SDL_MOUSEBUTTONDOWN:       //if the mouse button was pressed
                                        x=menuevent.button.x;   //get the coordinates
                                        y=menuevent.button.y;
                                        for(int i=0;i<NUMMENU;i++)      //do the same check
                                        {
                                                if(x>=pos[i].x && x <= (pos[i].x + menu[i]->clip_rect.w) && y>=pos[i].y && y <= (pos[i].y + menu[i]->clip_rect.h))
                                                {
                                                        for(int j=0;j<NUMMENU;j++)      //if we clicked one menuitem, we free the menus and return the number
                                                                SDL_FreeSurface(menu[j]);       //of the clicked menu
                                                        return i;
                                                }
                                        }
                                        break;
                                case SDL_KEYDOWN:       //if we press a key
                                        if(menuevent.key.keysym.sym==SDLK_ESCAPE) //which escape
                                        {
                                                for(int i=0;i<NUMMENU;i++)
                                                        SDL_FreeSurface(menu[i]);
                                                return 0;       //than return to the game
                                        }
                                        break;
                        }
                for(int i=0;i<NUMMENU;i++)
                        SDL_BlitSurface(menu[i],NULL,screen,&pos[i]);   //show the menu
                SDL_Flip(screen);       //and actually show it in the screen
        }
}

       void game::handelevents()
          {
           SDL_Event event;
           while (SDL_PollEvent(&event))
           {
            switch (event.type)
            {
            case SDL_QUIT:
            running=false;
            return;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_LEFT :
                direction[0]=1;
                player1->setMoving(1);
                //player1->setJump(0);
                break;
            case SDLK_RIGHT:
                direction[1]=1;
                player1->setMoving(1);
               // player1->setJump(0);
                break;
            case SDLK_SPACE:
                player1->setJump();
                player1->setMoving(0);
                break;
             case SDLK_c:
                 if(player1->getDirection()=='r' && player1->getpower()==1)
                 {
                bullets.push_back(new bullet(bull,player1->getRect()->x+player1->getRect()->w-8,player1->getRect()->y-5,5,0,10));
                break;
                 }
                 if(player1->getDirection()=='l' && player1->getpower()==1)
                 {
                bullets.push_back(new bullet(bull,player1->getRect()->x-player1->getRect()->w+10,player1->getRect()->y-5,-5,0,10));
                break;
             case SDLK_ESCAPE :
                int h=pause(screen);
                if (h==1)
                    running=false;
                    break;
                 }
            }
            break;
            case SDL_KEYUP:
            switch(event.key.keysym.sym)
            {
            case SDLK_LEFT :
                direction[0]=0;
                player1->setMoving(0);
                break;
            case SDLK_RIGHT:
                direction[1]=0;
                player1->setMoving(0);
                break;
            }
            break;
           }
          }
          }
          void game::start()
          {   float FPS=40;

                               SDL_Rect tmprect_surprises,tmprect_surprises2;
              int moneymove=0;

              Uint32 start;
              loadmap("map2.map");
            while(running)
            {
                start=SDL_GetTicks();
                handelevents();
                //logic
                if(direction[0])
                {
                    player1->setDirection('l');
                    if(player1->getRect()->x>80) //it was x>0
                        player1->setXvel(-1);
                    else{
                    camera.x--;
                    baseclass::coord.x--;
                    player1->setXvel(0);
                    }
                    if(camera.x<0)
                        camera.x=6400-screen_width;
                        //player1->set
                       // std::cout<<"la position de coord - est :"<<coord.x<<"la position de camera est :"<<camera.x<<std::endl;
                }
                     else if(direction[1])
                {

                    player1->setDirection('r');
                    if(player1->getRect()->x <80)
                        player1->setXvel(1);
                    else{
                     player1->setXvel(0);
                    camera.x++;
                    baseclass::coord.x++;
                    }
                    if(camera.x>=6400-screen_width)
                        camera.x=0;
                        // std::cout<<"la position de coord + est :"<<coord.x<<"la position de camera est :"<<camera.x<<std::endl;
                }
                else
                    player1->setXvel(0);
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
          for (int g=0;g<bullets.size();g++)
          {
            if(collision(bullets[g]->getRect(),&dest_rect))
               {
                 b1->setFrame(1);
                               // b1->setX(bullets[g]->getRect()->x+20);
                               if(player1->getDirection()=='r')
                               b1->setX(j*30-14);
                               else
                                b1->setX(j*30+24);
                                b1->setY(bullets[g]->getRect()->y);

                delete bullets[g];

                bullets.erase(bullets.begin()+g);
                }
           }

                             for (int j=0;j<Champignons.size();j++)
                          {
                              SDL_Rect tmprect ={Champignons[j]->getRect()->x-baseclass::coord.x,Champignons[j]->getRect()->y,30,30};

        for (int k=0;k<Champignons.size();k++)
                              {
                                  if(k!=j){


                                SDL_Rect tmprect2 ={Champignons[k]->getRect()->x-baseclass::coord.x,Champignons[k]->getRect()->y,30,30};
                                if (collision(&tmprect,&tmprect2))
                                {
                                   Champignons[j]->setxvel(1);
                                   Champignons[j]->setdirection('r');
                                   Champignons[k]->setxvel(-1);
                                   Champignons[k]->setdirection('l');
                                   std::cout<<"here is collision between two enemies "<<std::endl;
                                }
                              }
                             }



                             }

                               for (int j=0;j<Champignons.size();j++)
                          {
                              SDL_Rect tmprect ={Champignons[j]->getRect()->x-baseclass::coord.x,Champignons[j]->getRect()->y,30,30};

                             for (int k=0;k<Tortues.size();k++)
                              {


                                SDL_Rect tmprect2 ={Tortues[k]->getRect()->x-baseclass::coord.x,Tortues[k]->getRect()->y,30,30};
                                if ((tmprect.x+30==tmprect2.x)&&(Tortues[k]->getetat()==2)&&(Champignons[j]->getPuissance()==1))
                                {
                                   Champignons[j]->setxvel(-1);
                                   Champignons[j]->setdirection('r');
                                   Tortues[k]->setxvel(1);
                                   Tortues[k]->setdirection('l');
                               }else
                                if ((tmprect.x==tmprect2.x+30)&&(Tortues[k]->getetat()==2)&&(Champignons[j]->getPuissance()==1))
                                {
                                   Champignons[j]->setxvel(1);
                                   Champignons[j]->setdirection('r');
                                   Tortues[k]->setxvel(-1);
                                   Tortues[k]->setdirection('l');
                               }else
                                if ((tmprect.x==tmprect2.x+30)&&(Tortues[k]->getetat()==1)&&(Champignons[j]->getPuissance()==1))
                                {
                                   delete Champignons[j];
                                   Champignons.erase(Champignons.begin()+j);

                               }
                               else
                                if ((tmprect.x+30==tmprect2.x)&&(Tortues[k]->getetat()==1)&&(Champignons[j]->getPuissance()==1))
                                {
                                   delete Champignons[j];
                                   Champignons.erase(Champignons.begin()+j);

                               }

                             }
                          }

                            for (int j=0;j<Tortues.size();j++)
                          {
                              SDL_Rect tmprect ={Tortues[j]->getRect()->x-baseclass::coord.x,Tortues[j]->getRect()->y,30,30};

                               for (int k=0;k<Tortues.size();k++)
                              {
                                  if(k!=j){


                                SDL_Rect tmprect2 ={Tortues[k]->getRect()->x-baseclass::coord.x,Tortues[k]->getRect()->y,30,30};
                                if ((collision(&tmprect,&tmprect2))&&(Tortues[j]->getetat()!=1)&&(Tortues[k]->getetat()!=1))
                                {
                                   Tortues[j]->setxvel(1);
                                   Tortues[j]->setdirection('r');
                                   Tortues[k]->setxvel(-1);
                                   Tortues[k]->setdirection('l');
                                   std::cout<<"here is collision between two tortues "<<std::endl;
                                }
                                if (collision(&tmprect,&tmprect2)&&Tortues[j]->getetat()==1)
                                {
                                     delete Tortues[k];
                                     Tortues[j]->setxvel(5);
                                    Tortues.erase(Tortues.begin()+k);
                                }
                              }
                             }
                          }







        }
        }
                   for (int i=0;i<bullets.size();i++)
                    {
                      if((bullets[i]->getRect()->x >= screen->w)||(bullets[i]->getRect()->x  <=0))
                        {
                         delete bullets[i];
                         bullets.erase(bullets.begin()+i);
                        }
                         }
                         for (int i=0;i<bullets.size();i++)
                         {
                          for (int j=0;j<Champignons.size();j++)
                          {
                              SDL_Rect tmprect ={Champignons[j]->getRect()->x-baseclass::coord.x,Champignons[j]->getRect()->y,30,30};
                              if(collision(&tmprect,bullets[i]->getRect()))
                              {
                                b1->setFrame(1);
                                b1->setX(Champignons[j]->getRect()->x);
                                b1->setY(Champignons[j]->getRect()->y);
                                 delete bullets[i];
                                 delete Champignons[j];
                                 bullets.erase(bullets.begin()+i);
                                 Champignons.erase(Champignons.begin()+j);
                              }
                          }
                          for (int j=0;j<Tortues.size();j++)
                          {
                              SDL_Rect tmprect ={Tortues[j]->getRect()->x-baseclass::coord.x,Tortues[j]->getRect()->y,30,30};
                              if(collision(&tmprect,bullets[i]->getRect()))
                              {
                                b1->setFrame(1);
                                b1->setX(Tortues[j]->getRect()->x);
                                b1->setY(Tortues[j]->getRect()->y);
                                 delete bullets[i];
                                 delete Tortues[j];
                                 bullets.erase(bullets.begin()+i);
                                 Tortues.erase(Tortues.begin()+j);
                              }
                          }




                         }


                         for (int i=0;i<bullets.size();i++)
                         {
                          for (int j=0;j<fleur_toxiques.size();j++)
                          {
                              SDL_Rect tmprect ={fleur_toxiques[j]->getRect()->x-baseclass::coord.x,fleur_toxiques[j]->getRect()->y,30,30};
                              if(collision(&tmprect,bullets[i]->getRect()))
                              {
                                b1->setFrame(1);
                                  b1->setX(fleur_toxiques[j]->getRect()->x);
                                b1->setY(tmprect.y);
                               delete bullets[i];
                                 delete fleur_toxiques[j];
                                 bullets.erase(bullets.begin()+i);
                                 fleur_toxiques.erase(fleur_toxiques.begin()+j);
                              }
                          }
                         }

                               for (int j=0;j<Champignons.size();j++)
                          {
                              int set_life_power=0;
                              SDL_Rect tmprect ={Champignons[j]->getRect()->x-baseclass::coord.x,Champignons[j]->getRect()->y,30,30};
                                 if(collision(&baseclass::coord,Champignons[j]->getRect()))
                                 {
                              if(collision(&tmprect,player1->getRect()))
                              {
                                 std::cout<<"collesion enemy yvel  "<<tmprect.y<< "pleyer y vel "<<player1->getRect()->y<<std::endl;
                               if((player1->getRect()->y< tmprect.y )&&(Champignons[j]->getPuissance()>0))
                               {
                                   Champignons[j]->setpuissance(0);
                                   std::cout<<"collesion enemy yvel  "<<Champignons[j]->getFrame()<<std::endl;
                                  // delete Champignons[j];
                                   // Champignons.erase(Champignons.begin()+j);
                               }
                               else
                                if((player1->getRect()->y==tmprect.y )&&(set_life_power>=0)&&(Champignons[j]->getPuissance()>0))
                                {

                                     player1->setHealth(-1);
                                   //std::cout<<"enemy killl me et mon lhealth est  :"<<player1->getHealth();
                                   delete Champignons[j];//version before i was neot here
                                    Champignons.erase(Champignons.begin()+j); //version before i was neot here
                                }
                              }
                              if((player1->getRect()->x> tmprect.x+60||player1->getRect()->x < tmprect.x-60)&&(Champignons[j]->getPuissance()==0))
                              {
                                  delete Champignons[j];//version before i was neot here
                                    Champignons.erase(Champignons.begin()+j); //version before i was neot here

                              }
                              Champignons[j]->move(map1);
                              }
                               }
                               for (int j=0;j<Tortues.size();j++)
                          {   bool setEtat =false;
                              SDL_Rect tmprect ={Tortues[j]->getRect()->x-baseclass::coord.x,Tortues[j]->getRect()->y,30,30};
                                 if(collision(&baseclass::coord,Tortues[j]->getRect()))
                                 {
                              if(collision(&tmprect,player1->getRect()))
                              {
                                 std::cout<<"collesion enemy yvel  "<<tmprect.y<< "pleyer y vel "<<player1->getRect()->y<<std::endl;
                               if((player1->getRect()->y< tmprect.y )&&(Tortues[j]->getetat()==2))
                               {
                                   Tortues[j]->setetat(1);
                                  // delete Tortues[j];
                                   // Tortues.erase(Tortues.begin()+j);
                               }
                               else  if((player1->getRect()->y== tmprect.y )&&(Tortues[j]->getetat()==2))

                                {
                                     player1->setHealth(-1);
                                   //std::cout<<"enemy killl me et mon lhealth est  :"<<player1->getHealth();
                                   delete Tortues[j];//version before i was neot here
                                    Tortues.erase(Tortues.begin()+j); //version before i was neot here
                                }
                              }
                              Tortues[j]->move(map1);
                              }
                               }








                               for (int i=0;i<moneis.size();i++)
                               {
                                   SDL_Rect tmprect ={moneis[i]->getRect()->x-baseclass::coord.x,moneis[i]->getRect()->y,30,30};


                                 if(collision(&tmprect,player1->getRect()))
                              {
                                   delete moneis[i];//version before i was neot here
                                    moneis.erase(moneis.begin()+i); //version before i was neot here
                                   player1->setmoney(1);
                                   if (player1->getmoney()==100)
                                   {
                                    player1->setmoney(0);
                                    player1->setHealth(1);
                                   }

                              }



                               }

                                for (int i=0;i<surprises.size();i++)
                               {
                                    tmprect_surprises ={surprises[i]->getRect()->x-baseclass::coord.x,surprises[i]->getRect()->y,30,30};
                                    if((player1->getRect()->x+15>=tmprect_surprises.x)&&(player1->getRect()->x<=tmprect_surprises.x+20)&&(player1->getRect()->y==tmprect_surprises.y+40))
                                      {
                                           moneymove=1;
                                           tmprect_surprises2={surprises[i]->getRect()->x-baseclass::coord.x,surprises[i]->getRect()->y,30,30};

                                          std::cout<<"player get y"<<player1->getRect()->y<<std::endl;

                                   if (player1->getmoney()==100)
                                   {
                                   }
                                     }
                                   }
                                   for (int i=0;i<fleur_ames.size();i++)
                               {
                                 SDL_Rect tmprect ={fleur_ames[i]->getRect()->x-baseclass::coord.x,fleur_ames[i]->getRect()->y,30,30};

                               if(collision(player1->getRect(),&tmprect))
                               {
                                  delete fleur_ames[i];
                                 fleur_ames.erase(fleur_ames.begin()+i);
                                    player1->setpower(1);
                               }
                               }

                                  for (int i=0;i<fleur_toxiques.size();i++)
                               {
                                 SDL_Rect tmprect ={fleur_toxiques[i]->getRect()->x-baseclass::coord.x,fleur_toxiques[i]->getRect()->y,30,30};

                               if(collision(player1->getRect(),&tmprect)&&fleur_toxiques[i]->getmouvement()==true)
                               {
                                    player1->setpower(-1);
                               }
                               }

                                   if (moneymove>0 && moneymove<30)
                                    {
                                    moneymove++;
                                     for (int i=0;i<surprises.size();i++)
                                     {
                                        tmprect_surprises ={surprises[i]->getRect()->x-baseclass::coord.x,surprises[i]->getRect()->y,30,30};
                                       if (tmprect_surprises.x==tmprect_surprises2.x&& surprises[i]->getmovement()==false)
                                        {




                                            if (i!=2&&moneymove==5)
                                                     {
                                                      monies_surp.push_back(new money(mon2,surprises[i]->getRect()->x,tmprect_surprises.y-60,-1,0)); //because every tile is TILE_SIZE width and height, we can calculate
                                                      }








                                        surprises[i]->setY(-1);


                                        }
                                     }



                                    }
                                    if (moneymove>=30 && moneymove<=59)
                                        {


                                            moneymove++;

                                        for (int i=0;i<surprises.size();i++)
                                     {
                                        tmprect_surprises ={surprises[i]->getRect()->x-baseclass::coord.x,surprises[i]->getRect()->y,30,30};
                                       if (tmprect_surprises.x==tmprect_surprises2.x&& surprises[i]->getmovement()==false)
                                        {   if (i==2&&moneymove==31)
                                        {
                                             fleur_ames.push_back(new fleur_ame(fleur_am1,surprises[i]->getRect()->x-1,tmprect_surprises.y,10,0)); //because every tile is TILE_SIZE width and height, we can calculate

                                           }

                                        surprises[i]->setY(1);
                                       }
                                     }


                                     }





                                       for (int i=0;i<monies_surp.size();i++)
                                     {

                                      if (monies_surp[i]->getFrame()>1.5)
                                      {
                                            delete monies_surp[i];
                                        monies_surp.erase(monies_surp.begin()+i);
                                        player1->setmoney(1);
                                         if (player1->getmoney()>100)
                                         {
                                             player1->setHealth(1);
                                             player1->setmoney(0);

                                         }

                                      }

                                     }





                                     if (moneymove==59)
                                        {
                                        for (int i=0;i<surprises.size();i++)
                                        {
                                        tmprect_surprises ={surprises[i]->getRect()->x-baseclass::coord.x,surprises[i]->getRect()->y,30,30};
                                       if (tmprect_surprises.x==tmprect_surprises2.x&& surprises[i]->getmovement()==false){


                                        surprises[i]->setmovement(true);
                                        surprises[i]->setFrame(3);
                                        player1->setpower(1);
                                        }
                                     }
                                     }

                                       /*for (int i=0;i<surprises.size();i++)
                               {*/
                                    //tmprect_surprises ={surprises[i]->getRect()->x-baseclass::coord.x,surprises[i]->getRect()->y,30,30};

                                     // }
                                     //surprises[i]->setmovement(true);








                    for (int i=0;i<bullets.size();i++)
                       {
                       bullets[i]->setangle(20);
                       bullets[i]->move();

                       }

                player1->move(map1);

                   if(1000/FPS>SDL_GetTicks()-start)
                    {
                    SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
                       }

                time++;
                if(time>15)
                    {
                        time=0;
                        temps2--;
                    }
                //render

                SDL_BlitSurface(background,&camera,screen,NULL);
            b1->show2(screen);
               relatifdetails("Mario Bross World 1 ");
               currenttime();
                showmap();
                player1->showplayer(screen);

//                playe->show2(screen);
//                su->show(screen);
                 for (int i=0;i<bullets.size();i++)
                {
            bullets[i]->show("bullet2.bmp",screen);

               }
                for (int i=0;i<surprises.size();i++)
             {
            surprises[i]->show(screen);
             }
              for (int i=0;i<fleur_toxiques.size();i++)
              {
                  fleur_toxiques[i]->show(screen);
              }
              for (int i=0;i<fleur_ames.size();i++)
             {
            fleur_ames[i]->show(screen);
             }
               for (int i=0;i<moneis.size();i++)
             {
            moneis[i]->show(screen);
             }

              for (int i=0;i<monies_surp.size();i++)
             {
               monies_surp[i]->show2(screen);
             }
                 for (int i=0;i<Champignons.size();i++)
                  {
                    Champignons[i]->show(screen);
                 }
        for (int i=0;i<Tortues.size();i++)
                  {
                    Tortues[i]->show(screen);
                 }


                SDL_Flip(screen);
                if(temps2==0||player1->getHealth()==0 || player1->getRect()->y >=screen->h)//||player1->getRect())
                {
                    running=false;
                    SDL_Delay(3000);
                   showmessage("Game Over");
                }
                SDL_Rect tmprect2={finish.x-coord.x,finish.y,30,30};
                if(player1->getRect()->x+player1->getRect()->w>= tmprect2.x-tmprect2.w*2)
                {
                    showmessage("You win");
                    SDL_Delay(1000);
                    running=false;
                }

                   if(1000/FPS>SDL_GetTicks()-start)
                    {
                    SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
                       }
            }
          }
         void game::loadmap(const char *  filename)
          {
              int width,height;
            std::ifstream in(filename);
            if(!in.is_open())
            {
             // std::cout<<"Problem with loading Map File "<<std::endl;
              return;
            }
            in >> width;
            in >> height;
            int current; //variable actuel du block de la carte .
            for (int i=0;i<height;i++)
               {
                   std::vector<int> vec;
                   for (int j=0;j<width;j++)
                      {
                          if(in.eof())    //if we reached the file before we end with the read in
                        {
                                std::cout << "je trouve le fichier " << std::endl;  //write out and exit
                                return;
                        }
                        in >> current;  //read the current number
                        if (current==-4)
                        {
                        moneis.push_back(new money(mon,j*tile_size,i*tile_size,-1,0)); //because every tile is TILE_SIZE width and height, we can calculate
                        }

                       if (current==14)
                       {
                            fleur_toxiques.push_back(new fleur_toxique(fleur_tox1,j*tile_size-2,i*tile_size,-1,0)); //because every tile is TILE_SIZE width and height, we can calculate

                       }

                        if (current==13)
                        {
                       surprises.push_back(new surprise(sur,j*tile_size,i*tile_size,-1,0)); //because every tile is TILE_SIZE width and height, we can calculate
                        }

                        if (current==-2)
                        {
                       Tortues.push_back(new Tortue(Tortues1,j*tile_size,i*tile_size,-1,0)); //because every tile is TILE_SIZE width and height, we can calculate

                        }
                        if(current==-1) //if it's -1 than we put a new enemy to the position
                        {
                                Champignons.push_back(new Champignon(Champignon1,j*tile_size,i*tile_size,-1,0)); //because every tile is TILE_SIZE width and height, we can calculate
                                     //and we push back 0 to the vector (so nothing will be visible there)
                        }else{
                                if(current>=0 && current<=13 )    //if the current is greater or equal then 0 (so nothing) and less or equal than the max number of tiles
                                {
                                        if(current==12)  //if the current is 3
                                        {
                                                finish.x=j*30;  //set the finish coordinate
                                                finish.y=i*30;
                                        }
                                        vec.push_back(current); //put the current into our matrix which represent the map in the game
                                }else{
                                        vec.push_back(0);       //if the tile number is not known than just push 0 (so nothing) in the current position
                                }
                        }

                      }
                     map1.push_back(vec);
               }
               in.close();
          }
void game::showmap()
{
    int start1=(baseclass::coord.x-(baseclass::coord.x%baseclass::tile_size))/baseclass::tile_size;
    int end1=(baseclass::coord.x+baseclass::coord.w+(baseclass::tile_size-(baseclass::coord.x+baseclass::coord.w)%baseclass::tile_size))/baseclass::tile_size;
if(start1<0)
    start1=0;
if(end1>map1[0].size())
    end1=map1[0].size();
for (int i=0;i<map1.size();i++)
    {
      for (int j=start1;j<end1;j++)
      {
          if(map1[i][j]!=0)
          {
              SDL_Rect block_rect={(map1[i][j]-1)*baseclass::tile_size,0,baseclass::tile_size,baseclass::tile_size};
              SDL_Rect dest_rect={j*baseclass::tile_size-baseclass::coord.x,i*baseclass::tile_size};
              SDL_BlitSurface(block,&block_rect,screen,&dest_rect);
          }
      }
    }
}


