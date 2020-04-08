#include "game.hpp"
#include <iostream>
using namespace std;
Play::Play():
  tetromino_{static_cast<Action::Type>(rand() % 7)},
  moveTime_(SDL_GetTicks())
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    throw std::runtime_error("SDL_Init(SDL_INIT_VIDEO)");
  SDL_CreateWindowAndRenderer(660 / 2, 660, SDL_WINDOW_OPENGL, &window_, &renderer_);
  SDL_SetWindowPosition(window_, 100, 100);
}
Play::~Play(){
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

bool Play::tick(){
  SDL_Event evv;
  if (SDL_WaitEventTimeout(&evv, 225))
  {
    switch (evv.type)
    {
    case SDL_KEYDOWN:
      {
        switch (evv.key.keysym.sym)
        {
        case SDLK_s:
          {
            Action t = tetromino_;
            t.move(0, 1);
            if (!well_.check(t))
              tetromino_ = t;
          }
          break;
        case SDLK_d:
          {
            Action t = tetromino_;
            t.move(1, 0);
            if (!well_.check(t))
              tetromino_ = t;
          }
          break;
        case SDLK_a:
          {
            Action t = tetromino_;
            t.move(-1, 0);
            if (!well_.check(t))
              tetromino_ = t;
          }
          break;
        case SDLK_SPACE:
          {
            Action t = tetromino_;
            t.rotate();
            if (!well_.check(t))
              tetromino_ = t;
          }
          break;
        }
      }
      break;
    case SDL_QUIT:
      return false;
    }
  }
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0x4f);
  SDL_RenderClear(renderer_);
  well_.draw(renderer_);
  tetromino_.draw(renderer_);
  SDL_RenderPresent(renderer_);
  return true;
};
