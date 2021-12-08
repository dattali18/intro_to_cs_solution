#include <iostream>
using namespace std;

/*
Name: Daniel Attali
Id: 328780879
Ex: 8,  Q: 1
This program:
will take two array as a input
and will ouput a number according to if the small array is in the bigger array and what is the skip
*/
bool isInSkips(int * arr1, int * arr2, int len1, int len2, int skip);
int skips(int * arr1, int * arr2, int len1, int len2);

int main()
{
    const int MAX_SIZE = 80;
    int big[MAX_SIZE];
    int small[MAX_SIZE];
    int sizeBig;
    int sizeSmall;
    // getting the input from the user
    cout << "Enter the size of big:" << endl;
    cin >> sizeBig;
    cout << "Enter " << sizeBig << " numbers:" << endl;
    for (int i = 0; i < sizeBig; ++i) {
        cin >> big[i];
    }
    cout << "Enter the size of small:" << endl;
    cin >> sizeSmall;
    cout << "Enter " << sizeSmall << " numbers:" << endl;
    for (int i = 0; i < sizeSmall; ++i) {
        cin >> small[i];
    }
    // printing the size of the jump 
    // will print -1 if small is not in big in any jump
    cout << "Size of jump:" << endl;
    cout << skips(big, small, sizeBig, sizeSmall) << endl;
    return 0;
}

// check if an arr is contain in the other arr with some known skip
// and return true or false accordingly
bool isInSkips(int * arr1, int * arr2, int len1, int len2, int skip)
{
    bool flag;    
    for (int i = 0; i < len1 - 1; i++)
    {
        flag = true;
        for (int j = 0; j < len2; j++)
        {
            if ( *(arr2 + j) != *(arr1 + i + j * (skip + 1)))
            {
                flag = false;
                break;
            }
            
        }
        if (flag)
        {
            return flag;
        }
    }
    return flag;
}

// this function loop through every number between 0 and the length of big
// and check if small is contained in big with i skips
// and it will return i if found or -1 if small is not in big in any consecutive skips
int skips(int * arr1, int * arr2, int len1, int len2)
{
    for (int i = 0; i < len1; i++)
    {
        if (isInSkips(arr1, arr2, len1, len2, i))
        {
            return i;
        }
    }
    return -1;
}

/* 
test:
[1]
Enter the size of big:
10
Enter 10 numbers:
0 1 2 3 4 5 7 8 9
6
Enter the size of small:
3 
Enter 3 numbers:
0 1 4
Size of jump:
-1

[2]

 */