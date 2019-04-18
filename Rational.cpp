//  Rational.cpp
//  Created by Nathanael Leyton on 10/25/18.
//  rec08


#include "Rational.hpp"
using namespace std;

namespace CS2124 {
    // Non Member, friend.
    ostream& operator<<(ostream& os, const Rational& rhs) {
        os << rhs.numerator << '/' << rhs.denominator << endl;
        return os;
    }
    istream& operator>>(istream& is, Rational& rhs){
        char slash;
        is >> rhs.numerator >> slash >> rhs.denominator;
        rhs.normalize();
        return is;
    }
    bool operator==(const Rational& lhs, const Rational& rhs) {
        return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
    }
    bool operator<(const Rational& lhs, const Rational& rhs){
        if ( (lhs.numerator * rhs.denominator) < (rhs.numerator * lhs.denominator)) { return true; }
        return false;
    }
    // Member.
    // You have to remove the defaults when doing seperate compilation in the cpp.// This note is for me.
    Rational::Rational(int aNumerator, int aDenominator): numerator(aNumerator), denominator(aDenominator) {
        normalize();
    }
    Rational& Rational::operator+=(const Rational& rhs) {
        if (denominator != rhs.denominator){
            int rhsNum = rhs.numerator;
            numerator *= rhs.denominator;
            rhsNum *= denominator;
            numerator = numerator + rhsNum;
            denominator = denominator * rhs.denominator;
        }
        else { numerator += rhs.numerator; }
        normalize();
        return *this;
    }
    Rational& Rational::operator++(){// pre
        numerator += denominator;
        return *this;
    }
    Rational Rational::operator++(int dummy){//post
        Rational original = *this;
        numerator += denominator;
        return original;
    }
    // C++ knows to convert numerator to a bool and automatically compares it.
    Rational::operator bool() const {return numerator;}
    bool operator!=(const Rational& lhs, const Rational& rhs){
        return !(lhs ==rhs);
    }
    Rational& operator--(Rational& rhs){ // pre
        rhs += -1;
        return rhs;
    }
    Rational operator--(Rational& lhs, int dummy){ // post
        Rational original = lhs;
        lhs += -1;
        //
        return original;
    }
    Rational operator+(const Rational& lhs, const Rational& rhs) {
        Rational result(lhs);
        return result += rhs;
    }
    bool operator<=(const Rational& lhs, const Rational& rhs){
        if (lhs < rhs || lhs == rhs) { return true; }
        return false;
    }
    bool operator>(const Rational& lhs, const Rational& rhs){
        return !(lhs < rhs);
    }
    bool operator>=(const Rational& lhs, const Rational& rhs){
        return ((lhs == rhs) || (lhs > rhs));
    }
}
