#include <stdio.h>
#include <mpi.h>
#include <string.h>
#define SIZE 10000

int main(int argc, char *argv[])
{
  int error, n_procs, my_rank;
  float a, b, sum;

  error = MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Request request;

  int it = my_rank;
  a = (float)my_rank;
  // for (int i = 0; i < n_procs; i++)
  // {
  MPI_Isend(&a, SIZE, MPI_FLOAT, (it + n_procs - 1) % n_procs, 0, MPI_COMM_WORLD, &request);
  MPI_Irecv(&a, SIZE, MPI_FLOAT, (it + 1) % n_procs, 0, MPI_COMM_WORLD, &request);
  // sum += b;
  MPI_Wait(&request, MPI_STATUS_IGNORE);
  // }

  printf("I am process %d and sum = %f\n", my_rank, sum);

  error = MPI_Finalize();
};