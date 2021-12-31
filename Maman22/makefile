prog: complex.o mycomp.o
	gcc -ansi -Wall -pedantic -m32 complex.c mycomp.c complex.h -lm -o prog
complex.o: complex.c complex.h
	gcc -c -ansi -Wall -pedantic -m32 -lm complex.c 
mycomp.o: mycomp.c complex.h
	gcc -c -ansi -Wall -pedantic -m32 -lm mycomp.c 
