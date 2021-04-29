#ifndef SPRITE_H
#define SPRITE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "GameObject.h"

class Sprite
{
	public:
		Sprite(SDL_Renderer* ren, const char* graphic, int width = 0, int height = 0);
		~Sprite();

		//Loads image at specified path
		bool LoadFromFile( std::string path );

		//Free texture if it exists
		void FreeTexture();
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The SDL Renderer
		SDL_Renderer* my_renderer;

		//The actual hardware texture
		SDL_Texture* spriteTexture;

		//Image dimensions
		int spriteWidth;
		int spriteHeight;
};

#endif