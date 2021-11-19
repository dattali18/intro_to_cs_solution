#include <iostream>

using namespace std;

/*
Daniel Attali
ID: 328780879
Q5 EX2
course: intro to cs 150005
description:
this program will take a whole number as an input
and will ouput all perfect number smaller than him
and also will output all perfect number smaller than 500
*/
// creating the function perfect
bool perfect(int number)
{
    int sum = 0;
    // looping through every number smaller than number
    for (int i = 1; i < number; i++)
    {
        // checking if number is dividable by i
        if (number % i == 0)
        {
            // adding i to the sum
            sum += i;
        }
    }
    bool condition;
    // if the sum of the deviser of number = number so number is perfect so return true
    // else the number is not perfect and return false
    if(sum == number)
    {
        condition = true;
    }
    else
    {
        condition = false;
    }
    return condition;
}
// creating the function printPerfect
void printPerfect(int number = 500) // the default for number is 500 so if no paramter is past in the function will assign 500 to nubmer
{
    // lopping through every number smaller than nubmer and checking if i is perfect using the perfect fuction
    for (int i = 2; i < number; i++)
    {
        // printing i only if i is perfect
        if(perfect(i))
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int number;
    cout<<"Enter a number:"<<endl;
    // getting the input from the user and checking for the validity of the input
    cin>>number;
    while (number < 0)
    {
        cout<<"ERROR"<<endl;
        cin>>number;
    }
    // printing all the perfect number till number
    printPerfect(number);
    cout<<endl;
    // printing all the perfect number till 500
    printPerfect();
    return 0;
}


/*
test
[1]
Enter a number:
-1
ERROR
20
6 
6 28 496 

[2]
Enter a number:
10000
6 28 496 8128 
6 28 496
*/