#include <iostream>
#include <vector>

class Obj {
 public:
  Obj(int val) : mMyInt(val), CONSTANT_MEMBER(val) {}

  int GetIntValue() const { return mMyInt; }

  void Display() const {
    // mMyInt = 6;
    std::cout << "mMyInt: " << mMyInt << std::endl;
    std::cout << "CONSTANT_MEMBER: " << CONSTANT_MEMBER << std::endl;
  }

 private:
  int mMyInt;
  const int CONSTANT_MEMBER;
};

int main() {
  return 0;
}