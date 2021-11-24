#include <iostream>
using namespace std;

/* 
Daniel Attali
id: 3287890879
Ex-7 Q-4
description:
this program will take 10 word of 5 character as an input an will sort it with buble sort
and then will ouput it to the user
*/
void sort(char matrix[10][5], int j, int k);
void printMatrix(char matrix[10][5]);
void inputMatrix(char matrix[10][5]);
void sortWord(char matrix[10][5], int y, int x);
void swapWord(char * word1, char * word2);
void copyWord(char * word1, char * word2);

int main()
{
    char matrix[10][5];
    cout << "Enter 10 words:" << endl;
    inputMatrix(matrix);
    sortWord(matrix, 10, 5);
    cout << "After sorting:" << endl;
    printMatrix(matrix);
    cout << endl;
    return 0;
}
// this function is for printing the matrix to the screen
void printMatrix(char matrix[10][5])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] ;
        }
        
        cout << " ";
    }
}
// this function is for getting the input from the user and checking it for validity
void inputMatrix(char matrix[10][5])
{
    bool flag = false;
    while (!flag)
    {
        flag = true;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> matrix[i][j];
            }
            
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (matrix[i][j] < 97 || matrix[i][j] > 122)
                {
                    flag = false;
                }
            }
        }
        if (!flag)
        {
            cout << "ERROR"<< endl;
        }
    }
}
// this function copy a char arry from word2 to word1
void copyWord(char * word1, char * word2)
{
    for (int i = 0; i < 5; i++)
    {
        word2[i] = word1[i];
    }
}
// this function swap btween two word
// for example if word1 = hello and word2 = me after the swap word1 = me and word2 = hello
void swapWord(char * word1, char * word2)
{
    char temp[5];
    copyWord(word1, temp);
    copyWord(word2, word1);
    copyWord(temp, word2);
}
// this function is part of the bigger function sortWord but it was getting unreadable
void sort(char matrix[10][5], int j, int k)
{
    if (matrix[j][k] > matrix[j + 1][k])
        {
            char word1[5];
            char word2[5];
            // copying the two current word to char arrya
            for (int k = 0; k < 5; k++)
            {
                word1[k] = matrix[j][k];
                word2[k] = matrix[j+1][k];
            }
            // swaping the word using the function
            swapWord(word1, word2);
            // repasting back the word to the matrix
            for (int k = 0; k < 5; k++)
            {
                matrix[j][k] = word1[k];
                matrix[j+1][k] = word2[k];
            }
        }
}
// this function is for sorting a list of word using bubble sort
void sortWord(char matrix[10][5], int y, int x)
{
    int k; // k is the current letter that we are comparing between two words
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y - i - 1; j++)
        {
            // this bit of code is what make the algorithm works
             k = 0;
             // if to word have some letter in common so to see who is comming befor the other you need to look at the next letter
             // so while the letter of both word are equal to and k is smaller than the lngth of the word
             while(matrix[j][k] == matrix[j + 1][k] && k < x)
             {
                 k++;
             }
             // and then do the checking and the swaping of the words in the function sort() 
            sort(matrix, j, k);
        }
    }
}