#ifndef OBJECT_H
#define OBJECT_H
#include <SDL2/SDL.h>

class GameObject 
{
    private:
    SDL_Renderer* obj_renderer;
    SDL_Rect obj_rect;
    int obj_x_vel;
    int obj_y_vel;

    public:
    GameObject(SDL_Renderer* ren);
    void init(const char* graphic, int start_x, int start_y, int w, int h);
    void update();
    void render(SDL_Renderer*);
    void quit();

    int obj_get_x_pos();
    void obj_set_x_pos(int val);

    int obj_get_y_pos();
    void obj_set_y_pos(int val);

    int obj_get_x_vel();
    void obj_set_x_vel(int val);

    int obj_get_y_vel();
    void obj_set_y_vel(int val);

    int obj_get_w();
    int obj_get_h();
}