#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 3 שאלה 4


// this program will take 3 number as input
// and will output the type of triangle it is

int main()
{
    int side1, side2, side3;
    bool isTriangle;
    cout<<"enter 3 numbers:"<<endl;
    cin>>side1>>side2>>side3;
    // checking if the triangle is possible
    if ((side1+side2) > side3 && (side3+side2) > side1 && (side1+side3) > side2)
    {
        isTriangle = true;
    }
    else
    {
        isTriangle = false;
    }
    // is true
    if (isTriangle)
    {
        if (side1 == side2 && side1 == side3) // checking if the triangle is equilateral
        {
            cout<<"equilateral triangle"<<endl;
        }
        else if (side1 == side2 || side1 == side3 || side2 == side3) // checking if the triangle is isosceles
        {
            cout<<"isosceles triangle"<<endl;
        }
        else // if the triangle is just scalene
        {
            cout<<"scalene triangle"<<endl;
        }
    }
    else
    {
        cout<<"cannot form a triangle"<<endl;
    }
}

// test case:

/*
[1]:
enter 3 numbers:
5
5
5
equilateral triangle

[2]:
enter 3 numbers:
5
7
5
isosceles triangle

[3]:
enter 3 numbers:
3
4
5
scalene triangle

[4]:
enter 3 numbers:
1
7
5
cannot form a triangle

*/