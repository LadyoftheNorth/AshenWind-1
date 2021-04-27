#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "GameObject.h"

class CollisionDetector 
{
    private:

    public:
    CollisionDetector();

    int is_touching_sq(GameObject* a, GameObject* b);
};

#endif