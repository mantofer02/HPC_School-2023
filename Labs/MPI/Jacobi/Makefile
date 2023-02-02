GCC  = gcc -O3 -fopenmp 
FLAG = -lm
BIN = jacobi

help:
	@echo "Please specify the make target"

serial_c: jacobi-serial.c
	$(GCC) -o $(BIN) $< $(FLAG)

openmp_c: jacobi-openmp.c
	$(GCC) -o $(BIN) $< $(FLAG)

clean:
	$(RM) $(BIN) 
