#include "exec.h"

struct complex params[NUM_OF_PARAMS] = {0};

struct{
	char *name;
	void (*func)(struct complex params[], char input[]);
	}cmd[] = {
		{"read_comp", read_comp_exec},
		{"print_comp", print_comp_exec},
		{"add_comp", add_comp_exec},
		{"sub_comp", sub_comp_exec}, 
		{"mult_comp_real", mult_comp_real_exec}, 
		{"mult_comp_img", mult_comp_img_exec}, 
		{"mult_comp_comp", mult_comp_comp_exec}, 
		{"abs_comp", abs_comp_exec}, 
		{"stop", stop_exec},
		{"not_valid", NULL}
	};


int main(){
	int i;
	struct complex params[NUM_OF_PARAMS] = {0};
	
	/* Initializing the parameters */
	for(i = 0; i < NUM_OF_PARAMS; i++){
		params[i].re = 0;
		params[i].im = 0;
	}
	
	printf("Welcome to the complex calculator!\n");
	FOREVER
		executeCommand(params);
	
	return 0;
}

/*
	This function reads the line from the user, and executes the right function if it found a known
	command name. Else, it returns an error.
	parameters:
	params - the complex parameters.
*/
void executeCommand(struct complex params[]){
	char input[MAX_LEN] = {0};
	char command[MAX_LEN] = {0};
	int i, j;
	i = j = 0;
	
	fflush(stdin);
	
	printf("Please enter your command:\n");
	
	if(fgets(input, MAX_LEN, stdin) == NULL){
		fprintf(stderr, "EOF Entered.\n");
		stop();
	}
	
	input[strcspn(input, "\n")] = 0; /* replace the \n with a null terminator */
	
	printf("%s\n", input);
	
	for(; isalpha(input[i]) || input[i] == '_'; i++){
		command[j++] = input[i]; /* get each character of the command */ 
	}
	command[j] = '\0';
	
	/* Loop over each command, and check if it's name is equal to a known command */
	for(i = 0; cmd[i].func != NULL; i++){
		if(strcmp(command, cmd[i].name)==0)
			break;
	}
	
	/* if it isn't, we print an error */
	if(cmd[i].func == NULL){
		fprintf(stderr, "Command does not exist: %s\n", command);
		return;
	}
	
	/* if it is, we call the function that executes the command */
	else (*(cmd[i].func))(params, input);
	
}


