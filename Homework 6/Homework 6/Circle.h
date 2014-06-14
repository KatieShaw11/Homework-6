//
//  Circle.h
//  Homework 6
//
//  Created by katie joy shaw on 6/13/14.
//  Copyright (c) 2014 Katie Shaw. All rights reserved.
//

#ifndef __Homework_6__Circle__
#define __Homework_6__Circle__

#include <iostream>
#include <math.h>
#ifndef CIRCLE_H
#define CIRCLE_H
#define PI 3.14159

    // The Circle Class: Implement the relational operators (<, <=, ==, !=, >, >=) in the Circle class in Listing 10.9, CircleWithMemberFunctions.h, to order the Circle objects according to their radii.

class Circle
{
public:
    Circle();
    Circle(double Radius);
    double getArea() const;
    double getRadius() const;
    void setRadius(double Radius);
    static int getNumberOfObjects();
    
    bool operator<(const Circle &myCircle) const;
    bool operator>(const Circle &myCircle) const;
    bool operator==(const Circle &myCircle) const;
    bool operator<=(const Circle &myCircle) const;
    bool operator>=(const Circle &myCircle) const;
    bool operator!=(const Circle &myCircle) const;

private:
    double radius;
    static int numberOfObjects;
};

#endif //for circle
#endif /* defined(__Homework_6__Circle__) */
