class Vec2d {
public:
  float x = 0, y = 0;
  Vec2d() = default;
  Vec2d(float x, float y) : x(x), y(y) {}

  bool operator==(const Vec2d &vec) const;
  bool operator!=(const Vec2d &vec) const;

  Vec2d operator+(const Vec2d &vec) const;
  Vec2d operator-(const Vec2d &vec) const;
  Vec2d operator*(const float val) const;
  Vec2d operator/(const float val) const;

  void operator+=(const Vec2d &vec);
  void operator-=(const Vec2d &vec);
  void operator*=(const float val);
  void operator/=(const float val);

  float getDistance(const Vec2d &vec) const;
};
