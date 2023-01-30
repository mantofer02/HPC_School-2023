#include <stdio.h>
#include <mpi.h>

int main(int argc, char * argv[]) {
  int error, n_procs, my_rank;
  error = MPI_Innit(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  printf("Hello, I am %d of %d processes \n", my_rank, n_procs);

  error = MPI_Finalize();
}