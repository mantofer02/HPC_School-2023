#include <stdio.h>
#include <mpi.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int error, n_procs, my_rank;
  float buffer[10000];
  float data[10000];

  error = MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  for (int i = 0; i < 10000; i++)
  {
    buffer[i] = my_rank;
  };
  memset(buffer, 5, sizeof(buffer));
  printf("pre message %f", buffer[4]);

  if (my_rank == 0)
  {
    MPI_Send(&buffer, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&data, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  else if (my_rank == 1)
  {
    MPI_Send(&buffer, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
    MPI_Recv(&data, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  printf("Process %d received data: %f\n", my_rank, data[4]);

  error = MPI_Finalize();
}