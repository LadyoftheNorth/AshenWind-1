#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "GameEngine.h"
#include "GameObject.h"

enum MOVEMENT {IDLE, UP, DOWN, LEFT, RIGHT};

class Player
{
private:
    GameObject* player_obj;
    MOVEMENT player_move;

    static const int PLAYER_WIDTH = 1;
    static const int PLAYER_HEIGHT = 1;
    
    static const int START_PLAYER_HEALTH = 5;

    int playerHealth;
    int frame;

    SDL_Renderer* playerRenderer;
    SDL_Rect playerCollider;
    SDL_Rect spriteRect;
    Sprite* playerSprite;

public:
    Player(SDL_Renderer* ren);
    ~Player();

    void PlayerInit(const char* graphic, int start_x, int start_y, int w, int h);
    void PlayerUpdate();
    void PlayerRender(SDL_Renderer* ren);

    //Adds to / Subtracts from Position and Velocity
    void UpdatePlayerPosition(int x, int y);
    void UpdatePlayerVelocity(int x, int y);

    //Retrieves x, y Position components
    int GetPlayerPositionX();
    int GetPlayerPositionY();

    //Retrieves x, y Velocity components
    int GetPlayerVelocityX();
    int GetPlayerVelocityY();

    //Update and Get Health component
    void UpdatePlayerHealth(int healthChange);
    int GetPlayerHealth();

    GameObject* GetGameObject();
};
#endif