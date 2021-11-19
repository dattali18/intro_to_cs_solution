#include <iostream>

using namespace std;
// שם: דניאל אטלי בן מאיר תז: 328780879
// תרגיל 2 שאלה 4

// this program will take two number as an input and will give an output according to the given formula
// formula: c = (5a+3)/(6b+2)
int main()
{
    // creating two var for storing the two whole number input
    int numA, numB;
    // creating a float var to store the result of the formula
    float numC;
    cout<<"enter two numbers: "<<endl;
    // getting the input from the user
    cin>>numA>>numB;
    // assigning the value of the result of the formula into the var numC 
    numC = (float) (5*numA+3)/(6*numB +2);
    // outputing the result
    cout<<"C="<<numC<<endl;
    return 0;
}