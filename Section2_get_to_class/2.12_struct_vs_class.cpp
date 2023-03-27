#include <iostream>

struct SPoint2D {
  void SetX(int x);
  void SetY(int y);
  int GetX();
  int GetY();
  void Display();
  int mX;
  int mY;
};

class CPoint2D {
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
  SPoint2D structPoint;
  CPoint2D classPoint;
  structPoint.SetX(0);  // works
  classPoint.SetX(0);   // will not work

  return 0;
}