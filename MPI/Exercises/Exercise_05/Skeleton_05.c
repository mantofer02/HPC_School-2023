  #include <stdlib.h>
  #include <stdio.h>
  #include <mpi.h>

  #define N 20

  int main(int argc, char* argv[]){


    int my_id, num_procs;
    int i,j;
    int rem, num_local_row;
    int *matrix;
    int proc_up, proc_down;
    MPI_Status  status1, status2;

   /* Initialize the environment and die and store the size in "num_procs" and the rank in "my_id" */
    ...

    /*  number of rows for each mpi task. How does it work? Try to write it down. */
    rem= N % num_procs;
    num_local_row = (N - rem)/num_procs;
    if(my_id < rem) num_local_row = num_local_row+1;

    /* Allocation of the global matrix as an array of contiguous elements. Instead of "..." put one of the following:
    1. num_local_row  2. num_local_row+1  3. num_local_row+2 */
    matrix = (int*) malloc(((...)*N)*sizeof(int));

    /* initialization of the local matrix */
    for(i=0; i<num_local_row+2 ;i++){
      for(j=0; j<N; j++){
        matrix[i*N+j] = my_id ;
      }
    }

    /* Information about the neighbour processes (imagine that you are sending up and down arrays of data, so the variables are named to reflect that) */
    proc_down = my_id+1;
    proc_up = my_id-1;
    if(proc_down==num_procs) proc_down=0;
    if(proc_up < 0) proc_up=num_procs-1;

    /* check printings */
    /* printf("rank %d, proc up %d, proc down %d\n",
    my_id, proc_up, proc_down); */

    /* printf("my_id %d, num_local_row %d\n", my_id, num_local_row); */

    /* printf("my_id %d,matrix[0] %d, matrix[N] %d,
    matrix[(N)*(num_local_row+2)] %d \n", my_id, matrix[0],
    matrix[N], matrix[N*(num_local_row+2)]); */

    /* send receive of the ghost regions */
    /* First one: sends the uppest real row to the proc above it, and receives on the lowest ghost row from the proc below it */
    MPI_Sendrecv(...);

    /* Second one: sends the lowest real row to the prov below it, and receives on the uppest shost row from the proc above it */
    MPI_Sendrecv(...);


    /* check printings */
    printf("\n ");

    printf("my_id, %d, riga arrivata da sopra: ", my_id);
    for(i=0;i<N;i++){
      printf("%d \t", matrix[i]);
      }
    printf("\n ");

    printf("my_id, %d, riga arrivata da sotto: ", my_id);
    for(i=N*(num_local_row+1);i<N*(num_local_row+1)+N;i++){
      printf("%d \t", matrix[i]);
    }
    printf("\n ");

    free(matrix);
    /* Finalize MPI Environment */
    ...
    return 0;
  }
