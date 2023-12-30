#include "SFML/Graphics.hpp"

#include "War/Vec2D.hpp"
#include <iostream>

#define W_WIDTH 1200
#define W_HEIGHT 720
#define FPS 60
#define GAME_NAME "Back Office"

int main(int argc, char *argv[]) {
  sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), GAME_NAME);
  window.setFramerateLimit(FPS);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
          window.close();
      }
    }

    window.clear();
    window.display();
  }

  return 0;
}
