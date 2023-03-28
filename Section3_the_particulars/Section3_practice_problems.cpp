#include <iostream>

// Create and implement a class called Fraction which will represent a
// fractional number eg. 1/2

// This class should be able to:
// - Add, Subtract, Multiply, and Divide Fractional numbers together and return
// the result (no changes to the internal data should change for any of these
// methods).The return value for each should be the most simplified version of
// the fraction (eg. 1/2 not 128/256)
// - Have 2 different constructors - a default that takes no arguments and one
// that takes two. The default constructor should call the constructor that
// takes 2 arguments. The default should be 0/1
// - Have a method that compares two fractions to see if they are equal, less
// than or greater than each other.
// - Have a display method that will print the fraction in a formatted manner:
// "1/2"

// The Euclidean algorithm is a simple, efficient and widely used method for
// finding the greatest common divisor (GCD) of two positive integers. The basic
// idea behind the algorithm is to divide the larger number by the smaller
// number, and keep repeating the process until the remainder is 0. At that
// point, the smaller number is the GCD of the two original numbers. Here's how
// it works: Divide the larger number by the smaller number and find the
// remainder. If the remainder is 0, then the smaller number is the GCD. If the
// remainder is not 0, then repeat the process by dividing the smaller number by
// the remainder and finding the new remainder. Continue this process until the
// remainder is 0.

// For example, let's find the GCD of 20 and 8:
// Divide 20 by 8 to get a quotient of 2 and a remainder of 4.
// Divide 8 by 4 to get a quotient of 2 and a remainder of 0.
// Since the remainder is 0, 4 is the GCD of 20 and 8.
static int FindGreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  }
  return FindGreatestCommonDivisor(b, a % b);
}

class Fraction {
 public:
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
  // std::cout << frac1.numerator << " and den 2: " << frac2.numerator << std::endl;

  if (frac1.numerator == frac2.numerator) {
    std::cout << "Fractions are equal!" << std::endl;
  } else if (frac1.numerator < frac2.numerator) {
    std::cout << "Fraction 2 is larger" << std::endl;
  } else {
    std::cout << "Fraction 1 is larger" << std::endl;
  }
}

int main() {
  Fraction frac;
  frac.Display();

  Fraction frac1(1, 2);
  Fraction frac2(3, 4);

  frac1.Display();
  frac2.Display();

  // 1/2 + 3/4 = 5/4
  Fraction addition = frac1.add(frac2);
  addition.Display();

  Fraction frac3(10, 8);
  int gcd = FindGreatestCommonDivisor(128, 256);
  std::cout << gcd << std::endl;

  // 1/2 - 3/4 = -1/4
  Fraction substraction = frac1.substract(frac2);
  substraction.Display();

  // 1/2 * 3/4 = 3/8
  Fraction multiplication = frac1.multiply(frac2);
  multiplication.Display();

  // // 1/2 / 3/4 = 2/3
  Fraction division = frac1.divide(frac2);
  division.Display();

  // frac6 is lager
  Fraction frac5(2, 6);
  Fraction frac6(8, 18);
  CompareFractions(frac5, frac6);

  // Fractions are equal
  Fraction frac7(3, 6);
  Fraction frac8(5, 10);
  CompareFractions(frac7, frac8);

  // Fractions are equal
  Fraction frac9(2, 3);
  Fraction frac10(40, 60);
  CompareFractions(frac9, frac10);

  Fraction fracZERO(10,0);
  fracZERO.Display();

  return 0;
}