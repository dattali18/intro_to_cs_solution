#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 4 שאלה 3

// this program take a number n as a input and output the fibonacci sequence till the nth item
int main()
{
    int n;
    cout<<"enter a number:"<<endl;
    cin>>n;
    // checking the validity of the input n
    while (n < 0)
    {
        cout<<"ERROR"<<endl;
        cin>>n;
    }
    if(n == 0)
    {
        cout<<0<<endl;
    }
    else
    {
        int f1 = 0;
        int f2 = 1;
        cout<<f1<<" "<<f2<<" ";
        int fn;
        // applying the double recessivity in the fibonacci sequence
        for (int i = 0; i < n - 1; i++)
        {
            // creating the new fn
            fn = f1 + f2;
            // shifting the f1 and f2 to the next nth
            f1 = f2;
            f2 = fn;
            cout<<fn<<" ";
        }
    }
    
    return 0;
}
//test 1:
/*
enter a number:
9
0 1 1 2 3 5 8 13 21 34
*/

