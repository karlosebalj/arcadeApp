#include <iostream>
#include <vector>

class B {
 public:
  B(int value) : mValue(value) {}
  int Value() { return mValue; }

 private:
  int mValue;
};

int main() {
  std::vector<B> myBVec;
  return 0;
}