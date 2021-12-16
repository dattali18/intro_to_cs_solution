#include <iostream>
#define NOT_FOUND -1
using namespace std;
/*
Name: Daniel Attali
Id: 328780879
Ex: 9,  Q: 1
This program:
is a program to manage a database of classes
it will give the user choices (to input a number between 0 - 5)
and the program will execute a task accordingly
the program can add data to the database to remove to display etc.
note: the only difference with ex8q2 is the dynamic memory allocation
*/


void newClass(int *& database, int &size, int classNum);
void delClass(int *& database, int &size, int classNum);
int searchClass(int *database, int size, int classNum);
void printCode(int *database, int size, int instituteNum);
void menu(int *database, int &size);
void printAll(int *database, int size);

int main()
{
    int size = 0;
    int* database = new int[size];
    menu(database, size);
//    I wanted to delete the database a t the end, but it gives me a warning, so I put it a comment
//    delete[] database;
    return 0;
}

// this is a new function that use dynamic memory allocation to add new classes into the database
void newClass(int *& database, int &size, int classNum)
{

    // checking if the new class is already in
    for (int i = 0; i < size; ++i) {
        if (database[i] == classNum)
        {
            // if classNum is already in the database we exit the function
            return;
        }
    }
    // creating the new array
    int * newArr = new int[++size];
    // in case of the first item
    // this is here because of the way the compiler initialize a dynamic array to all be 0,
    // so it created problem with my algorithm
    if (size == 1)
    {
        newArr[0] = classNum;
        delete []database;
        database = newArr;
        return;
    }
    // copying all the element into the new array
    for (int i = 0; i < size - 1; ++i) {
        newArr[i] = database[i];
    }
    // putting the new element at the last position
    newArr[size-1] = classNum;
    // sort the newArr
    for (int i = size - 1; i > 0; --i) {
        // if the element to the left it bigger than the new class switch them
        if (newArr[i - 1] > classNum)
        {
            int temp = newArr[i];
            newArr[i] = newArr[i-1];
            newArr[i-1] = temp;

        }
    }
    // deleting the old database
    delete []database;
    // linking to the new database
    database = newArr;
}
// this function is for searching an element inside the database
// if it is in the database it returns the index
// else it returns NOT_FOUND
int searchClass(int *database, int size, int classNum)
{
    int i = 0;
    for (int *p = database; p < database + size; p++, i++)
    {
        if (*p == classNum)
        {
            return i;
        }
    }
    return NOT_FOUND;
}

// this function delete an item from the database
void delClass(int *& database, int &size, int classNum)
{
    // searching for the index of the classNum
    int index = searchClass(database, size, classNum);
    // if the value is NULL so the classNum is not in database we exit the function
    if (index == NOT_FOUND)
    {
        return;
    }
    // creating the newArr
    int * newArr = new int[--size];
    int k = 0;
    // copying every element but the class to the new array
    for (int i = 0; i < size + 1; ++i) {
        if (*(database + i) != classNum)
        {
            *(newArr + k++) = *(database + i);
        }
    }
    // deleting the old database
    delete []database;
    // linking the new database
    database = newArr;
}

// this function will print all the class in the same Institute 'makhon'
void printCode(int *database, int size, int instituteNum)
{
    int temp;
    for (int *ptr1 = database; ptr1 < database + size; ptr1++)
    {
        temp = *ptr1 / 1000;
        if (temp == instituteNum)
        {
            cout << *ptr1 << " ";
        }
    }
    cout << endl;
}

void printAll(int *database, int size)
{
    for (int *ptr1 = database; ptr1 < database + size; ptr1++)
    {
        cout << *ptr1 << endl;
    }
}

// this function take care of all the UI
void menu(int *database, int &size)
{
    enum function
    {
        newClassF,
        delClassF,
        searchClassF,
        printCodeF,
        printAllF,
        exitF
    };
    int choice;
    // flag is for exiting the loop
    bool flag = true;
    // printing the message for the user
    cout << "Enter 0 to add a new classroom." << endl;
    cout << "Enter 1 to delete a hybrid classroom." << endl;
    cout << "Enter 2 to search for a specific classroom." << endl;
    cout << "Enter 3 to print all the classrooms for a specific Machon." << endl;
    cout << "Enter 4 to print all the hybrid classrooms." << endl;
    cout << "Enter 5 to exit." << endl;
    cout << "Enter your choice:" << endl;
    // while the choice is not 5
    while (flag)
    {
        // take the user choice
        cin >> choice;
        int num;
        switch (choice)
        {
            case newClassF: // case 0
                cout << "Enter the code of the classroom to add:" << endl;
                cin >> num;
                // while the input is not correct the program will print an error message and will continue to take the user input num is a 5-digit number
                while (num < 10000 || num > 99999)
                {
                    cout << "ERROR" << endl;
                    cin >> num;
                }
                // calling the function
                newClass(database, size, num);
                printAll(database, size);
                break;
            case delClassF: // case 1
                cout << "Enter the code of the classroom to delete:" << endl;
                cin >> num;
                // while the input is not correct the program will print an error message and will continue to take the user input num is a 5-digit number
                while (num < 10000 || num > 99999)
                {
                    cout << "ERROR" << endl;
                    cin >> num;
                }
                // calling the function
                delClass(database, size, num);
                printAll(database, size);
                break;
            case searchClassF: // case 2
                cout << "Enter the code of the classroom to search for:" << endl;
                cin >> num;
                // while the input is not correct the program will print an error message and will continue to take the user input num is a 5-digit number
                while (num < 10000 || num > 99999)
                {
                    cout << "ERROR" << endl;
                    cin >> num;
                }
                // calling the function
                if (searchClass(database, size, num) != NOT_FOUND) // if the class is in database
                {
                    cout << "Found" << endl;
                }
                else
                {
                    cout << "Not found" << endl;
                }
                break;
            case printCodeF: // case 3
                cout << "Enter the code of the Machon:" << endl;
                cin >> num;
                // while the input is not correct the program will print an error message and will continue to take the user input num is a 2-digit number
                while (num < 10 || num > 99)
                {
                    cout << "ERROR" << endl;
                    cin >> num;
                }
                printCode(database, size, num);
                break;
            case printAllF: // case 4
                printAll(database, size);
                break;
            case exitF: // case 5
                flag = false;
                break;
            default: // in the case of an incorrect input choice
                cout << "ERROR" << endl;
                break;
        }
        if (choice != 5)
        {
            cout << "Enter your next choice:" << endl;
        }
    }
}
/*
 * testing:
Enter 0 to add a new classroom.
Enter 1 to delete a hybrid classroom.
Enter 2 to search for a specific classroom.
Enter 3 to print all the classrooms for a specific Machon.
Enter 4 to print all the hybrid classrooms.
Enter 5 to exit.
Enter your choice:
0
Enter the code of the classroom to add:
10003
10003
Enter your next choice:
0
Enter the code of the classroom to add:
10005
10003
10005
Enter your next choice:
0
Enter the code of the classroom to add:
50003
10003
10005
50003
Enter your next choice:
0
Enter the code of the classroom to add:
10000
10000
10003
10005
50003
Enter your next choice:
0
Enter the code of the classroom to add:
40005
10000
10003
10005
40005
50003
Enter your next choice:
3
Enter the code of the Machon:
10
10000 10003 10005
Enter your next choice:
5
 * */