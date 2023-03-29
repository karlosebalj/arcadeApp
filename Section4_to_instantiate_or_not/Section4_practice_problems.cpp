#include <iostream>

// Create and implement a class called Fraction which will represent a
// fractional number eg. 1/2

// 1. Add const to the methods of your Fraction class that are appropriate
// 2. Create constant static variables in the Fraction class for: a half, a
// third, a fourth and a fifth that we can be used outside of the class
// 3. Does the Fraction class require a copy constructor? Why or why not?
// 4. Implement two new methods on the fraction class called GetNumerator and
// GetDenominator. Make these methods inline.

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

  Fraction add(Fraction other);
  Fraction substract(Fraction other);
  Fraction multiply(Fraction other);
  Fraction divide(Fraction other);

  void Display() {
    if (denominator < 0) {
      denominator *= -1;
      numerator *= -1;
    }
    std::cout << numerator << "/" << denominator << std::endl;
  }

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

Fraction Fraction::add(Fraction other) {
  int new_numerator = (this->numerator * other.denominator) +
                      (this->denominator * other.numerator);
  int common_denominator = this->denominator * other.denominator;
  Simplify(new_numerator, common_denominator);
  return Fraction(new_numerator, common_denominator);
}

Fraction Fraction::substract(Fraction other) {
  int new_numerator = (this->numerator * other.denominator) -
                      (this->denominator * other.numerator);
  int common_denominator = this->denominator * other.denominator;
  Simplify(new_numerator, common_denominator);
  return Fraction(new_numerator, common_denominator);
}

Fraction Fraction::multiply(Fraction other) {
  int new_numerator = this->numerator * other.numerator;
  int common_denominator = this->denominator * other.denominator;
  Simplify(new_numerator, common_denominator);
  return Fraction(new_numerator, common_denominator);
}

Fraction Fraction::divide(Fraction other) {
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

int main() {
  Fraction::half.Display();
  Fraction::third.Display();
  Fraction::fourth.Display();
  Fraction::fifth.Display();

  return 0;
}