#include <iostream>

class Point2D {
 public:
  void SetX(int x);
  void SetY(int y);
  int GetX();
  int GetY();
  void Display();

 private:
  int mX;
  int mY;
};

int main() {
  Point2D myPoint;
  std::cout << "size of myPoint is: " << sizeof(myPoint) << std::endl;
  return 0;
}