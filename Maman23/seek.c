#include "seek.h"

FILE* openFile(char* fp);

int main(int argc, char* argv[]){
	int target, numOfFiles;
	int index, sizeOfFile, charToRead;
	if(argc < 2){
		printf("Too little arguments sent");
		return 1;
	}
	target = strtol(argv[1], NULL, 10);
	
	if(target <= 0){
		printf("Number of file should be bigger than 0!");
		return 1;
	}
	
	numOfFiles = argc - 2;
	index = 2;
	while(numOfFiles > 0){
		FILE* fp = openFile(argv[index++]);
		if(fp){
			fseek(fp, 0, SEEK_END);
			sizeOfFile = ftell(fp);
			if(sizeOfFile < target){
				printf("Number of characters in file is smaller than the argument passed.");
			}S
			else{
				fseek(fp, target - 1, SEEK_SET);
				charToRead = fgetc(fp);
				printf("%c\n", charToRead);
			}
			
			fclose(fp);
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

