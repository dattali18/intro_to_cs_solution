#include <iostream>
#include <cmath>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 4 שאלה 4


// double power(double, int);
// double solution(double, int);


// this program take in two number as an input x and n
// and output the sum of the series ((-1)^(n-1)/(2n-1))(x)^(2n-1)
int main()
{
    int n;
    float x;
    cout<<"enter 2 numbers:"<<endl;
    cin>>x;
    cin>>n;
     // checking the validity of n
    while (n <= 0)
    {
        cout<<"ERROR"<<endl;
        cin>>n;
    }
    // starting the algorithem to apply the formula
    double sum = 0;
    double xPow = 1;
    int one = 1;
    double power = 1;
    for (int i = 1; i <= n; i++)
    {
        // getting the nth power of x
         for (int j = 0; j < (2 * i - 1); j++)
        {
            power *= x;
        }
        // getting the nth power of one by applying the logic that (-1)^n is either 1 or -1
        one = (i % 2 == 0) ? -1 : 1;
        // adding the current item to the sum
        sum += ((double) one / (2*i - 1)) * power;
        power = 1;
    }
    // outputing the sum
    cout<<sum<<endl;
    return 0;
}




// I didn't know if I could use function to divide the algorithem because we didn't learn it yet

// double solution(double x, int n)
// {
//     double sum = 0;
//     double xPow = 1;
//     int one = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         one = (i % 2 == 0) ? -1 : 1;
//         sum += ((double) one / (2*i - 1))*(power(x, 2*i-1));
//     }
//     return sum;
// }

// double power(double x, int n)
// {
//     double nthPower = 1;
//     for (int i = 0; i < n; i++)
//     {
//         nthPower *= x;
//     }
//     return nthPower;
// }
