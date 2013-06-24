#include "game.h"
int main(int argc, char* argv[])
{
game g;
g.start();
return 0;
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <iostream>
void setrects(SDL_Rect*clip)
       {
          clip[0].x=0;
          clip[0].y=0;
           clip[0].w=30;
           clip[0].h=30;

         clip[1].x=30;
         clip[1].y=0;
         clip[1].w=30;
         clip[1].h=30;

         clip[2].x=60;
         clip[2].y=0;
         clip[2].w=30;
         clip[2].h=30;
       }
       void item_start(SDL_Rect*tabsatart)
       {
           //trois copies de chaqu'un parseque FPSrapide
           tabsatart[0].x=0;
           tabsatart[0].y=0;
           tabsatart[0].w=184;
           tabsatart[0].h=27;

           tabsatart[1].x=0;
           tabsatart[1].y=0;
           tabsatart[1].w=184;
           tabsatart[1].h=27;


          tabsatart[2].x=0;
           tabsatart[2].y=0;
           tabsatart[2].w=184;
           tabsatart[2].h=27;

           tabsatart[3].x=185;
           tabsatart[3].y=0;
           tabsatart[3].w=184;
           tabsatart[3].h=27;

            tabsatart[4].x=185;
           tabsatart[4].y=0;
           tabsatart[4].w=184;
           tabsatart[4].h=27;

            tabsatart[5].x=185;
           tabsatart[5].y=0;
           tabsatart[5].w=184;
           tabsatart[5].h=27;

            tabsatart[6].x=369;
           tabsatart[6].y=0;
           tabsatart[6].w=184;
           tabsatart[6].h=27;

           tabsatart[7].x=369;
           tabsatart[7].y=0;
           tabsatart[7].w=184;
           tabsatart[7].h=27;

           tabsatart[8].x=369;
           tabsatart[8].y=0;
           tabsatart[8].w=184;
           tabsatart[8].h=27;

           tabsatart[9].x=580;
           tabsatart[9].y=0;
           tabsatart[9].w=184;
           tabsatart[9].h=27;

           tabsatart[10].x=580;
           tabsatart[10].y=0;
           tabsatart[10].w=184;
           tabsatart[10].h=27;

           tabsatart[11].x=580;
           tabsatart[11].y=0;
           tabsatart[11].w=184;
           tabsatart[11].h=27;


       }
       bool collesion (SDL_Rect * rect1,SDL_Rect * rect2)
       {
        if(rect1->y>=rect2->y+rect2->h)
            return 0;
         if(rect1->x >=rect2->x+rect2->w)
            return false;
         if(rect1->y+rect1->h <= rect2->y)
            return false;
        if(rect1->x+rect1->w <= rect2->x)
            return false;
            return true;

       }
  int show_menu()
       {
           Uint32 start_item;
            int FPS1=35;
           int frame_menu=0;
           int frame_menu2=0;
    Mix_Chunk * effect_menu;
    Mix_Music * music_menu;
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    //music_menu=Mix_LoadMUS("gamemenu1.wav");
    effect_menu=Mix_LoadWAV("gamemenu1.wav");
           int x=0;
           bool runnig_menu;
           bool choice_tem[4]={0,0,0,0};
         SDL_Init(SDL_INIT_EVERYTHING);
           SDL_Surface *screen_menu,*image_menu,*mario_head,*items_menu,*items_menu2,*items_menu3,*items_menu4,*items_menu6,*items_menu5;
           screen_menu=SDL_SetVideoMode(640,480,32, SDL_SWSURFACE);
           Uint32 color =SDL_MapRGB(screen_menu->format,0xff,0xff,0xff);
           SDL_Rect rect_mario_head,rect_item_start,rect_item2_start,rect_item3_start,rect_item4_start,rect_item5_start,rect_item6_start,rect_tab_item[12],rect2_tab_item[12];
           mario_head=SDL_DisplayFormat(SDL_LoadBMP("mario_head.bmp"));
           image_menu=SDL_DisplayFormat(SDL_LoadBMP("backround_menu.bmp"));
           items_menu=SDL_DisplayFormat(SDL_LoadBMP("item1_start1.bmp"));
           items_menu2=SDL_DisplayFormat(SDL_LoadBMP("item2_start1.bmp"));
           items_menu3=SDL_DisplayFormat(SDL_LoadBMP("item3_start1.bmp"));
           items_menu4=SDL_DisplayFormat(SDL_LoadBMP("item4_start1.bmp"));
           items_menu5=SDL_DisplayFormat(SDL_LoadBMP("item5_start1.bmp"));
           items_menu6=SDL_DisplayFormat(SDL_LoadBMP("item6_start1.bmp"));

           rect_mario_head.x=200;
           rect_mario_head.y=280;
           rect_mario_head.w=30;
           rect_mario_head.h=27;

           rect_item_start.x=250;
           rect_item_start.y=280;
           rect_item_start.w=184;
           rect_item_start.h=27;

           rect_item2_start.x=253;
           rect_item2_start.y=303;
           rect_item2_start.w=184;
           rect_item2_start.h=27;

           rect_item3_start.x=244;
           rect_item3_start.y=403;
           rect_item3_start.w=196;
           rect_item3_start.h=29;

           rect_item4_start.x=249;
           rect_item4_start.y=329;
           rect_item4_start.w=187;
           rect_item4_start.h=29;

           rect_item5_start.x=254;
           rect_item5_start.y=352;
           rect_item5_start.w=187;
           rect_item5_start.h=29;

           rect_item6_start.x=255;
           rect_item6_start.y=378;
           rect_item6_start.w=187;
           rect_item6_start.h=29;

           item_start(rect_tab_item);
           item_start(rect2_tab_item);

           runnig_menu=true;

//           Mix_OpenAudio(music_menu);
           //Mix_PlayingMusic(music_menu);
            Mix_PlayChannel(-1,effect_menu,0);
           while (runnig_menu)
           {
               start_item=SDL_GetTicks();
           SDL_SetColorKey(mario_head,SDL_SRCCOLORKEY,SDL_MapRGB(screen_menu->format,0x00,0xFF,0xFF));
           SDL_SetColorKey(items_menu,SDL_SRCCOLORKEY,SDL_MapRGB(screen_menu->format,0x00,0xFF,0xFF));
           SDL_SetColorKey(items_menu2,SDL_SRCCOLORKEY,SDL_MapRGB(screen_menu->format,0x00,0xFF,0xFF));
           SDL_SetColorKey(items_menu3,SDL_SRCCOLORKEY,SDL_MapRGB(screen_menu->format,0x00,0xFF,0xFF));
           SDL_SetColorKey(items_menu4,SDL_SRCCOLORKEY,SDL_MapRGB(screen_menu->format,0x00,0xFF,0xFF));
           SDL_SetColorKey(items_menu5,SDL_SRCCOLORKEY,SDL_MapRGB(screen_menu->format,0x00,0xFF,0xFF));
           SDL_SetColorKey(items_menu6,SDL_SRCCOLORKEY,SDL_MapRGB(screen_menu->format,0x00,0xFF,0xFF));

            SDL_WM_SetIcon(mario_head, NULL);
             SDL_Event event_menu;
        while (SDL_PollEvent(&event_menu))
        {
            switch (event_menu.type)
            {
              //case SDL_QUIT:
              //runnig_menu=false;
             // break;
              case SDL_KEYDOWN:

                switch(event_menu.key.keysym.sym)
                  {
                   case SDLK_UP:
                  choice_tem[0]=1;
                   break;
                   case SDLK_DOWN:
                   choice_tem[1]=1;
                   break;
                   case SDLK_LEFT:
                      choice_tem[2]=1;
                      x=1;
                   break;
                  }
                  break;
                  case SDL_KEYUP:

                switch(event_menu.key.keysym.sym)
                  {
                   case SDLK_UP:choice_tem[0]=0;break;
                   case SDLK_DOWN:choice_tem[1]=0;break;
                   case SDLK_LEFT:choice_tem[2]=0;break;
                  }
            }

      }
//logic
    if(choice_tem[0]==1)
    {
        rect_mario_head.y=280;
    }
     if(choice_tem[1]==1)
    {
        rect_mario_head.y=303;
    }
     if(choice_tem[2]==1)
    {
        Mix_FreeMusic(music_menu);
        Mix_FreeChunk(effect_menu);
        runnig_menu=false;
        return x;
    }

// Render
SDL_FillRect(screen_menu,&screen_menu->clip_rect,color);
SDL_BlitSurface(image_menu,NULL,screen_menu,NULL);
  SDL_BlitSurface(mario_head,NULL,screen_menu,&rect_mario_head);
  SDL_BlitSurface(items_menu,&rect_tab_item[frame_menu],screen_menu,&rect_item_start);
  SDL_BlitSurface(items_menu2,&rect2_tab_item[frame_menu2],screen_menu,&rect_item2_start);
  SDL_BlitSurface(items_menu3,&rect2_tab_item[frame_menu2],screen_menu,&rect_item3_start);
  SDL_BlitSurface(items_menu4,&rect2_tab_item[frame_menu2],screen_menu,&rect_item4_start);
  SDL_BlitSurface(items_menu5,&rect2_tab_item[frame_menu2],screen_menu,&rect_item5_start);
 SDL_BlitSurface(items_menu6,&rect2_tab_item[frame_menu2],screen_menu,&rect_item6_start);

        SDL_Flip(screen_menu);
        if(rect_item_start.y==rect_mario_head.y)
        {
        frame_menu++;
        if(frame_menu==12)
        frame_menu=0;
        }
        else
        {
            frame_menu=0;
        }


        if(rect_item2_start.y==rect_mario_head.y)
        {
        frame_menu2++;
        if(frame_menu2==12)
        frame_menu2=0;
        }
        else
        {
            frame_menu2=0;
        }
        if(1000/FPS1>SDL_GetTicks()-start_item)
        SDL_Delay(1000/FPS1-(SDL_GetTicks()-start_item));
       }
     SDL_FreeSurface(mario_head);
     SDL_FreeSurface(image_menu);
     SDL_FreeSurface(items_menu);

    //SDL_free(rect_mario_head);
    SDL_Quit();


           return x;
       }
int main(int argc, char * argv[])
{

if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
    std::cout<<"there is an error"<<std::endl;
else
{

   //SDL_Init(SDL_INIT_EVERYTHING); // Initialisation de la SDL
    Mix_Chunk * effect1;
    Mix_Music * music;
  Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    TTF_Init();
    TTF_Font *font=TTF_OpenFont("angelina.ttf",32);
    music=Mix_LoadMUS("mar1.wav");
    effect1=Mix_LoadWAV("Mar2.wav");
    SDL_Surface * screen=NULL,*image=NULL,*image2,*image3,*text=NULL,*imagebackground,*img_sky,*img_sky2=NULL,*mario_head;
    SDL_Color color3={220,120,113};
    text=TTF_RenderText_Solid(font,"Mario Bross",color3);
    screen=SDL_SetVideoMode(640,480,32, SDL_SWSURFACE); // Ouverture de la fenêtre
    if(screen==NULL)
        std::cout<<"screen cant not be loaded"<<SDL_GetError()<<std::endl;
    else
    {
    bool running=true;
    const int FPS=5;
    int speed=5;
    bool b[4]={0,0,0,0};
    int frame =0;
    int x=-100,y=0;
    Uint32 start;
    SDL_Rect rect,first,second,rect2,rect3,rect4,rect5,rect6[5],rect7,rects[4],rect_mario_head,rects_items,rect_sky2,rect_sky,rect_mario_headsss,rect_background,rect_camera;
rect.x=270;
rect.y=180;
rect2.x=0;
rect2.y=280;
rect3.x=70;
rect3.y=200;
rect4.x=140;
rect4.y=200;
rect5.x=140;
rect5.y=167;
rect6[0].x=0;
rect6[0].y=150;
rect6[1].x=70;
rect6[1].y=150;
rect6[2].x=130;
rect6[2].y=150;
rect6[3].x=190;
rect6[3].y=150;
rect6[4].x=230;
rect6[4].y=150;

rect_sky.x=0;
rect_sky.y=0;
rect_sky.w=640;
rect_sky.h=35;

rect_sky2.x=0;
rect_sky2.y=250;
rect_sky2.w=640;
rect_sky2.h=35;

rect_background.x=0;
rect_background.y=0;
rect_background.w=640;
rect_background.h=460;

rect_mario_head.x=0;
rect_mario_head.y=20;
rect_mario_head.w=30;
rect_mario_head.h=27;

rect_camera.x=30;
rect_camera.y=10;
rect_camera.w=640;
rect_camera.h=460;
            // premier partie de l'image
setrects(rects);
Uint32 color =SDL_MapRGB(screen->format,0xff,0xff,0xff);
Uint32 color2 =SDL_MapRGB(screen->format,0x00,0x00,0x00);
image=SDL_DisplayFormat(SDL_LoadBMP("chompions_arigi.bmp"));
img_sky2=SDL_DisplayFormat(SDL_LoadBMP("sky2.bmp"));
img_sky=SDL_DisplayFormat(SDL_LoadBMP("sky5.bmp"));
image2=SDL_DisplayFormat(SDL_LoadBMP("terre.bmp"));
image3=SDL_DisplayFormat(SDL_LoadBMP("barmil.bmp"));
imagebackground=SDL_DisplayFormat(SDL_LoadBMP("background2.bmp"));
mario_head=SDL_DisplayFormat(SDL_LoadBMP("mario_head.bmp"));
//menu images



//image2=SDL_DisplayFormat(SDL_LoadBMP("tortu_terre2.bmp"));

SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xFF,0xFF));
SDL_SetColorKey(image2,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xFF,0xFF));
SDL_SetColorKey(img_sky,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xFF,0xFF));
SDL_SetColorKey(mario_head,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xFF,0xFF));
SDL_SetColorKey(img_sky2,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xFF,0xFF));
SDL_WM_SetCaption("Mario For Ever 3", NULL);
     // Mise en pause du programme
    if(show_menu()==1)
        {
                     Mix_PlayChannel(-1,effect1,0);

    while (running)
    {

        start=SDL_GetTicks();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
              case SDL_QUIT:
              running=false;
              break;
              case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                  {
                   case SDLK_UP:
                   b[0]=1;
                   break;
                   case SDLK_DOWN:
                   b[1]=1;
                   break;
                   case SDLK_LEFT:
                   b[2]=1;
                   break;
                   case SDLK_RIGHT:
                   b[3]=1;
                   break;
                  }
                 break;

              case SDL_KEYUP:
                switch(event.key.keysym.sym)
                  {
                   case SDLK_UP:b[0]=0;break;
                   case SDLK_DOWN:b[1]=0;break;
                   case SDLK_LEFT:b[2]=0;break;
                   case SDLK_RIGHT:b[3]=0;break;
                  }
                 break;
            }
      }
    //logic
    if(b[0])
    {
        rect.y-=3;
        for (int i=0;i<6;i++)
        {
        if(collesion(&rect6[i],&rect))
        rect.y+=3;
        }
    }
    if(b[1])
    {
        rect.y+=3;
        for (int i=0;i<6;i++)
        {
        if(collesion(&rect6[i],&rect))
        rect.y-=3;
        }
    }
    if(b[2])
    {
        rect.x-=3;
        for (int i=0;i<6;i++)
      {
        if(collesion(&rect6[i],&rect))
        rect.x+=3;
        if(rect.x<0)
        {
        rect_camera.x-=10;
       //rect_sky.x-=10;

        }
        if(rect_camera.x<0)
        {    rect_sky.x=2520-640*4;
            rect_camera.x=6400-640;
        }
        }
    }
    if(b[3])
    {
       // x+=speed;
        rect.x+=3;
        for (int i=0;i<6;i++)
        {
        if(collesion(&rect6[i],&rect))
        rect.x-=3;
         if(rect.x>=400)
         {
        rect_camera.x+=10;
       // rect_sky.x+=10;
         }
        if(rect_camera.x>6400-640)
        {
            rect_camera.x=0;
        }
        //if(rect_sky.x>6400-640)
          //  rect_sky.x=0;
        }
       //rect_camera.x+=speed;
    }
// render
   SDL_FillRect(screen,&screen->clip_rect,color);
   //ajouter un image directement dans le screene
   //SDL_BlitSurface(image,NULL,screen,NULL);
  //SDL_BlitSurface(imagebackground,NULL,screen,&rect_background);
   SDL_BlitSurface(imagebackground,&rect_camera,screen,NULL);
   rect_sky.x+=10;
   if(rect_sky.x>6400-640)
           rect_sky.x=0;
  SDL_BlitSurface(img_sky,&rect_sky,screen,NULL);
    SDL_BlitSurface(img_sky2,NULL,screen,&rect_sky2);

   // partager une image contient plusieurs images comme css sprite
            first.x=0;
            first.y=0;
            first.w=96;
            first.h=62;
// deusieme partie de l'image
   SDL_BlitSurface(image2,&first,screen,&rect2);

//    partitoin de l'image
        second.x=0;
        second.y=0;
        second.w=96;
        second.h=62;
        //charger l'image dans l'ecran
  SDL_BlitSurface(image2,&second,screen,&rect3);
  SDL_BlitSurface(image2,&second,screen,&rect4);
  //SDL_BlitSurface(img_sky2,NULL,screen,&rect_sky2);

  for (int i=0;i<5;i++)
  {
SDL_BlitSurface(image3,&second,screen,&rect6[i]);
  }
// mettre l'image dans un rectangle puis dans l'acran
   //SDL_BlitSurface(image,NULL,screen,&rect);
  // SDL_FillRect(screen,&rect,color2);
   //cleap rect utiliserr pour effesser l'ecran
   //SDL_FillRect(screen,&screen->clip_rect,color);
// afficher le tableau des images
//SDL_BlitSurface(image,NULL,screen,&rect);
     SDL_BlitSurface(text,NULL,screen,NULL);
     SDL_BlitSurface(mario_head,NULL,screen,&rect_mario_head);

   SDL_BlitSurface(image,&rects[frame],screen,&rect);
        SDL_Flip(screen);
        frame++;
        if(frame==2)
        frame=0;
    if(1000/FPS>SDL_GetTicks()-start)
        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    }
    SDL_FreeSurface(image);
    SDL_FreeSurface(text);
    TTF_Quit();
    Mix_FreeChunk(effect1);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    } // Arrêt de la SDL
    return 0; // Fermeture du programme
}
}
}
*/

