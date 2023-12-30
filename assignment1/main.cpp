// C++ Libraries
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
// 3rd party Libraries
#include "SFML/Graphics.hpp"

#define W_HEIGHT 720
#define W_WIDTH 1200
#define FPS 60
#define GAME_NAME "Back Office"

class MyCircle : public sf::CircleShape {
public:
  float xVelocity;
  float yVelocity;

  MyCircle(float radius, float initialX, float initialY, float xVelocity,
           float yVelocity, int rColor, int gColor, int bColor)
      : CircleShape(radius), xVelocity(xVelocity), yVelocity(yVelocity) {
    this->setPosition(initialX, initialY);
    this->setFillColor(sf::Color(rColor, gColor, bColor));
  }

  void setBounce() {
    float xCircle = this->getPosition().x;
    float yCircle = this->getPosition().y;

    if (xCircle <= 0.0f || xCircle + this->getRadius() * 2 >= W_WIDTH) {
      this->xVelocity *= -1.0f;
    }

    if (yCircle <= 0.0f || yCircle + this->getRadius() * 2 >= W_HEIGHT) {
      this->yVelocity *= -1.0f;
    }

    this->setPosition(xCircle + this->xVelocity, yCircle + this->yVelocity);
  }
};

std::vector<std::string> splitString(const std::string &targetString,
                                     const char &delimiter) {
  std::vector<std::string> substrings;

  long currentMatchedPos = 0;
  std::string token;

  std::size_t found;
  while ((found = targetString.find(delimiter, currentMatchedPos)) !=
         std::string::npos) {
    token = targetString.substr(currentMatchedPos, found - currentMatchedPos);
    substrings.push_back(token);
    currentMatchedPos = 0;
    currentMatchedPos += found + 1;
  }

  substrings.push_back(targetString.substr(currentMatchedPos));

  return substrings;
}

std::vector<MyCircle> readConfigFile(const std::string &filePath) {
  std::vector<MyCircle> shapes;

  std::ifstream configFile(filePath);

  std::string shapeConfig;
  while (std::getline(configFile, shapeConfig)) {
    std::vector<std::string> configs = splitString(shapeConfig, ' ');
    MyCircle circle(std::stof(configs[1]), std::stof(configs[2]),
                    std::stof(configs[3]), std::stof(configs[4]),
                    std::stof(configs[5]), std::stof(configs[6]),
                    std::stof(configs[7]), std::stof(configs[8]));
    shapes.push_back(circle);
  }
  std::cout << "Objects loaded: " << shapes.size() << std::endl;

  configFile.close();
  return shapes;
}

int main(int argc, char *argv[]) {
  sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), GAME_NAME);
  window.setFramerateLimit(FPS);

  std::vector<MyCircle> circles = readConfigFile("config.txt");
  bool isBounce = true;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
          window.close();
        if (event.key.code == sf::Keyboard::Space)
          isBounce = !isBounce;
      }
    }

    window.clear();

    for (MyCircle &circle : circles) {
      if (isBounce)
        circle.setBounce();
      window.draw(circle);
    }

    window.display();
  }

  return 0;
}
