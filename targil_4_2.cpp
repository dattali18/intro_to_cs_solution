#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 4 שאלה 2

// this program will take in two whole number as an input
// !! part of the program is checking the validity of the input
// and than will take in a list of number till on of two condition is true
// [1] the sum of the number inputted is greater than the first number inputted
// [2] the amount of number inputted is equal to the seconde number inputted
int main()
{
    int num1, num2;
    cout<<"enter 2 positive numbers:"<<endl;
    cin>>num1;
    // checking the validity of the first number and looping trough the input till a valid input
    while (num1 < 0)
    {
        cout<<"ERROR"<<endl;
        cin>>num1;
    }
    cin>>num2;
    // checking the validity of the seconde number and looping trough the input till a valid input
    while (num2 < 0)
    {
        cout<<"ERROR"<<endl;
        cin>>num2;
    }
    cout<<"enter a list of numbers:"<<endl;
    int sum = 0;
    int count = 0;
    int list;
    // looping trough the list till on of two condition is reached
    while (sum <= num1 && count < num2)
    {
        cin>>list;
        sum += list; // adding the current number to the sum var
        count++; // incrementing the count var count by one
    }
    // outputing the value of the var sum
    cout<<sum<<endl;
    return 0;
}
// test [1]
/*
enter 2 positive numbers:
-25
ERROR
-10
ERROR
25
2
enter a list of numbers:
2
9
11
*/
// test [2]
/*
enter 2 positive numbers:
-5
ERROR
-2
ERROR
15
6
enter a list of numbers:
5
6
7
18
*/
