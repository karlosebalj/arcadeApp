#include "Vec2D.h"
#include "Utils.h"

#include <cassert>
#include <cmath>

std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec) {
  consoleOut << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
  return consoleOut;
}

Vec2D operator*(float scalar, const Vec2D& vec) {
  return vec * scalar;
}

bool Vec2D::operator==(const Vec2D& vec2) const {
  return IsEqual(mX, vec2.mX) && IsEqual(mY, vec2.mY);
}

bool Vec2D::operator!=(const Vec2D& vec2) const {
  return !(*this == vec2);
}

Vec2D Vec2D::operator-() const {
  return Vec2D(-mX, -mY);
}

Vec2D Vec2D::operator*(float scale) const {
  return Vec2D(scale * mX, scale * mY);
}

Vec2D Vec2D::operator/(float scale) const {
  assert(fabsf(scale) > EPSILON);

  return Vec2D(scale / mX, scale / mY);
}

Vec2D Vec2D::operator*=(float scale){
  return *this = *this * scale;
  return *this;
}

Vec2D Vec2D::operator/=(float scale){
  assert(fabsf(scale) > EPSILON);
  *this = *this / scale;
  return *this;
}