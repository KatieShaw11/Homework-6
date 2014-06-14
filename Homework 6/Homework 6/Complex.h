//
//  Complex.h
//  Homework 6
//
//  Created by katie joy shaw on 6/13/14.
//  Copyright (c) 2014 Katie Shaw. All rights reserved.
//

#ifndef __Homework_6__Complex__
#define __Homework_6__Complex__

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Complex
{
public:
    Complex();
    Complex(double A);
    Complex(double A, double B);
    
    Complex add(const Complex &C) const;
    Complex subtract(const Complex &C) const;
    Complex multiply(const Complex &C) const;
    Complex divide(const Complex &C) const;
    
    string toString() const;
    
    
    //Member
    Complex operator+(const Complex &myCNum) const;
    Complex operator-(const Complex &CNum) const;
    Complex operator*(const Complex &CNum) const;
    Complex operator/(const Complex &CNum) const;
    Complex operator+=(const Complex &CNum);
    Complex operator-=(const Complex &CNum);
    Complex operator*=(const Complex &CNum);
    Complex operator/=(const Complex &CNum);
    double operator[](int index) const;
    Complex operator+() const; //Literally does nothing
    Complex operator-() const; //Changes the sign
    Complex operator++(int dummy);
    Complex operator--(int dummy);
    Complex operator++();
    Complex operator--();
    
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, const Complex&);

private:
    double a;
    double b;
};

//Nonmember

Complex operator+(const Complex &CNum1, const Complex &CNum2);
Complex operator-(const Complex &CNum1, const Complex &CNum2);
Complex operator*(const Complex &CNum1, const Complex &CNum2);
Complex operator/(const Complex &CNum1, const Complex &CNum2);



#endif /* defined(__Homework_6__Complex__) */
