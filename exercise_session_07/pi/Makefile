all: main

main: leibnitz.o /usr/include/openmpi-x86_64/mpi.h
	mpicc -o leibnitz.o leibnitz.c


clean: 
	rm -f *.o
