#include <iostream>
#include <ostream>
#include <string>

class Vec2D {
 public:
  static const Vec2D Zero;

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

 private:
  float mX;
  float mY;
};

const Vec2D Vec2D::Zero;

std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec) {
  consoleOut << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
  return consoleOut;
}

int main() {
  Vec2D aVec(10, 5);
  Vec2D vec2(5, 10);
  std::cout << aVec << std::endl << vec2;
  return 0;
}
