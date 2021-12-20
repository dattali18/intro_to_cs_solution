#include "iostream"
#include<cstring>
#include<string>
#pragma warning (disable:4996)

using namespace std;

/*
 Name: Daniel Attali
 ID: 328780879
 Ex 10 Q 2
 Description:
 this program take a sentence and reverse every word in the sentence
*/
const char * reverse(char * string);

int main()
{
    cout << "Enter a string:" << endl;
    char sentence[81];
    // getting the sentence from the user
    cin.getline(sentence,80);
    cout << "After reverse:";
    // printing the reverse sentence
    cout << reverse(sentence) << endl;
}

// this function take a sentence and return and return the same sentence but the word are inverted
// for example hello -> olleh
const char * reverse(char * string)
{
    // creating the new char array for the reversed sentence
    char * reverse = new char[81];
    int last = 0;
    int k = 0;
    // looping for each character in the string
    for (int i = 0; string[i] != '\0'; ++i) {
        // if the current char is a space ' ' we reverse the word back and keeping it reversed
        if (string[i] == ' ' || string[i+1] == '\0')
        {
            for (int j = i; j >= last; --j) { // the first time last = 0, so we are reversing the first word the second time last = i where string[i] = 0 etc.
                reverse[k++] = string[j];
            }
            last = i;
        }
    }
//    delete []reverse
    return reverse;
}

/*
testing
 Enter a string:
This is a silly88 sentence
After reverse: sihT si  a  88yllis ecnetnes


 Enter a string:
my name is daniel
After reverse: ym eman  si leinad
 */

