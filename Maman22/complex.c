#include "complex.h"

void read_comp(complex *param, double re, double im){
	param->re = re;
	param->im = im;
}

void print_comp(complex *param){
	printf("%f + (%f)i\n", param->re, param->im);
}

void add_comp(complex *param, complex *param1){
	struct complex new;
	new.re = param->re + param1-> re;
	new.im = param->im + param1->im;
	
	print_comp(&new);
}

void sub_comp(complex *param, complex *param1){
	struct complex new;
	new.re = param->re - param1->re;
	new.im = param->im - param1->im;
	
	print_comp(&new);
}

void mult_comp_real(complex *param, double re){
    	struct complex new;
	new.re = param->re * re;
	new.im = param->im * re;
	
	print_comp(&new);
}

void mult_comp_img(complex *param, double im){
	struct complex new;
	new.re = -1 * param->im*im;
	new.im = param->re * im;

	print_comp(&new);
}

void mult_comp_comp(complex *param, complex *param1){
	struct complex new;
	new.re = param->re*param1->re - param->im*param1->im;
	new.im = param->re*param1->im + param->im*param1->re;
	
	print_comp(&new);

}

void abs_comp(complex *param){
	struct complex new;
	new.re = sqrt(pow(param->re, 2) + pow(param->im, 2));
	new.im = 0;

	print_comp(&new);	
}

void stop(){
	exit(0);
}

