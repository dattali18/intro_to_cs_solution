#include <iostream>

using namespace std;
// תז 328780879 דניאל אטלי קורס מבוא למדעי המחשב
// תרגיל 3 שאלה 6

// declaring the enum
enum MONTH {
        JAN = 31,
        FEB = 28,
        MARCH = 31,
        APRIL = 30,
        MAY = 31,
        JUNE = 30,
        JULY = 31,
        AUG = 31,
        SEPT = 30,
        OCT = 31,
        NOV = 30,
        DEC = 31
};

int main()
{
    int number;
    cout<<"enter a number: "<<endl;
    
    cin>>number;
    MONTH choice;
    // applying the switch statement
    switch (number)
    {
    case 1:
        choice = JAN;
        break;
    case 2:
        choice = FEB;
        break;
     case 3:
        choice = MARCH;
        break;
    case 4:
        choice = APRIL;
        break; 
    case 5:
        choice = MAY;
        break; 
    case 6:
        choice = JUNE;
        break;
    case 7:
        choice = JULY;
        break; 
    case 8:
        choice = AUG;
        break;
    case 9:
        choice = SEPT;
        break; 
    case 10:
        choice = OCT;
        break; 
    case 11:
        choice = NOV;
        break;
    case 12:
        choice = DEC;
        break;                                         
    default:
        break;
    }
    cout<<choice<<" days in the month"<<endl;
    return 0;
}

// test case:

/*
[1]:

*/
