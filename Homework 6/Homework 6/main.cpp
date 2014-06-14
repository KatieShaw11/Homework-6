//
//  main.cpp
//  Homework 6
//
//  Created by katie joy shaw on 6/12/14.
//  Copyright (c) 2014 Katie Shaw. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string>
#define SIZE 5 // size of test array for 14.3

#include "Circle.h"
#include "Complex.h"

using namespace std;

void swap(Circle *Array);

int main()
{
    
    
// 13.1
    // Write a program to create a file named Exercise13_1.txt if it does not exist. If it does exist, append new data to it. Write 100 integers created randomly into the file using text I/O. Integers are separated by a space.
    
    cout << "\t13.1 : CREATE A TEXT FILE\n\n";
    
    cout << "Text file created or appended!";
    
    srand (time(NULL));

    ofstream outputFile;

    outputFile.open ("/Users/katidid/Documents/Exercise13_1.txt", fstream::out | fstream::app);
    int integer;
    
    for (int i = 0; i < 100; i++)
    {
        integer = rand() % 1000;
        outputFile << integer << " ";
    }
    
    outputFile.close();
    
// 13.2
    // Write a program that prompts the user to enter a file name and displays the number of charaters in the file.
    
    cout << "\n\n\t13.2 : COUNT CHARACTERS\n\n";

    string filename;
    
    cout << "Enter a file name: " << endl;
    
    getline(cin, filename);
    
    int sumChars = 0;
    char currentChar;
    
    ifstream inputFile(filename);
    
    if (inputFile.fail())
    {
        cout << "File does not exist.";
    }
    else
    {
        while (inputFile >> currentChar)
        {
            cout << currentChar << " ";
            sumChars ++;
        }
    }
    inputFile.close();
    
    cout << "\n\nSum is " << sumChars  << "." << endl;
    
// 13.5
    // Baby name popularity ranking
    
    cout << "\n\n\t13.5 : BABY NAME POPULARITY RANKING\n\n";
    
    string myYear;
    string myGender;
    string myName;
    
    cout << "Enter the year: ";
    getline(cin, myYear);
    
    cout << "\nEnter the gender: ";
    getline(cin, myGender);
    
    cout << "\nEnter the name: ";
    getline(cin, myName);
    
    ifstream babyFile;
    babyFile.open ("/Users/katidid/Documents/BabyNames2013.txt", fstream::in);
    
    string rank;
    string femaleName;
    string maleName;
    
    while (!babyFile.eof())
    {
        babyFile >> rank >> maleName >> femaleName;
        if(myName == femaleName||myName == maleName)
            cout << "The name " << myName << " was ranked " << rank << " in " << myYear << ".\n";
        //cout << rank << " " << maleName << " " << femaleName << endl;
    }


    
// 14.3
    // The Circle Class: Implement the relational operators (<, <=, ==, !=, >, >=) in the Circle class in Listing 10.9, CircleWithMemberFunctions.h, to order the Circle objects according to their radii.
    
    cout << "\n\n\t14.3 : THE CIRCLE CLASS\n\n";
    
    Circle arrayOfCircles[SIZE] = {Circle(5), Circle(18), Circle(2.3), Circle(5), Circle(10.5)};
    
    cout << "Here are the circles in order of index:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Circle [" << i << "]: area of " << arrayOfCircles[i].getArea() << ", radius of " << arrayOfCircles[i].getRadius() << endl;
    }
    
    cout << "\nHere are the circles in order of size (least to greatest):\n";
    
    Circle temp;
    
    for (int i = 0; i < SIZE-1; i++)
    {
        for (int j = SIZE-1; j > 0; j--)
        {
            if (arrayOfCircles[j] < arrayOfCircles[j-1])
            //if (arrayOfCircles[j] >= arrayOfCircles[j-1]) // This worked too!
            {
                temp = arrayOfCircles[j];
                arrayOfCircles[j] = arrayOfCircles[j-1];
                arrayOfCircles[j-1] = temp;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
           cout << "Circle [" << i << "]: area of " << arrayOfCircles[i].getArea() << ", radius of " << arrayOfCircles[i].getRadius() << endl;
    }

    
// 14.7
    // Math: the Complex class:
    
    cout << "\n\n\t14.7 : MATH: THE COMPLEX CLASS\n\n";
    double r1, r2, i1, i2; //real and imaginary components for the complex numbers
    cout << "Enter the first complex number: ";
    cin >> r1 >> i1;
    cout << "\nEnter the secornd complex number: ";
    cin >> r2 >> i2;
    
    Complex num1(r1, i1);
    Complex num2(r2, i2);
    
    Complex num3 = num1.add(num2);

    cout << "\n\n" << num1.toString() << " + " << num2.toString() << " = " << num3.toString();
    num3 = num1.subtract(num2);
    cout << "\n" << num1.toString() << " - " << num2.toString() << " = " << num3.toString();
    num3 = num1.multiply(num2);
    cout << "\n" << num1.toString() << " * " << num2.toString() << " = " << num3.toString();
    num3 = num1.divide(num2);
    cout << "\n" << num1.toString() << " / " << num2.toString() << " = " << num3.toString();

}


