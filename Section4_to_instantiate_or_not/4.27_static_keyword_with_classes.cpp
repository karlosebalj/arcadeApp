#include <iostream>
#include <vector>

class B {
 public:
 static int sB;
  B() : mMyInt(0) {
    std::cout << "Constructor called" << std::endl;
  }

  ~B() {
    std::cout << "Destructor called" << std::endl;
  }

  static void PrintStaticMsg() {
    std::cout << "Static method called" << std::endl;
    // std::cout << "I can't print this: " << mMyInt << std::endl;

  }

 private:
  int mMyInt;
};

int B::sB = 10;

int main() {

  // B myBoj;

  // std::cout << "sB: " << myBoj.sB << std::endl;
  // std::cout << "sB: " << B::sB << std::endl;

  static B myB;
  std::cout << "End of main" << std::endl;

  B::PrintStaticMsg();

  return 0;
}