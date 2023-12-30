#include "War/Game.hpp"
#include <string>

int main(int argc, char *argv[]) {
  Game game(std::string("config.txt"));
  game.run();

  return 0;
}
