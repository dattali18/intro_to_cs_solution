#include <iostream>

using namespace std;

/*
Daniel Attali
ID: 328780879
Q5 EX3
course: intro to cs 150005
description:
this program will take an id number and will calculate using 
an algorithem the last digit of the id and will output the complete id number
*/
// the function for calculating the sum of the digit of a number
int sumDigit(int number)
{
    int sum = 0;
    // looping through every digit in number and adding the digit value to sum
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
int lastDigitID(int IdNumber)
{
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        int nthPlace = (i % 2 == 0) ? 2 : 1; // if nth place is even so the value is 2 if it's odd the value is 1
        int multiplicationWithPlace = (IdNumber% 10) * nthPlace; // multiplying the nth digit of number with the value the corespond to the place
        int sumMultiplication = sumDigit(multiplicationWithPlace); // calculating the sum of the digit of the number above
        sum += sumMultiplication; // adding the sum of the digit to sum
        IdNumber /= 10; // dividing by 10 to pass on to the next digit
    }
    int firstDigit = sum % 10; // taking the first digit of sum
    int differenceWithTen = 10 - firstDigit; // calculating the difference with 10 
    return differenceWithTen; 
    
}
int main()
{
    int idNumber;
    cout<<"Enter your ID"<<endl;
    // getting the input from the user
    cin>>idNumber;
    cout<<"Your full ID is:"<<endl;
    cout<<idNumber<<lastDigitID(idNumber); // outputing the full id
    return 0;

}
/*
test
[1]
Enter your ID
32878087
Your full ID is:
328780879

Enter your ID
12345678 
Your full ID is:
123456782
*/