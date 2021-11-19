#include <iostream>
using namespace std;
/*
Daniel Attali
intro to cs 150005
Q6 EX2
this program:
will ask the user to input a number for the size of an array
and then will ask the user to give value for each item in th array
and will repeat for two array
and than the program will check if vector1 contain all of vector2's item in order and how many time
and the program will ouput the amount of times
*/

// declaring a function that check if the vector1 contain all vector2's value in the right order and return how many repetition
int checking(int * vector1, int size1,int * vector2, int size2);

int main()
{
    // declaring the max value of the size of vector1 and vector2
    const int MAX1 = 500;
    const int MAX2 = 100;
    
    // declaring the vector1 and vector2 with max value
    int vector1[MAX1];
    int vector2[MAX2];

    // declaring the size of the vectors which will store the user input
    int size1;
    int size2;

    // getting the user's input for the size of vector1
    cout<<"enter size of first array:"<<endl;
    cin>>size1;
    // checking the validity of the input
    // if the value entered by the user is smaller or equal to 0 or greater than 500
    // printing "ERROR" and wating for another input
    while (size1 <= 0 || size1 > 500)
    {
        cout<<"ERROR"<<endl;
        cin>>size1;
    }
    
    // getting the input for each value of vector1 by the user
    cout<<"enter first array values:"<<endl;
    for (int i = 0; i < size1; i++)
    {
        cin>>vector1[i];
    }
    

    // same as vector1
    cout<<"enter size of second array: "<<endl;
    cin>>size2;
    while (size2 <= 0 || size2 > 100)
    {
        cout<<"ERROR"<<endl;
        cin>>size2;
    }
    

    // same as vector1
    cout<<"enter second array values:"<<endl;
    for (int i = 0; i < size2; i++)
    {
        cin>>vector2[i];
    }

    // calling the function that will check if vector1 contain vector2 and how many times
    int rep = checking(vector1, size1, vector2, size2);
    cout<<"result:"<<rep<<" times"<<endl;
    return 0;
}


// init the function
int checking(int * vector1, int size1, int * vector2, int size2)
{
    // decalring the var that will count how many repetition
    int repetition = 0;


    // looping through every element in vector1 till (size1 - size2 + 1)
    // because after that point there is no repetition because it can't contain all the value of vector2
    for (int i = 0; i <= (size1 - size2); i++)
    {
        // declaring a bool var to check if there is a repetition
        bool contain = true;
        // looping through vector1 and checking if vector[i+j] == vector2[j]
        // and if all of the value in that sequence in vector1 equal the value of vector2
        // so there is a repetition else there isn't one in that sequence
        for (int j = 0; j < size2; j++)
        {
            if(!(vector1[i+j] == vector2[j]))
            {
                contain = false;
            }
        }  
        // adding one to the count only if the value of the var contain is true 
        // which means of the value of the sequence in vector1 equal the value in vector2 in order
        repetition = (contain)? (repetition+1) : repetition; 
    }
    //returning the count
    return repetition;
}

/*
test
[1]:
4
enter first array values:
1 1 1 1
enter size of second array: 
1
enter second array values:
1
4

[2]:
enter size of first array:
-2
ERROR
0
ERROR
600
ERROR
5
enter first array values:
1 1 1 1 1 
enter size of second array: 
2
enter second array values:
1
1
4
*/