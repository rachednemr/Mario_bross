#include "base.h"
bool baseclass::collision(SDL_Rect* rec1,SDL_Rect* rec2)
{
        if(rec1->y >= rec2->y + rec2->h)        //if rec2 is upper than rec1 there is no way to be a collision
                return 0;       //so return 0
        if(rec1->x >= rec2->x + rec2->w) //if rec2 is more to the left than there is no way to be a collision
                return 0;
        if(rec1->y + rec1->h <= rec2->y)        //if rec2 is under rec1 no collision
                return 0;
        if(rec1->x + rec1->w <= rec2->x)        //if rec2 is righter then rec1 there is no way for collision
                return 0;
        return 1;       //if all fails, we have a collision
}
SDL_Rect* baseclass::getRect()
{
        return &box;
}
void baseclass::setFrame(double Fr)
{
frame=Fr;
}
double baseclass::getFrame()
{
return frame;
}

