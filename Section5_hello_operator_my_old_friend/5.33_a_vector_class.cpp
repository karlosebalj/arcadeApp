#include <iostream>
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

 private:
  float mX;
  float mY;
};

const Vec2D Vec2D::Zero;

int main() {return 0; }
