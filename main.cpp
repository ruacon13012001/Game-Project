#include "game.hpp"
#include "movement.hpp"
#include <iostream>

int main(int argc, char *argv[]){
  Play game;
  while (game.tick());
}
