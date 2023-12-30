#include "Vec2D.hpp"
#include <cmath>

bool Vec2d::operator==(const Vec2d &vec) const {
  return (x == vec.x && y == vec.y);
}

bool Vec2d::operator!=(const Vec2d &vec) const {
  return (x != vec.x || y != vec.y);
}

Vec2d Vec2d::operator+(const Vec2d &vec) const {
  return Vec2d(x + vec.x, y + vec.y);
}

Vec2d Vec2d::operator-(const Vec2d &vec) const {
  return Vec2d(x - vec.x, y - vec.y);
}

Vec2d Vec2d::operator*(const float val) const {
  return Vec2d(x * val, y * val);
}

Vec2d Vec2d::operator/(const float val) const {
  return Vec2d(x / val, y / val);
}

void Vec2d::operator+=(const Vec2d &vec) {
  x += vec.x;
  y += vec.y;
}

void Vec2d::operator-=(const Vec2d &vec) {
  x -= vec.x;
  y -= vec.y;
}

void Vec2d::operator*=(const float val) {
  x *= val;
  y *= val;
}

void Vec2d::operator/=(const float val) {
  x /= val;
  y /= val;
}

float Vec2d::getDistance(const Vec2d &vec) const {
  return hypot(vec.x - x, vec.y - y);
}
