#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 4 שאלה 5

// this program take a number n as an input  
// and output a triangle form with number
int main()
{
    int n;
    cout<<"enter a one digit number:"<<endl;
    cin>>n;
    while (n < 0 )
    {
        cout<<"ERROR"<<endl;
        cin>>n;
    }
    for (int i = 0; i < n; i++)
    {
        // putting the spaces to create the triangle
        for (int k = 0; k < i; k++)
        {
            cout<<"  ";
        }
        // printing the number
        for (int j = n - i; j > 0; j--)
        {
            char tab = (j != 1) ? ',' : ' '; 
            cout<<j<<tab;
        }
        cout<<endl;
    }
    return 0;
    
}

//test [1]
/*
enter a one digit number:
-5
ERROR
5
5,4,3,2,1 
  4,3,2,1 
    3,2,1 
      2,1 
        1 
*/
