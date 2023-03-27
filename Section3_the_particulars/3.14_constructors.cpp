#include <iostream>

class Point2D {
 public:
  Point2D(int x = 0, int y = 0);
  void SetX(int x);
  void SetY(int y);
  int GetX();
  int GetY();
  void Display();

 private:
  int mX;
  int mY;
};

Point2D::Point2D(int x, int y) {
  mX = x;
  mY = y;
}

void Point2D::SetX(int x) { mX = x; }

void Point2D::SetY(int y) { mY = y; }

int Point2D::GetX() { return mX; }

int Point2D::GetY() { return mY; }

void Point2D::Display() {
  std::cout << "X: " << mX << ", Y: " << mY << std::endl;
}

int main() {
  // Default ways of constructing an object
  // Point2D myPoint(5, 10);
  // Point2D myPoint = Point2D(5, 10);
  // Point2D myPoint = {5, 10};
  Point2D myPoint(5, 10);
  myPoint.Display();
  return 0;
}
