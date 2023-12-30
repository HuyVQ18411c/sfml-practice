#include <SFML/Graphics.hpp>

#include "Vec2D.hpp"

class CTransform {
public:
  Vec2d position = {0.0, 0.0};
  Vec2d velocity = {0.0, 0.0};
  float angle = 0;

  CTransform(const Vec2d &position, const Vec2d &velocity, float angle)
      : position(position), velocity(velocity), angle(angle) {}
};

class CShape {
public:
  sf::CircleShape circle;
  CShape(float radius, int points, const sf::Color &fill,
         const sf::Color &outline, float thickness)
      : circle(radius, points) {
    circle.setFillColor(fill);
    circle.setOutlineColor(outline);
    circle.setOutlineThickness(thickness);
    circle.setOrigin(radius, radius);
  }
};

class CCollision {
public:
  float radius = 0;
  CCollision(float r) : radius(r) {}
};

class CScore {
public:
  int score = 0;
  CScore(int score) : score(score) {}
};

class CLifespan {
public:
  int remaining = 0;
  int total = 0;
  CLifespan(int total) : remaining(total), total(total) {}
};

class CInput {
public:
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
  bool shoot = false;

  CInput() = default;
};
