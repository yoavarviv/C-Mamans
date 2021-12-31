#include "complex.h"
#define FOREVER for(;;)

struct complex params[6] = {0};

void read_comp_exec(struct complex params[], char input[]);
void print_comp_exec(struct complex params[], char input[]);
void add_comp_exec(struct complex params[], char input[]);
void sub_comp_exec(struct complex params[], char input[]);
void mult_comp_real_exec(struct complex params[], char input[]);
void mult_comp_img_exec(struct complex params[], char input[]);
void mult_comp_comp_exec(struct complex params[], char input[]);
void abs_comp_exec(struct complex params[], char input[]);
void stop_exec(struct complex params[], char input[]);


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
	struct complex params[6] = {0};
	
	/* Initializing the parameters */
	for(i = 0; i < NUM_OF_PARAMS; i++){
		params[i].re = 0;
		params[i].im = 0;
	}
	
	FOREVER
		executeCommand(params);
	
	return 0;
}

void executeCommand(struct complex params[]){
	char input[MAX_LEN] = {0};
	char command[MAX_LEN] = {0};
	int i, j;
	i = j = 0;
	
	fflush(stdin);
	if(fgets(input, MAX_LEN, stdin) == NULL){
		fprintf(stderr, "EOF Entered.");
		return;
	}
	
	input[strcspn(input, "\n")] = 0;
	
	for(; isalpha(input[i]) || input[i] == '_'; i++){
		command[j++] = input[i];
	}
	command[j] = '\0';
	
	for(i = 0; cmd[i].func != NULL; i++){
		if(strcmp(command, cmd[i].name)==0)
			break;
	}
	
	if(cmd[i].func == NULL){
		fprintf(stderr, "Command does not exist:%s\n", command);
		return;
	}
	
	else (*(cmd[i].func))(params, input);
	
}

int isValidParam(char param){
	return param == 'A' || param == 'B' || param == 'C' || param == 'D' || param == 'E' || param == 'F';
}

void alertError(char errorMsg[]){
	printf("%s\n", errorMsg);
}

void read_comp_exec(struct complex params[], char input[]){	
	int i = 0, j = 0, paramIndex = 0;
	char number[MAX_LEN];
	double num1, num2;
	char param;
	num1 = num2 = 0;

	for(; isalpha((input)[i]) || (input)[i] == '_'; i++) /* skipping the command */
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param = input[++i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the comma */
	if(input[i] != ',') { 
		alertError("Missing comma"); 
		return; 
	}
	i++;
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the number */
	
	while(isdigit(input[i]) || input[i] == '.' || input[i] == '-') number[j++] = input[i++]; /* getting all the digits of the number. */
	
	number[j] = '\0';
	num1 = atof(number); /* converting to a number */
	if(j == 0){ alertError("Wrong parameters, second parameter should be a number."); return; }
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the comma */
	if(input[i++] != ',') { 
		alertError("Missing comma"); 
		return; 
	}
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the number */
	
	j = 0;
	while(isdigit(input[i]) || input[i] == '.' || input[i] == '-') number[j++] = input[i++];  /* getting all the digits of the number. */
	number[j] = '\0';
	num2 = atof(number); /* converting to a number */
	if(j == 0){ alertError("Wrong parameters, third parameter should be a number."); return; }
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the \n (in case it's valid) */
	if(input[i] != '\n' && input[i] != EOF && input[i] != '\0'){
		alertError("Extraneous text after command.");
		return;
	}
	
	paramIndex =  param - 'A';
	read_comp(&params[paramIndex], num1, num2);
}

void print_comp_exec(struct complex params[], char input[]){
	int i = 0, paramIndex = 0;
	char param;

	for(; isalpha((input)[i]) || (input)[i] == '_'; i++) /* skipping the command */
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param = input[++i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the \n (in case it's valid) */
	if(input[i] != '\n' && input[i] != EOF && input[i] != '\0'){
		alertError("Extraneous text after command.");
		return;
	}
	
	paramIndex = param - 'A';
	print_comp(&params[paramIndex]);
}
void add_comp_exec(struct complex params[], char input[]){
	int i = 0, paramIndex = 0, param1Index = 0;
	char param, param1;

	for(; isalpha((input)[i]) || (input)[i] == '_'; i++) /* skipping the command */
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param = input[++i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the comma */
	if(input[i] != ',') { 
		alertError("Missing comma"); 
		return; 
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param1 = input[i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the \n (in case it's valid) */
	if(input[i] != '\n' && input[i] != EOF && input[i] != '\0'){
		alertError("Extraneous text after command.");
		return;
	}
	
	paramIndex =  param - 'A';
	param1Index = param1 - 'A';
	add_comp(&params[paramIndex], &params[param1Index]);
}

void sub_comp_exec(struct complex params[], char input[]){
	int i = 0, paramIndex = 0, param1Index = 0;
	char param, param1;

	for(; isalpha((input)[i]) || (input)[i] == '_'; i++) /* skipping the command */
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param = input[++i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the comma */
	if(input[i] != ',') { 
		alertError("Missing comma"); 
		return; 
	}
	i++;
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param1 = input[i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the \n (in case it's valid) */
	if(input[i] != '\n' && input[i] != EOF && input[i] != '\0'){
		alertError("Extraneous text after command.");
		return;
	}
	
	paramIndex =  param - 'A';
	param1Index = param1 - 'A';
	sub_comp(&params[paramIndex], &params[param1Index]);
}

void mult_comp_real_exec(struct complex params[], char input[]){
	int i = 0, j = 0, paramIndex = 0;
	char number[MAX_LEN];
	double num1;
	char param;

	for(; isalpha((input)[i]) || (input)[i] == '_'; i++) /* skipping the command */
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param = input[++i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the comma */
	if(input[i] != ',') { 
		alertError("Missing comma"); 
		return; 
	}
	i++;
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the number */
	
	while(isdigit(input[i]) || input[i] == '.' || input[i] == '-') number[j++] = input[i++]; /* getting all the digits of the number. */
	
	number[j] = '\0';
	num1 = atof(number); /* converting to a number */
	if(j == 0){ alertError("Wrong parameters, second parameter should be a number."); return; }
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the \n (in case it's valid) */
	if(input[i] != '\n' && input[i] != EOF && input[i] != '\0'){
		alertError("Extraneous text after command.");
		return;
	}
	
	paramIndex =  param - 'A';
	mult_comp_real(&params[paramIndex], num1);
}
void mult_comp_img_exec(struct complex params[], char input[]){
	int i = 0, j = 0, paramIndex = 0;
	char number[MAX_LEN];
	double num1;
	char param;

	for(; isalpha((input)[i]) || (input)[i] == '_'; i++) /* skipping the command */
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param = input[++i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the comma */
	if(input[i] != ',') { 
		alertError("Missing comma"); 
		return; 
	}
	i++;
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the number */
	
	while(isdigit(input[i]) || input[i] == '.' || input[i] == '-') number[j++] = input[i++]; /* getting all the digits of the number. */
	
	number[j] = '\0';
	num1 = atof(number); /* converting to a number */
	if(j == 0){ alertError("Wrong parameters, second parameter should be a number."); return; }
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the \n (in case it's valid) */
	if(input[i] != '\n' && input[i] != EOF && input[i] != '\0'){
		alertError("Extraneous text after command.");
		return;
	}
	
	paramIndex =  param - 'A';
	mult_comp_img(&params[paramIndex], num1);
}

void mult_comp_comp_exec(struct complex params[], char input[]){
	int i = 0, paramIndex = 0, param1Index = 0;
	char param, param1;

	for(; isalpha((input)[i]) || (input)[i] == '_'; i++) /* skipping the command */
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param = input[++i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the comma */
	if(input[i] != ',') { 
		alertError("Missing comma"); 
		return; 
	}
	i++;
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param1 = input[i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the \n (in case it's valid) */
	if(input[i] != '\n' && input[i] != EOF && input[i] != '\0'){
		alertError("Extraneous text after command.");
		return;
	}
	
	paramIndex =  param - 'A';
	param1Index = param1 - 'A';
	mult_comp_comp(&params[paramIndex], &params[param1Index]);
}

void abs_comp_exec(struct complex params[], char input[]){
	int i = 0, paramIndex = 0;
	char param;

	for(; isalpha((input)[i]) || (input)[i] == '_'; i++) /* skipping the command */
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the parameter */
	
	if(!isValidParam(param = input[++i])){
		if(input[i] == ','){ 
			alertError("Invalid comma"); 
			return;
		}
		else { 
			alertError("Missing or invalid parameter"); 
			return; 
		}
	}
	i++;
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the \n (in case it's valid) */
	if(input[i] != '\n' && input[i] != EOF && input[i] != '\0'){
		alertError("Extraneous text after command.");
		return;
	}
	
	paramIndex = param - 'A';
	abs_comp(&params[paramIndex]);
}
void stop_exec(struct complex params[], char input[]){
	int i = 0;
	for(; isalpha((input)[i]) || (input)[i] == '_'; i++) /* skipping the command */
	
	while(isspace(input[i]) && input[i] != '\n') i++;  /* skipping all the spaces until the \n (in case it's valid) */
	
	if(input[i] != '\n' && input[i] != EOF && input[i] != '\0'){
		alertError("Extraneous text after command.");
		return;
	}
	stop();
}
