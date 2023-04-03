#include <iostream>
#include <ostream>
#include <string>

#include "Utils/Vec2D.h"

int main() {
  Vec2D aVec(3, 7);

  // Vec2D resultvec = aVec.operator*(3);
  Vec2D resultvec = aVec * 3;
  std::cout << resultvec << std::endl;

  Vec2D resultvec2 = 3 * aVec ;
  std::cout << resultvec2 << std::endl;

  Vec2D a(5,4);
  Vec2D b(6,10);

  std::cout << a + b << std::endl;
  std::cout << a - b << std::endl;

  return 0;
}
