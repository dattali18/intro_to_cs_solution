#include <iostream>
using namespace std;
/*
Daniel Attali
intro to cs 150005
Q6 EX5
this program:
will take two array as an input and will perfem a symmetrical difference between the two
and will output an array with the symmetrical difference as element
*/
void symmetricalDifference(int * set1, int * set2,int * difference, int &size);

int main()
{
    const int SIZE = 6;

    int set1[SIZE];
    int set2[SIZE];
    int difference[SIZE];

    // getting the input from the user
    cout<<"enter first 6 numbers:"<<endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin>>set1[i];
    }

    cout<<"enter next 6 numbers:"<<endl;
    for (int i = 0; i < SIZE; i++)
    {
        cin>>set2[i];
    }
    
    // declaring k because we want to change k in the function but SIZE is a const so it's easyier with a non const
    int k = SIZE;
    // calling the function
    symmetricalDifference(set1, set2, difference, k);

    cout<<"set difference is:"<<endl;

    // print the array and if k (which is the size of difference) is 0 the loop will never start
    for (int i = 0; i < k; i++)
    {
        cout<<difference[i]<<" ";
    }
    // if k = 0 the program will print empty
     if (k == 0)
    {
        cout<<"empty"<<endl;
    }
    return 0;
}

// this function will do the symmetrical difference between two sets (array)
// the function will return void because instad of returning an array we are
// modifying an existing one
void symmetricalDifference(int * set1, int * set2, int * difference, int &size)
{
    int k = 0;
    bool isIn;
    for (int i = 0; i < size; i++)
    {
        isIn = true;
        for (int j = 0; j < size; j++)
        {
            if (set1[i] == set2[j])
            {
               isIn = false;
            } 
        }
        if (isIn)
        {
            difference[k] = set1[i];
            k++;
        }
        
    }
    size = k;
}

/* 
test
[1]:
enter first 6 numbers:
10 2 5 7 3 0
enter next 6 numbers:
1 2 8 9 10 11
set difference is:
10 2 % 
 */