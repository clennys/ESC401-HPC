cpi: cpi.o get_time.o
	cc -O3 -o cpi cpi.o get_time.o

cpi_mpi: cpi_mpi.o get_time.o
	cc -O3 -o cpi_mpi cpi_mpi.o get_time.o

cpi_mpi.o: cpi_mpi.c get_time.h
	cc -O3 -c -o cpi_mpi.o cpi_mpi.c 

cpi.o: cpi.c get_time.h
	cc -O3 -c -o cpi.o cpi.c 

get_time.o: get_time.c get_time.h
	cc -O3 -c -o get_time.o get_time.c 
all: cpi cpi_mpi

clean:
	rm -f cpi cpi.o get_time.o cpi_mpi cpi_mpi.o
