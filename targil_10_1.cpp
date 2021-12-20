#include "iostream"
#include "cstring"
#include "string"
#pragma warning (disable:4996)
using namespace std;

/*
 Name: Daniel Attali
 ID: 328780879
 Ex 10 Q 1
 Description:
 this program take a word and cypher it by reversing the value of lower case latter
*/

const char * crypto(char * word);

int main()
{
    char word[80];
    cout << "Enter a string:" << endl;
    cin >> word;
    cout << "After crypto:" << endl;
    cout << crypto(word) << endl;
    return 0;
}

// this function reverse the value of lower case letter
const char * crypto(char * word)
{
    char alphabet[26];
    char * reverse = new char[80];
    // creating an array with the alphabet
    for (int i = 0; i < 26; ++i) {
        alphabet[i] = 97 + i;
    }
    // looping through the word
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] >= 'a' && word[i] <= 'z') // if the current char is a lower case letter
        {
            int temp = word[i] - 97; // for example if word[i] = a so temp = 0 etc.
            reverse[i] = alphabet[26 - 1 - temp]; // pointing to the right place in the alphabet array
        } else {
            reverse[i] = word[i]; // if the letter is not a lower case letter just copy as it
        }
    }
//    delete[] reverse;
    return reverse;
}
/*
 * test:
Enter a string:
bamba
After crypto:
yznyz


Enter a string:
bam?ba
After crypto:
yzn?yz

 Enter a string:
AVRdna
After crypto:
AVRwmz
 */
