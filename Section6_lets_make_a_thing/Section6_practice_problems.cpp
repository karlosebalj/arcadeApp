#include <iostream>
#include <ostream>


// Create and implement a class called Fraction which will represent a
// fractional number eg. 1/2

// 1. Add const to the methods of your Fraction class that are appropriate
// 2. Create constant static variables in the Fraction class for: a half, a
// third, a fourth and a fifth that we can be used outside of the class
// 3. Does the Fraction class require a copy constructor? Why or why not?
// 4. Implement two new methods on the fraction class called GetNumerator and
// GetDenominator. Make these methods inline.

// Section 6 task: Convert the fraction class to use operators instead of the named methods.

static int FindGreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  }
  return FindGreatestCommonDivisor(b, a % b);
}

class Fraction {
 public:
  static Fraction half;
  static Fraction third;
  static Fraction fourth;
  static Fraction fifth;

  friend void CompareFractions(Fraction frac1, Fraction frac2);
  Fraction() : Fraction(0, 1) {}
  Fraction(int num, int den) : numerator(num), denominator(den) {
    if (den == 0) {
      std::cout << "Error: denominator cannot be zero!" << std::endl;
      numerator = 0;
      denominator = 1;
      return;
    }
  }

  // 3. It does not need a copy constructor explicitly as it defines one
  // implicitly and we do not have any dynamic memory allocation.
  Fraction(const Fraction &other) {
    numerator = other.numerator;
    denominator = other.denominator;
  }

  Fraction operator+(const Fraction& other);
  Fraction operator-(const Fraction& other);
  Fraction operator*(const Fraction& other);
  Fraction operator/(const Fraction& other);


  void Display() {
    if (denominator < 0) {
      denominator *= -1;
      numerator *= -1;
    }
    std::cout << numerator << "/" << denominator << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &os, const Fraction &frac);

  inline int GetNumerator() const { return numerator; }
  inline int GetDenominator() const { return denominator; }

 private:
  int numerator;
  int denominator;

  void Simplify(int &num, int &den) {
    int gcd = FindGreatestCommonDivisor(num, den);
    num /= gcd;
    den /= gcd;
  }
};

Fraction Fraction::operator+(const Fraction &other) {
  int new_numerator = (this->numerator * other.denominator) +
                      (this->denominator * other.numerator);
  int common_denominator = this->denominator * other.denominator;
  Simplify(new_numerator, common_denominator);
  return Fraction(new_numerator, common_denominator);
}

Fraction Fraction::operator-(const Fraction &other) {
  int new_numerator = (this->numerator * other.denominator) -
                      (this->denominator * other.numerator);
  int common_denominator = this->denominator * other.denominator;
  Simplify(new_numerator, common_denominator);
  return Fraction(new_numerator, common_denominator);
}

Fraction Fraction::operator*(const Fraction &other) {
  int new_numerator = this->numerator * other.numerator;
  int common_denominator = this->denominator * other.denominator;
  Simplify(new_numerator, common_denominator);
  return Fraction(new_numerator, common_denominator);
}

Fraction Fraction::operator/(const Fraction &other) {
  int new_numerator = this->numerator * other.denominator;
  int common_denominator = this->denominator * other.numerator;
  Simplify(new_numerator, common_denominator);
  return Fraction(new_numerator, common_denominator);
}

void CompareFractions(Fraction frac1, Fraction frac2) {
  int common_denominator =
      (frac1.denominator * frac2.denominator) /
      FindGreatestCommonDivisor(frac1.denominator, frac2.denominator);
  std::cout << common_denominator << std::endl;
  frac1.numerator = (frac1.numerator * common_denominator) / frac1.denominator;
  frac2.numerator = (frac2.numerator * common_denominator) / frac2.denominator;

  if (frac1.numerator == frac2.numerator) {
    std::cout << "Fractions are equal!" << std::endl;
  } else if (frac1.numerator < frac2.numerator) {
    std::cout << "Fraction 2 is larger" << std::endl;
  } else {
    std::cout << "Fraction 1 is larger" << std::endl;
  }
}

Fraction Fraction::half = Fraction(1, 2);
Fraction Fraction::third = Fraction(1, 3);
Fraction Fraction::fourth = Fraction(1, 4);
Fraction Fraction::fifth = Fraction(1, 5);

std::ostream &operator<<(std::ostream &os, const Fraction &frac) {
  os << frac.numerator << "/" << frac.denominator;
  return os;
}

int main() {
  Fraction frac;
  std::cout << frac << std::endl;

  Fraction frac1(1, 2);
  Fraction frac2(3, 4);

  // frac1.Display();
  // frac2.Display();
  std::cout << frac1 << std::endl;
  std::cout << frac2 << std::endl;

  std::cout << "ADDITION:" << std::endl;
  // 1/2 + 3/4 = 5/4
  Fraction addition = frac1 + frac2;
  // addition.Display();
  std::cout << addition << std::endl;

  Fraction frac3(10, 8);
  int gcd = FindGreatestCommonDivisor(128, 256);
  std::cout << gcd << std::endl;

  std::cout << "SUBSTRACTION:" << std::endl;
  // 1/2 - 3/4 = -1/4
  Fraction substraction = frac1 - frac2;
  // substraction.Display();
  std::cout << substraction << std::endl;

  std::cout << "MULTIPLICATION:" << std::endl;
  // 1/2 * 3/4 = 3/8
  Fraction multiplication = frac1 * frac2;
  // multiplication.Display();
  std::cout << multiplication << std::endl;

  std::cout << "DIVISION:" << std::endl;
  // 1/2 / 3/4 = 2/3
  Fraction division = frac1 / frac2;
  // division.Display();
  std::cout << division << std::endl;

  // // frac6 is lager
  // Fraction frac5(2, 6);
  // Fraction frac6(8, 18);
  // CompareFractions(frac5, frac6);

  // // Fractions are equal
  // Fraction frac7(3, 6);
  // Fraction frac8(5, 10);
  // CompareFractions(frac7, frac8);

  // // Fractions are equal
  // Fraction frac9(2, 3);
  // Fraction frac10(40, 60);
  // CompareFractions(frac9, frac10);

  // Fraction fracZERO(10, 0);
  // fracZERO.Display();
  // std::cout << fracZERO << std::endl;

  // // Fraction::half.Display();
  // // Fraction::third.Display();
  // // Fraction::fourth.Display();
  // // Fraction::fifth.Display();
  // std::cout << Fraction::half << std::endl;
  // std::cout << Fraction::third << std::endl;
  // std::cout << Fraction::fourth << std::endl;
  // std::cout << Fraction::fifth << std::endl;

  return 0;
}