#include <iostream>
using namespace std;
/*
Daniel Attali
intro to cs 150005
Q6 EX1
this program:
take 15 number as an input and store theme in an int array
the program will check if all the number in range of [1, 15]
is in the number sequence that the user inputted
if it's true the program will output 'GOOD'
else it will output 'NOT GOOD'
*/

// this two function are for testing the program
void randomValueArray(int * array, int size);
void printArray(int * array, int size);

// this function check if a number is contained in an array
// and will ouput a bool of true or false
bool containValue(int * array , int contain, int size)
{
    bool isContained = false;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == contain)
        {
            isContained = true;
        }    
    }
    return isContained;
}

// this function loop through an array the is past as a parameter
// and will check the array if it contain every digit from 1 to 15
// using the function convainValue()
// this function will print 'Good' is the array contain all digit
// and print 'NOT GOOD' if it's not
void checkingArray(int * array, int size)
{
    bool condition = true;
    for (int i = 0; i < size; i++)
    {
        if((!containValue(array, i+1, size)))
        {
            condition = false;
        }
    }
    if (condition)
    {
        cout<<"GOOD"<<endl;
    }
    else
    {
        cout<<"NOT GOOD"<<endl;
    } 
}


// apllying and calling all the function above
int main()
{
    // putting the size as a const is better for avoiding problame
    const int SIZE = 15;
    // initializing the array
    int array[SIZE];

    // getting the input from the user
    cout<<"enter 15 numbers"<<endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin>>array[i];
    }
    checkingArray(array, SIZE);
    return 0;
}



/*
test:
[1]
enter 15 numbers
15 8 9 7 1 3 4 2 10 14 6 5 13 12 11
GOOD

[2]
enter 15 numbers
15 8 9 16 1 3 4 2 10 14 6 5 13 12 11
NOT GOOD

*/


// those function are for testing the program
void randomValueArray(int * array, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        srand(i);
        array[i] = rand() % 15 + 1;
    }  
}

void printArray(int * array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<endl;
    }
}