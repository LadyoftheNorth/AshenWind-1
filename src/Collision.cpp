#include <iostream>
#include <string>
#include <cmath>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include "Collision.h"

CollisionDetector::CollisionDetector()
{

}

int CollisionDetector::is_touching_sq(GameObject* a, GameObject* b)
{
    if ((a->obj_get_x_pos() > (b->obj_get_x_pos() + b->obj_get_w()))
        || ((a->obj_get_x_pos() + a->obj_get_w()) < b->obj_get_x_pos())
        || (a->obj_get_y_pos() > (b->obj_get_y_pos() + b->obj_get_h()))
        || ((a->obj_get_y_pos() + a->obj_get_h()) < b->obj_get_y_pos()))
    {
        return 0;
    }

    return 1;
}