#include <iostream>

using namespace std;
// שם: דניאל אטלי בן מאיר תז: 328780879
// תרגיל 2 שאלה 5


// this program will intervert the value between two var
int main()
{
    int numX, numY, tempBox;
    cout<<"enter two numbers:"<<endl;
    cin>>numX>>numY;
    cout << "x=" << numX << " ,y=" << numY << endl;
    // applying the algorithem for interveting the value of two var
    tempBox = numX;
    numX = numY;
    numY = tempBox;
    cout << "x=" << numX << " ,y=" << numY << endl;
    return 0;
}
