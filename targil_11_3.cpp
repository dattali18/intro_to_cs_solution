#include "iostream"
using namespace std;
/*
 Name: Daniel Attali
 ID: 328780879
 Ex 11 Q 3
 Description:
 this program will take a number from the user and then will take an array as an input
 and will output the array after a selection sort is perform using a recursive function
*/

void selectionSort(int * , int );
int smallest(int * arr, int size);

int main() {
    int *arr;
    int num;
    do {
        cout << "Enter a number:" << endl;
        cin >> num;
        if (num <= 0)
            cout << "ERROR" << endl;
    } while (num <= 0);
    arr = new int[num];
    cout << "Enter array values: ";
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    cout << "Before:" << endl;
    for (int i = 0; i < num; ++i) {
        cout << arr[i] << " ";
    }
    selectionSort(arr, num);
    cout << endl << "After:" << endl;
    for (int i = 0; i < num; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    //delete [] arr;
    return 0;
}


// this function will give back the index of the smallest item in an array
int smallest(int * arr, int size)
{
    // the stopping condition is if the array contain only one item, so we return the smallest one which is the item itself
    if (size == 1)
        return 0;
    // calling the function again on the same array, but we moved the pointer by one so now the array is smaller
    int help = smallest(arr + 1, size - 1);
    // if the first item (of the current iteration) is smaller than the smallest item in the last iteration
    // return 0 (the first item) else return the last smallest item
    return (*arr < *(arr + ++help))? 0 : help;
}

// this function will perform the recursive selection sort
void selectionSort(int * arr, int size)
{
    // the stopping condition is if the size of the array is one
    if (size == 1)
        return;
    // using the smallest function to find the smallest item in the array
    int small = smallest(arr, size);
    // checking if the current smallest is smaller than the first item and swapping it
    if (*(arr + small) < *(arr))
    {
        int temp = *(arr + small);
        *(arr + small) = *(arr);
        *(arr) = temp;
    }
    // calling back the function on the array but moving the pointer by one
    selectionSort(arr + 1, size - 1);
}

/*test
Enter a number:
5
Enter array values: 8 7 5 9 2
Before:
8 7 5 9 2
After:
2 5 7 8 9
 * */