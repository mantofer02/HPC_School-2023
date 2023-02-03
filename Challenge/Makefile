GCC  = gcc -O3 -fopenmp
GF90 = gfortran -O3 -fopenmp
FLAGS = -lm
BIN = binary_omp

help:
	@echo "Please specify the make target"

code_c: *.c
	$(GCC) -o $(BIN) $< $(FLAGS)

clean:
	$(RM) $(BIN) 
