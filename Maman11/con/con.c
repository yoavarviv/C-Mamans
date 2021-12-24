#include "con.h"

/* 
 This function returns whether a given char (namely, ch) is alphanumerical.
*/
int isAlphaNumerical(char ch);

int main() {
    char s1[MAX_LENGTH] = {0}; // Given string.
    char s2[MAX_LENGTH] = {0}; // Result string.
    /*
     * Friendly welcome message and getting user input.
     */
    printf("Hello!\nPlease Enter your string to be shortened:\n");
    printf("Max size: 80 characters\n");
    fgets(s1, 81, stdin);
    contract(s1, s2); // calling our function.
    printf("\nThe original string:\n%s", s1);
    printf("The shortened string:\n%s\n", s2);
}

/*
 * This function is a helper function. It returns zero if the char is alpha-numeric, else it returns one.
 */
int isAlphaNumerical(char ch) {
    return (ch >= 48 && ch < 58) || (ch >= 65 && ch < 91) || (ch >= 97 && ch < 123) ? 0 : 1;
}

/*
 * This function receives a string in s1,
 * and prints the same string in a simplified format in s2.
 */
void contract(char s1[], char s2[]) {
    /*
     * Initializing variables.
     */
    int length = 1;
    int index = 0;
    char startingLetter = s1[0];
    int i;

    /*
     * Main Loop:
     * Checking for each sequence; if there's a sequence, we keep going until we reach its max length -
     * When we do, we add it to s2 in the simplified form.
     * Else, we simply add the characters to s2.
     */
    for (i = 0; i < MAX_LENGTH && s1[i] != '\0'; i++) {
        if (i - 1 >= 0 && s1[i - 1] + 1 == s1[i] && isAlphaNumerical(s1[i - 1]) == 0) {
            length += 1; // If the sequence is valid (including this letter), we increment the length and keep going.
        } 
        else {
            // Else, we must do a few checks:
            if (i != 0) {
                s2[index++] = startingLetter;
                if (length == 2)
                    /*
                     * if i != 0 and length == 2, it is illegal to print it as a sequence,
                     * which is why we add both of the characters.
                    */
                    s2[index++] = s1[i - 1];
                startingLetter = s1[i];
            }
            if (length > 2) {
                // if i != 0 and length > 2, we add the sequence to s2.
                s2[index++] = '-';
                s2[index++] = s1[i - 1];
                startingLetter = s1[i];
            }
            length = 1;
        }
    }
}
