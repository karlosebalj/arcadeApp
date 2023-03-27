#include <iostream>
#include <string>

class A {
 public:
  A() : A("") {}
  A(const std::string& strVal) : mStrVal(strVal) {}
  ~A() { std::cout << "Destroying: " << mStrVal << std::endl; }

 private:
  std::string mStrVal;
};

class B {
 public:
  B() : mA1("A1"), mA2("A2") {}

 private:
  A mA1;
  A mA2;
};

int main() {
  {
    B myB;
  }
  return 0;
}