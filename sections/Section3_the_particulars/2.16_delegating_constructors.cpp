#include <iostream>

class Point2D {
 public:
  Point2D();
  Point2D(int x, int y);
  void SetX(int x);
  void SetY(int y);
  int GetX();
  int GetY();
  void Display();

 private:
  int mX;
  int mY;
};

Point2D::Point2D() : Point2D(0, 0)
{
}

Point2D::Point2D(int x, int y) : mX(x), mY(y)
{
}

void Point2D::SetX(int x) {
  mX = x;
}

void Point2D::SetY(int y) {
  mY = y;
}

int Point2D::GetX() {
  return mX;
}

int Point2D::GetY() {
  return mY;
}

void Point2D::Display() {
  std::cout << "X: " << mX << ", Y: " << mY << std::endl;
}

int main() {
  Point2D myPoint;
  myPoint.Display();
  return 0;
}