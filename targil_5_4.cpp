#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
Daniel Attli
Id: 328780879
Q5 EX4
course: intro to cs 150005
this programe:
will take a number is an input
if the user know what it want the user will enter a number and the program will ouput the nearest bigger prime number to the number
else the program will take a random number and will ouput the nearest bigger prime to the number
*/

// this function will check if a number is prime
// by dividing it with all number samller than the (sqrt(number) + 1) of the number and checking if the remain is 0
// if the remain is 0 so the number is not prime because it's divisalbe by i
// else the number is prime
bool isPrime(int number)
{
    bool condition = true;
    int sqrtOfNum = sqrt(number)+1;
    for (int i = 2; i < sqrtOfNum; i++) // looping thourgh all the number in range of [2, sqrt(number)]
    {
        if (number % i == 0) // checking if the number is divisable by i
        {
            condition = false; // if it's divisable it's not prime
        }
    }
    return condition; // return the condtion
}
// this function finde the bigger than or equal to nearest prime number
int findPrime(int number) 
{
    int biggerPrime = 0;
    int i = number;
    while(biggerPrime == 0) // looping through every number that is bigger or equal to number, note that it will never be an infinit loop because there is always a prime bigger than n
    {
        if(isPrime(i)) // checking if i is a prime
        {
            biggerPrime = i;
        }
        i++;
    }
    return biggerPrime; // returning the prime number, will always work because the loop will not end till it found a prime number
}
int main()
{
    srand(time(NULL)); 
    int number;
    int closePrime;
    cout<<"Enter number of values:"<<endl;
    // getting the input from user
    cin>>number;
    if (number > 0) // checking the input from the user
    {
        closePrime = findPrime(number); // ouputing the nearest prime to the number the user inputed
    }
    else
    {
        int randomNumber = rand() % 91 + 10; // getting a random number in rande [10, 100]
        closePrime = findPrime(randomNumber); // ouputing the nearest prime to the random number
    }
    cout<<"Table size: "<<closePrime<<endl;
}
/*
test:
[1]
Enter number of values:
10
Table size: 11

[2]
Enter number of values:
-1
Table size: 23
*/