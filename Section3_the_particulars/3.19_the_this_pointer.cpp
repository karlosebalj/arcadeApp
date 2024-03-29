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

  Point2D& RefOurselves();
  Point2D* PointerOurselves();

 private:
  int mX;
  int mY;
};

Point2D::Point2D() : Point2D(0, 0) {}

Point2D::Point2D(int x, int y) : mX(x), mY(y) {
  Display(); // implicit
  this->Display();  // explicit: does the same thing
  mX = 0; // implicit
  this->mX = 0;  // explicit: does the same thing as above
}

Point2D& Point2D::RefOurselves() { return *this; }
Point2D* Point2D::PointerOurselves() { return this; }

void Point2D::SetX(int x) { mX = x; }

void Point2D::SetY(int y) { mY = y; }

int Point2D::GetX() { return mX; }

int Point2D::GetY() { return mY; }

void Point2D::Display() {
  std::cout << "X: " << mX << ", Y: " << mY << std::endl;
}

int main() {
  Point2D point(5, 10);

  Point2D& refPoint = point.RefOurselves();
  Point2D* ptrPoint = point.PointerOurselves();

  refPoint.Display();
  ptrPoint->Display();
  std::cout << "Point's address: " << &point
            << " refPoint is referencing: " << &refPoint
            << " ptrPoint is pointing to: " << ptrPoint << std::endl;
  return 0;
}
