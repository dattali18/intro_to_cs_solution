#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 3 שאלה  2


// the program take three number as an input
// first last and number
// if the number is in the between those two number the program will output "between"
// if the number is small than the first the program will output "smaller"
// end if the number is bigger than the last the program will output "bigger"
int main ()
{
    int first, last, number;
    cout<<"enter 3 numbers:"<<endl;    
    cin>>first>>last>>number;
    // apllying the logic of the program
    if (number  >= first && number <= last) // first <= number <= last
    {
        cout<<"between"<<endl;
    }
    else if (number < first) // first > number
    {
        cout<<"smaller"<<endl;
    }
    else // last < number
    {
        cout<<"bigger"<<endl;
    }    
}


// test case:
/*
[1]:
enter 3 numbers:
1
4
3
between

[2]:
enter 3 numbers:
2
6
8
bigger

[3]:
enter 3 numbers:
4
6
1
smaller

*/