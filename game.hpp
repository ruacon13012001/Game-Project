#pragma once
#include <SDL.h>
#include "runtetris.hpp"
#include "movement.hpp"
class Play{
    public:
      Play();
      ~Play();
      bool tick();
    private:
      Play(const Play &);
      Play &operator=(const Play &);
      SDL_Window *window_;
      SDL_Renderer *renderer_;
      Ahihi well_;
      Action tetromino_;
      uint32_t moveTime_;
      void check(const Action &);
};
