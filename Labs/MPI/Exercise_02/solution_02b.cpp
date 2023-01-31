#include <mpi.h>
#include <string>

#define ndata 10000

using namespace std;

int main(int argc, char* argv[]){

    int ierr, me, nprocs, i=0, you;
    MPI_Status status;
    MPI_Request req;

    float a[ndata];
    float b[ndata];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &me);


    for(i=0;i<ndata;++i){
    a[i] = me;
    }

    if(nprocs>2){
      if(me==0)
        cout << "This program must run on 2 processors" << endl;
      MPI_Finalize();
      return 0;
    }

    you = 1-me;

    MPI_Isend(a, ndata, MPI_REAL, you, 0, MPI_COMM_WORLD, &req);
    MPI_Recv(b, ndata, MPI_REAL, you, 0, MPI_COMM_WORLD, &status);
    
    MPI_Wait(&req,&status);

    cout << "I am task "<< me << " and I have received b(0) = " << b[0] << endl;

    MPI_Finalize();
    return 0;
}
