#include <iostream>

class Point2D {
 public:
  void SetX(int x);
  void SetY(int y);
  int GetX();
  int GetY();
  void Display();

 private:
  void MyPrivateMethod();
  int mX;
  int mY;
};

void Point2D::SetX(int x) {
  mX = x;
}

void Point2D::SetY(int y) {
  mY = y;
}

int Point2D::GetX(){
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
  myPoint.SetX(0);
  std::cout << "Size of myPoint is: " << sizeof(myPoint) << std::endl;
  return 0;
}