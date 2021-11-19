#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 3 שאלה  3


// the program will take two number as an input and an operation
// and will output the solution
int main ()
{
    int num1, num2;
    char operation;
    int result;
    cout<<"enter 2 numbers:"<<endl;
    cin>>num1>>num2;
    cout<<"enter an operator:"<<endl;
    cin>>operation;
    switch (operation)
    {
    case '+':
        cout<<num1<<operation<<num2<<'='<<num1 + num2<<endl;
        break;
    case '-':
        cout<<num1<<operation<<num2<<'='<<num1 - num2<<endl;
        break;
    case '*':
        cout<<num1<<operation<<num2<<'='<<num1 * num2<<endl;
        break;
    case '/':
        cout<<num1<<operation<<num2<<'='<<(float) num1 / num2<<endl;
        break;
    default:
        cout<<"ERROR"<<endl;
        break;
    }
    return 0;
}

// test case:

/*
[1]:
enter 2 numbers:
1
5
enter an operator:
+
1+5=6

[2]:
enter 2 numbers:
2
6
enter an operator:
-
2-6=-4

[3]:
enter 2 numbers:
6
2
enter an operator:
*
6*2=12

[4]:
enter 2 numbers:
6
3
enter an operator:
/
6/3=2

[5]:
enter 2 numbers:
8
4
enter an operator:
)
ERROR
*/