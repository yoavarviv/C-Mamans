#define SIZE 3

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
 * This function gets the input of the matrix. 
 * It checks validity and returns if it can be a magic square matrix or if the input is invalid. 
 * Time Complexity: O(n)
*/
bool getMatrix(int matrix[SIZE][SIZE], bool *endProgram);
/*
 * This function iterates over the matrix and prints it in format.
*/
void printMatrix(int matrix[SIZE][SIZE]);
/*
 * This function prints the matrix and then
 * prints it's not a magic square matrix.
*/ 
void printNormal(int matrix[SIZE][SIZE]);
/*
 * This function checks if the sums of the rows, cols and diagonals are equal.
 * If so, it returns the true, else, it returns false.
*/
bool checkRowsColsDiagonals(int matrix[SIZE][SIZE]);

