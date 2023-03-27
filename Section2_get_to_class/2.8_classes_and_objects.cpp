#include <iostream>

class Point2D {
 public:
  void Set(int dx, int dy);
  void Display();

 private:
  int mX;
  int mY;
};

void Point2D::Set(int dx, int dy) {
  mX = dx;
  mY = dy;
}

void Point2D::Display() {
  std::cout << "X: " << mX << ", Y: " << mY << std::endl;
}

int main() {
  Point2D point;
  point.Set(10, 5);
  point.Display();

  Point2D point2;
  point2.Set(3, 8);
  point2.Display();

  return 0;
}