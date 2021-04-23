#include <stdio.h>
#include <stdlib.h>

#include "GameEngine.h"

class Player
{
private:
    static const PLAYER_WIDTH = 1;
    static const PLAYER_HEIGHT = 1;
    
    static const START_PLAYER_HEALTH = 5;

    int posX, posY;
    int velX, velY;

    int playerHealth;

    SDL_Rect playerCollider;
    Sprite playerSprite;

public:
    Player();
    ~Player();

    //Adds to / Subtracts from Position and Velocity
    UpdatePlayerPosition(int x, int y);
    UpdatePlayerVelocity(int x, int y);

    //Retrieves x, y Position components
    GetPlayerPositionX();
    GetPlayerPositionY();

    //Retrieves x, y Velocity components
    GetPlayerVelocityX();
    GetPlayerVelocityY();

    //Update and Get Health component
    UpdatePlayerHealth(int healthChange);
    GetPlayerHealth();

};