#include "iostream"
using namespace std;
/*
 Name: Daniel Attali
 ID: 328780879
 Ex 11 Q 4
 Description:
 this program will take a number from the user and then will take an array as an input
 and will output the array after a selection sort is perform using a recursive function
*/

void swap(int * a, int i, int j);
void reverse(int*, int);

int main()
{
    int* arr;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    arr = new int[num];
    cout << "Enter array values: ";
    for (int i = 0; i < num; i++)
        cin >> arr[i];

    cout << "Before: \n";
    for (int i = 0; i < num; i++)
        cout << arr[i] << " ";
    cout << endl;
    reverse(arr, num);
    cout << "After: \n";
    for (int i = 0; i < num; i++)
        cout << arr[i] << " ";
    cout << endl;
    //delete [] arr;
    return 0;
}

// this function swap between two items in an array
void swap(int * a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


// this function reverse an array recursively
void reverse(int * arr, int size)
{
    // the stopping condition is if size is smaller or equal to 1
    if (size <= 1)
    {
        return;
    }
    // swapping the first and last item
    swap(arr, 0, size - 1);
    // calling back the function but moving the pointer by on and size - 2
    reverse(arr + 1, size - 2);
}


/*test
Enter a number: 5
Enter array values: 5 4 3 2 1
Before:
5 4 3 2 1
After:
1 2 3 4 5
*/
