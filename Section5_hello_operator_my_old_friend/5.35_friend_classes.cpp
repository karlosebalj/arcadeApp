#include <iostream>
#include <ostream>
#include <string>

class A {
 private:
  float mVal;
  friend class B;
};

class B {
 public:
  B() {}
  void DoSomethingWithA(A& a) {
    a.mVal = 5;
    std::cout << a.mVal << std::endl;
  }
};

int main() {
  A a;
  B b;
  b.DoSomethingWithA(a);
  return 0;
}
