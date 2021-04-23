#include "Player.h"

Player::Player()
{
    posX = 0;
    posY = 0;
    velX = 0;
    velY = 0;

    player_health = START_PLAYER_HEALTH;

	//Set collision box dimensions
	playerCollider.w = PLAYER_WIDTH;
	playerCollider.h = PLAYER_HEIGHT;
}

Player::~Player()
{
}
