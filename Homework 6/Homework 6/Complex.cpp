//
//  Complex.cpp
//  Homework 6
//
//  Created by katie joy shaw on 6/13/14.
//  Copyright (c) 2014 Katie Shaw. All rights reserved.
//

#include "Complex.h"

Complex::Complex()
{
    a = 0;
    b = 0;
}
Complex::Complex(double A)
{
    a = A;
    b = 0;
}
Complex::Complex(double A, double B)
{
    a = A;
    b = B;
}
Complex Complex::add(const Complex &C) const
{
    double newa = a + C.a;
    double newb = b + C.b;
    Complex newc(newa, newb);
    return newc;
}

Complex Complex::subtract(const Complex &C) const
{
    double newa = a - C.a;
    double newb = b - C.b;
    Complex newc(newa, newb);
    return newc;
}
Complex Complex::multiply(const Complex &C) const
{
    Complex newc((a*C.a - b*C.b), ((a*C.b + b*C.a)));
    return newc;
}
Complex Complex::divide(const Complex &C) const
{
    Complex newc((a*C.a + b*C.b)/(C.a*C.a + C.b*C.b) , (b*C.a - a*C.b)/(C.a*C.a + C.b*C.b));
    return newc;
}

string Complex::toString() const
{
    std::ostringstream s;
    s << "(" << a << " + " << b << "i)"; //Something found online to convert easily to strings
    
    return s.str();
}








Complex Complex::operator+(const Complex &myCNum) const
{
    return add(myCNum);
}
Complex Complex::operator-(const Complex &CNum) const
{
    return subtract(CNum);
}
Complex Complex::operator*(const Complex &CNum) const
{
    return multiply(CNum);

}
Complex Complex::operator/(const Complex &CNum) const
{
    return divide(CNum);

}
Complex Complex::operator+=(const Complex &CNum)
{
    a = a + CNum.a;
    b = b + CNum.b;

    return *this;

}
Complex Complex::operator-=(const Complex &CNum)
{
    a = a - CNum.a;
    b = b - CNum.b;
    
    return *this;
}
Complex Complex::operator*=(const Complex &CNum)
{
    a = a*CNum.a - b*CNum.b;
    b = a*CNum.b + b*CNum.a;
    return *this;
}
Complex Complex::operator/=(const Complex &CNum)
{
    a = (a*CNum.a + b*CNum.b)/(CNum.a*CNum.a + CNum.b*CNum.b);
    b = (b*CNum.a - a*CNum.b)/(CNum.a*CNum.a + CNum.b*CNum.b);
    return *this;
}
double Complex::operator[](int index) const
{
    if (index == 1)
        return b;
    else if (index==0)
        return a;
    else
        return 0;
}
Complex Complex::operator+() const
{
    return Complex(a, b);
}
Complex Complex::operator-() const
{
    return Complex(-a, -b);
}
Complex Complex::operator++(int dummy) //postfix
{
    return Complex(a++, b);
}
Complex Complex::operator--(int dummy) //postfix
{
    return Complex(a--, b);
}
Complex Complex::operator++() //prefix
{
    return Complex(++a, b);

}
Complex Complex::operator--() //prefix
{
    return Complex(--a, b);

}

//Non-members:

Complex operator+(const Complex &CNum1, const Complex &CNum2)
{
    return CNum1.add(CNum2);
}
Complex operator-(const Complex &CNum1, const Complex &CNum2)
{
    return CNum1.add(CNum2);
}
Complex operator*(const Complex &CNum1, const Complex &CNum2)
{
    return CNum1.multiply(CNum2);
}
Complex operator/(const Complex &CNum1, const Complex &CNum2)
{
    return CNum1.divide(CNum2);
}

//BELOW: This code is exactly the format as was in the book, so I don't know why it doesn't work. It comes up with errors claiming that it needs to be a binary rather than a trinary operator.

/*

ostream& Complex::operator<<(ostream& out, const Complex& CNum)
{
    out << CNum.toString();
    return out;
}
istream& Complex::operator>>(istream& in, const Complex& CNum)
{
    cout << "Enter real number: " << endl;
    in >> CNum.a;
    cout << "Enter imaginary number: " << endl;
    in >> CNum.b;
    return in;
}

*/
