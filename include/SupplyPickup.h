#ifndef SUPPLYPICKUP_H
#define SUPPLYPICKUP_H
#include <stdio.h>
#include <stdlib.h>

#include "GameObject.h"
#include "Sprite.h"

class SupplyPickup
{
private:
    

    SDL_Renderer* my_renderer;

public:
    SupplyPickup(SDL_Renderer* ren);
    ~SupplyPickup();
};
#endif