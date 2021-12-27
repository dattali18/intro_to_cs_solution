#include <iostream>
using namespace std;

/*
 Name: Daniel Attali
 ID: 328780879
 Ex 11 Q 1
 Description:
 this program will take a number from the user and will print a and b using a recursive function
*/
void printABs(int);

int main()
{
    int num;
    cout << "Enter a number:" << endl;
    cin >> num;
    printABs(num);
    return 0;
}

// this function print 'a' and 'b' recursively
void printABs(int num)
{
    if (num == 0)
    {
        return;
    }
    // printing the 'a' as we go down the chain of recursive call
    cout << "a";
    printABs(num - 1);
    // printing the 'b' as we go back up to chain of recursive call

    cout << "b";
}

/*test
Enter a number:
5
aaaaabbbbb
 */
