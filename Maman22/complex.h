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
struct complex add_comp(complex *param, complex *param1);
struct complex sub_comp(complex *param, complex *param1);
struct complex mult_comp_real(complex *param, double re);
struct complex mult_comp_img(complex *param, double im);
struct complex mult_comp_comp(complex *param, complex *param1);
struct complex abs_comp(complex *param);
void stop();






