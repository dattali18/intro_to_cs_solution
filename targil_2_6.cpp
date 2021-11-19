#include <iostream>

using namespace std;
// שם: דניאל אטלי בן מאיר תז: 328780879
// שאלה 2 תרגיל 6

/*
this program will take two whole number as an input
and will output:
1) their sum
2) their difference
3) their multiplication
4) their division
*/
int main()
{
    int numA, numB;
    cout<<"enter two numbers:"<<endl;
    cin>>numA>>numB;
    cout<<numA<<"+"<<numB<<"="<<numA+numB<<endl;
    cout<<numA<<"-"<<numB<<"="<<numA-numB<<endl;
    cout<<numA<<"*"<<numB<<"="<<numA*numB<<endl;
    cout<<numA<<"/"<<numB<<"="<<(float)numA/numB<<endl;
    return 0;
}