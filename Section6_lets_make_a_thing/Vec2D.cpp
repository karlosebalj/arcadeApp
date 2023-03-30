#include "Vec2D.h"
#include "Utils.h"

std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec) {
  consoleOut << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
  return consoleOut;
}

bool Vec2D::operator==(const Vec2D& vec2) const {
  return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
}

bool Vec2D::operator!=(const Vec2D& vec2) const {
  return !(*this == vec2);
}