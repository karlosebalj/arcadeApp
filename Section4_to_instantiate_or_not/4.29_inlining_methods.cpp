#include <iostream>
#include <vector>

class Obj {
 public:
  Obj(int val) : mVal(val) {}

  inline int GetValue() const { return mVal; }

 private:
  int mVal;
};

int main() {
  return 0;
}