#include <iostream>
using namespace std;
/*
Daniel Attali
intro to cs 150005
Q6 EX4
this program:
take 6 floating point (decimal) number and will output the indicies of the number
*/

// declaring the function to print the array
// was used to debug the program so it's easier to see what the array look like at any point in the code
void printArray(float * vector, int size);
void printArray(int * vector, int size);

// this function will find indicies of the array you pass as a parameter
void findIndicies(float * vector, int size);

int main()
{
    const int SIZE = 6;
    float vector[SIZE];

    float temp;
    int i = 0;
    cout<<"enter  6 numbers between 0 and 1:"<<endl;
    // checking the validity of the input and if one of the number is not valid you need to start all over again
    while(i < 6)
    {
        cin>>temp;
        // if an input is not valid
        if (temp > 1 || temp < 0)
        {
            cout<<"ERROR"<<endl;
            // by setting i = 0 the count will start all over
            // and because the loop will continue till i < 6 
            // so if the user don't put 6 consecutive corect input the loop will never end
            i = 0;
        }
        else
        {
            // if the input is correct we put it in the i'th place in the vector (array)
            vector[i] = temp;
            i++;
        } 
    }

    cout<<"sorted indices:"<<endl;
    // calling the function
    findIndicies(vector, SIZE);
    return 0;
}

// this function will find the indicies of a vector
void findIndicies(float * vector, int size)
{
    float smaller;
    // decalaring the array that will store the indicies
    int indicied[size];
    int index;
    // looping through every item in the array
    for (int i = 0; i < size + 1; i++)
    {
        index = 0;
        smaller = 1;
        // taking the smaller as 1 because we know for sure that is the greater number possible in the array
        for (int j = 0; j < size; j++)
        {
            // if the current element in array is smaller than the var smaller so the new smaller element is vector[j]
            // and the most important thing that we know that index is equal j so at the end of the loop we have the indicies
            if (vector[j] < smaller)
            {
                smaller = vector[j];
                index = j;
            }
        }
        // by reassigning the value of vector at index 'index' to one we know that it we no longer be the smallest element because we've allready store is in the array of indicies
        vector[index] = 1;
        indicied[i] = index;
    }


    // print the new array of indicies using a for-range-loop
    // note: this kind of loop only works with c++11 so make sure to use the right one
    for (int i : indicied)
    {
        cout<<i<<" ";
    }
}

void printArray(float * vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<vector[i]<<" ";
    }
    cout<<endl;
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
[1]:
enter  6 numbers between 0 and 1:
0.9 0.05 0.002 0.1 0.14 0
sorted indices:
5 2 1 3 4 0 %

[2];
enter  6 numbers between 0 and 1:
0.9 0.05 0.1 0.4 0.2 0.3
sorted indices:
1 2 4 5 3 0 %   
 */