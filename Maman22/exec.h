#define FOREVER for(;;)
#include "complex.h"

void read_comp_exec(struct complex params[], char input[]);
void print_comp_exec(struct complex params[], char input[]);
void add_comp_exec(struct complex params[], char input[]);
void sub_comp_exec(struct complex params[], char input[]);
void mult_comp_real_exec(struct complex params[], char input[]);
void mult_comp_img_exec(struct complex params[], char input[]);
void mult_comp_comp_exec(struct complex params[], char input[]);
void abs_comp_exec(struct complex params[], char input[]);
void stop_exec(struct complex params[], char input[]);
