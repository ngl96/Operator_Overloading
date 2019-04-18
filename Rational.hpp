//
//  Rational.hpp
//  rec08
//
//  Created by Nathanael Leyton on 10/25/18.
//  Copyright © 2018 Nathanael Leyton. All rights reserved.
//

#ifndef Rational_hpp
#define Rational_hpp
#include <iostream>
namespace CS2124 {
    class Rational {
        friend std::ostream& operator<<(std::ostream& os, const Rational& rhs);
        friend std::istream& operator>>(std::istream& is, Rational& rhs);
        friend bool operator==(const Rational& lhs, const Rational& rhs);
        friend bool operator<(const Rational& lhs, const Rational& rhs);
    public:
        Rational(int aNumerator = 0, int aDenominator = 1);
        Rational& operator+=(const Rational& rhs);
        Rational& operator++();
        Rational operator++(int dummy);
        // C++ knows to convert numerator to a bool and automatically compares it.
        explicit operator bool() const;
    private:
        int numerator, denominator;
        int greatestCommonDivisor(int x, int y) {
            while (y != 0) {
                int temp = x % y;
                x = y;
                y = temp;
            }
            return x;
        }
        void normalize(){
            int gcd = greatestCommonDivisor(numerator, denominator);
            numerator /= gcd; denominator /= gcd;
            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
        }
    };
    bool operator!=(const Rational& lhs, const Rational& rhs);
    Rational& operator--(Rational& rhs);
    Rational operator--(Rational& lhs, int dummy);
    Rational operator+(const Rational& lhs, const Rational& rhs);
    bool operator<=(const Rational& lhs, const Rational& rhs);
    bool operator>(const Rational& lhs, const Rational& rhs);
    bool operator>=(const Rational& lhs, const Rational& rhs);
}
#endif
