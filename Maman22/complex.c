#include "complex.h"

/* 
   This function reads values into a complex number 
   parameters: 
   param - the parameter to insert it to.
   re - the real value to insert.
   im - the imaginary value to insert.
*/
void read_comp(complex *param, double re, double im){
	param->re = re;
	param->im = im;
}

/* 
   This function prints a complex number 
   parameters: 
   param - the parameter to print.
*/
void print_comp(complex *param){
	printf("%f + (%f)i\n", param->re, param->im);
}

/* 
   This function adds 2 complex numbers.
   parameters: 
   param - first operand.
   param1 - second operand.
*/
struct complex add_comp(complex *param, complex *param1){
	struct complex new;
	new.re = param->re + param1-> re;
	new.im = param->im + param1->im;
	
	return new;
}

/* 
   This function substracts 2 complex numbers.
   parameters: 
   param - first operand.
   param1 - second operand.
*/
struct complex sub_comp(complex *param, complex *param1){
	struct complex new;
	new.re = param->re - param1->re;
	new.im = param->im - param1->im;
	
	return new;
}

/* 
   This function multiplies a complex number by a real value.
   parameters: 
   param - the complex number.
   re - the real value.
*/
struct complex mult_comp_real(complex *param, double re){
    	struct complex new;
	new.re = param->re * re;
	new.im = param->im * re;
	
	return new;
}

/* 
   This function multiplies a complex number by an image value.
   parameters: 
   param - the complex number.
   re - the real value.
*/
struct complex mult_comp_img(complex *param, double im){
	struct complex new;
	new.re = -1 * param->im*im;
	new.im = param->re * im;

	return new;
}

/* 
   This function multiplies a complex number by another complex number.
   parameters: 
   param - first complex number.
   param1 - second complex number.
*/
struct complex mult_comp_comp(complex *param, complex *param1){
	struct complex new;
	new.re = param->re*param1->re - param->im*param1->im;
	new.im = param->re*param1->im + param->im*param1->re;
	
	return new;

}

/* 
   This function returns the absolute value of a complex number.
   parameters: 
   param - the complex number.
*/
struct complex abs_comp(complex *param){
	struct complex new;
	new.re = sqrt(pow(param->re, 2) + pow(param->im, 2));
	new.im = 0;

	return new;	
}

/*
   This function stops the execution of the program.
*/
void stop(){
	exit(0);
}

