#include "magic.h"

int main(){
    int matrix[SIZE][SIZE] = { 0 };
    bool endProgram = false;
    if(getMatrix(matrix, &endProgram)){ /* True - it is still possible the matrix is a magic square */
        if(checkRowsColsDiagonals(matrix)){
	    /* If the matrix has the same sum for all the rows, cols and diagonals, we print the matrix and the message. */
            printMatrix(matrix);
            printf("is a magic square matrix!\n");
        }
        else{
            /* If the matrix is not a magic square matrix, we print the matrix and print the normal message. */
            printNormal(matrix);
        }
    }
    else if(endProgram){
        /* If the input was invalid, we end the program. */
        printf("\nInput is invalid, ending the program...");
        printf("\nThink about what you did to me.. Timeout time..\n");
        exit(0);
    }
    else{
        /* If the matrix is not a magic square matrix, we print the matrix and print the normal message. */
        printNormal(matrix);
    }

    return 0;
}

/*
 * This function gets the input of the matrix. 
 * It checks validity and returns if it can be a magic square matrix or if the input is invalid. 
 * Time Complexity: O(n)
*/
bool getMatrix(int matrix[SIZE][SIZE], bool *endProgram){
    int i = 0, j = 0, num;
    bool canBeMagic = true;
    int count = 0;
    int res;
    bool contains[SIZE*SIZE] = {0};

    printf("Please enter %2d numbers:\n", SIZE*SIZE);
    while((res = scanf("%d", &num)) != EOF && res != 0){
        count += 1;
        if(i >= SIZE){
            *endProgram = true;
            return false;
        }
        else if(j == SIZE){
            j = 0;
            i += 1;
        }
        if(canBeMagic){
            if(num < 1 || num > SIZE * SIZE){
                canBeMagic = false;
            }
            else if(contains[num - 1]){
            	canBeMagic = false;
            }
            else{
            	 contains[num - 1] = true;
            }
        }
        matrix[i][j++] = num;
    }
    if(count != SIZE * SIZE || res == 0){
        *endProgram = true;
        return false;
    }
    return canBeMagic;
}


/*
 * This function iterates over the matrix and prints it in format.
*/
void printMatrix(int matrix[SIZE][SIZE]){
    int i, j;
    
    printf("\nThe Matrix:\n");
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%6d", matrix[i][j]);
        }
	printf("\n");
    }
}

/*
 * This function prints the matrix and then
 * prints it's not a magic square matrix.
*/ 
void printNormal(int matrix[SIZE][SIZE]){
    printMatrix(matrix);
    printf("is not a magic square matrix.\n");
    exit(0);
}

/*
 * This function checks if the sums of the rows, cols and diagonals are equal.
 * If so, it returns the true, else, it returns false.
*/
bool checkRowsColsDiagonals(int matrix[SIZE][SIZE]){
    /* First, we get the sum of the first row and check if it's equal to the sum of each of the other rows, columns and diagonals */
    int firstRowSum = 0, sumRow = 0, sumCol = 0, firstDiagonalSum = 0, secondDiagonalSum = 0;
    int i, j;
    
    for(j = 0; j < SIZE; j++){
        firstRowSum += matrix[0][j];
    }

    for(i = 0; i < SIZE; i++){
    	firstDiagonalSum += matrix[i][i];
	secondDiagonalSum += matrix[i][SIZE - 1 - i];
        for(j = 0; j < SIZE; j++){
            sumRow += matrix[i][j];
            sumCol += matrix[j][i];
        }
        if(sumRow != firstRowSum || sumCol != firstRowSum){
            return 0;
        }
	sumRow = 0;
	sumCol = 0;
    }
    return firstRowSum == firstDiagonalSum && firstRowSum == secondDiagonalSum ? true : false;
}



