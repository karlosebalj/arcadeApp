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
  bool mNewPrivateMember;
};
