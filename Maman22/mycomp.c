#define MAX_LEN 100
#define NUM_OF_PARAMS 6
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "complex.h"
#include <string.h>
#include <stdbool.h>

void getCommand();
void inputSwitch(char command[]);
int isValidParam(char param);
void alertError(char errorMsg[]);

struct complex params[6] = {0};

int main(){
	int i;
	for(i = 0; i < NUM_OF_PARAMS; i++){
		params[i].re = 0;
		params[i].im = 0;
	}
	
	getCommand();	
	
	return 0;
}

void getCommand(){
	char command[MAX_LEN] = {0};
	int i = 0;
	char c;
	bool isValid = true;
	
	
	while(1){
		while(isspace(c = getchar())); /* skip all the spaces. */
		command[i++] = c;
		while(isalpha(c = getchar()) || c == '_'){
			command[i++] = c;
		}
		
		if(c == '\n' || c == EOF) { alertError("Missing parameter/s"); isValid = false; }
		else if(c == ',') { alertError("Illegal comma after command"); isValid = false; }
		
			
		command[i] = '\0';
		if(isValid){
			inputSwitch(command);
		}
		while(getchar() != '\n');
		
		i = 0;
		isValid = true;
	}
	
}

void inputSwitch(char command[]){
	char param, param1, c;
	float firstOperand, secondOperand;
	int paramIndex = 0, param1Index = 0;
	
	if(!strcmp(command, "read_comp")){
	
		while(isspace(param = getchar()) && param != '\n');
		
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param)){
			if(param == '\n' || param == EOF){
				alertError("Missing complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');

		/* Check if they entered illegal characters after the parameter */
		if(c != ','){
			if(c == '\n' || c == EOF){
				alertError("Missing parameter");
			}
			else{
				alertError("Illegal character/characters after parameter.");
			}
			return;
		}
		
		/* Check if they didn't enter a valid first operand */
		if(scanf("%f", &firstOperand) != 1){
			alertError("Invalid or missing first parameter.");
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered illegal characters after the parameter */
		if(c != ','){
			if(c == '\n' || c == EOF){
				alertError("Missing parameter");
			}
			else{
				alertError("Illegal character/characters after parameter.");
			}
			return;
		}
		
		
		/* Check if they didn't enter a valid second operand */
		if(scanf("%f", &secondOperand) != 1){
			alertError("Invalid or missing second parameter.");		
			return;				
		}
		
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered extraneous text after the end of the command */
		if(c != '\n' && c != EOF){
			alertError("Extraneous text after end of command.");		
			while((c = getchar()) != '\n' && c != EOF);
			return;
		}	
		
		paramIndex = param - '0';
		
		read_comp(&params[paramIndex], firstOperand, secondOperand);
	}
	/*------------------------------------------------------------------------------*/
	else if(!strcmp(command, "print_comp")){
		char c;
		
		while(isspace(param = getchar()) && param != '\n');
		
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param)){
			if(param == '\n' || param == EOF){
				alertError("Missing complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered extraneous text after the end of the command */
		if(c != '\n' && c != EOF){
			alertError("Extraneous text after end of command.");	
			while((c = getchar()) != '\n' && c != EOF);	
			return;
		}	
			
		paramIndex = param - '0';
		print_comp(&params[paramIndex]);
	}
	/*------------------------------------------------------------------------------*/
	else if(!strcmp(command, "add_comp")){
	
		while(isspace(param = getchar()) && param != '\n');
		
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param)){
			if(param == '\n' || param == EOF){
				alertError("Missing complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');

		/* Check if they entered illegal characters after the parameter */
		if(c != ','){
			if(c == '\n' || c == EOF){
				alertError("Missing parameter");
			}
			else{
				alertError("Illegal character/characters after parameter.");
			}
			return;
		}
		
		while(isspace(param1 = getchar()) && param1 != '\n');
		
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param1)){
			alertError("Undefined complex variable.");
			return;
		}
		
		
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered extraneous text after the end of the command */
		if(c != '\n' && c != EOF){
			alertError("Extraneous text after end of command.");		
			while((c = getchar()) != '\n' && c != EOF);	
			return;
		}	
		
		paramIndex = param - '0';
		param1Index = param1 - '0';
		add_comp(&params[paramIndex], &params[param1Index]);
	}
	/*------------------------------------------------------------------------------*/
	else if(!strcmp(command, "sub_comp")){
		while(isspace(param = getchar()) && param != '\n');
		
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param)){
			if(param == '\n' || param == EOF){
				alertError("Missing complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');

		/* Check if they entered illegal characters after the parameter */
		if(c != ','){
			if(c == '\n' || c == EOF){
				alertError("Missing parameter");
			}
			else{
				alertError("Illegal character/characters after parameter.");
			}
			return;
		}
		
		while(isspace(param1 = getchar()) && param1 != '\n');
		
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param1)){
			if(!isalpha(param1) || param1 == '\n' || param1 == EOF){
				alertError("Missing complex variable / Invalid complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered extraneous text after the end of the command */
		if(c != '\n' && c != EOF){
			alertError("Extraneous text after end of command.");		
			while((c = getchar()) != '\n' && c != EOF);	
			return;
		}	
			
		paramIndex = param - '0';
		param1Index = param1 - '0';
		sub_comp(&params[paramIndex], &params[param1Index]);
	}
	/*------------------------------------------------------------------------------*/
	if(!strcmp(command, "mult_comp_real")){
	
		while(isspace(param = getchar()) && param != '\n');
		
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param)){
			if(param == '\n' || param == EOF){
				alertError("Missing complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');

		/* Check if they entered illegal characters after the parameter */
		if(c != ','){
			if(c == '\n' || c == EOF){
				alertError("Missing parameter");
			}
			else{
				alertError("Illegal character/characters after parameter.");
			}
			return;
		}
		
		/* Check if they didn't enter a valid first operand */
		if(scanf("%f", &firstOperand) != 1){
			alertError("Invalid or missing first parameter.");
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered extraneous text after the end of the command */
		if(c != '\n' && c != EOF){
			alertError("Extraneous text after end of command.");		
			while((c = getchar()) != '\n' && c != EOF);	
			return;
		}	
		
		paramIndex = param - '0';
		mult_comp_real(&params[paramIndex], firstOperand);
	}
	/*------------------------------------------------------------------------------*/
	if(!strcmp(command, "mult_comp_img")){
	
		while(isspace(param = getchar()) && param != '\n');
		
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param)){
			if(param == '\n' || param == EOF){
				alertError("Missing complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');

		/* Check if they entered illegal characters after the parameter */
		if(c != ','){
			if(c == '\n' || c == EOF){
				alertError("Missing parameter");
			}
			else{
				alertError("Illegal character/characters after parameter.");
			}
			return;
		}
		
		/* Check if they didn't enter a valid first operand */
		if(scanf("%f", &firstOperand) != 1){
			alertError("Invalid or missing first parameter.");
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered extraneous text after the end of the command */
		if(c != '\n' && c != EOF){
			alertError("Extraneous text after end of command.");		
			while((c = getchar()) != '\n' && c != EOF);	
			return;
		}
		
		paramIndex = param - '0';
		mult_comp_img(&params[paramIndex], firstOperand);
	}
	/*------------------------------------------------------------------------------*/
	if(!strcmp(command, "mult_comp_comp")){
	
		while(isspace(param = getchar()) && param != '\n');
	
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param)){
			if(param == '\n' || param == EOF){
				alertError("Missing complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');

		/* Check if they entered illegal characters after the parameter */
		if(c != ','){
			if(c == '\n' || c == EOF){
				alertError("Missing parameter");
			}
			else{
				alertError("Illegal character/characters after parameter.");
			}
			return;
		}
		
		while(isspace(param1 = getchar()) && param1 != '\n');
		
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param1)){
			if(param1 == '\n' || param1 == EOF){
				alertError("Missing complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered extraneous text after the end of the command */
		if(c != '\n' && c != EOF){
			alertError("Extraneous text after end of command.");		
			while((c = getchar()) != '\n' && c != EOF);	
			return;
		}	
		
		paramIndex = param - '0';
		param1Index = param1 - '0';
		mult_comp_comp(&params[paramIndex], &params[param1Index]);
	}
	/*------------------------------------------------------------------------------*/
	else if(!strcmp(command, "abs_comp")){
		char c;
		char param;
		
		while(isspace(param = getchar()) && param != '\n');
	
		/* Check if they provided an invalid parameter */
		if(!isValidParam(param)){
			if(param == '\n' || param == EOF){
				alertError("Missing complex variable");
			}
			else{
				alertError("Undefined complex variable.");
			}
			return;
		}
		
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered extraneous text after the end of the command */
		if(c != '\n' && c != EOF){
			alertError("Extraneous text after end of command.");		
			while((c = getchar()) != '\n' && c != EOF);	
			return;
		}
			
		paramIndex = param - '0';
		abs_comp(&params[paramIndex]);
	}
	/*------------------------------------------------------------------------------*/
	else if(!strcmp(command, "stop")){
	
		while(isspace(c = getchar()) && c != '\n');
		
		/* Check if they entered extraneous text after the end of the command */
		if(c != '\n' && c != EOF){
			alertError("Extraneous text after end of command.");		
			while((c = getchar()) != '\n' && c != EOF);	
			return;
		}
		exit(0);
	}
	else{ alertError("Unknown Command"); return; }
	
}

int isValidParam(char param){
	return param == 'A' || param == 'B' || param == 'C' || param == 'D' || param == 'E' || param == 'F';
}

void alertError(char errorMsg[]){
	printf("%s\n", errorMsg);
}


