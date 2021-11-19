#include <iostream>

using namespace std;

/*
Daniel Attali
ID: 328780879
Q5 EX1
course: intro to cs 150005
description:
this program:
will take two whole number as an input and will output the area of a rectangle with
those width and height
then the program will take a number as an input and will output the area of a circle
with this radius
my part of the code is to write two function to do the work
*/
// creating the first area function
int area(int height, int width)
{
    return height * width;
}
// creating the seconde area function
float area(int radius)
{
    const float PI = 3.14159;
    return radius * PI;
}
int main()
{
    int length, width;
    float radius;
    cout<<"Enter length and width of the rectangle:"<<endl;
    // getting the input from the user
    cin>>length>>width;
    while (length < 0 || width < 0)
    {
        cout<<"ERROR"<<endl;
        cin>>length>>width;
    }
    
    // outputing the result
    cout<<area(length, width)<<endl;;
    cout<<"Enter radius of the circle:"<<endl;
    // checking the validity of the input
    cin>>radius;
    // checking the validity of the input
    while (radius < 0)
    {
        cout<<"ERROR"<<endl;
        cin>>radius;
    }
    // outputing the result
    cout<<area(radius)<<endl;
    return 0;
}

/*
test:
[1]
Enter length and width of the rectangle:  
2 4
8
Enter radius of the circle: 
1
3.14159

[2]
Enter length and width of the rectangle:  
1
3-
ERROR
2
2
4
Enter radius of the circle: 
4-
ERROR
3
28.2743

*/