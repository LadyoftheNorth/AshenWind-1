#ifndef COLLISIONS_H
#define COLLISIONS_H
#include <SDL2/SDL.h>
#include "Object.h"

class CollisionDetector 
{
    private:

    public:
    CollisionDetector();

    int is_touching_sq(GameObject* a, GameObject* b);
};

#endif