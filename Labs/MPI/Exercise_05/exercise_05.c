#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#define N 100

int main(int argc, char *argv[])
{
  int matrix[N][N];
  int my_rank, n_procs, left, right;

  MPI_Status status;
  MPI_Request request;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  right = (my_rank + 1) % n_procs;
  left = (my_rank - 1 + n_procs) % n_procs;

  MPI_Finalize();

  return 0;
}
