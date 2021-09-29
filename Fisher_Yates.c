// C Program to shuffle a given vector
// Vector code from https://github.com/Mashpoe/c-vector
// compile with the command gcc Fisher_Yates.c vec.c -o Fisher_Yates
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vec.h"

// A utility function to swap to integers
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to print a vector
void printVector (int vec[])
{
    int n = vector_size(vec);
    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);
    printf("\n");
}

 // A function to generate a random permutation of a vector
void randomize ( int vec[])
{   
    int n = vector_size(vec);

    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap vec[i] with the element at random index
        swap(&vec[i], &vec[j]);
    }
}

// Driver program to test above function.
int main()
{
    int* num_vec = vector_create();
    for (int i = 0; i<=10; i++) {
        vector_add(&num_vec, i);
    }
    randomize (num_vec);
    printVector(num_vec);
 
    return 0;
}