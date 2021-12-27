#include "iostream"
using namespace std;

/*
 Name: Daniel Attali
 ID: 328780879
 Ex 11 Q 2
 Description:
 this program will take a number from the user and then will take an array as an input
 and will output the smallest item in that array using a recursive function
*/
int smallest(int*, int);

int main()
{
    int* arr;
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
    cout << "The smallest is: " << arr[smallest(arr, num)] << endl;
    //delete[] arr;
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
/*
 * test
Enter a number:
5
Enter array values: 8 75 4 5 2
The smallest is: 2
 */
