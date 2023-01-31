#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

  int me, nprocs;

  /* Initialize MPI environment */
  MPI_Init(&argc, &argv) ;
    
  /* Get the size of the MPI_COMM_WORLD communicator */
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs) ;
   
  /* Get my rank... */
  MPI_Comm_rank(MPI_COMM_WORLD, &me) ;
    
  /* ...and print it. */
  cout << "Hello, I am task " << me << " of " << nprocs << endl;
  /* Finalize MPI environment */
  MPI_Finalize() ;

  return 0;
}
