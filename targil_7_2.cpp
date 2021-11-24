#include <iostream>
using namespace std;

/* 
Daniel Attali
id: 3287890879
Ex 7 Q 2
description:
 */
void initArray(int * vector , int len);
void inputArray(int * vector, int len);
void printArray(int * vector, int len);
void mergeArray(int * vector1, int * vector2, int * vector);

int main()
{
    const int SIZE = 10 + 1;
    int vector1[SIZE];
    int vector2[SIZE];
    int vector3[SIZE];
    int midVector[SIZE * 2];
    int mergedVector[SIZE * 3];

    initArray(vector1, SIZE);
    initArray(vector2, SIZE);
    initArray(vector3, SIZE);
    initArray(midVector, 2 * SIZE);
    initArray(mergedVector,3 * SIZE);

    cout << "Enter values for the first vector:" << endl;
    inputArray(vector1, SIZE - 1);

    cout << "Enter values for the second vector:" << endl;
    inputArray(vector2, SIZE - 1);

    cout << "Enter values for the third vector:" << endl;
    inputArray(vector3, SIZE - 1);

    
    // I will merge the vector in two times
    mergeArray(vector1, vector2, midVector);
    // printArray(midVector, 2 * SIZE);
    mergeArray(vector3, midVector, mergedVector);
    

    cout << "Merged vector is:" << endl;
    int i = 0;
    while (mergedVector[i]) // while the current item is not 0
    {
        cout << mergedVector[i] << " ";
        i++;
    }
    

    return 0;
}

// this function will take an array as an input and will check if the 
// array is in the right order (in our case the order is desending order)
void inputArray(int *arr, int len)
{
    bool isInOrder = false;
    int temp = 1;
    int topIndex;
    while (!isInOrder)
    {
        isInOrder = true;

        for (int i = 0; i < len; i++)
        {
            cin >> temp;
            if (temp) // if temp is not 0
            {
                arr[i] = temp;
            }
            else
            {
                topIndex = i; // so we can check if the array is sorted up to the 0
                break;
            }
            topIndex = len; // if none of the number inputted by the user is 0
        }
        for (int i = 0; i < topIndex - 1; i++)
        {
            if (arr[i] <= arr[i + 1])
            {
                isInOrder = false; // if the array is not in order 
            }
        }
        if (!isInOrder)
        {
            cout << "ERROR" << endl; // printing ERROR if the array is not sorted and the loop will start all over again
        }
    }
}

// init the array by putting 0 in all indices
void initArray(int * vector , int len)
{
    for (int i = 0; i < len; i++)
    {
        vector[i] = 0;
    }
    
}

// this function is for debugging
void printArray(int * vector, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << vector[i] << " ";
    }
    cout << endl;
}


// assuming non of the item in the array is 0 and 0 means NONE or NULL
void mergeArray(int * vector1, int * vector2, int * vector)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (vector1[i] && vector2[j]) // if none of the current items is 0 because in  our case 0 means the array if finnshed
    {
        if (vector1[i] >= vector2[j])
        {
            vector[k] = vector1[i];
            i++;
        }
        else
        {
            vector[k] = vector2[j];
            j++;
        }
        k++;  
    }

    // in the case of one of the array beeing longer than the other
    while (vector1[i])
    {
        vector[k] = vector1[i];
        i++;
        k++;
    }

    while (vector2[j])
    {
        vector[k] = vector2[j];
        j++;
        k++;
    }
}

/* 
test:
[1]:
Enter values for the first vector:
29 28 27 26 25 24 23 22 21 20
Enter values for the second vector:
19 18 17 16 15 14 13 0
Enter values for the third vector:
9 8 7 6 5 4 3 2 0
Merged vector is:
29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 9 8 7 6 5 4 3 2 

[2]:
Enter values for the first vector:
1 2 3 4 5 6 78 9
1 
2
ERROR
10 9 8 7 6 5 4 3 2 1
Enter values for the second vector:
20 19 18 17 16 15 14 13 12 11
Enter values for the third vector:
10 9 8 7 6 5 4 3 2 1
Merged vector is:
20 19 18 17 16 15 14 13 12 11 10 10 9 9 8 8 7 7 6 6 5 5 4 4 3 3 2 2 1 1 
 */