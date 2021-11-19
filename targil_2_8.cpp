#include <iostream>

using namespace std;
// שם: דניאל אטלי בן מאיר תז: 328780879
// תרגיל 2 שאלה 8


/*
the program will take two input of the starting hour of a flight and the duration 
of the flight and will output the landing hour of the flight
*/
int main()
{
    int sHour, sMinute, sSeconde;
    int dHour, dMinute, dSeconde;
    int lHour, lMinute, lSeconde;
    // the s is standig for starting
    // the d is standing for duration
    cout<<"enter flight takeoff:"<<endl;
    cin>>sHour>>sMinute>>sSeconde;
    cout<<"enter flight duration:"<<endl;
    cin>>dHour>>dMinute>>dSeconde;
    /*
    apllying the algorithem of converting seconde/minute to base 60
    if the addition of the seconde/minute is greater than 60
    so we are adding 1 to minute/hour and taking the rest and putting it into the landing var
    else we are taking the addition and putting it into the landing var
    */
   lSeconde = (sSeconde + dSeconde) % 60;
   lMinute = (sMinute + dMinute) % 60;
   // adding the remainder of the addition of the seconde by the int division to the minute 
   // because minute and seconde are counted in base 60 
   lMinute += (sSeconde + dSeconde) / 60;
   lHour  = (sHour + dHour) % 24;
   lHour += (sMinute + dMinute) / 60;
   // outputing the result
    cout<<"flight arrival is: "<<lHour<<":"<<lMinute<<":"<<lSeconde<<endl;
    return 0;
}