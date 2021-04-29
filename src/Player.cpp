#include "Player.h"
#include "GameObject.h"



Player::Player(SDL_Renderer* ren)
{
    playerRenderer = ren;
    player_obj = new GameObject(ren);
    playerHealth = START_PLAYER_HEALTH;

	//Set collision box dimensions
	playerCollider.w = PLAYER_WIDTH;
	playerCollider.h = PLAYER_HEIGHT;

    spriteRect.x = 0;
    spriteRect.y = 0;
    spriteRect.w = 0;
    spriteRect.h = 0;
}

Player::~Player()
{
}

void Player::PlayerInit(const char* graphic, int start_x, int start_y, int w, int h)
{
    player_obj->init(graphic, start_x, start_y, w, h, 0, 0);
    playerSprite = new Sprite(playerRenderer, graphic, 32, 44);
    frame = 0;

    spriteRect.w = 32;
    spriteRect.h = 44;
}

void Player::PlayerUpdate()
{
    player_obj->update();

    if (GetPlayerVelocityX() < 0)
    {
        if (player_move == 3)
        {
            frame += 1;
            spriteRect.y = ((frame / 6) % 7) * 48;
        } else
        {
            frame = 0;
            playerSprite->LoadFromFile("./img/Left.png");
            spriteRect.y = 0;
            spriteRect.h = 42;
            player_move = LEFT;
        }
    } else
    if (GetPlayerVelocityX() > 0)
    {
        if (player_move == 4)
        {
            frame += 1;
            spriteRect.y = ((frame / 6) % 7) * 48;
        } else
        {
            frame = 0;
            playerSprite->LoadFromFile("./img/Right.png");
            spriteRect.y = 0;
            spriteRect.h = 42;
            player_move = RIGHT;
        }
    } else
    if (GetPlayerVelocityY() < 0)
    {
        if (player_move == 1)
        {
            frame += 1;
            spriteRect.y = ((frame / 6) % 8) * 48;
        } else
        {
            frame = 0;
            playerSprite->LoadFromFile("./img/Up.png");
            spriteRect.y = 0;
            spriteRect.h = 48;
            player_move = UP;
        }
    } else
    if (GetPlayerVelocityY() > 0)
    {
        if (player_move == 2)
        {
            frame += 1;
            spriteRect.y = ((frame / 6) % 8) * 48;
        } else
        {
            frame = 0;
            playerSprite->LoadFromFile("./img/Down.png");
            spriteRect.y = 0;
            spriteRect.h = 48;
            player_move = DOWN;
        }
    } else
    {
        frame = 0;
        spriteRect.y = 0;
        player_move = IDLE;
    }

    if (GetPlayerPositionX() < 0)
    {
      UpdatePlayerPosition(0, GetPlayerPositionY());
    }

    if (GetPlayerPositionX() > 600)
    {
      UpdatePlayerPosition(600, GetPlayerPositionY());
    }

    if (GetPlayerPositionY() < 0)
    {
      UpdatePlayerPosition(GetPlayerPositionX(), 0);
    }

    if (GetPlayerPositionY() > 450)
    {
      UpdatePlayerPosition(GetPlayerPositionX(), 450);
    }
}

void Player::PlayerRender(SDL_Renderer* ren)
{
    playerSprite->render(GetPlayerPositionX(), GetPlayerPositionY(), &spriteRect);
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
