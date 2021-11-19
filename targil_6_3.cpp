#include <iostream>
using namespace std;
/*
Daniel Attali
intro to cs 150005
Q6 EX3
this program:
will take input from the user till the user input a 0
and store all the value in an array
and than the program will do manupulation on the array
so there is only one copy of each digit
and the program will output the new array and the length of the new array
*/

// declaring the fuction to modify the array
void modifyArray(int * vector, int &size);

// declaring the function to print the array
// was used to debug the program so it's easier to see what the array look like at any point in the code
void printArray(int * vector, int size);

int main()
{
    const int MAX = 100;

    int vector[100];

    // temp is for storing temperately the value that the user entered
    int temp;
    // i store how many value the user entered
    int i = 0;

    // getting the input of the user
    cout<<"enter up to 100  values, to stop enter 0:"<<endl;
    cin>>temp;

    while (temp != 0)
    {
        vector[i] = temp;
        i++;
        cin>>temp;
    }
    // calling the function to modify the array
    modifyArray(vector, i);
    cout<<"the new vector is: "<<endl;
    // printing the new array
    printArray(vector, i);
    cout<<"number of elements:  "<<i<<endl;
    return 0;
}

void modifyArray(int * vector, int &size)
{
    // looping through every element in the vector and checking for any duplicate
    for (int i = 0; i < size; i++)
    {
        // after finding an element that we didn't see till now we loop through the array from that element till the and and
        // erasing every duplicate of that element
        for (int j = i+1; j < size; j++)
        {
            if (vector[i] == vector[j])
            {
                vector[j] = 0;
            }
        }
    }
    // copying the array to a new array which will contain only the element that aren't duplicate
    // and will be in the order without hole in the middle
    int newVector[size];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (vector[i] != 0)
        {
            newVector[k] = vector[i];
            k++;
        }
    }

    // copying the new array beck to the original one
    for (int i = 0; i < k; i++)
    {
        vector[i] = newVector[i];
    }
    // modifying the value of size which in the main function is i the the new size of the array
    size = k;
}

void printArray(int * vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<vector[i]<<" ";
    }
    cout<<endl;
}

/* 
test
[1]
1 5 8 9 5 4 1 2 3 5 1 4 8 9 6 5 0
the new vector is: 
1 5 8 9 4 2 3 6 
number of elements:  8

[2]
1 2 3 4 5 1 2 3 4 5 6 7 23 0
the new vector is: 
1 2 3 4 5 6 7 23 
number of elements:  8
 */