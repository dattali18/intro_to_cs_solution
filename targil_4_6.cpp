#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 4 שאלה 6

// this program take a number n as an input
// and check if every digit is bigger by one than the digit on his right
// and output YES or NO accordinly
int main()
{
    int n;
    cout<<"enter a number:"<<endl;
    cin>>n;
    // checking the validity of n
    while (n < 0)
    {
        cout<<"ERROR"<<endl;
        cin>>n;
    }
    int currentDigit = n % 10;
    n /= 10;
    int lastDigit;
    bool isSmaller = true;
    // looping through the digit of the number n
    while(n > 0)
    {
        lastDigit = currentDigit;
        currentDigit = n % 10;
        // checking if the condition is false
        if(lastDigit + 1 != currentDigit)
        {
            isSmaller = false;
        }
        n /= 10;
    }
    // outputing the result
    if (isSmaller)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}



// test:

/*
[1]
enter a number:
1234
NO

[2]
enter a number:
1234
NO
*/