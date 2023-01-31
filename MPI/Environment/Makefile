# The command to use it is: make
# Alternative to the Makefile: mpicc mycode.c -o myexe

PROGRAM=solution_01    # Edit this to change the name of your executable!
CC=mpicc
COMMON_FLAGS=-g -o $(PROGRAM)
SOURCE=solution_01.c   # Edit this to change the name of your source code!


multinode: $(SOURCE)
	$(CC) $(COMMON_FLAGS) $(SOURCE)

clean:
	rm $(PROGRAM)
