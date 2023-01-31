#include <stdio.h>
#include <mpi.h>
#include <string.h>
#define SIZE 10000

int main(int argc, char *argv[])
{
  int error, n_procs, my_rank;
  float a[SIZE];
  float b[SIZE];

  error = MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  memset(a, my_rank, sizeof(buffer));

  MPI_Isend(a, SIZE, MPI_FLOAT, (my_rank + 1) % n_procs, 0, MPI_COMM_WORLD);
  MPI_Irecv(b, SIZE, MPI_FLOAT, (my_rank - 1 >= 0 ? my_rank : n_procs - 1, 0, MPI_COMM_WORLD));

  printf("I am rocess %d  and I received value: %f\n", my_rank, b[5]);

  error = MPI_Finalize();
};