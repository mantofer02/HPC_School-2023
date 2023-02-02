# Jacobi solver
The Jacobi method is an iterative algorithm for solving a system of linear equations (more details on the presentation contained in this folder). Here is presented in two "flavours": a serial code and an MPI code, where the problem is divided in grids with the techniques of domain decomposition.


# Exercise on scaling
1. Try first the serial code, for various grid sizes.   ./jacobi_serial 100 100
2. Choose a grid size (for example 200x200) and run with 1,2,4,8, .. MPI processes.
3. Calculate the parallel efficiency depending on the number of processors. (PE=100*PN/(N*P1))
4. (optional) Replace the blocking send/recv with non-blocking send/recv ot with MPI_Sendrecv and re-run. Check the results.


# Exercise on hybridization
1. Have a look at the source code and answer the following questions:
	-  Which loop or loops would you try to parallelize with OpenMP?
	-  Which OpenMP C pragmas would you use to do the parallelization?
Try to parallelize the serial code on the correct loops with OpenMP and check the results. They have to be *similar* to the serial version.
2. This code would be a good choice for hybrid MPI+OpenMP: use MPI and domain decomposition to distribute data over shared memory nodes, but use OpenMP to parallize with threads the loops over local data. Try that on the MPI version of the code and run it with different number of tasks and threads.


# To compile
serial version:
```
gcc jacobi-serial.c –o <your_exec_name> -lm
```
MPI version:
```
mpicc jacobi-serial.c –o <your_exec_name> -lm
```
OpenMP version:
```
gcc jacobi-serial.c –o <your_exec_name> -lm -fopenmp
```
Hybrid version:
```
mpicc jacobi-serial.c –o <your_exec_name> -lm -fopenmp
```

# To run
Serial and OpenMP: launch "time ./your_exec_name 200 200" on login node.  
MPI and Hybrid: edit and use job.sh (see presentation)
