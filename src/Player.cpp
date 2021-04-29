#include "Player.h"
#include "GameObject.h"

Player::Player(SDL_Renderer* ren)
{
    player_obj = new GameObject(ren);
    playerHealth = START_PLAYER_HEALTH;

	//Set collision box dimensions
	playerCollider.w = PLAYER_WIDTH;
	playerCollider.h = PLAYER_HEIGHT;
}

Player::~Player()
{
}

void Player::PlayerInit(const char* graphic, int start_x, int start_y, int w, int h)
{
    player_obj->init(graphic, start_x, start_y, w, h);
}

void Player::PlayerUpdate()
{
    player_obj->update();
}

void Player::PlayerRender(SDL_Renderer* ren)
{
    player_obj->render(ren);
}

//Adds to / Subtracts from Position and Velocity
void Player::UpdatePlayerPosition(int x, int y)
{
    player_obj->obj_set_x_pos(x);
    player_obj->obj_set_y_pos(y);
}

void Player::UpdatePlayerVelocity(int x, int y)
{
    player_obj->obj_set_x_vel(x);
    player_obj->obj_set_y_vel(y);
}

//Retrieves x, y Position components
int Player::GetPlayerPositionX()
{
    return player_obj->obj_get_x_pos();
}

int Player::GetPlayerPositionY()
{
    return player_obj->obj_get_y_pos();
}

//Retrieves x, y Velocity components
int Player::GetPlayerVelocityX()
{
    return player_obj->obj_get_x_vel();
}

int Player::GetPlayerVelocityY()
{
    return player_obj->obj_get_y_vel();
}

//Update and Get Health component
void Player::UpdatePlayerHealth(int healthChange)
{
    playerHealth += healthChange;
}

int Player::GetPlayerHealth()
{
    return playerHealth;
}

GameObject* Player::GetGameObject()
{
    return player_obj;
}
