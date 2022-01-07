prog: complex.o mycomp.o
	gcc -ansi -Wall -pedantic -m32 complex.c mycomp.c exec_comp.c complex.h exec.h -lm -o prog
complex.o: complex.c complex.h
	gcc -c -ansi -Wall -pedantic -m32 -lm complex.c 
mycomp.o: mycomp.c complex.h
	gcc -c -ansi -Wall -pedantic -m32 -lm mycomp.c 
exec_comp.o: exec_comp.c exec.h
	gcc -c -ansi -Wall -pedantic -m32 exec_comp.c
