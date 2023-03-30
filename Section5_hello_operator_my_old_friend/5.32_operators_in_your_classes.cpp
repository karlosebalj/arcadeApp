#include <iostream>
#include <string>

class Student {
 public:
  Student() : Student("", "") {}
  Student(const std::string& firstName, const std::string& lastName)
      : mFristName(firstName), mLastName(lastName) {}

  // bool Equals(const Student& otherStudent) {
  //   return mFristName == otherStudent.mFristName &&
  //          mLastName == otherStudent.mLastName;
  // }

  bool operator==(const Student& otherStudent) {
    return mFristName == otherStudent.mFristName &&
           mLastName == otherStudent.mLastName;
  }

 private:
  std::string mFristName;
  std::string mLastName;
};

int main() {
  Student studentA("John", "Smith");
  Student studentB("Aurthur", "Clark");

  // if (studentA.operator==(studentB)) {
  //   std::cout << "Student A and Student B are the same!" << std::endl;
  // } else {
  //   std::cout << "Student A and Student B are NOT the same!" << std::endl;
  // }

  if (studentA == studentB) {
    std::cout << "Student A and Student B are the same!" << std::endl;
  } else {
    std::cout << "Student A and Student B are NOT the same!" << std::endl;
  }
  return 0;
}
