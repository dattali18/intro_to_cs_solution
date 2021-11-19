#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 3 שאלה 1

// this program take any number between 10 and 99 and
// if both digit are even the program will output a message and their multiplication
// if both digit are odd the program will output a message and their addition
// if both they are not both even or odd the program will ouput a message
int main()
{
    cout<<"enter a number: "<<endl;
    int number;
    cin>>number;
    // dividing the number into two digit
    int digit1, digit2;
    digit1 = number % 10;
    number /= 10;
    digit2 = number % 10;
    // applying the logic of the program
    if (digit1 % 2 == 0 && digit2 % 2 == 0) // if both are even
    {
        cout<<"even number only "<<endl;
        cout<<digit1*digit2;
    }
    else if (digit1 % 2 == 0 || digit2 % 2 == 0) // if one is even and the other is odd
    {
        cout<<"mixed number "<<endl;
    }
    else // if both are odd
    {
        cout<<"odd number only "<<endl;
        cout<<digit1+digit2;
    }
}
// test case:
/*
[1]:
enter a number: 
21
mixed number

[2]:
enter a number: 
22
even number only
4

[3]:
enter a number: 
33
odd number only
6
*/