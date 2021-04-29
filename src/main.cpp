//Christine Wendell, Tristan C Gill, Benjamin Rhys Gerrish

#include "GameEngine.h"

int main() 
{ 
  GameEngine* engine = new GameEngine();
  
  int fps = 30;
  int startTime = 0;
  int currentDuration = 0;
  int frameDuration = 1 + 1000 / fps;

  while(engine->GetCurrentGameState() == RUNNING){
    
    //Get milliseconds since start of game
    startTime = SDL_GetTicks(); 

    //Meat of the Game Loop
    engine->HandleEvents();
    engine->UpdateMechanics();
    engine->Render();

    //Limit FPS
    currentDuration = SDL_GetTicks() - startTime;
    if (currentDuration < frameDuration){
      SDL_Delay(frameDuration - currentDuration);
    }
  }

  delete engine;
  
  return 0; 
}