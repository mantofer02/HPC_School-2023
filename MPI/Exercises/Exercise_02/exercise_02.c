#include <stdio.h>
#include <mpi.h>

int main(int argc, char * argv[]) {
  int error, n_procs, my_rank;
  error = MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  printf("Hello, I am %d of %d processes \n", my_rank, n_procs);


   if (rank == 0) {
    MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    printf("Process 0 sent data: %d\n", data);
  } else if (rank == 1) {
    MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received data: %d\n", data);
  }

  error = MPI_Finalize();
}