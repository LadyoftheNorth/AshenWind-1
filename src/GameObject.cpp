#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* ren) : 
    objRenderer {ren} 

void GameObject::init(const char* graphic, int start_x, int start_y, int w, int h)
{
    SDL_Surface* temp = IMG_Load(graphic);
    obj_texture = SDL_CreateTextureFromSurface(obj_renderer, temp);
    SDL_FreeSurface(temp);

    obj_rect.x = start_x;
    obj_rect.y = start_y;
    obj_rect.w = w;
    obj_rect.h = h;
}

void GameObject::update()
{

}

void GameObject::render(SDL_Renderer*)
{

}

void GameObject::quit()
{
    IMG_Quit();
}

int GameObject::obj_get_x_pos()
{
    return obj_rect.x;
}

void GameObject::obj_set_x_pos(int val)
{
    obj_rect.x = val;
}

int GameObject::obj_get_y_pos()
{
    return obj_rect.y;
}

void GameObject::obj_set_y_pos(int val)
{
    obj_rect.y = val;
}

int GameObject::obj_get_x_vel()
{
    return obj_x_vel;
}

void GameObject::obj_set_x_vel(int val)
{
    obj_x_vel = val;
}

int GameObject::obj_get_y_vel()
{
    return obj_y_vel;
}

void GameObject::obj_set_y_vel(int val)
{
    obj_y_vel = val;
}

int GameObject::obj_get_w()
{
    return obj_rect.w;
}

int GameObject::obj_get_h()
{
    return obj_rect.h;
}