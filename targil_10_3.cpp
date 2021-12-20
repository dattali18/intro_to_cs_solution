#include <iostream>
#include <cstring>
#include <string>
#pragma warning (disable:4996)

#define NOT_FOUND -1

using namespace std;

/*
 Name: Daniel Attali
 ID: 328780879
 Ex 10 Q 3
 Description:
 this program is a program for managing a database of words
 it can add or delete word
 it can print all the data in the database or e selection of it
 etc.
*/

void newStr(char **& lexicon, int & size, char *  newWord);
void delStr(char **& lexicon, int & size, char *  word);
void printAll(char ** lexicon, int size);
int searchStr(char ** lexicon, int size, char *  word);
void printChar(char ** lexicon, int size, char letter);
void cpyStr(const char * source, char * target);
int length(const char * word);
void menu(char ** lexicon, int size);

int main()
{
    int size = 0;
    char ** lexicon = new char * [size];
    menu(lexicon, size);
    delete []lexicon;
    return  0;
}

// this function adds a new word to the lexicon
void newStr(char **& lexicon, int & size, char *  newWord)
{
    // checking if the word is already in the lexicon
    for (int i = 0; i < size; ++i) {
        if (strcmp(lexicon[i], newWord) == 0)
        {
            // exiting the function
            return;
        }
    }
    // creating the new lexicon
    char * word = newWord;
    char ** help = new char * [++size];
    if (size == 1)
    {
        help[0] = word;
        delete []lexicon;
        lexicon = help;
        return;
    }
    // copying all the element into the new array
    for (int i = 0; i < size - 1; ++i) {
        help[i] = lexicon[i];
    }
    help[size - 1] = word;
    // sorting the lexicon
    for (int i = size - 1; i > 0 ; --i) {
        int condition = strcmp(help[i - 1], word);
        if (condition > 0)
        {
            char * temp = help[i];
            help[i] = help[i - 1];
            help[i - 1] = temp;
        }
    }
    delete []lexicon;
    lexicon = help;

}

// this function search for a word inside the lexicon and return the index if it is in and  NOT_FOUND if it isn't in
int searchStr(char ** lexicon, int size, char *  word)
{
    // searching through all the lexicon
    for (int i = 0; i < size; ++i) {
        if (strcmp(lexicon[i], word) == 0)
        {
            return i;
        }
    }
    return NOT_FOUND;
}


// this function delete a word from the lexicon
void delStr(char **& lexicon, int & size, char *  word)
{
    int index = searchStr(lexicon, size,  word);
    if (index == NOT_FOUND)
    {
        // if the word is not in the lexicon we exit the function
        return;
    }
    // creating the new lexicon
    char ** help = new char * [--size];
    int k = 0;
    // copying every element except for word
    for (int i = 0; i < size + 1; ++i) {
        if (strcmp(lexicon[i], word) != 0)
        {
            help[k++] = lexicon[i];
        }
    }
    // deleting the old lexicon
    delete []lexicon;
    lexicon = help;
}

// this function print all the word in the lexicon
void printAll(char ** lexicon, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << *(lexicon + i) << endl;
    }
}

// this function print all the word that starts with the letter 'letter'
void printChar(char ** lexicon, int size, char letter)
{
    for (int i = 0; i < size; ++i) {
        if (lexicon[i][0] == letter)
        {
            cout << lexicon[i] << " ";
        }
    }
    cout << endl;
}

// this function copy the string from the source to the target
void cpyStr(const char * source, char * target)
{
    for (int i = 0; source[i] != '\0'; ++i) {
        target[i] = source[i];
    }
}


// this function give back the length of a string
int length(const char * word)
{
    int i;
    for (i = 0; i < 81 ; i++)
    {
        if (word[i] == '\0')
        {
            return i;
        }

    }
    return -1;
}


// this function manage the all menu option for the program
void menu(char ** lexicon, int size)
{
    enum function{
        newStrF,
        delStrF,
        searchStrF,
        printCharF,
        printAllF,
        exitF
    };
    int choice;
    bool flag = true;
    // while the user as not pressed 5
    while(flag){
        cout << "Enter 0-5:" << endl;
        cin >> choice;
        char word[81];
        char letter;
        int len;
        char * newWord;
        switch (choice)
        {
            case newStrF: // case 0
                cout << "Enter the word:" << endl;
                cin >> word;
                len = length(word) + 1;
                // creating a new word for the lexicon
                newWord = new char[len];
                cpyStr(word, newWord);

                newStr(lexicon, size, newWord);
                printAll(lexicon, size);
                break;
            case delStrF: // case 1
                cout << "Enter the word to delete:" << endl;
                cin >> word;
                delStr(lexicon, size, word);
                printAll(lexicon, size);
                break;
            case searchStrF: // case 2
                cout << "Enter the word to search for:" << endl;
                cin >> word;
                if (searchStr(lexicon, size, word) != NOT_FOUND) // if the function return an index print FOUND
                {
                    cout << "Found" << endl;
                } else { // else the function returned NOT_FOUND, so we print Not found
                    cout << "Not found" << endl;
                }
                break;
            case printCharF: // case 3
                cout << "Enter the char:" << endl;
                cin >> letter ;
                printChar(lexicon, size, letter);
                break;
            case printAllF: // case 4
                printAll(lexicon, size);
                break;
            case exitF: // case 5
                flag = false;
                break;
            default: // in the case of an incorrect input choice
                cout << "ERROR" << endl;
                break;
        }
    }
}
/*
 * test:
Enter 0-5:
0
Enter the word:
print
print
Enter 0-5:
0
Enter the word:
attali
attali
print
Enter 0-5:
0
Enter the word:
name
attali
name
print
Enter 0-5:
1
Enter the word to delete:
name
attali
print
Enter 0-5:
2
Enter the word to search for:
name
Not found
Enter 0-5:
3
Enter the char:
a
attali
Enter 0-5:
4
attali
print
Enter 0-5:
5
 * */