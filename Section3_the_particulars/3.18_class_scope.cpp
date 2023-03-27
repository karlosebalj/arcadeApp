#include <iostream>

class A
{
public:
  enum MyEnumType {
    MET_A1 = 0,
    MET_A2,
    MET_A3
  };

  A();
  A(MyEnumType type);
private:
  MyEnumType mMET;
};

A::A() : A(MyEnumType::MET_A1)
{
}

A::A(MyEnumType type) : mMET(type)
{
}

int main() {
  A::MyEnumType type = A::MyEnumType::MET_A3;
  A myA = A(type);
  return 0;
}