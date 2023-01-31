#include <stdio.h>
#include <mpi.h>
#include <string.h>

int main(int argc, char * argv[]) {
  int error, n_procs, my_rank;
  error = MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  printf("Hello, I am %d of %d processes \n", my_rank, n_procs);

  float data[10000];
  memset(data, my_rank, sizeof(data));

   if (my_rank == 0) {
    MPI_Send(&data, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&data, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  } else if (my_rank == 1) {
    MPI_Send(&data, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
    MPI_Recv(&data, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
    printf("Process %d received data: %f\n", my_rank, data[4]);

  error = MPI_Finalize();
}