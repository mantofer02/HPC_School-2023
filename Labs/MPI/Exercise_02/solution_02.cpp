#include <mpi.h>
#include <iostream>

#define NDATA 10000

using namespace std;

int main(int argc, char* argv[]){

    int me, nprocs, i = 0;
    MPI_Status status;

    float a[NDATA];
    float b[NDATA];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &me);

    /* Initialize data */
    for(i=0;i<NDATA;++i){
    a[i] = me;
    }
    /* Protect against the use with a number of processes != 2 */
    if(nprocs!=2){
      if (me==0)
          cout << "This program must run on 2 processors" << endl;
      MPI_Finalize();
      return 0;
    }
    /* Send and Receive data */
    if(me==0){
      MPI_Send(a, NDATA, MPI_REAL, 1, 0, MPI_COMM_WORLD);
      MPI_Recv(b, NDATA, MPI_REAL, 1, 0, MPI_COMM_WORLD, &status);
    }
    else{
      MPI_Recv(b, NDATA, MPI_REAL, 0, 0, MPI_COMM_WORLD, &status);
      MPI_Send(a, NDATA, MPI_REAL, 0, 0, MPI_COMM_WORLD);
    }

    cout << "I am task " << me << " and I have received b(0) = " << b[0] << endl;

    MPI_Finalize();
    return 0;
}
