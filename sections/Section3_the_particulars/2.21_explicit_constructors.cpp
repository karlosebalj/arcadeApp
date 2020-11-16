#include <iostream>
#include <string>

class String {
 public:
  explicit String(int n);
  String(const char* p);

  void Display();

 private:
  std::string mStr;
};

String::String(int n)
{
  for (int i = 0; i < n; i++)
  {
    mStr += '0';
  }
}

String::String(const char * p) : mStr(p)
{

}

void String::Display()
{
  std::cout << mStr << std::endl;
}

int main() {
  String myString = String(10);
  myString.Display();
  return 0;
}