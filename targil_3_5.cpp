#include <iostream>
using namespace std;

#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 3 שאלה 5


// the program take three number as an input and will output the sorted list
int main() {
	int num1, num2, num3, smallest, middle, biggest;
	cout << "enter 3 numbers: " << endl;
	cin >> num1 >> num2 >> num3;
    // applying the algorithem for sorting three number
    if (num1 > num2 && num1 > num3)
    {
        biggest = num1;
        if (num2 > num3)
        {
            middle = num2;
            smallest = num3;
        }
        else
        {
            middle = num3;
            smallest = num2;
        }
    }
    else if (num2 > num1 && num2 > num3)
    {
        biggest = num2;
        if (num1 > num3)
        {
            middle = num1;
            smallest = num3;
        }
        else
        {
            middle = num3;
            smallest = num1;
        }
    }
    else
    {
       biggest = num3;
        if (num1 > num2)
        {
            middle = num1;
            smallest = num2;
        }
        else
        {
            middle = num2;
            smallest = num1;
        } 
    }
	cout << smallest << " " << middle << " " << biggest << endl;
	return 0;
}

// test case:
/*
enter 3 numbers: 
2
9
4
2 4 9
*/