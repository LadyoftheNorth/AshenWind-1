#include <stdio.h>
#include <stdlib.h>

#include "GameEngine.h"
#include "GameObject.h"

class Player: public GameObject
{
private:
    GameObject* player_obj

    static const PLAYER_WIDTH = 1;
    static const PLAYER_HEIGHT = 1;
    
    static const int START_PLAYER_HEALTH = 5;

    int playerHealth;

    SDL_Rect playerCollider;
    Sprite playerSprite;

public:
    Player(SDL_Renderer* ren);
    ~Player();

    void PlayerInit(const* char graphic, int start_x, int start_y, int w, int h);
    void PlayerUpdate();
    void PlayerRender(SDL_Renderer* ren);s

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