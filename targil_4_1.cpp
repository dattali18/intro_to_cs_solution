#include <iostream>
#include <stdio.h>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 4 שאלה 1

// this program will use the stdio.h lib to generate random number and will print theme out to the screen
// if the order of the number is sorted a message will appear on the screen and else another message will
// be printed
int main()
{
    int randNumber = 0;
    int oldNumber = 0;
    bool isSorted = true;
    // generting the random number
    for (int i = 0; i < 10; i++)
    {
        oldNumber = randNumber;
        randNumber = rand() % 1000; // genereting a random number between 1 - 1000
        cout<<randNumber<<" ";
        // checking if the order of the number is sorted
        if (randNumber >= oldNumber)
        {
            isSorted = true;
        }
        else
        {
            isSorted = false;
        }
    }
    if (isSorted)
    {
        cout<<"'\nsorted list"<<endl;
    }
    else
    {
        cout<<"\nnot sorted list"<<endl;
    }
    
    return 0;
}

/*
test 1:

807 249 73 658 930 272 544 878 923 709 
not sorted list
*/