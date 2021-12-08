#include <iostream>
#define NOT_FOUND -1
using namespace std;
/*
Name: Daniel Attali
Id: 328780879
Ex: 8,  Q: 2
This program:
is a program to manage a database of classes
it will give the user choices (to input a number between 0 - 5)
and the program will execute a task accordingly
the program can add data to the database to remove to display etc.
*/
void newClass(int *database, int &size, int classNum);
void delClass(int *database, int &size, int classNum);
void printAll(int *database, int size);
int searchClass(int *database, int size, int classNum);
void printCode(int *database, int size, int makhonNum);
void menu(int *database, int &size);

int main()
{
    int const MAX_SIZE = 50;
    int database[MAX_SIZE];
    int size = 0;
    menu(database, size);
    return 0;
}

//  this function will add a class to the database in the right order
void newClass(int *database, int &size, int classNum)
{

    // checking if the new class is already in
    bool isAlreadyIn = false;
    for (int *ptr1 = database; ptr1 < database + size; ptr1++)
    {
        if (*ptr1 == classNum)
        {
            isAlreadyIn = true;
            // if classNum is already in the database we exit the function
            return;
        }
    }
    // finding the place to put the new class
    // by implementing insertion
    // creating a pointer that point at the end of the database
    int *ptr1 = database + size;
    // putting classNum at the end
    *ptr1 = classNum;
    for (ptr1 = database + size; ptr1 > database + 1; ptr1 -= 1)
    {
        // if the current cell content is bigger then classNum we switch them
        if (*(ptr1 - 1) > classNum)
        {
            int temp = *ptr1;
            *ptr1 = *(ptr1 - 1);
            *(ptr1 - 1) = temp;
        }
    }
    // incrementing size by 1
    size++;
}

// this function take a class number as an input and return the index of the class inside the database
// F.Y.I I could have used the binary search but beacause the data base is only 50 max so it's actually faster to use linear search
int searchClass(int *database, int size, int classNum)
{
    for (int i = 0; i < size; i++)
    {
        if (*(database + i) == classNum)
        {
            return i;
        }
    }
    return NOT_FOUND;
}

// this function take a classNum and delete it from the data base
void delClass(int *database, int &size, int classNum)
{
    // searching for the index of the classNum
    int index = searchClass(database, size, classNum);
    // if the value is NULL so the classNum is not in database we exit the function
    if (index == NOT_FOUND)
        return;
    // creating a pointer to the placement of classNum
    int *ptr = database + index;
    *ptr = 0;
    // shifting all the data by 1 cell
    for (ptr = database + index + 1; ptr < database + size; ptr++)
    {
        int temp = *ptr;
        *ptr = *(ptr - 1);
        *(ptr - 1) = temp;
    }
    // decrementing size by 1
    size--;
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

// this function will print all the data in the database
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
            // while the input is not corect the program will print an error mesage and will continue to take the user input num is a 5 digit number
            while (num < 10000 || num > 99999) // todo check the condition for the while loop
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
            // while the input is not corect the program will print an error mesage and will continue to take the user input num is a 5 digit number
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
            // while the input is not corect the program will print an error mesage and will continue to take the user input num is a 5 digit number
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
            // while the input is not corect the program will print an error mesage and will continue to take the user input num is a 2 digit number
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