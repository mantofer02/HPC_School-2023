#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

/* #define ndata 1000 */
#define ndata 1000000

int main(int argc, char *argv[])
{

  int my_rank, n_procs, left, right;
  float a, b, sum;

  MPI_Status status;
  MPI_Request request;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  a = (float)my_rank;
  right = (my_rank + 1) % n_procs;
  left = (my_rank - 1 + n_procs) % n_procs;

  for (int i = 0; i < n_procs; i++)
  {
    MPI_Isend(&a, 1, MPI_FLOAT, right, 0, MPI_COMM_WORLD, &request);
    MPI_Recv(&b, 1, MPI_FLOAT, left, 0, MPI_COMM_WORLD, &status);
    a = b;
    sum += b;
    MPI_Wait(&request, &status);
  }

  /* Sendrecv data */

  printf("\tI am task %d and my sum is: %1.2f \n", my_rank, sum);

  MPI_Finalize();
  return 0;
}
