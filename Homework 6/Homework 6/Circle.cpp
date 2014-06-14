//
//  Circle.cpp
//  Homework 6
//
//  Created by katie joy shaw on 6/13/14.
//  Copyright (c) 2014 Katie Shaw. All rights reserved.
//

#include "Circle.h"

int Circle:: numberOfObjects = 0;

Circle::Circle()
{
    radius = 0;
    numberOfObjects++;
}

Circle::Circle(double Radius)
{
    radius = Radius;
    numberOfObjects++;
}
double Circle::getArea() const
{
    return PI*radius*radius;
}
double Circle::getRadius() const
{
    return radius;
}
void Circle::setRadius(double Radius)
{
    radius = Radius;
}

int Circle::getNumberOfObjects()
{
    return numberOfObjects;
}





bool Circle::operator<(const Circle &myCircle) const
{
    if (radius < myCircle.radius)
    {
        return true;
    }
    else
        return false;
}

bool Circle::operator>(const Circle &myCircle) const
{
    if (radius > myCircle.radius)
    {
        return true;
    }
    else
        return false;
}

bool Circle::operator==(const Circle &myCircle) const
{
    if (radius == myCircle.radius)
    {
        return true;
    }
    else
        return false;
}

bool Circle::operator<=(const Circle &myCircle) const
{
    if (radius <= myCircle.radius)
    {
        return true;
    }
    else
        return false;
}

bool Circle::operator>=(const Circle &myCircle) const
{
    if (radius >= myCircle.radius)
    {
        return true;
    }
    else
        return false;
}

bool Circle::operator!=(const Circle &myCircle) const
{
    if (radius != myCircle.radius)
    {
        return true;
    }
    else
        return false;
}
