#include <iostream>
#include <vector>

class B {
 public:
  B() : B(0, 0.0f) {}

  B(const B& otherB) {
    mInt = 5; //otherB.mInt;
    mFloat = 9.0f; //otherB.mFloat;
  }

  B(int intVal, float floatVal) : mInt(intVal), mFloat(floatVal) {}

  void Display() {
    std::cout << "Int val: " << mInt << ", Float val: " << mFloat << std::endl;
  }

 private:
  int mInt;
  float mFloat;
};

void Func(B b) {
  b.Display();
}

int main() {
  B b;
  b.Display();

  Func(b);
  return 0;
}