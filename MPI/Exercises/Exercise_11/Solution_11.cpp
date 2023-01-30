
#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) { 

// Declare variables (or do it later)
 int n_proc, n_rank, i,j ;
 MPI_Datatype myvector;
 int myvector_size;
 const int n=5, nb=2;
 MPI_Aint myvector_extent, myvector_lb;
 float a[n][n];
 MPI_Status mystatus;

// Start MPI
 MPI_Init(&argc,&argv);
 MPI_Comm_size(MPI_COMM_WORLD,&n_proc);
 MPI_Comm_rank(MPI_COMM_WORLD,&n_rank);

// Check the number of processes is 2
 if(n_proc != 2) {
    if(n_rank == 0) cout << "Test program has to work only with two MPI processes" << endl;
   MPI_Finalize();
   exit(1);
 }

// Initialize matrix
 if(n_rank == 0) for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j] = 0.F;
 if(n_rank == 1) for(i=0;i<n;i++) for(j=0;j<n;j++) a[i][j] = 1.F;

// Define vector, extract and print size and extent
 MPI_Type_vector(n, nb, n, MPI_FLOAT, &myvector);
 MPI_Type_commit(&myvector);

 MPI_Type_size(myvector, &myvector_size);
 MPI_Type_get_extent(myvector, &myvector_lb, &myvector_extent);

 cout << "MPI myvector size, lb, extent: " << myvector_size << ", " << myvector_lb << ", " << myvector_extent << endl;

// Print matrix a for rank=1
 if(n_rank == 1) {
    cout << "Matrix A before communications:" << endl;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
 }

// Communicate
 if(n_rank == 0) {
    MPI_Send(a, 1, myvector, 1, 100, MPI_COMM_WORLD);
 }
 if(n_rank == 1) {
    MPI_Recv(a, 1, myvector, 0, 100, MPI_COMM_WORLD, &mystatus);
 }

// Print matrix a for rank=1
 if(n_rank == 1) {
    cout << "Matrix A after communications:" << endl;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
 }

 MPI_Type_free(&myvector);

// Finalize MPI
 MPI_Finalize();

 return 0;
}
