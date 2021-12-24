prog: complex.o mycomp.o
	gcc -ansi -Wall -pedantic -g complex.c mycomp.c complex.h -lm -o prog
complex.o: complex.c complex.h
	gcc -c -ansi -Wall -pedantic -lm complex.c 
mycomp.o: mycomp.c complex.h
	gcc -c -ansi -Wall -pedantic -lm mycomp.c 
