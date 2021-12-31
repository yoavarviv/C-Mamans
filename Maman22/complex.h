
#define MAX_LEN 81
#define NUM_OF_PARAMS 6
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


typedef struct complex{
	double re, im;
} complex;

void initComplex();
void read_comp(complex *param, double re, double im);
void print_comp(complex *param);
void add_comp(complex *param, complex *param1);
void sub_comp(complex *param, complex *param1);
void mult_comp_real(complex *param, double re);
void mult_comp_img(complex *param, double im);
void mult_comp_comp(complex *param, complex *param1);
void abs_comp(complex *param);
void stop();


void getCommand(char input[]);
void inputSwitch(char command[]);
int isValidParam(char param);
void alertError(char errorMsg[]);
void executeCommand(struct complex params[]);


