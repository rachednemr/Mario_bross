#ifndef COMPOSANT_H_INCLUDED
#define COMPOSANT_H_INCLUDED
#include "base.h"
class Composant:public baseclass
 {
     int X;
     int Y;
     int getX();
     int setX(int x);
     int getY();
     int setY(int x);
     int getFrame();
};

#endif // COMPOSANT_H_INCLUDED
