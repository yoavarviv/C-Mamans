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
