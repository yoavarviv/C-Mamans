#include "par.h"

void handleSpecial();
void checkClosingBrackets(char c, bool *isBalanced, char *buf, int *nIndex);
void checkCommentsAndString(char c, bool *inComment, bool *inString, int *nIndex);
void checkOpeningBrackets(char c, char *buf, int *nIndex);
void checkSpecialCase(char c, bool *isSpecial, bool *isBalanced, int *curlyCount, int *charCount, char *buf, int *nIndex);
void printResult(bool isBalanced);

int main(){
	printResult(isFileBalanced());
	return 0;
}

void printResult(bool isBalanced){
	printf(isBalanced ? "\nFile is balanced, well done.\n" : "\nFile is unbalanced.\n");
}

bool isFileBalanced(){
	/* Variable declarations and initializations. */
	bool wholeFileBalanced = true;
	char c;
	bool inComment = false, inString = false;
	char buf[MAX_SIZE] = {0};
	int nIndex = 0;
	bool isBalanced = true;
	bool isSpecial = false;
	int curlyCount = 0, charCount = 0;
	
	/* Program's output */
	printf("Hello! Please enter a text to check!\n");
	printf("Please do not enter rows with more than 100 characters!\n");
	
	/* Getting user's input and handling it */
	while(c != EOF && (c = getchar())){
		while(c != '\n' && c != EOF){
			/* First, we'll check comments and strings: */
			checkCommentsAndString(c, &inComment, &inString, &nIndex);
			/* This is for the special cases, we check that the bracket is the only thing in the line: */
			if(c != '\t' && c != ' '){
				charCount += 1;
			}
			
			/* If we're not in a comment or a string, we'll check the following cases:
				1. Closing brackets
				2. Opening brackets
				3. Special case
			*/
			if(!inComment && !inString){
				checkClosingBrackets(c, &isBalanced, &buf[0], &nIndex);
				checkOpeningBrackets(c, &buf[0], &nIndex);
				if(charCount == 1){
					checkSpecialCase(c, &isSpecial, &isBalanced, &curlyCount, &charCount, buf, &nIndex);
					
				}
				if(isSpecial)
					break;
			}
			c = getchar();
		}
		
		/*
			When we're done with the line, we'll check if the line is balanced, 
			print the necessary output and initialize variables again.
		*/
		if(c != EOF){
			if(isBalanced && nIndex == 0)
				printf("\nThis line is balanced\n");
			else
				printf("\nThis line is NOT balanced\n");
				
			/* The whole file is unbalanced if the line is not special, it is unbalanced or if the curlyCount is smaller than 0. */
			wholeFileBalanced = ((!isBalanced && !isSpecial) || curlyCount < 0) ? false : wholeFileBalanced;
			nIndex = 0;
			isBalanced = true;
			isSpecial = false;
			charCount = 0;
		}
	}
	
	/* 
	   Checking if the whole file is balanced and printing accordingly-
	   Final output.
	 */
	if(wholeFileBalanced && curlyCount == 0){
		return true;
	}
	else{
		return false;
	}
}

/*
	In this function we check whether the closing brackets are the correct ones.
	### PARAMETER LIST ###
	c - the character we check.
	isBalanced - a bool representing whether the line is balanced.
	buf - the buffer.
	nIndex - current within the buffer.
*/ 
void checkClosingBrackets(char c, bool *isBalanced, char *buf, int *nIndex){
	/* 
	   Checking closing brackets:
	   For each bracket, if it's closing we check whether the opening one is the last one in the buffer,
	   and update our isBalanced accordingly.
	*/
	if(c == ']'){
		*isBalanced = buf[--(*nIndex)] == '[' ? *isBalanced : false;
	}

	if(c == '}'){
		*isBalanced = buf[--(*nIndex)] == '{' ? *isBalanced : false;
	}

	if(c == ')'){
		*isBalanced = buf[--(*nIndex)] == '(' ? *isBalanced : false;
	}
}

/*
	In this function we check whether we're in a comment or a string or leaving a comment or string.
	### PARAMETER LIST ###
	c - the character we check.
	inComment - a boolean representing whether we're in a comment.
	inString - a boolean representing whether we're in a string.
	nIndex - current within the buffer.
*/ 
void checkCommentsAndString(char c, bool *inComment, bool *inString, int *nIndex){
	/* Checking closing comments: */
	if(*inComment && c == '*'){
		if((c = getchar()) == '/'){
		*inComment = false;
		printf("*/");
		}
		else{
			printf("*%c", c);
		}
		return;
	}
	if(*inComment){
		printf("%c", c);
		return;
	}

	/* Checking closing strings: */
	if(*inString){
		if(c == '\"'){
			printf("\"");
			*inString = false;
		}
		else{
			printf("%c", c);
		}
		return;
	}
	
	/* Checking opening strings: */
	if(c == '\"'){
		*inString = true;
		printf("\"");
		return;
	}

	/* Checking opening comments: */
	if(c == '/'){
		if((c = getchar()) == '*'){
			*inComment = true;
			printf("/*");
		}
		else{
			printf("/%c", c);
		}
		return;
	}
	printf("%c", c);
}

/*
	In this function we're updating our buffer accordingly in case the current character is a bracket.
	### PARAMETER LIST ###
	c - the character we check.
	buf - the buffer.
	nIndex - current within the buffer.
*/ 
void checkOpeningBrackets(char c, char *buf, int *nIndex){
	/* Checking for opening brackets and updating our buffer: */
	if(c == '{' || c == '[' || c == '('){
		buf[(*nIndex)++] = c;	
	}
}

/*
	In this function we're checking for the special cases and handling them accordingly.
	### PARAMETER LIST ###
	c - the character we check.
	isSpecial - a boolean representing whether the line is special.
	isBalanced - a boolean representing whether the line is balanced.
	curlyCount - an int for checking whether the overall curly count (+1 for opening, -1 for closing) is balanced.
	charCount - number of character in the line so far (white-spaces excluded).
	buf - the buffer.
	nIndex - current within the buffer.
*/ 
void checkSpecialCase(char c, bool *isSpecial, bool *isBalanced, int *curlyCount, int *charCount, char *buf, int *nIndex){
	/*
		if the first character of the line is a { or a } we check whether it is the end of the line.
	*/
	if(c == '{'){
		if((c = getchar()) == '\n'){
			/* If it is, we mark it as non-balanced and special, and handle the rest of the variables
			   as needed.
			*/
			*charCount += 1;
			*isSpecial = true;
			*isBalanced = false;
			(*curlyCount)++;
			
			return;
		}
		else{
			/* Else, we increase charCount and perform checks on the next character. */
			*charCount += 1;
			printf("%c", c);
			checkClosingBrackets(c, &(*isBalanced), buf, &(*nIndex));
			checkOpeningBrackets(c, buf, &(*nIndex));
			return;
		}
	}
	else if(c == '}'){
		if((c = getchar()) == '\n'){
			/* If it is, we mark it as non-balanced and special, and handle the rest of the variables
			   as needed.
			*/
			*isSpecial = true;
			(*curlyCount)--;
			*charCount += 1;
			*isBalanced = false;
			
			return;
		}
		else{
			/* Else, we increase charCount and perform checks on the next character. */
			*charCount += 1;
			printf("%c", c);
			checkClosingBrackets(c, &(*isBalanced), buf, &(*nIndex));
			checkOpeningBrackets(c, buf, &(*nIndex));
			return;
		}
	}
}
				


