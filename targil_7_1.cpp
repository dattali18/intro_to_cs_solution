#include <iostream>
using namespace std;

/* 
Daniel Attali
id: 3287890879
Ex 7 Q 1
description:
this program will take a list of ten number in a assending order 
and also will take a number as a input
and will output the index of the number in the list or -1 if it's not in the list
 */

int binarySearch(int *arr, int len, int number);
void inputArray(int *arr, int len);

int main()
{
    const int SIZE = 10;
    bool isComplete = false;
    bool isInOrderOrder;
    int arr[SIZE];
    int temp;
    cout << "Enter 10 numbers:" << endl;
    inputArray(arr, SIZE);

    int number;

    cout << "Enter 1 number:" << endl;

    cin >> number;

    int index = binarySearch(arr, SIZE, number);

    // printing the result

    if (index >= 0)
    {
        cout << "The number " << number << " was found at index " << index << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}

// this function will do a binary search in loop for a number

int binarySearch(int *arr, int len, int number)
{
    int beg = 0;
    int end = len;
    int index = (beg + end) / 2;
    for (int i = 0; i < len + 1; i++)
    {
        if (arr[index] == number)
        {
            return index;
        }
        else if (arr[index] > number)
        {
            end = index;
            index = (beg + end) / 2;
        }
        else
        {
            beg = index;
            index = (beg + end) / 2;
        }
    }
    // if the code exited the loop so it means that the number is not in the list so return -1
    return -1;
}

void inputArray(int *arr, int len)
{
    bool isInOrder = false;
    while (!isInOrder)
    {
        isInOrder = true;

        for (int i = 0; i < len; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] >= arr[i + 1])
            {
                isInOrder = false;
            }
        }
        if (!isInOrder)
        {
            cout << "ERROR" << endl;
        }
    }
}

/* 
test:
{1} : 
Enter 10 numbers:
1 3 5 7 9 11 13 15 17 19
Enter 1 number:
4
Not found

{2}:
Enter 10 numbers:
1 3 5 7 9 11 13 15 17 19
Enter 1 number:
3
The number 3 was found at index 1
 */