#include "Player.h"
#include "GameObject.h"

Player::Player()
{
    player_obj = new GameObject();
    player_health = START_PLAYER_HEALTH;

	//Set collision box dimensions
	playerCollider.w = PLAYER_WIDTH;
	playerCollider.h = PLAYER_HEIGHT;
}

Player::~Player()
{
}

void PlayerInit(const* char graphic, int start_x, int start_y, int w, int h)
{
    player_obj->init(graphic, start_x, start_y, w, h);
}

//Adds to / Subtracts from Position and Velocity
void UpdatePlayerPosition(int x, int y)
{
    player_obj->obj_set_x_pos(x);
    player_obj->obj_set_y_pos(y);
}

void UpdatePlayerVelocity(int x, int y)
{
    player_obj->obj_set_x_vel(x);
    player_obj->obj_set_y_vel(y);
}

//Retrieves x, y Position components
int GetPlayerPositionX()
{
    return player_obj->obj_get_x_pos();
}

int GetPlayerPositionY()
{
    return player_obj->obj_get_y_pos();
}

//Retrieves x, y Velocity components
int GetPlayerVelocityX()
{
    return player_obj->obj_get_x_vel();
}

int GetPlayerVelocityY()
{
    return payer_obj->obj_get_y_vel();
}

//Update and Get Health component
void UpdatePlayerHealth(int healthChange)
{
    playerHealth += healthChange;
}

int GetPlayerHealth()
{
    return playerHealth;
}

GameObject* GetGameObject()
{
    return &player_obj;
}
