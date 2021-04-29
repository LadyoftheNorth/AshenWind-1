#ifndef LEVEL_H
#define LEVEL_H
#include <stdio.h>
#include <stdlib.h>

#include "GameObject.h"
#include "Sprite.h"

class Level
{
private:
    SDL_Renderer* my_renderer;

public:
    Level(SDL_Renderer* ren);
    ~Level();
};
#endif