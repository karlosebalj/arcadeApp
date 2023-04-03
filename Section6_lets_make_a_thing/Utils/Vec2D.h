

#ifndef UTILS_VEC2D_H_
#define UTILS_VEC2D_H_

#include <iostream>
#include <ostream>
#include <string>

class Vec2D {
 public:
  Vec2D() : Vec2D(0, 0) {}
  Vec2D(float x, float y) : mX(x), mY(y) {}

  inline void SetX(float x) { mX = x; }
  inline void SetY(float y) { mY = y; }
  inline float GetX() const { return mX; }
  inline float GetY() const { return mY; }

  void Display() const {
    std::cout << "X: " << mX << ", Y: " << mY << std::endl;
  }

  friend std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec);
  bool operator==(const Vec2D& vec2) const;
  bool operator!=(const Vec2D& vec2) const;

  Vec2D operator-() const;

 private:
  float mX;
  float mY;
};

#endif /* UTILS_VEC2D_H_ */