#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>


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


