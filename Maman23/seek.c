#include "seek.h"

FILE* openFile(char* fp);
int getSize(FILE* fp);

int main(int argc, char* argv[]){
	int target, numOfFiles;
	int index, sizeOfFile, charToRead;
	
	/* if argc < 2, we did not receive enough argument and we display an error. */
	if(argc < 2){
		printf("Too little arguments sent");
		return 1;
	}
	
	target = strtol(argv[1], NULL, 10);
	
	/* if target is 0 or negative, the target destination is invalid and we display an error. */
	if(target <= 0){
		printf("Target destination should be bigger than 0!");
		return 1;
	}
	
	numOfFiles = argc - 2;
	index = 2;
	while(numOfFiles > 0){
		/* getting the file pointer */
		FILE* fp = openFile(argv[index++]);
		
		if(fp){
			sizeOfFile = getSize(fp);
		
			if(sizeOfFile < target){
				printf("Number of characters in file is smaller than the argument passed.");
			}
			else{
				fseek(fp, target - 1, SEEK_SET); /* getting the cursor to the spot before the char to read */
				charToRead = fgetc(fp); /* reading the character */
				printf("%d\n", charToRead); /* printing the decimal value of the character */
			}
			fclose(fp); /* if we successfully opened the file, we close it */
		}
		numOfFiles--;
	}
	
	return 0;
}

FILE* openFile(char* fp){
	FILE* temp = fopen(fp, "r");
	
	if(!temp){
		printf("Cannot open file, invalid input");
		return NULL;
	}
	
	return temp;
}

int getSize(FILE* fp){
	fseek(fp, 0, SEEK_END);
	return ftell(fp);
}

