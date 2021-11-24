#include <iostream>
using namespace std;

/* 
Daniel Attali
ID: 328780879
Q7 EX3
this program will take a matrix of 10 by 10 item
wich is 100 number inputed
and will output the matrix with the folowing rule
the f(x) = -x axis where i = j will not be change
the bottom triangle below the  -x axis will be sorted row by row
 */

void generate(int matrix[10][10]);
void printArray(int * vec, int len);
void printMatrix(int matrix[10][10], int lenX, int lenY);
void insertionSort(int * vec, int len);
void sortMatrix(int matrix[10][10], int lenX, int lenY);
void inputMatix(int matrix[10][10]);

int main()
{
    int matrix[10][10];

    cout << "Enter the values:" << endl;
    inputMatix(matrix);
    cout << "Before sorted:" << endl;
    printMatrix(matrix, 10, 10);
    sortMatrix(matrix, 10, 10);
    cout << endl;
    cout << "Sorted matrix:" << endl;
    printMatrix(matrix, 10, 10);

    return 0;
}
void generate(int matrix[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
    
}

void inputMatix(int matrix[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

// for debugging
void printArray(int * vec, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    
}
// for debugging
void printMatrix(int matrix[10][10], int lenX, int lenY)
{
    for (int i = 0; i < lenY; i++)
    {
        for (int j = 0; j < lenX; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}

// applying the insrtion sort algorithm
void insertionSort(int * vec, int len)
{
    int current;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        current = vec[i];
        j = i;
        while (j > 0 && current < vec[j - 1])
        {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = current;
    } 
}

// this function is the algorithm to sort the matrix 
// according to the question
void sortMatrix(int matrix[10][10], int lenY, int lenX)
{
    int vector1[45];
    int vector2[45];
    int k = 0;
    int w = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i > j)
            {
                vector1[k] = matrix[i][j];
                k++;
            }
            else if (i < j)
            {
                vector2[w] = matrix[i][j];
                w++;
            }
        }
    }
    insertionSort(vector1, 45);
    insertionSort(vector2, 45);
    k = 0;
    w = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i > j)
            {
                matrix[i][j]  = vector1[k];
                k++;
            }
            else if (i < j)
            {
                matrix[i][j] = vector2[w] ;
                w++;
            }
        }
    }

    
}


/* 
test
Enter the values:
1 11 21 31 41 51 61 71 81 91 2 12 22 32 42 52 62 72 82 92 3 13 23 33 43 53 63 73 83 93 4 14 24 34 44 54 64 74 84 94 5 15 25 35 45 55 65 75 85 95 6 16 26 36 46 56 66 76 86 96 7 17 27 37 47 57 67 77 87 97 8 18 28 38 48 58 68 78 88 98 9 19 29 39 49 59 69 79 89 99 10 20 30 40 50 60 70 80 90 100
Before sorted:
1 11 21 31 41 51 61 71 81 91 
2 12 22 32 42 52 62 72 82 92 
3 13 23 33 43 53 63 73 83 93 
4 14 24 34 44 54 64 74 84 94 
5 15 25 35 45 55 65 75 85 95 
6 16 26 36 46 56 66 76 86 96   
7 17 27 37 47 57 67 77 87 97   
8 18 28 38 48 58 68 78 88 98   
9 19 29 39 49 59 69 79 89 99   
10 20 30 40 50 60 70 80 90 100 

Sorted matrix:
1 11 21 31 41 51 61 71 81 91   
2 12 22 32 42 52 62 72 82 92   
3 13 23 33 43 53 63 73 83 93   
4 14 24 34 44 54 64 74 84 94
5 15 25 35 45 55 65 75 85 95
6 16 26 36 46 56 66 76 86 96
7 17 27 37 47 57 67 77 87 97
8 18 28 38 48 58 68 78 88 98
9 19 29 39 49 59 69 79 89 99
10 20 30 40 50 60 70 80 90 100
 */