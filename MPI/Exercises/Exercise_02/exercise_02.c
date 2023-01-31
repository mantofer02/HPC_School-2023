#include <stdio.h>
#include <mpi.h>
#include <string.h>
#define SIZE 10000

int main(int argc, char *argv[])
{
  int error, n_procs, my_rank;
  float buffer[SIZE];
  float data[SIZE];

  error = MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  for (int i = 0; i < SIZE; i++)
  {
    buffer[i] = 9;
  };
  // preguntar porque memset pone todo en 0
  // memset(buffer, 5, sizeof(buffer));

  if (my_rank == 0)
  {
    MPI_Send(buffer, SIZE, MPI_FLOAT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(data, SIZE, MPI_FLOAT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  else if (my_rank == 1)
  {
    MPI_Recv(data, SIZE, MPI_FLOAT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Send(buffer, SIZE, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
  }
  printf("Process %d received data: %f\n", my_rank, buffer[4]);

  error = MPI_Finalize();
}