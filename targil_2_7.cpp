#include <iostream>

using namespace std;
// שם: דניאל אטלי בן מאיר תז: 328780879
// תרגיל 2 שאלה 7

// this program will take a three digit number
// and will ouput the sum of the digit
int main()
{
    int number;
    cout<<"enter a three digit number:"<<endl;
    cin>>number;
    int sum = 0;
    // applying the algorithem deconstrecting the number into different digit
    // and adding it to the var sum
    while(number > 0)
    {
        sum += number % 10;
        number = number / 10;
    }
    cout<<"the sum is: "<<sum<<endl;
    return 0;
}