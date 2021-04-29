#ifndef COLLISIONS_H
#define COLLISIONS_H
#include <SDL2/SDL.h>
#include "GameObject.h"

class CollisionDetector 
{
    private:

    public:
    CollisionDetector();

    //tests if two GameObjects are touching based on their boxes
    int is_touching_sq(GameObject* a, GameObject* b);
};

#endif