CC = mpicxx
FLAG = -g

no_mpi_io_1: no_mpi_io_1.cpp
	${CC} -g -o $@.o $^
no_mpi_io_2: no_mpi_io_2.cpp
	${CC} -g -o $@.o $^

.PHONY: clean
clean:
	-rm *.o file*
